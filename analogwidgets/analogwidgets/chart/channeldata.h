#ifndef CHANNELDATA_H
#define CHANNELDATA_H
#include <utility>

namespace chart
{
  class ChannelData
  {
    public:
    /**
    * Inicjuje kana� danych w taki spos�b by zwraca� pozycj� pierwszego elementu
    * po wywo�aniu metody next
    * @return True je�eli pojemnik zawiera dane w przeciwnym wypadku zwraca false
    */
    virtual bool init() = 0 ; // ustawia pojemnik na pierwszym elemencie ...
    /**
    * Ustawia warto�ci x oraz y kolejnych punkt�w danych zaczynaj�c od pierwszego
    * tak d�ugo dop�ki s� jakie� elementy zwracaj�c warto�� true tak d�ugo a�
    * znajduje si� co� jeszcze w tym strumieniu
    * @return Zwraca warto�� false gdy osi�gnie koniec strumienia danych
    */
    virtual bool next(double & x, double & y) = 0;
    /** Destruktor wirtualny by mozna bylo �adnie posprz�ta� */
    virtual ~ChannelData()
    { ; }
    
    virtual std::pair<double,double> findX(double x)=0; 

  };// class ChannelData
}; // namespace chart
#endif // CHANNELDATA_H
