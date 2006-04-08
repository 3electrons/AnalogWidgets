#ifndef DATACONTAINERS_H
#define DATACONTAINERS_H
#include <cmath> 
#include "channeldata.h"

using namespace chart;
using namespace std;

/**
* Klasa szablonowa na pojemniki z dostêpem sekwencyjnym zawieraj±cych dane typu pair<double,double>
* jest pochodn± klasy ChannelData co czyni j± ideln± do zastosowania jako ¼ród³o danych
* dla komponentu typu Chart.
* @see ChannelData
*/
template <typename type>
class PairDataContainer : public ChannelData
{

  type & m_container;
  typename type::iterator m_iterator;
  public:

  PairDataContainer ( type & container ): m_container(container)
  { ; }

  bool init()
  {
    m_iterator = m_container.begin();
    return !m_container.empty();
  }

  bool next(double & x , double & y)
  {
    if (m_container.end() == m_iterator) 
      return false; 
    
     x = static_cast<double> (m_iterator->first);
     y = static_cast<double> (m_iterator->second);
        
    ++m_iterator; 
    
    return true;
  }
  
  std::pair<double,double> findX (double x)
  {
   // @TODO Ta funkcja musi zostaæ napisana ...  return pair<double,double>(0,0); 
  }

}; // class DataContainers


#include <iostream> 
using namespace std; 
/**
* Klasa szablonowa na 2 pojemniki z dostêpem sekwencyjnym zawieraj±cych dane skalarne (double,int,etc.)
* jest klas± pochodn± klasy ChannelData co czyni j± idealn± do zastosowania jako ¼ród³o danych
* dla komponentu typu Chart
*/




template <typename T >
class between
{
 T val;
 public:
 between(T v):val(v)
 { ; } 
 bool operator()(T & a,T & b)
 {
  return a>=val && val<b; 
 }
};

template <typename type1, typename type2>
class DoubleDataContainer : public ChannelData
{
  type1 & m_xcontainer;
  type2 & m_ycontainer;
  typename type1::iterator m_xit;
  typename type2::iterator m_yit;
  
  typename type1::iterator m_xfind_it;
  typename type2::iterator m_yfind_it;
 
  
  public:
  DoubleDataContainer(type1 & xContainer, type2 & yContainer)
	  : m_xcontainer(xContainer),m_ycontainer(yContainer)
  { 
    init();
  }
  
  bool init()
  {
    m_xit = m_xcontainer.begin();
    m_yit = m_ycontainer.begin();
    
    return ! (m_xcontainer.empty() || m_ycontainer.empty() );
  }

  bool next( double & x, double & y)
  {
    if ( (m_xcontainer.end() == m_xit ) || (m_ycontainer.end() == m_yit) )
          return false; 
    x = static_cast<double> (*m_xit++);
    y = static_cast<double> (*m_yit++);

   return true;
  }
  
  
  std::pair<double,double> findX (double x)
  {
    typedef typename type1::value_type just_type; 
    typename type1::iterator b,xi = adjacent_find(m_xcontainer.begin(),m_xcontainer.end(),between<just_type>((just_type)x)); 
    if (xi==m_xcontainer.end()) return pair<double,double>(0.0,0.0); 
    
    typename type2::iterator yi = m_ycontainer.begin();   
    
    b=xi; b++; 
    if (fabs(x-*xi) > fabs(x-*b)) xi++; 
    b = xi; 
    int s=0; 
    while (xi!=m_xcontainer.begin())
    { xi --; s++; } 
    
    for (int i=0;i<s;i++,yi++); 
        
        
        
   return pair<double,double>(*b,*yi); 
  }
  
 
  protected: 
   
   
};


#endif // DATACONTAINERS_H
