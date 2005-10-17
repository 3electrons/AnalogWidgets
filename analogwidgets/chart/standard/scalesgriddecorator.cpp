/************************************************************************
  			scalesgriddecorator.cpp - Copyright coder
**************************************************************************/
#include <QtGui>

#include "scalesgriddecorator.h"
#include "chart.h"

using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */

void ScalesGridDecorator::paint (QPainter & painter, Chart * chart)
{

  QLinearGradient background(0,0,0,chart->height());
  background.setColorAt(0.0,QColor(0,0,150));
  background.setColorAt(1.0,Qt::black);
  painter.setBrush(QBrush(background));
  painter.drawRect(0,0,chart->width(),chart->height());


  ChartDecorator::paint(painter,chart);
}

  void paintBackground(QPainter &painter, Chart * chart);
  void paintXScale(QPainter & painter, Chart * chart);
  void paintYScale(QPainter & painter, Chart * chart);
  void paintGrid  (QPainter & painter, Chart * chart);

