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

void QMyWidgetWithBackground::drawBackground()
{
  if (m_pixmap->size() != size() || m_modified )
    {
	delete m_pixmap;
	m_pixmap = new QPixmap(size());
	m_modified=true; // by wiadomo bylo ¿e jest przemalowywane tlo
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

bool QMyWidgetWithBackground::doRepaintBackground()
{
  return m_modified;
}

void QMyWidgetWithBackground::repaintBackground()
{
  m_pixmap->fill(QColor(0,0,0,0));
  QPainter painter(m_pixmap);
  paintBackground(painter);
}
