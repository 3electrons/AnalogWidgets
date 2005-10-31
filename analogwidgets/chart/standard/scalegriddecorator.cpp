/************************************************************************
  			scalesgriddecorator.cpp - Copyright coder
**************************************************************************/
#include <QtGui>
// #include <iostream>
#include "scalegriddecorator.h"
#include "chart.h"
#include "functions.h"

using namespace std;
using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
ScalesGridDecorator::ScalesGridDecorator (ChartDecorator * component )
  :ChartDecorator(component)
{
  scaleSize = 0.0;
  m_max = 0.0;
  m_min = 0.0;
  yScaleWidth = 0.0;
  yScaleHeight = 0.0;
}

void ScalesGridDecorator::paint (QPainter & painter, Chart * chart)
{



  if (chart->doRepaintBackground())
  {  // to jest malowane na bitmapce w tle
     paintBackground(painter,chart);
     paintXScale(painter,chart);
     paintXGrid(painter,chart);
  }
  else
  {  // a to ju¿ na samym ekranie
     paintYScale(painter,chart);
     paintYGrid(painter,chart);

     painter.setClipRect(yScaleWidth,0,chart->width()-yScaleWidth,yScaleHeight+1);
     painter.setViewport(yScaleWidth,0,chart->width()-yScaleWidth,yScaleHeight);
     //   painter.setWindow(yScaleWidth,0,chart->width()-yScaleWidth,yScaleHeight);
     //painter.setWindow(yScaleWidth,0,chart->width()-yScaleWidth,yScaleHeight);
  }

  ChartDecorator::paint(painter,chart);
}

void ScalesGridDecorator::paintBackground(QPainter &painter, Chart * chart)
{

  QLinearGradient background(0,0,0,chart->height());
  background.setColorAt(0.0,QColor(0,0,150));
  background.setColorAt(1.0,Qt::black);
  painter.setBrush(QBrush(background));
  //painter.setBrush(Qt::black);
  painter.drawRect(0,0,chart->width(),chart->height());


}

#define XFONT_DISTANCE 7
#define YFONT_DISTANCE 2.5
void ScalesGridDecorator::paintXScale(QPainter & painter, Chart * chart)
{
  painter.setFont(chart->scaleGrid().m_font);

  // wysoko¶æ skali X
   if (chart->scaleGrid().showScale)
   xScaleHeight = painter.fontMetrics().height()*2;
   else xScaleHeight = 0.0;
  // wysoko¶æ skali Y

   yScaleHeight = chart->height() - xScaleHeight;
  // szeroko¶æ skali Y

  int yMesh = chart->scaleGrid().m_yMesh;  // ilo¶æ lini na skali
  if (chart->scaleGrid().showScale)
   yScaleWidth=XFONT_DISTANCE;
  else yScaleWidth=0.0;

   Channels & channels = chart->channels();
  Channels::iterator i=channels.end();

  // Rysowanie opisu skali X

  while (i--!=channels.begin())
  {

   int maxTextWidth=0; // maksymalna szeroko¶æ napisu skali
   if (i->showScale)
   {
     painter.setPen(i->m_pen);
     double m_min,m_max;
     range(i->min,i->max,m_min,m_max,yMesh,true,5.0);  // wyznaczenie ca³ej rangi ...

     double scaleStep = (m_max-m_min)/ yMesh;
      i->m_min = m_min; i->m_max = m_max+scaleStep; //  ustawianie wymiarów dla kana³ów
     double scalePos=m_max;
     double posStep = yScaleHeight /( yMesh+1), posText=posStep;
     // malowanie literek skali
     while (scalePos >= m_min)
     {
      QString Str = QString("%1").arg(scalePos);
      int tw = painter.fontMetrics().size(Qt::TextSingleLine, Str ).width();
      if (tw>maxTextWidth) maxTextWidth=tw;
      painter.drawText(QPointF(yScaleWidth,posText-YFONT_DISTANCE),Str);
      posText+=posStep;
      scalePos-=scaleStep;
     }
     yScaleWidth+=XFONT_DISTANCE+maxTextWidth;
   }// if showScale

  }// while i!=channels.end()

}


