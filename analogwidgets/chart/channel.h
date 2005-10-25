/************************************************************************
  			channel.h - Copyright coder
**************************************************************************/

#ifndef CHANNEL_H
#define CHANNEL_H
#include <QString>
#include <QPen>


//class Iterator;
namespace chart {
/** Stuktura zawieraj±ca dane na temat konkretnego kana³u */
class Channel  {

public:
   /** Iteratory wskazuj±ce na dane do odczytania */

  // Iterator * m_iterator_begin,m_iterator_end;

  /** Pióro jakim ma byæ malowany kana³ - czyli jego kolor, grubo¶æ i styl. */
   QPen m_pen;
  /** Nazwa daych np. Napiêcie */
   QString m_name;


  /** Warto¶æ minmalna dla kana³u która ma byæ wy¶wietlana na wykresie */
   double min;
  /** Warto¶æ maksymalna dla kana³u która ma byæ wy¶wietlana na wykresie */
   double max;
  /** Wato¶æ minimalna wyznaczona na podstawie rozleg³o¶ci skali oraz ilo¶ci wêz³ów skali*/
   double m_min;
  /** Wato¶æ maksymalna wyznaczona na podstawie rozleg³o¶ci skali oraz ilo¶ci wêz³ów skali */
   double m_max;

  /** Okre¶la czy kana³ ma mieæ pokazan± w³asn± o¶ z danymi*/
   bool showScale;

  /** Konstruktor domy¶lny */ 
  Channel();
  
  /** Konstruktor kopiuj±cy */
  //Channel (const Channel & ch); 
  

}; //  class channel
} // namespace chart
#endif //CHANNEL_H
