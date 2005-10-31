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

  /**
  * Konstruktor parametryzowany
  * Pozwala na okre�lenie warto�ci minimalnych oraz maksymalnych
  * @param min - minimalna warto�� na skali jak� chcemy mie�
  * @param max - maksymalna warto�� na skali jak� chcemy mie�.
  * @param name - nazwa kana�u danych
  * @param pen  - rodzaj pi�ra jakim ma by� malowany dany wykres
  */
  Channel(double min,double max, QString name,QPen pen );

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