void ScalesGridDecorator::paintYScale(QPainter & painter, Chart * chart)
{
   int xMesh = chart->scaleGrid().m_xMesh;
   double pos = chart->scaleGrid().pos;
   double minimal_step = 1;
   if (scaleSize != chart->scaleGrid().size)
   {
     scaleSize = chart->scaleGrid().size;
     range(0.0,scaleSize,m_min,m_max,xMesh,true,minimal_step);
     // Absolutna pozycja ...
//     chart->scaleGrid().m_min = m_min + pos;
//     chart->scaleGrid().m_max = m_max + pos;
   }


     double scale_step = (m_max - m_min) / (xMesh);

     double factor = (chart->width() - yScaleWidth )/ scaleSize;
     double start_pos = - fmod(pos,scale_step); // by rozpocz±³ od pocz±tku
     double scale_pos = start_pos * factor;

     painter.setFont(chart->scaleGrid().m_font);
     painter.setPen(chart->scaleGrid().m_fontColor); //kolor fontu

     double scale_value_step = ( m_max - m_min ) / xMesh;
     double scale_value=pos - fmod(pos,scale_value_step);
     //cout<<"Pos:"<<pos <<" fmod:"<<fmod(pos,scale_value_step);
     //cout<<" scale_number:"<<scale_value<<" scale_number_step:"<<scale_value_step<<endl;
     chart->scaleGrid().m_min = m_min + pos;
     chart->scaleGrid().m_max = pos + scaleSize;

    if (chart->scaleGrid().showScale)
   {
    int x,y,fw;
    do
    {
      y = (chart->height()- static_cast<int>(yScaleHeight));
      //  painter.drawLine(QPointF(scale_pos,yScaleHeight + y*0.25 ),QPointF(scale_pos,yScaleHeight));

      QString Str = QString("%1").arg(scale_value);
      fw = painter.fontMetrics().size(Qt::TextSingleLine, Str ).width();
      x = static_cast<int> (scale_pos - fw/2 + yScaleWidth);
      if (x + fw/2 >= yScaleWidth )
      painter.drawText(QPointF(x ,yScaleHeight+y*0.6+YFONT_DISTANCE),Str);
      scale_pos+=scale_step * factor;
      scale_value+=scale_value_step;

      start_pos += scale_step;
    }while (x <= chart->width() ) ;
   } // if showScale

}

void ScalesGridDecorator::paintYGrid(QPainter & painter, Chart * chart)
{

  if (chart->scaleGrid().showScale)
  {
     int xMesh = chart->scaleGrid().m_xMesh;
     double pos = chart->scaleGrid().pos;

     // scaleSize = chart->scaleGrid().size; - jako zmienna klasy
     //range(0.0,scaleSize,m_min,m_max,xMesh,true,minimal_step);
     double scale_step = (m_max - m_min) / (xMesh);

     double factor = (chart->width() - yScaleWidth )/ scaleSize;
     double start_pos = - fmod(pos,scale_step);
     double scale_pos = yScaleWidth + start_pos * factor;
     painter.setPen(QColor(40,40,180)); // kolor siatki

     int xSubMesh = chart->scaleGrid().m_xSubMesh +1;
     int y;
     do
     {
      //painter.drawLine(QPointF(scale_pos,0),QPointF(scale_pos,yScaleHeight));

      y = (chart->height()- static_cast<int>(yScaleHeight) );
      if (scale_pos>=yScaleWidth)
      painter.drawLine(QPointF(scale_pos,yScaleHeight + y*0.25 ),QPointF(scale_pos,0));
      for (int i=-xSubMesh;i<xSubMesh;i++)
      {
        double scale_sub_step = scale_step / xSubMesh;
        double xSub = scale_pos+scale_sub_step*i*factor;
        if (xSub>yScaleWidth) painter.drawLine(QPointF(xSub,0),QPointF(xSub,yScaleHeight));
      }

      scale_pos+=scale_step * factor;
     }while (scale_pos <= chart->width() ) ;
  } // if showGrid
}

void ScalesGridDecorator::paintXGrid(QPainter & painter, Chart * chart)
{
  painter.setPen(QColor(40,40,180));

  // Malowanie lini poziomych
  unsigned int ySteps    = chart->scaleGrid().m_yMesh + 1;
  unsigned int ySubSteps = 1;
  double       length    = yScaleWidth;

  if ( chart->scaleGrid().showGrid & ySubSteps)
   {
      length = chart->width();
      ySubSteps = chart->scaleGrid().m_ySubMesh + 1;
   }

 double step   = yScaleHeight/(ySteps*ySubSteps);
 double pos = 0.0;

  for (unsigned int i=0;i<=ySteps*ySubSteps;i++)
  {
    if (i%ySubSteps)  // je¿eli s± ustawione
        painter.drawLine(QPointF(yScaleWidth,pos),QPointF(length,pos));
    else
        painter.drawLine(QPointF(0.0,pos),QPointF(length,pos));
    pos+=step;
  }
  painter.drawLine(QPointF(yScaleWidth,0.0),QPointF(yScaleWidth,yScaleHeight));

}

