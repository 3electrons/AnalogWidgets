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
template <typename Type>
class PairDataContainer : public ChannelData
{

   Type & m_container;
  typename Type::iterator m_iterator;
  public:

  PairDataContainer ( Type & container ): m_container(container)
  { ; }

  bool init()
  {
    m_iterator = m_container.begin();
    return !m_container.empty();
  }

  bool next(double & x , double & y)
  {
    x = static_cast<double> (m_iterator->first);
    y = static_cast<double> (m_iterator->second);
    return m_container.end() != ++m_iterator;
  }

}; // class DataContainers


/**
* Klasa szablonowa na 2 pojemniki z dostêpem sekwencyjnym zawieraj±cych dane skalarne (double,int,etc.)
* jest klas± pochodn± klasy ChannelData co czyni j± idealn± do zastosowania jako ¼ród³o danych
* dla komponentu typu Chart
*/
template <typename Type1, typename Type2>
class DoubleDataContainer : public ChannelData
{
  Type1 & m_xcontainer;
  Type2 & m_ycontainer;
  typename Type1::iterator m_xit;
  typename Type2::iterator m_yit;

  public:
  DoubleDataContainer(Type1 & xContainer, Type2 & yContainer)
	  : m_xcontainer(xContainer),m_ycontainer(yContainer)
  { ; }
  bool init()
  {
    m_xit = m_xcontainer.begin();
    m_yit = m_ycontainer.begin();
    return ! (m_xcontainer.empty() || m_ycontainer.empty() );
  }

  bool next( double & x, double & y)
  {
    x = static_cast<double> (*m_xit++);
    y = static_cast<double> (*m_yit++);


   return ( m_xcontainer.end() != m_xit ) || ( m_ycontainer.end() != m_yit );
  }

};


#endif // DATACONTAINERS_H
