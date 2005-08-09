#include <QtGui>
#include <cmath>
#include <assert.h>
#include "thermometer.h"

using namespace std;
ThermoMeter::ThermoMeter(QWidget *parent)
        : QMyAbstractMeter(parent)
{
        m_max=100;
        m_min=0;

	m_maximum=100; // najpierw r�cznie potem seterem by wywo�a� calcMaxMin
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
	// kszta�t szkalnej ba�ki

	QPainterPath glass;

	// pocz�tek �uku dolnego po lewej stronie
	glass.moveTo(12.5,267.5);
	glass.quadTo(12.5,263.0, 7.5,259.0);

	glass.lineTo(7.5,25.0);

	// �uk g�rny zamykajac5y ba�k� od g�ry.
	glass.quadTo(7.5,12.5 , 0,12.5);
	glass.quadTo(-7.5,12.5,-7.5,25.0);
	glass.lineTo(-7.5,259.0);
	// tutaj musi by� �uk dolny o promineniu 25
	glass.quadTo(-12.5,263.0, -12.5,267.5);
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

// Offset by lepiej by�o wida� o co z nim biega - m�wi�c ogl�dnie offset to miejsce
// poni�ej zera od kt�rego zaczynamy rysowa� s�upek rt�ci.
#define OFFSET 10

void ThermoMeter::paintEvent(QPaintEvent * )
{
      // Inicjalizacja paintera
	QPainter painter(this);
        initCoordinateSystem(painter);
      // --------------------------------------------- ///
       // Dob�r color�w do rysowania
	QColor color=Qt::blue;
	if (m_value >= m_nominal )
	    color=Qt::green;

	if (m_value >= m_critical)
	   {
		color=Qt::red;
	     	painter.setPen(color); // by potem temp poda� na czerwono
	   }

	QLinearGradient slupek(0.0,0.0,5.0,0.0);
	QRadialGradient zbiornik(0.0,0.0, 5.0,5.0);

	slupek.setSpread(QGradient::ReflectSpread);

	color.setHsv(color.hue(),color.saturation(),color.value());
	slupek.setColorAt(1.0,color);
	zbiornik.setColorAt(1.0,color);

	color.setHsv(color.hue(),color.saturation()-200,color.value());
	slupek.setColorAt(0.0,color);
	zbiornik.setColorAt(0.0,color);

        // Wyznaczenie wysoko�ci s�upka;
	double factor =  m_value - m_min;
	       factor /= m_max - m_min;
	int temp = static_cast<int> (224.0 *  factor), height = temp + OFFSET;
	if (231 < temp  ) height = 231 + OFFSET; // by rt�� dosz�a do ko�ca terometra ale go nie rozwali�a
	if (OFFSET-5 >= height )  height = OFFSET-5; // by nie zeszlo poni�ej pieciu "pixeli" poni�ej zera
	// Narysowanie s�upka  wraz z zbiorniczkiem rt�ci
        painter.setPen(Qt::NoPen);
	painter.setBrush(slupek);
        painter.drawRect(-5,252+OFFSET - height ,10, height);
	painter.setBrush(zbiornik);
	painter.drawEllipse(-10,258,20,20);

	// Na�o�enie szklanej ba�ki
	doUpdateBackground();

}// paintEvent
#undef OFFSET
