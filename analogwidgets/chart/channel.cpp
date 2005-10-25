#include "channel.h" 

using namespace chart; 

Channel::Channel()
{
    min=m_min=0;
    max=m_max=450;
    showScale=true;
    m_pen.setColor(Qt::white);
   // m_iterator_begin=m_iterator_end=0; // wska¼nik na NULL
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