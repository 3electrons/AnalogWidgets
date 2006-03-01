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
/** Stuktura zawieraj�ca dane na temat konkretnego kana�u */
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
   /** Iteratory wskazuj�ce na dane do odczytania */
  // Iterator * m_iterator_begin,m_iterator_end;
  /** Pi�ro jakim ma by� malowany kana� - czyli jego kolor, grubo�� i styl. */
   QPen m_pen;
  /** Nazwa daych np. Napi�cie */
   QString m_name;
  /** Dane kana�u */ 
  ChannelData * m_data;
  

  /** Warto�� minmalna dla kana�u kt�ra ma by� wy�wietlana na wykresie */
   double m_min;
  /** Warto�� maksymalna dla kana�u kt�ra ma by� wy�wietlana na wykresie */
   double m_max;
  /** Wato�� minimalna wyznaczona na podstawie rozleg�o�ci skali oraz ilo�ci w�z��w skali*/
   double m_calc_min;
  /** Wato�� maksymalna wyznaczona na podstawie rozleg�o�ci skali oraz ilo�ci w�z��w skali */
   double m_calc_max;

  /** Okre�la czy kana� ma mie� pokazan� w�asn� o� z danymi*/
   bool m_showScale;
  /** Konstruktor domy�lny */
  public: 

 
  Channel();

  /**
  * Konstruktor parametryzowany
  * Pozwala na okre�lenie warto�ci minimalnych oraz maksymalnych
  * @param min - minimalna warto�� na skali jak� chcemy mie�
  * @param max - maksymalna warto�� na skali jak� chcemy mie�.
  * @param name - nazwa kana�u danych
  * @param pen  - rodzaj pi�ra jakim ma by� malowany dany wykres
  */
  Channel(double min,double max, ChannelData * data,const char * name,QPen pen );

  /** Ustawia warto�� minimum */
  // void setMin(double min);
  /** Zwraca warto�� minimun */
  //double min() const ;
  /** Ustawia warto�� maksimum */
  //void setMax(double max);
  /** Zwraca warto�� maksimum */
  //double max() const;

  /** Zwraca warto�� minimum na skali */
  //double m_min() const;
  /** Zwraca warto�� maksimum na skali */
  //double m_max() const;

}; //  class channel
} // namespace chart
#endif //CHANNEL_H
