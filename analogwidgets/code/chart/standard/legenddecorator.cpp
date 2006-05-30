/************************************************************************
  			legenddecorator.cpp - Copyright coder
**************************************************************************/
#include <QtGui>
#include <cmath>
#include "chart/standard/legenddecorator.h"
#include "chart.h"

using namespace std;
using namespace Standard;

/** Operacja malowania. Maluje kolejne elementy komponentu Chart. */

void LegendDecorator::paint (QPainter & painter, Chart * chart)
{
 
 if (!chart->doRepaintBackground())
  if (chart->isPaintOver())
  if (chart->showLegend()) 
  {
    unsigned int rh = painter.renderHints();
    painter.setRenderHint(QPainter::RenderHint(0x0)); // w�aczenie antialiasingu

    paintLegendFrame(painter,chart);

    painter.setRenderHint(QPainter::RenderHint(rh)); // wylaczenie antialiasingu
  }// if isPaintOver
  ChartDecorator::paint(painter,chart); // uruchomienie nast�pnego dekoratora
}

#define XOFFSET 10
#define YOFFSET 10
#define RIGHTOFFSET 15
#define TOPOFFSET 15
void LegendDecorator::paintLegendFrame(QPainter & painter, Chart * chart)
{

    Channels & channels = chart->channels();
    Channels::iterator i=channels.end();
    int width=0,height=0;
    QSize size;
    // Wyliczenie rozmiar�w maksymalnych ramki
    painter.setFont(chart->font());
    while (i--!=channels.begin())
    {
      size = painter.fontMetrics().size(Qt::TextSingleLine, i->name());
      width = max(width,size.width());
     if (i->visible()) 
      height += size.height();
    } // while

    // Utworzenie gradientu oraz innych niezbednych pedzli i szczotek :)
    QLinearGradient gradient(0,0,0,(height+2*XOFFSET+TOPOFFSET)/2);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(1.0,QColor(50,150,90,150));
    gradient.setColorAt(0.0,QColor(0,150,150,150));
    painter.setBrush(gradient);
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidthF(1.5);
    painter.setPen(pen);
    int x = width + 2*XOFFSET + RIGHTOFFSET;
    int y =  TOPOFFSET;
    // Namalowanie ramki z t�em
    painter.drawRoundRect(chart->width() - x, y, width+XOFFSET*2,height+YOFFSET,9,18);

    // Malowanie napis�w z opisami
    i = channels.begin();
    x = chart->width() - x + XOFFSET;
    y = TOPOFFSET + YOFFSET*2;
    while (i!=channels.end())
    {
      if (i->visible())
      {
        size = painter.fontMetrics().size(Qt::TextSingleLine, i->name());
        painter.setPen(i->pen());
        painter.drawText(x,y,i->name());
        y += size.height();        
      }
      ++i; 
    } // while
}

