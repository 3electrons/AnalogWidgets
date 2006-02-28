#include "chart/channel.h"

using namespace chart;

Channel::Channel()
{
    min= m_min= 0;
    max= m_max= 450;
    showScale=true;
    m_pen.setColor(Qt::white);
    m_data = NULL;
   // m_iterator_begin=m_iterator_end=0; // wska¼nik na NULL
}

Channel::Channel(double min,double max, ChannelData * data,const char * name,QPen pen )
{
  this->min = m_min = min;
  this->max = m_max = max;
  this->m_data = data;
  this->m_name = QString::fromLocal8Bit(name);
  this->m_pen = pen;
  showScale = true;
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
