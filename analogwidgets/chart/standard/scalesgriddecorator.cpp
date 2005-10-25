/************************************************************************
  			scalesgriddecorator.cpp - Copyright coder
**************************************************************************/
#include <QtGui>
#include "scalesgriddecorator.h"
#include "chart.h"
#include "functions.h"


using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */

void ScalesGridDecorator::paint (QPainter & painter, Chart * chart)
{
  paintBackground(painter,chart);

  paintXScale(painter,chart);

  paintYScale(painter,chart);
  paintXGrid(painter,chart);
  paintYGrid(painter,chart);


  ChartDecorator::paint(painter,chart);
}

void ScalesGridDecorator::paintBackground(QPainter &painter, Chart * chart)
{
  QLinearGradient background(0,0,0,chart->height());
  background.setColorAt(0.0,QColor(0,0,150));
  background.setColorAt(1.0,Qt::black);
  painter.setBrush(QBrush(background));
  painter.drawRect(0,0,chart->width(),chart->height());


}

#define XFONT_DISTANCE 7
#define YFONT_DISTANCE 2.5
void ScalesGridDecorator::paintXScale(QPainter & painter, Chart * chart)
{
  painter.setFont(chart->scaleGrid().m_font);

  // wysoko뜻 skali X
   xScaleHeight = painter.fontMetrics().height()*2;

  // wysoko뜻 skali Y
   yScaleHeight = chart->height() - xScaleHeight;
  // szeroko뜻 skali Y

  int yMesh = chart->scaleGrid().m_yMesh;  // ilo뜻 lini na skali

  yScaleWidth=XFONT_DISTANCE;
   Channels & channels = chart->channels();
  Channels::iterator i=channels.end();

  // Rysowanie opisu skali X

  while (i--!=channels.begin())
  {

   int maxTextWidth=0; // maksymalna szeroko뜻 napisu skali
   if (i->showScale)
   {
     painter.setPen(i->m_pen);
     range(i->min,i->max,i->m_min,i->m_max,yMesh);  // wyznaczenie ca쿮j rangi ...
     double scaleStep = (i->m_max-i->m_min)/ yMesh;
     double scalePos=i->m_max;
     double posStep = yScaleHeight /( yMesh+1), posText=posStep;
     // malowanie literek skali
     while (scalePos >= i->m_min)
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
   double m_min,m_max,min = chart->scaleGrid().min,max = chart->scaleGrid().max;
   double minimal_step = 0.5;
   range(min,max,m_min,m_max,xMesh,true,minimal_step);
   double scale_step = (m_max - m_min) / (xMesh +1 );
   double start_pos = m_min + scale_step - min;
   double factor = (chart->width() - yScaleWidth )/ (max - min );
   double scale_pos = yScaleWidth + start_pos * factor;


 painter.setFont(chart->scaleGrid().m_font);
 painter.setPen(chart->channels()[0].m_pen); // kolor siatki

 double scale_number_step = ( m_max - m_min ) / xMesh;
 double scale_number= m_min + scale_number_step;

   do
   {
    int y = (chart->height()- yScaleHeight);
  //  painter.drawLine(QPointF(scale_pos,yScaleHeight + y*0.25 ),QPointF(scale_pos,yScaleHeight));

    QString Str = QString("%1").arg(scale_number);
    int tw = painter.fontMetrics().size(Qt::TextSingleLine, Str ).width();
    painter.drawText(QPointF(scale_pos - tw/2 ,yScaleHeight+y*0.6+YFONT_DISTANCE),Str);

    scale_pos+=scale_step * factor;
    scale_number+=scale_number_step;


    start_pos += scale_step;
   }while (scale_pos < chart->width() ) ;

}

void ScalesGridDecorator::paintYGrid(QPainter & painter, Chart * chart)
{
   int xMesh = chart->scaleGrid().m_xMesh;
   double m_min,m_max,min = chart->scaleGrid().min,max = chart->scaleGrid().max;
   double minimal_step = 1.0;
   range(min,max,m_min,m_max,xMesh,true,minimal_step);
   double scale_step = (m_max - m_min) / (xMesh +1 );
   double start_pos = m_min + scale_step - min;
   double factor = (chart->width() - yScaleWidth )/ (max - min );
   double scale_pos = yScaleWidth + start_pos * factor;
   painter.setPen(QColor(40,40,180)); // kolor siatki

   int xSubMesh = chart->scaleGrid().m_xSubMesh +1;
   do
   {
    painter.drawLine(QPointF(scale_pos,0),QPointF(scale_pos,yScaleHeight));

    int y = (chart->height()- yScaleHeight);
    painter.drawLine(QPointF(scale_pos,yScaleHeight + y*0.25 ),QPointF(scale_pos,yScaleHeight));
    for (int i=-xSubMesh;i<xSubMesh;i++)
    {
       double scale_sub_step = scale_step / xSubMesh;
       double x = scale_pos+scale_sub_step*i*factor;
       if (x>yScaleWidth) painter.drawLine(QPointF(x,0),QPointF(x,yScaleHeight));
    }

    scale_pos+=scale_step * factor;
   }while (scale_pos <= chart->width() ) ;


}

void ScalesGridDecorator::paintXGrid(QPainter & painter, Chart * chart)
{
  painter.setPen(QColor(40,40,180));

  // Malowanie lini poziomych
  unsigned int ySteps    = chart->scaleGrid().m_yMesh + 1;
  unsigned int ySubSteps = 1;
  double       length    = yScaleWidth;

  if ( chart->scaleGrid().m_showGrid & ySubSteps)
   {
      length = chart->width();
      ySubSteps = chart->scaleGrid().m_ySubMesh + 1;
   }

 double step   = yScaleHeight/(ySteps*ySubSteps);
 double pos = 0.0;

  for (unsigned int i=0;i<=ySteps*ySubSteps;i++)
  {
    if (i%ySubSteps)  // je풽li s� ustawione
        painter.drawLine(QPointF(yScaleWidth,pos),QPointF(length,pos));
    else
        painter.drawLine(QPointF(0.0,pos),QPointF(length,pos));
    pos+=step;
  }
  painter.drawLine(QPointF(yScaleWidth,0.0),QPointF(yScaleWidth,yScaleHeight));

}

