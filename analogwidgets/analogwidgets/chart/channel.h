/************************************************************************
  			channel.h - Copyright coder
**************************************************************************/

#ifndef CHANNEL_H
#define CHANNEL_H
#include <QString>
#include <QPen>
#include "channeldata.h"


//class Iterator;
namespace chart {
/** Stuktura zawieraj±ca dane na temat konkretnego kana³u */
class Channel  {

public:

   void setPen(QPen & pen);
   QPen pen() const; 
   
   void setName(QString & name); 
   QString name() const; 
  
   /** Zwraca wska¼nik do "pojemnika" z danymi */ 
   ChannelData * data() const; 
   
   /** Zwraca maksymaln± warto¶æ kana³u jaka ma byæ widoczna na wykresie */ 
   double maximum() const;
   /** Ustawia maksymaln± warto¶æ kana³u jaka ma byæ widoczna na wykresie */ 
   void setMaximum(double i);
   /** Zwraca minimaln± warto¶æ kana³u jaka ma byæ widoczna na wykrsie */
   double minimum() const ;
   /** Zadaje minimaln± warto¶æ kana³u jaka ma byæ widoczna na wykresie */
   void setMinimum(double i);
   
   /** Ustawia wyliczone warto¶ci max i min kana³u do rysowania na wykresie */ 
   void setCalcMinMax(double a,double b);
   /** Zwraca maximum i minimum wyliczone kana³u do rysowania na wykresie */   
   void getCalcMinMax(double &a, double &b);
   
   /** Zwraca flagê czy skala kana³u ma byæ rysowana na wykresie */
   bool showScale() const;
   /** Ustawia flagê czy skala kana³u ma byæ rysowana na wykresie */ 
   void setShowScale(bool i );
   
   /** Zwraca flagê czy kana³ ma byæ widoczny i wy¶wietlany na wykresie */
   bool visible() const;
   
   /** Ustawia flagê widoczno¶ci @see visible */
   void setVisible(bool i); 

   protected: 
   /** Iteratory wskazuj±ce na dane do odczytania */
  // Iterator * m_iterator_begin,m_iterator_end;
  /** Pióro jakim ma byæ malowany kana³ - czyli jego kolor, grubo¶æ i styl. */
   QPen m_pen;
  /** Nazwa daych np. Napiêcie */
   QString m_name;
  /** Dane kana³u */ 
  ChannelData * m_data;
  

  /** Warto¶æ minmalna dla kana³u która ma byæ wy¶wietlana na wykresie */
   double m_min;
  /** Warto¶æ maksymalna dla kana³u która ma byæ wy¶wietlana na wykresie */
   double m_max;
  /** Wato¶æ minimalna wyznaczona na podstawie rozleg³o¶ci skali oraz ilo¶ci wêz³ów skali*/
   double m_calc_min;
  /** Wato¶æ maksymalna wyznaczona na podstawie rozleg³o¶ci skali oraz ilo¶ci wêz³ów skali */
   double m_calc_max;

  /** Okre¶la czy kana³ ma mieæ pokazan± w³asn± o¶ z danymi*/
   bool m_showScale;


  /** Okre¶³a czy ma byæ pokazany na wykresie */
   bool m_visible; 

  /** Okre¶la czy kana³ ma byæ widoczny ...w ogóle */ 
   //bool m_visible; 
  /** Konstruktor domy¶lny */
  public: 

 
  Channel();

  /**
  * Konstruktor parametryzowany
  * Pozwala na okre¶lenie warto¶ci minimalnych oraz maksymalnych
  * @param min - minimalna warto¶æ na skali jak± chcemy mieæ
  * @param max - maksymalna warto¶æ na skali jak± chcemy mieæ.
  * @param name - nazwa kana³u danych
  * @param pen  - rodzaj pióra jakim ma byæ malowany dany wykres
  */
  Channel(double min,double max, ChannelData * data,QString name,QPen pen );

  /** Ustawia warto¶æ minimum */
  // void setMin(double min);
  /** Zwraca warto¶æ minimun */
  //double min() const ;
  /** Ustawia warto¶æ maksimum */
  //void setMax(double max);
  /** Zwraca warto¶æ maksimum */
  //double max() const;

  /** Zwraca warto¶æ minimum na skali */
  //double m_min() const;
  /** Zwraca warto¶æ maksimum na skali */
  //double m_max() const;

}; //  class channel
} // namespace chart
#endif //CHANNEL_H
