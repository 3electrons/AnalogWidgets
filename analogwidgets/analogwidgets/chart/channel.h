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
  
   /** Zwraca wska�nik do "pojemnika" z danymi */ 
   ChannelData * data() const; 
   
   /** Zwraca maksymaln� warto�� kana�u jaka ma by� widoczna na wykresie */ 
   double maximum() const;
   /** Ustawia maksymaln� warto�� kana�u jaka ma by� widoczna na wykresie */ 
   void setMaximum(double i);
   /** Zwraca minimaln� warto�� kana�u jaka ma by� widoczna na wykrsie */
   double minimum() const ;
   /** Zadaje minimaln� warto�� kana�u jaka ma by� widoczna na wykresie */
   void setMinimum(double i);
   
   /** Ustawia wyliczone warto�ci max i min kana�u do rysowania na wykresie */ 
   void setCalcMinMax(double a,double b);
   /** Zwraca maximum i minimum wyliczone kana�u do rysowania na wykresie */   
   void getCalcMinMax(double &a, double &b);
   
   /** Zwraca flag� czy skala kana�u ma by� rysowana na wykresie */
   bool showScale() const;
   /** Ustawia flag� czy skala kana�u ma by� rysowana na wykresie */ 
   void setShowScale(bool i );
   
   /** Zwraca flag� czy kana� ma by� widoczny i wy�wietlany na wykresie */
   bool visible() const;
   
   /** Ustawia flag� widoczno�ci @see visible */
   void setVisible(bool i); 

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


  /** Okre��a czy ma by� pokazany na wykresie */
   bool m_visible; 

  /** Okre�la czy kana� ma by� widoczny ...w og�le */ 
   //bool m_visible; 
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
  Channel(double min,double max, ChannelData * data,QString name,QPen pen );

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
