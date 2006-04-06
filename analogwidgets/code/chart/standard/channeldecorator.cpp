/************************************************************************
  			channeldecorator.cpp - Copyright coder
**************************************************************************/

#include <QtGui>
#include <QPainterPath>
#include "chart.h"
#include "chart/standard/channeldecorator.h"
#include <cmath>
#include <iostream> 

using namespace std;

using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */


void ChannelDecorator::paint (QPainter & painter, Chart * chart)
{
 if (!chart->doRepaintBackground())
 {
   //painter.save(); 
   unsigned int rh = painter.renderHints();
   if (chart->isPaintOver())  painter.setRenderHint(QPainter::Antialiasing); // w�aczenie antialiasingu

   Channels & channels = chart->channels();
   Channels::iterator i=channels.end();

   while (i--!=channels.begin())
   {
     painter.save();
     painter.setPen(i->pen());
     translateToChannel(painter,chart,*i);
     paintChannel(painter,chart,*i);
     painter.restore();
   } // while

   painter.setRenderHint(QPainter::RenderHint(rh)); // wylaczenie antialiasingu
    
 }// if not doRepaintBackground
  painter.restore(); // odwraca zmiany jakie by�y wprowadzone przez porzedni dekorator 
  ChartDecorator::paint(painter,chart); // uruchomienie nast�pnego dekoratora
}


void ChannelDecorator::absPosition(QPoint & curPos, QPolygonF & absPoints, Chart * chart,QRect & clip)
{
   double xmin,ymin,xmax,ymax,pos;
 //  pos  = chart->scaleGrid().pos ;
 //  xmin = chart->scaleGrid().m_min;
  // xmax = chart->scaleGrid().m_max;
   
  // xfactor = window.width()/(xmax - xmin );
  // dx = -pos * xfactor;
   
   double current_x = curPos.x(); 
   double current_y = curPos.y(); 
   double abs_x =  (current_x - dx )/(xfactor);  
   double abs_y = 0; 
   
    Channels & channels = chart->channels();
   Channels::iterator i=channels.begin();

   while (i!=channels.end())
   {
     i++->getCalcMinMax(ymin,ymax); 
     yfactor = -window.height()/(ymax - ymin);
     dy = ymax * -yfactor;
     abs_y =  (current_y - dy )/(yfactor); 
     absPoints.push_back(QPointF(abs_x,abs_y));
    }  
}


void ChannelDecorator::translateToChannel (QPainter & painter, Chart * chart, Channel & channel)
{
   double xmin,ymin,xmax,ymax,pos;
   pos  = chart->scaleGrid().pos ;
   xmin = chart->scaleGrid().m_min;
   xmax = chart->scaleGrid().m_max;
   channel.getCalcMinMax(ymin,ymax); 
   window = painter.window(); 
   xfactor = window.width()/(xmax - xmin );
   yfactor = -window.height()/(ymax - ymin);
   dx = -pos * xfactor;
   dy = ymax * -yfactor;
   dxw = window.width();  

  // painter.scale( window.width()/(xmax - xmin) ,  -window.height()/(ymax-ymin) );
  // painter.translate(-pos,-ymax);
 //  painter.scale( xfactor,  yfactor );
  // painter.translate(dx,dy);

}

bool anyVector (double x1,double x2) 
{
  return fabs(x1-x2)>1.0; 
}





void ChannelDecorator::paintChannel(QPainter & painter, Chart * chart, Channel & channel)
{
  double x,y;  
  double current_x = 0 ,old_x=-1.0,current_y,old_y=-1.0;
  bool init = false,add = false;
  
  
  if (channel.data())
   if (channel.data()->init())
      {
        QPolygonF line;
        while( channel.data()->next(x,y) )
        {
           current_x = x*xfactor+dx;
           current_y = y*yfactor+dy;
             
             
           bool xvector = anyVector(old_x,current_x); 
           bool yvector = anyVector(old_y,current_y); 
           bool vector = xvector||yvector; 
           bool oldInWindow = painter.window().contains(old_x,old_y); 
       	   bool newInWindow = painter.window().contains(current_x,current_y); 

           add =  (  ((oldInWindow || newInWindow)||(!oldInWindow && !newInWindow)) && (xvector || yvector) );
    
           if (!init || add )
           {
              line.append(QPointF(current_x,current_y)); 
	      old_x = current_x; 
	      old_y = current_y; 
	      qDebug("(%d,%d)",(int)current_x,(int)current_y);    
	   
	   }
	 
           init = true;
           add = false; 
           
        }// while channel.data()->next ... 
        {
         painter.drawPolyline(line);
         //cout<<"Paint lines"<<line.size()<<" Channel:"<<qPrintable(channel.name())<<endl; 
        }
      }
    else
     cout<<"Channel:"<<qPrintable(channel.name())<<" has no data"<<endl;
   
  //painter.setRenderHint(QPainter::RenderHint(0x0));
}
