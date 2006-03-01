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
   
/*
Channel::Channel( const Channel & ch)
{
   m_pen    	= ch.m_pen;
   m_name 	= ch.m_name;

   min		= ch.min;
   max		= ch.max;
   m_min	= ch.min;
   m_max	= ch.max;
   showScale	= ch.showScale;
}
*/
/**
void setMin(double min);

double min() const ;

void setMax(double max);

double max() const;


double m_min() const;

double Channel::m_max() const { return _m_min
*/
