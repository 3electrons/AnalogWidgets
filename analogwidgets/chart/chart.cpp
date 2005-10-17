#include <QtGui>
#include "chart.h"
#include "standard/scalesgriddecorator.h"
#include "standard/glassdecorator.h"


Chart::Chart(QWidget *parent)
	: QMyWidgetWithBackground(parent)
{
  // QWidget
   setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
   setWindowTitle(tr("Chart diagram"));
   m_channels.push_back(Channel());
   m_channel=0;

   InitDecorators();

}

void Chart::InitDecorators()
{
	m_painterDecorator.reset
	(
           new Standard::ScalesGridDecorator
          (
           NULL// new Standard::GlassDecorator(NULL)
          )
        );

}

void Chart::paintEvent(QPaintEvent * /*event */)
{
  drawBackground();
}

void Chart::paintBackground(QPainter & painter)
{
  if (m_painterDecorator.get()) m_painterDecorator->paint(painter,this);
}

void Chart::initCoordinateSystem(QPainter & painter)
{

}
