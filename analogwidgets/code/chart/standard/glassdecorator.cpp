/************************************************************************
  			glassdecorator.cpp - Copyright coder
**************************************************************************/
#include <QtGui>
#include "chart/standard/glassdecorator.h"
#include "chart.h"

using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */

void GlassDecorator::paint (QPainter & painter, Chart * chart)
{
  QLinearGradient background(0,0,0,chart->width());
  background.setColorAt(0.0,QColor(255,0,0,170));
  background.setColorAt(1.0,QColor(255,0,0,0));
  painter.setBrush(QBrush(background));
  painter.drawRect(0,0,chart->width(),chart->height());

  ChartDecorator::paint(painter,chart);
}

