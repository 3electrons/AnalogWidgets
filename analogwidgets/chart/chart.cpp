#include <QtGui> 
#include "chart.h" 
    	
 	
Chart::Chart(QWidget *parent)
	: QMyWidgetWithBackground(parent) 
{
}
     
void Chart::paintEvent(QPaintEvent *event)
{
  drawBackground(); 	
}

void Chart::paintBackground(QPainter & painter)
{
  QLinearGradient background(0,0,0,height()); 
  background.setColorAt(0.0,QColor(0,0,150)); 
  background.setColorAt(1.0,Qt::black); 
  painter.setBrush(QBrush(background)); 
  painter.drawRect(0,0,width(),height()); 
  	
}

void Chart::initCoordinateSystem(QPainter & painter)
{
}
