/************************************************************************
  			channeldecorator.h - Copyright coder
**************************************************************************/

#ifndef CHANNELDECORATOR_H
#define CHANNELDECORATOR_H

#include "chart/chartdecorator.h"



namespace chart {
namespace Standard {
/**
 * Class ChannelDecorator
 * Implementacja rysowania kana��w z danymi dla komponentu Chart
 */
class ChannelDecorator :  public ChartDecorator 
{
  
public:

  /**
  * Konstruktor
  * @param component Pointer na nast�pny dekorator
  */
  ChannelDecorator (ChartDecorator * component ):ChartDecorator(component){}

  /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
   void paint (QPainter & painter, Chart * chart);
   
  /** 
  * Podaje pozycje absolutne w kt�rych (w kana�ach) znajduje si� krusor (odczytan� z wykresu) 
  * @see ChartDecorator::absPosition 
  */ 
 void absPosition(QPoint & pos, QPolygonF & absPoints, Chart * chart,QRect & clip);
  
private:
   /** Wyskalowywuje uk�ad rysowania do wieko�ci danych w kanale */
   void translateToChannel (QPainter & painter, Chart * chart, Channel & channel);
   /** Rysuje dane z kana�u */
   void paintChannel(QPainter & painter,Chart * chart, Channel & channel);

   double xfactor;
   double yfactor;
   double dx,dy;
   // Szeroko�� okienka 
   double dxw; 
   // Wielko�� okienka ... 
   QRect window; 

};// class ChannelDecorator
} // chart
} // Standard
#endif //CHANNELDECORATOR_H

