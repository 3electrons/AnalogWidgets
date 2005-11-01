#include <QtGui>
#include <cmath>
#include <iostream>

#include "chart.h"
#include "standard/scalegriddecorator.h"
#include "standard/glassdecorator.h"
#include "standard/channeldecorator.h"
#include "standard/legenddecorator.h"


using namespace std;

//
//      public
//
Chart::Chart(QWidget *parent)
	: QMyWidgetWithBackground(parent)
{
  // QWidget
   setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
   setWindowTitle(tr("Chart diagram"));
   m_channel=0;
   timer = new QTimer(this);
   timer->setInterval(1000);
   m_isPaintOver = true;
   connect(timer,SIGNAL(timeout()),this,SLOT(setPaintOver()));
   InitDecorators();
}

Chart::~Chart()
{
  if (timer) delete timer;
  timer = NULL;
}
void Chart::addChannel(Channel & channel)
{
  m_channels.push_back(channel);
  updateWithBackground();
}


//
//      private
//

void Chart::InitDecorators()
{
	m_painterDecorator.reset
	(
           new Standard::ScalesGridDecorator
          (
            new Standard::ChannelDecorator
		( new Standard::LegendDecorator(NULL) ) // new Standard::GlassDecorator(NULL)
          )
        );

}

void Chart::setPaintOver()
	{
          m_isPaintOver = true;
          timer->stop();
	  //cout<<"Uaktualniam"<<endl;
          update();
          // By malowalo normalnie wygladzone no chyba ze malujemy z duza czestoliwoscia ...
          m_isPaintOver = true; // kiedy ma byc malowane w antialiasingu jak czesto sie da ...
	}
void Chart::paintEvent(QPaintEvent * /*event */)
{
   drawBackground();
   QPainter painter(this);
   initCoordinateSystem(painter);
   if (m_painterDecorator.get()) m_painterDecorator->paint(painter,this);
   if (!m_isPaintOver) timer->start();
   m_isPaintOver = false;

}

void Chart::paintBackground(QPainter & painter)
{
   initCoordinateSystem(painter);
   if (m_painterDecorator.get()) m_painterDecorator->paint(painter,this);
}

void Chart::initCoordinateSystem(QPainter & /*painter*/)
{
   	;
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
	update();
}

//
//  	public slots
//
void Chart::setPosition(double i)
{
	m_scalegrid.pos=i;
        update();
}

void Chart::zoom(double factor)
{
  if (fabs(factor)>0.001)
  {
    m_scalegrid.size *= factor;
    update();
  }
}

