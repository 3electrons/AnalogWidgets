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
   if (chart->isPaintOver() && chart->antialiasing())  painter.setRenderHint(QPainter::Antialiasing); // w³aczenie antialiasingu

   Channels & channels = chart->channels();
   Channels::iterator i=channels.end();

   while (i--!=channels.begin())
   {
     if (i->visible())
     {
       painter.save();
       painter.setPen(i->pen());
       translateToChannel(painter,chart,*i);
       paintChannel(painter,chart,*i);
       painter.restore();
     }
   } // while

   painter.setRenderHint(QPainter::RenderHint(rh)); // wylaczenie antialiasingu
    
 }// if not doRepaintBackground
  painter.restore(); // odwraca zmiany jakie by³y wprowadzone przez porzedni dekorator 
  ChartDecorator::paint(painter,chart); // uruchomienie nastêpnego dekoratora
}


void ChannelDecorator::absPosition(QPoint & curPos, QPolygonF & absPoints, Chart * chart,QRect & clip)
{
   double xmin,ymin,xmax,ymax,pos;
   pos  = chart->scaleGrid().pos ;
   xmin = chart->scaleGrid().m_min;
   xmax = chart->scaleGrid().m_max;
   
   xfactor = (viewport.width())/(xmax - xmin );
   dx = -pos * xfactor;
   
   double current_x = curPos.x(); 
   double current_y = curPos.y(); 
   double abs_x =  (current_x - dx)/xfactor ;  
   double abs_y = 0; 
   
    Channels & channels = chart->channels();
    Channels::iterator i=channels.begin();
  // qDebug("Okno (%d,%d)",window.width()-window.x(),window.height()); 
  // qDebug("View (%d,%d)",viewport.width(),viewport.height()); 
   
   while (i!=channels.end())
   {
     i++->getCalcMinMax(ymin,ymax); 
     yfactor = (-viewport.height())/(ymax - ymin);
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

   viewport = painter.viewport(); // do odczytów 
   window = painter.window(); //  to samo co QRect(0,0,viewport.width()+viewport.x(),viewport.height()+viewport.y()); 
    
   xfactor = window.width()/(xmax - xmin );
   yfactor = -window.height()/(ymax - ymin);
   dx = -pos * xfactor; 
   dy = ymax * -yfactor;
   dxw = window.width();  
}


bool anyVector (double x1,double x2) 
{
  double x = x2-x1; 
  if (x<0) x = -x; 
   return x>1.0; 
}


void ChannelDecorator::paintChannel(QPainter & painter, Chart * chart, Channel & channel)
{
  double x,y;  
  double current_x = 0 ,old_x=-1.0,current_y,old_y=-1.0;
  bool init = false,add = false;
  ChannelData * data = channel.data() ;
  
  if (data)
   if (data->init())
      {
        //QPolygon lineA
        const int size = 100; 
        QPoint line[size+2]; 
        //line.resize(data->size());
        unsigned int i =0; 
        while( data->next(x,y) )
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
             line[i++]=(QPoint(current_x,current_y)); 
             if (i > size ) 
             {
               painter.drawPolyline(line,size);
	       line[0] = line[size-1]; // Last point is first one 
               i=1; 
             }
	      old_x = current_x; 
	      old_y = current_y; 
	     // qDebug("(%d,%d)",(int)current_x,(int)current_y);
	   }

           init = true;
           add = false;

        }// while channel.data()->next ... 
       //  painter.setMatrixEnabled(false); 
       // painter.setViewTransformEnabled ( false ); 
        painter.drawPolyline(line,i);
      //  painter.setViewTransformEnabled ( true ); 
      //  painter.setMatrixEnabled(true); 
        //cout<<"Paint lines"<<line.size()<<" Channel:"<<qPrintable(channel.name())<<endl; 
      }
      else
     cout<<"Channel:"<<qPrintable(channel.name())<<" has no data"<<endl;

  //painter.setRenderHint(QPainter::RenderHint(0x0));
}
