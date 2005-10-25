/************************************************************************
  			channel.h - Copyright coder
**************************************************************************/

#ifndef CHANNEL_H
#define CHANNEL_H
#include <QString>
#include <QPen>


//class Iterator;
namespace chart {
/** Stuktura zawieraj�ca dane na temat konkretnego kana�u */
class Channel  {

public:
   /** Iteratory wskazuj�ce na dane do odczytania */

  // Iterator * m_iterator_begin,m_iterator_end;

  /** Pi�ro jakim ma by� malowany kana� - czyli jego kolor, grubo�� i styl. */
   QPen m_pen;
  /** Nazwa daych np. Napi�cie */
   QString m_name;


  /** Warto�� minmalna dla kana�u kt�ra ma by� wy�wietlana na wykresie */
   double min;
  /** Warto�� maksymalna dla kana�u kt�ra ma by� wy�wietlana na wykresie */
   double max;
  /** Wato�� minimalna wyznaczona na podstawie rozleg�o�ci skali oraz ilo�ci w�z��w skali*/
   double m_min;
  /** Wato�� maksymalna wyznaczona na podstawie rozleg�o�ci skali oraz ilo�ci w�z��w skali */
   double m_max;

  /** Okre�la czy kana� ma mie� pokazan� w�asn� o� z danymi*/
   bool showScale;

  /** Konstruktor domy�lny */ 
  Channel();
  
  /** Konstruktor kopiuj�cy */
  //Channel (const Channel & ch); 
  

}; //  class channel
} // namespace chart
#endif //CHANNEL_H
