#include <QtGui>
#include <math.h>
#include <assert.h>
#include "manometer.h"
#define PI 3.141592653589793238512808959406186204433

ManoMeter::ManoMeter(QWidget *parent)
        : QMyWidgetWithBackground(parent)
{
        m_max=300; 
        m_min=0;
	m_maximum=300; // najpierw rêcznie potem seterem by wywo³aæ calcMaxMin 
  	setMinimum(0);
	setValue(0);
        setNominal(80);
	setCritical(220);
	setValueOffset(-100);
	setDigitOffset(105);
	setSuffix(QString(" [bar]"));
	m_digitFont.setPointSize(20);
	m_valueFont.setPointSize(25);

	// QWidget
        setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
        setWindowTitle(tr("Analog Barmeter"));
	resize(311, 311);
	assert(m_max-m_min != 0); 
}

bool ManoMeter::calcMaxMin()
{
  
  int max_tmp = m_max, min_tmp = m_min; 
  m_max=m_maximum;
  m_min=m_minimum;

  assert( m_max > m_min );
  assert( m_max - m_min >! 0 );

  int diff = abs(m_max - m_min);
  int scale = 0,inc = 5 , factor = 0 ;
  bool done = false; 
  while ( diff > scale ) { factor+=inc; scale = 8 * factor; }
  while (!done)
  {
     m_max=0;  
     while ( m_max < m_maximum ) m_max +=factor; 
     m_min = m_max - scale;
     if (m_min <= m_minimum ) done = true; 
     else { factor+=inc; scale = 8*factor; } 
  }
 return (m_max != max_tmp) | (m_min != min_tmp);  
}


void ManoMeter::setValue( int val )
{
  if ( m_value != val )
  {
    m_value = val;
    update(); // Ciekawe czy tak jest lepiej ??
    emit valueChanged(val);
  }
}

void ManoMeter::setMinimum(int i)
{
  if ((m_minimum != i) && (i < m_maximum - 7 ) )
  {
    m_minimum = i;
    if (calcMaxMin()) updateWithBackground();
  }
}

void ManoMeter::setMaximum(int i)
{
  if ((m_maximum != i) && (i > m_minimum + 7) )
  {
    m_maximum = i;
    if (calcMaxMin()) updateWithBackground();
  }
}


void ManoMeter::initCoordinateSystem(QPainter & painter)
{
        int side = qMin(width(), height());
        // inicjalizacja paintera
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 311.0, side / 311.0);
}

void ManoMeter::paintBackground(QPainter & painter)
{
	static const int scaleTriangle[6] = { -6,141,6,141,0,129 };

	initCoordinateSystem(painter);

        // Malowanie obwiedni tarczy. Bia³a tarcza z czarn± skal±
        QPen Pen(QColor(0,0,0)); Pen.setWidth(1);
        painter.setPen(Pen);

	Pen.setWidth(4);
        painter.setBrush(QBrush(Qt::white));
        painter.drawEllipse(-154,-154,308,308);

	// wewnêtrzene ko³o skali

	painter.setPen(Pen);
	painter.drawEllipse(-142,-142,284,284);

	  painter.setPen(Qt::NoPen);
          // nominal
	  painter.setBrush(QBrush(Qt::green));
	  assert(m_max-m_min != 0); 
	  int angle = (3840 * ( m_nominal - m_min ))/(m_max-m_min);
	  if (m_min <= m_nominal && m_nominal < m_max ) 
           painter.drawPie(QRect(-141,-141,282,282),-480,3840 - angle % 5760 ); 
	  // Critical

	  painter.setBrush(QBrush(Qt::red));
	  angle = (3840 * ( m_critical - m_min ))/(m_max-m_min);
	  if ( m_min <= m_critical && m_critical < m_max  ) 
	  painter.drawPie(QRect(-141,-141,282,282),-480, 3840 - angle % 5760  ); //-480, 3840*( m_max-m_min - critical()-abs(m_min) )/static_cast<double>(m_max-m_min));
	  // bia³a obwiednia
	  painter.setBrush(QBrush(Qt::white));
	  painter.drawEllipse(-129,-129,258,258);

        // Ustawienie siê na pocz±tku skali

        painter.rotate(60.0);

 	// Rysowanie skali kreski
	painter.save();
        painter.setBrush(QBrush(Qt::black));
  	int line_length=10;
	for (int i=0;i<33;i++)
	{
	  painter.setPen(Pen);

          if (i % 4) painter.drawLine(0,140,0,140-line_length);
          else {
	    painter.setPen(Qt::NoPen);
	    painter.drawConvexPolygon(QPolygon(3, scaleTriangle));
	  }

	  painter.rotate(7.5);

	Pen.setWidth(3);

 	  if (i % 2)  line_length=10;
	  else        line_length=5;
	}
	painter.restore();

        // Rysowanie skali liczby .
	if (digitOffset())
        {
          painter.rotate(-60.0);
	  painter.setFont(digitFont());
	  for (int i=0;i<9;i++)
	  {
	    QString val = QString("%1").arg(m_min + i*(m_max - m_min)/8.0 );
	    QSize Size = painter.fontMetrics().size(Qt::TextSingleLine, val);
            painter.save();
	    painter.translate( digitOffset() * cos((5+i)*PI/6.0), digitOffset() * sin((5+i)*PI/6.0));
	    painter.drawText( Size.width()/ -2, Size.height() / 4, val);
	    painter.restore();
	  }
	}

}// paintBackground

void ManoMeter::paintEvent(QPaintEvent * )
{
	doUpdateBackground();
	QPainter painter(this);
        initCoordinateSystem(painter);
      // --------------------------------------------- ///
	static const int hand[12] = {-4, 0, -1, 129, 1, 129, 4, 0, 8,-50, -8,-50};

        // Rysowanie wskazówki
	painter.save();
	painter.rotate(60.0);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(Qt::red));
   	painter.rotate(  (  (abs(m_min)+value()) * 240.0) / static_cast<double> (m_max - m_min) );
	painter.drawConvexPolygon(QPolygon(6,hand));
	painter.drawEllipse(-10,-10,20,20);


        painter.restore();// Przywrocenie do wychylenia o 60 stopni

	// Rysowanie wy¶wietlanej warto¶ci
        if (valueOffset())
        {

	  if (value() >= critical() ) painter.setPen(Qt::red);
	  painter.setFont(valueFont());
          QString Str = prefix() + QString("%1").arg(value()) + suffix();
          QSize Size = painter.fontMetrics().size(Qt::TextSingleLine, Str);
          painter.drawText( Size.width() / -2,static_cast<int>( 0 - valueOffset()) , Str);
        }
}// paintEvent
