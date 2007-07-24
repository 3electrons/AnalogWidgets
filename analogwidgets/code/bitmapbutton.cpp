#include <QPainter>
#include "bitmapbutton.h" 


BitmapButton::BitmapButton(QWidget * parent):QAbstractButton(parent)
{

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
  
  QPainter painter(this);   
  if( isDown() || isChecked()) 
    m_downIcon.paint(&painter,0,0,width(),height()); 
  else 
    icon().paint(&painter,0,0,width(),height());
}