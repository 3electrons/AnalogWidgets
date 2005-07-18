#include <QtGui>
#include <math.h>
#include "barmeter.h"
#define PI 3.141592653589793238512808959406186204433


void BarMeter::calcMaxMin()
{
  m_max=maximum();
  m_min=minimum();
  int diff = m_max - m_min;
  int scale = 8;
  int factor = 5;
  while ( diff > scale ) { scale=8 * factor; factor+=5; }
  int m_m_min = 0;
  while (m_min > m_m_min ) m_m_min-=scale/8;
  m_max = scale - m_m_min;
  m_min = m_max - scale;
}

BarMeter::BarMeter(QWidget *parent)
        : QWidget(parent)
{
        m_max=m_min=0;
	setWindowTitle(tr("Analog BarMeter"));
	setNominal(80);
	setCritical(220);
        resize(300, 300);
	setMaximum(300);
  	setMinimum(0);
	setValue(0);
	setValueOffset(-100);
	setDigitOffset(105);
	m_digitFont.setPointSize(20);
	m_valueFont.setPointSize(25);


	// QWidget
        setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);

}

void BarMeter::setValue( int val )
{
  if ( m_value != val )
  {
    m_value = val;
    update(); // Ciekawe czy tak jest lepiej ??
    emit valueChanged(val);
  }
}

void BarMeter::paintEvent(QPaintEvent * )
{
	static const int scaleTriangle[6] = { -6,141,6,141,0,129 };


        int side = qMin(width(), height());
        // inicjalizacja paintera
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 307.0, side / 307.0);

        // Malowanie obwiedni tarczy. Bia³a tarcza z czarn± skal±
        QBrush Brush;
        Brush.setColor(Qt::white);
        Brush.setStyle(Qt::SolidPattern);
        QPen Pen; Pen.setWidth(4); Pen.setColor(QColor(0,0,0));
        painter.setPen(Pen);



        // zewnêtrzene ko³o
        painter.setBrush(Brush);
        painter.drawEllipse(-152,-152,304,304);
	// wewnêtrzene ko³o
	Pen.setWidth(4);
	painter.setPen(Pen);
	painter.drawEllipse(-142,-142,284,284);

	  painter.setPen(Qt::NoPen);
          // nominal
	  painter.setBrush(QBrush(Qt::green));
	  painter.drawPie(QRect(-141,-141,282,282),-480,3840-nominal()*3840/(m_max-m_min));
	  // Critical
	  painter.setBrush(QBrush(Qt::red));
	  painter.drawPie(QRect(-141,-141,282,282),-480,3840-critical()*3840/(m_max-m_min));
	  // bia³a obwiednia
	  painter.setBrush(QBrush(Qt::white));
	  painter.drawEllipse(-129,-129,258,258);

        // Ustawienie siê na pocz±tku skali
        painter.save();
        painter.rotate(60.0);

	// Rysowanie skali
	Brush.setColor(Qt::black);
	painter.setBrush(Brush);
	painter.save();
  	int line_length=10;
	for (int i=0;i<33;i++)
	{

	  painter.setPen(Pen);

	  if (! (i % 4) )
          {
	    painter.setPen(Qt::NoPen);
	    painter.drawConvexPolygon(QPolygon(3, scaleTriangle));
	  }
	  else painter.drawLine(0,140,0,140-line_length);

	  painter.rotate(7.5);

		Pen.setWidth(3);
		line_length=5;
 		if (i % 2) { line_length=10; }
	}
	painter.restore();
	// Rysowanie skali.
	painter.save();
	painter.rotate(-60.0);
	   painter.setFont(digitFont());
	   for (int i=0;i<9;i++)
	   {
	     	QString val = QString("%1").arg(m_min + i*(m_max - m_min)/8 );
	     	QSize Size = painter.fontMetrics().size(Qt::TextSingleLine, val);
             	painter.save();
		painter.translate( digitOffset() * cos((5+i)*PI/6.0), digitOffset() * sin((5+i)*PI/6.0));
		painter.drawText( Size.width()/ -2, Size.height() / 4, val);
		painter.restore();
	   }
	painter.restore();
        // --------------------------------------------- ///
	static const int hand[12] = {-4, 0, -1, 129, 1, 129, 4, 0, 8,-50, -8,-50};

        // Rysowanie wskazówki
	painter.save() ;
	Brush.setColor(Qt::red);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Brush);
   	painter.rotate( (value() * 240.0) / (m_max - m_min) );
	painter.drawConvexPolygon(QPolygon(6,hand));
	painter.drawEllipse(-10,-10,20,20);
	painter.restore();


	painter.restore(); // Przywrocenie do wychylenia o 60 stopni

	// Rysowanie wy¶wietlanej warto¶ci
	painter.setFont(valueFont());
        QString Str = prefix() + QString("%1").arg(value()) + suffix();
        QSize Size = painter.fontMetrics().size(Qt::TextSingleLine, Str);
        painter.drawText( Size.width() / -2,static_cast<int>( 0 - valueOffset()) , Str);


}
