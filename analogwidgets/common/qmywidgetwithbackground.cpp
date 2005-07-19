#include <QtGui>
#include "qmywidgetwithbackground.h"

QMyWidgetWithBackground::QMyWidgetWithBackground(QWidget * parent) : QWidget(parent)
{
  m_pixmap = new QPixmap(size());
  m_modified = false;
}

QMyWidgetWithBackground::~QMyWidgetWithBackground()
{
   if (m_pixmap)
     {
	delete m_pixmap;
	m_pixmap = NULL;
     }
}

void QMyWidgetWithBackground::repaintBackground()
{
  QPainter backPainter(this);
  QPainter painter(m_pixmap);
  // inicjalizacja paintera oraz odmalowanie t³a
  painter.setBrush(backPainter.background());
  painter.setPen(Qt::NoPen);
  painter.drawRect(0,0,width(),height());
  paintBackground(painter);
}

void QMyWidgetWithBackground::doUpdateBackground()
{
  if (m_pixmap->size() != size() || m_modified )
    {
	delete m_pixmap;
	m_pixmap = new QPixmap(size());
	repaintBackground();
	m_modified=false;
    }
    QPainter painter(this);
    painter.drawPixmap(0,0,*m_pixmap);
}

void QMyWidgetWithBackground::updateWithBackground()
{
  m_modified=true;
  update();

}
