#include <QtGui>
#include <math.h>
#include <assert.h>
#include "thermometer.h"

ThermoMeter::ThermoMeter(QWidget *parent)
        : QMyAbstractMeter(parent)
{
        m_max=100;
        m_min=0;

	m_maximum=100; // najpierw rêcznie potem seterem by wywo³aæ calcMaxMin
  	setMinimum(0);
	setValue(0);
        setNominal(30);
	setCritical(60);
	setValueOffset(-100);
	setDigitOffset(105);
	setSuffix(QString(" [C]"));
	m_digitFont.setPointSize(20);
	m_valueFont.setPointSize(25);

	// QWidget
        setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
        setWindowTitle(tr("Analog Thermometer"));
	resize(200, 200);
	assert(m_max-m_min != 0);

}

void ThermoMeter::initCoordinateSystem(QPainter & painter)
{
        // inicjalizacja paintera
        painter.setRenderHint(QPainter::Antialiasing);
        //painter.translate(width() / 2, height() / 2);
        painter.translate( width()/2.0,0.0);
        painter.scale( height()/ 300.0, height()/300.0);
}

void ThermoMeter::paintBackground(QPainter & painter)
{
	initCoordinateSystem(painter);
	// kszta³t szkalnej bañki

	QPainterPath glass;

	// pocz±tek ³uku dolnego po lewej stronie
	glass.moveTo(12.5,267.5);
	glass.quadTo(12.5,264.0, 7.5,259.0);

	glass.lineTo(7.5,25.0);

	// ³uk górny zamykajac5y bañkê od góry.
	glass.quadTo(7.5,12.5 , 0,12.5);
	glass.quadTo(-7.5,12.5,-7.5,25.0);
	glass.lineTo(-7.5,259.0);
	// tutaj musi byæ ³uk dolny o promineniu 25
	glass.quadTo(-12.5,264.0, -12.5,267.5);
	glass.quadTo(-12.5,280.0,  0.0,280.0);
	glass.quadTo( 12.5,280.0,  12.5,267.5);

        QLinearGradient linearGrad(QPointF(-12.5, 0.0), QPointF(12.5, 0.0));
	//linearGrad.setSpread(QGradient::ReflectSpread);
        linearGrad.setColorAt(0, QColor(0,150,255,110));
        linearGrad.setColorAt(1, QColor(255,255,255,0));

	painter.setBrush(QBrush(linearGrad));
	painter.setPen(Qt::black);
	painter.drawPath(glass);

	int length = 12;
	for (int i=0;i<=32;i++)
	{
	  length = 12;
	 	 if (i%4) length = 8;
	  if (i%2) length = 5;
	  painter.drawLine(-7,28+i*7, -7+length,28+i*7);
	}

	painter.setPen(Qt::red);


}// paintBackground

void ThermoMeter::paintEvent(QPaintEvent * )
{

	QPainter painter(this);
        initCoordinateSystem(painter);
      // --------------------------------------------- ///
	QPen Pen;
	Pen.setWidth(9);
	Pen.setColor(Qt::blue);
	painter.setPen(Pen);
	double factor =  m_value - m_min;
	       factor /= m_max - m_min;
	int temp = static_cast<int> (238.0 * factor);
	painter.drawLine(0,266,0,266 -temp);
	doUpdateBackground();
	//painter.drawLine(0,0,300,300);
}// paintEvent
