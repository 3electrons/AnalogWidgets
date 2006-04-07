#ifndef CHANNELDATA_H
#define CHANNELDATA_H
#include <utility>

namespace chart
{
  class ChannelData
  {
    public:
    /**
    * Inicjuje kana³ danych w taki sposób by zwraca³ pozycjê pierwszego elementu
    * po wywo³aniu metody next
    * @return True je¿eli pojemnik zawiera dane w przeciwnym wypadku zwraca false
    */
    virtual bool init() = 0 ; // ustawia pojemnik na pierwszym elemencie ...
    /**
    * Ustawia warto¶ci x oraz y kolejnych punktów danych zaczynaj±c od pierwszego
    * tak d³ugo dopóki s± jakie¶ elementy zwracaj±c warto¶æ true tak d³ugo a¿
    * znajduje siê co¶ jeszcze w tym strumieniu
    * @return Zwraca warto¶æ false gdy osi±gnie koniec strumienia danych
    */
    virtual bool next(double & x, double & y) = 0;
    /** Destruktor wirtualny by mozna bylo ³adnie posprz±taæ */
    virtual ~ChannelData()
    { ; }
    
    virtual std::pair<double,double> findX(double x)=0; 

  };// class ChannelData
}; // namespace chart
#endif // CHANNELDATA_H
