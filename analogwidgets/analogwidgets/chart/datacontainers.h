#ifndef DATACONTAINERS_H
#define DATACONTAINERS_H

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
    return pair<double,double>(0,0); 
  }

}; // class DataContainers


#include <iostream> 
using namespace std; 
/**
* Klasa szablonowa na 2 pojemniki z dostêpem sekwencyjnym zawieraj±cych dane skalarne (double,int,etc.)
* jest klas± pochodn± klasy ChannelData co czyni j± idealn± do zastosowania jako ¼ród³o danych
* dla komponentu typu Chart
*/
template <typename type1, typename type2>
class DoubleDataContainer : public ChannelData
{
  type1 & m_xcontainer;
  type2 & m_ycontainer;
  typename type1::iterator m_xit;
  typename type2::iterator m_yit;
  
  typename type1::iterator m_xfind_it;
  typename type2::iterator m_yfind_it;
  unsigned int find_index ; 
  
  public:
  DoubleDataContainer(type1 & xContainer, type2 & yContainer)
	  : m_xcontainer(xContainer),m_ycontainer(yContainer)
  { 
   initFind(); 
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
    cout<<"findX"<<endl; 
    if (find_index > m_xcontainer.size() || find_index > m_ycontainer.size())
      initFind(); 
    
    double left = *m_xfind_it;
    double right = left; 
    while ( left < x && right >= x 
            && m_xfind_it!=m_xcontainer.begin() 
            && m_xfind_it!=m_xcontainer.end()
            && m_yfind_it!=m_ycontainer.begin() 
            && m_yfind_it!=m_ycontainer.end()
            ) 
    {
       left = *m_xfind_it;
       if (left > x ) 
        { m_xfind_it --;  m_yfind_it --;
           right = left; 
        }
        else 
        { m_xfind_it++ ; m_yfind_it++; }  
    }
    
     cout<<"Left:"<<left<<" Right:"<<right<<endl;
     
    return pair<double,double>(right,*m_yfind_it++);       
  }
  
 
  protected: 
   void initFind()
   {
     find_index=0; 
     m_xfind_it = m_xcontainer.begin();
     m_yfind_it = m_ycontainer.begin(); 
    
   }
   
};


#endif // DATACONTAINERS_H
