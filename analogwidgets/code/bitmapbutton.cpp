#include <QPainter>
#include "bitmapbutton.h" 

#define TIMERCYCLES 20
BitmapButton::BitmapButton(QWidget * parent):QAbstractButton(parent)
{
  m_timer.setInterval(50); 
  m_timer.setSingleShot(false); 
  m_timer_cycles = 0; 
}

QIcon BitmapButton::downIcon() const 
{
  return m_downIcon; 
}

void BitmapButton::setDownIcon(const QIcon & icon)
{
  m_downIcon = icon; 
}


void BitmapButton::paintEvent ( QPaintEvent * event )
{
  
  m_timer_cycles = TIMERCYCLES; 
  m_timer.start(); 
  
  /*
  QPainter painter(this);
  if( isDown() || isChecked()) 
    m_downIcon.paint(&painter,0,0,width(),height()); 
  else 
    icon().paint(&painter,0,0,width(),height());
  */ 
}

void BitmapButton::drawTimer()
{
  QPainter painter(this); 
  icon().paint(&painter,0,0,width(),height());
  if (isDown() || isChecked() ) 
  {
    QPixmap image = m_downIcon.pixmap(width(),height());
    QPixmap alpha(width(),height()); 
    
    int c = (255.0/TIMERCYCLES) * m_timer_cycles; 
    alpha.fill(QColor(c,c,c));
    image.setAlphaChannel(alpha); 
    painter.drawPixmap(0,0,image);  
  }
  else 
  {
    QPixmap image = m_downIcon.pixmap(width(),height());
    QPixmap alpha(width(),height()); 
    
    int c = 255 - (255.0/TIMERCYCLES) * m_timer_cycles; 
    alpha.fill(QColor(c,c,c));
    image.setAlphaChannel(alpha); 
    painter.drawPixmap(0,0,image);  
  }
  
  
  if (m_timer_cycles == 0 ) 
  m_timer.stop(); 
  
  m_timer_cycles --; 
}