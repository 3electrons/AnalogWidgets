#include "chart/channel.h"

using namespace chart;

Channel::Channel()
{
    m_min= m_calc_min= 0;
    m_max= m_calc_max= 450;
    m_showScale=true;
    m_pen.setColor(Qt::white);
    m_data = NULL;
   // m_iterator_begin=m_iterator_end=0; // wska¼nik na NULL
}

Channel::Channel(double min,double max, ChannelData * data,const char * name,QPen pen )
{
  this->m_min = m_calc_min = min;
  this->m_max = m_calc_max = max;
  this->m_data = data;
  this->m_name = QString::fromLocal8Bit(name);
  this->m_pen = pen;
  m_showScale = true;
}


void Channel::setPen(QPen & pen) 
{
 m_pen = pen;
}

QPen Channel::pen() const
{
 return m_pen; 
}
   
void Channel::setName(QString & name)
{
  m_name = name;  
}
   
QString Channel::name() const
{
  return m_name; 
}
  
ChannelData * Channel::data() const
{
  return m_data;  
}
   
 
double Channel::maximum() const 
{
  return m_max ; 
}


void Channel::setMaximum(double i) 
{ 
   if (i>m_min) 
      m_max = i;
}


double Channel::minimum() const 
{ 
  return m_min ; 
}


void Channel::setMinimum(double i) 
{ 
  if (i<m_max) 
    m_min = i;
}
   
   
void Channel::setCalcMinMax(double a,double b)
{
  if (a<b)
  {
    m_calc_min = a; 
    m_calc_max = b; 
  }
}


void Channel::getCalcMinMax(double &a, double &b)
{
  a = m_calc_min; 
  b = m_calc_max ; 
}
   
   
bool Channel::showScale() const 
{ 
  return m_showScale; 
}


void Channel::setShowScale(bool i)
{ 
  m_showScale = i ; 
} 
