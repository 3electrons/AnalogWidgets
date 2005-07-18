#include <QtGui>
#include <math.h>
#include "barmeter.h"
#define PI 3.141592653589793238512808959406186204433

void max_min(int & min, int & max)
{
 

} 

BarMeter::BarMeter(QWidget *parent)
        : QWidget(parent)
{
         setWindowTitle(tr("Analog BarMeter"));
        resize(300, 300);
	m_maximum = 300;
  	m_minimum = 0;
   	m_value   = 0;
	m_valueOffset=-100;
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
        static const int hand[10] = {-4, 0, 0, 129, 4, 0, 8,-50, -8,-50};

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
	Pen.setWidth(2);
	painter.setPen(Pen);
	painter.drawEllipse(-142,-142,284,284);

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

		Pen.setWidth(2);
		line_length=5;
 		if (i % 2) { line_length=10; }
	}
	painter.restore();


        // Rysowanie wskazówki
	painter.save() ;
	Brush.setColor(Qt::red);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Brush);
   	painter.rotate( (value() * 240.0) / (maximum() - minimum()) );
	painter.drawConvexPolygon(QPolygon(5,hand));
	painter.drawEllipse(-10,-10,20,20);
	painter.restore();

	painter.restore(); // Przywrocenie do wychylenia o 60 stopni

	// Rysowanie wy¶wietlanej warto¶ci
	painter.setFont(valueFont());
        QString Str = prefix() + QString("%1").arg(value()) + suffix();
        QSize Size = painter.fontMetrics().size(Qt::TextSingleLine, Str);
        painter.drawText( Size.width() / -2,static_cast<int>( 0 - valueOffset()) , Str);
	

	// Rysowanie skali. 
	

}
