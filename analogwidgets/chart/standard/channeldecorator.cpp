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
  double x,y;
  bool init = false;
  QPainterPath path; 
  for (double i=0;i<=2002;i+=1)
  {
    x=i;
    y=sin(x/100) * 100 +65 ;
    if (init)
    {
     //cout<<"X:"<<x<<" Y:"<<y<<endl;
     //painter.drawLine(QPointF(x,y),QPointF(oldX,oldY));
     path.lineTo(x,y); 
    // painter.translate(0,1);
    }
    else
    {
       path.moveTo(x,y); 
       init = true;
    }
  }// for
  //painter.setRenderHint(QPainter::Antialiasing); 
    painter.drawPath(path);   
  //painter.setRenderHint(QPainter::RenderHint(0x0)); 
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
    paintChannel(painter,chart,*i); 
    //paintSin(painter);
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

void ChannelDecorator::paintChannel(QPainter & painter, Chart * chart, Channel & channel)
{
  double x,y;
  
  double i=chart->scaleGrid().m_min; +  chart->scaleGrid().pos; 
  double j=chart->scaleGrid().m_max  + chart->scaleGrid().pos; 
  bool init = false;
  QPainterPath path; 
  for (;i<=j;i+=1)
  {
    x=i;
    y=sin(x/100) * 100 +165 ;
    if (init) path.lineTo(x,y); 
    else
    {
       path.moveTo(x,y); 
       init = true;
    }
  }// for
  //painter.setRenderHint(QPainter::Antialiasing); 
    painter.drawPath(path);   
  //painter.setRenderHint(QPainter::RenderHint(0x0)); 	
}
