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
  
   ChannelData * data() const; 
   
   double maximum() const { return m_max ; }
   void setMaximum(double i) { if (i>m_min) m_max = i;}
   double minimum() const { return m_min ; }
   void setMinimum(double i) { if (i<m_max) m_min = i;}
   
   void setCalcMinMax(double a,double b)
   {
     if (a<b) { m_calc_min = a ; m_calc_max = b; }
   }
   void getCalcMinMax(double &a, double &b)
   {
     a = m_calc_min; b = m_calc_max ; 
   }
   
   bool showScale() const { return m_showScale; }
   void setShowScale(bool i ){ m_showScale = i ; } 
   
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
  Channel(double min,double max, ChannelData * data,const char * name,QPen pen );

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
