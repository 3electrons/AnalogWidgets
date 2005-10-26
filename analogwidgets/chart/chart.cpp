#include <QtGui>
#include "chart.h"
#include "standard/scalesgriddecorator.h"
#include "standard/glassdecorator.h"


Chart::Chart(QWidget *parent)
	: QMyWidgetWithBackground(parent)
{
  // QWidget
   setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
   setWindowTitle(tr("Chart diagram"));
   m_channels.push_back(Channel());
     Channel t; 
     t.max=1000.0;    
     t.min=100.0; 
     t.m_pen.setColor(Qt::green); 
     m_channels.push_back(t);
   m_channel=0;

   InitDecorators();

}

void Chart::InitDecorators()
{
	m_painterDecorator.reset
	(
           new Standard::ScalesGridDecorator
          (
           NULL// new Standard::GlassDecorator(NULL)
          )
        );

}

void Chart::paintEvent(QPaintEvent * /*event */)
{
  drawBackground();
}

void Chart::paintBackground(QPainter & painter)
{
    initCoordinateSystem(painter);
 if (m_painterDecorator.get()) m_painterDecorator->paint(painter,this);
}

void Chart::initCoordinateSystem(QPainter & painter)
{
   	//painter.translate(0.0,0.0);
	//double ratio = height()/100.0;
	//painter.scale(ratio,ratio);
}

// 
//	 Setters and getters 
//
void Chart::setChannel(unsigned int i)
{ 
	m_channel = i;
        if (m_channel > m_channels.size())
        { 
          m_channels.push_back(Channel());
          updateWithBackground(); 
        }
}

void Chart::setSize(double i) 
{
      	m_scalegrid.size=i;
	updateWithBackground(); 
}

void Chart::setPosition(double i)
{ 
	m_scalegrid.pos=i; 
        updateWithBackground(); 
}

//
//  	Slots 
//
void Chart::zoom(double factor) 
{
  if (abs(factor)>0.001)
  {
    m_scalegrid.size *= factor; 
    updateWithBackground(); 
  }
}

