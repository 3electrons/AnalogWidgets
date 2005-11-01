/************************************************************************
  			channeldecorator.cpp - Copyright coder
**************************************************************************/

#include <QtGui>
#include "chart.h"
#include "channeldecorator.h"
#include <cmath>
#include <iostream>

using namespace std;

using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */


void ChannelDecorator::paint (QPainter & painter, Chart * chart)
{
 if (!chart->doRepaintBackground())
 {
   unsigned int rh = painter.renderHints();
   if (chart->isPaintOver())  painter.setRenderHint(QPainter::Antialiasing); // w�aczenie antialiasingu

   Channels & channels = chart->channels();
   Channels::iterator i=channels.end();

   while (i--!=channels.begin())
   {
     painter.save();
     painter.setPen(i->m_pen);
     translateToChannel(painter,chart,*i);
     paintChannel(painter,chart,*i);
     painter.restore();
   } // while

   painter.setRenderHint(QPainter::RenderHint(rh)); // wylaczenie antialiasingu
 }// if not doRepaintBackground
  ChartDecorator::paint(painter,chart); // uruchomienie nast�pnego dekoratora
}

void ChannelDecorator::translateToChannel (QPainter & painter, Chart * chart, Channel & channel)
{
   double xmin,ymin,xmax,ymax,pos;
   pos  = chart->scaleGrid().pos ;
   xmin = chart->scaleGrid().m_min;
   xmax = chart->scaleGrid().m_max;
   ymin = channel.m_min;
   ymax = channel.m_max;

   QRect window = painter.window();
   xfactor = window.width()/(xmax - xmin );
   yfactor = -window.height()/(ymax - ymin);
   dx = -pos * xfactor;
   dy = ymax * -yfactor;


  // painter.scale( window.width()/(xmax - xmin) ,  -window.height()/(ymax-ymin) );
  // painter.translate(-pos,-ymax);
 //  painter.scale( xfactor,  yfactor );
  // painter.translate(dx,dy);

}

void ChannelDecorator::paintChannel(QPainter & painter, Chart * chart, Channel & channel)
{
  double x,y;

//  double i=chart->scaleGrid().m_min; +  chart->scaleGrid().pos;
  double j=chart->scaleGrid().m_max  + chart->scaleGrid().pos;
  if (channel.m_data)
   if (channel.m_data->init())
      {
        QPolygonF line;
        while( channel.m_data->next(x,y) && x <= j  )
          line.append(QPointF(x*xfactor+dx,y*yfactor+dy));
	  // @TODO - tak by nie dodawal danych sprzed okienka podgl�du
        painter.drawPolyline(line);
      }
    else
     cout<<"Channel:"<<channel.m_name.toLocal8Bit().constData()<<" has no data"<<endl;

  //painter.setRenderHint(QPainter::RenderHint(0x0));
}
