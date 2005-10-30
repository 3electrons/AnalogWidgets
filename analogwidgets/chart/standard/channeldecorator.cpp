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


void paintSin(QPainter & painter)
{
  double x,y,oldX,oldY;
  bool init = false;
  for (double i=0;i<=2002;i+=1)
  {

    x=i;
    y=sin(x/100) * 100 +65 ;

    if (init)
    {
     //cout<<"X:"<<x<<" Y:"<<y<<endl;
     painter.drawLine(QPointF(x,y),QPointF(oldX,oldY));
    // painter.translate(0,1);
    }
    else
    {

       init = true;
    }
    oldX=x;
    oldY=y;



  }// for




}

void ChannelDecorator::paint (QPainter & painter, Chart * chart)
{

 if (!chart->doRepaintBackground())
 {
   unsigned int rh = painter.renderHints();
   //painter.setRenderHint(QPainter::Antialiasing); //

   Channels & channels = chart->channels();
   Channels::iterator i=channels.end();

  // Rysowanie opisu skali X

  while (i--!=channels.begin())
  {
    painter.save();
    painter.setPen(i->m_pen);
    translateToChannel(painter,chart,*i);
    paintSin(painter);
    painter.restore();
  } // while

    painter.setRenderHint(QPainter::RenderHint(rh)); //
 }// if not doRepaintBackground
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
   //painter.scale(window.width()/(xmax - xmin) , window.height()/(ymax-ymin) );
  // QMatrix m(1.0,0.0,0.0,1.0,-pos,0);
   painter.scale( window.width()/(xmax - xmin) ,  -window.height()/(ymax-ymin) );
   painter.translate(-pos,-ymax);

   //cout<<"Translate(x,y):"<<-pos<<","<<ymax<<endl;

}
