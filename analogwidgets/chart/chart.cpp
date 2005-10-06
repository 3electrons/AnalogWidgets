#include <QtGui> 
#include "chart.h" 
    	
 	
Chart::Chart(QWidget *parent)
	: QMyWidgetWithBackground(parent) 
{
  // QWidget
   setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
   setWindowTitle(tr("Chart diagram"));
   m_Ychannels.push_back(Channel());
   m_channel=0; 
   m_xGrid=10; 
   m_yGrid=10; 
}
     
void Chart::paintEvent(QPaintEvent * /*event */)
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
  
  QFont Font= painter.font(); 
  
  
  painter.setPen(QColor(255,255,255,180)); 
  
  	
}

void Chart::initCoordinateSystem(QPainter & painter)
{

}
