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
class ChannelDecorator : public ChartDecorator {

public:

  /**
  * Konstruktor
  * @param component Pointer na nast�pny dekorator
  */
  ChannelDecorator (ChartDecorator * component ):ChartDecorator(component){}

  /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
   void paint (QPainter & painter, Chart * chart);

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


};// class ChannelDecorator
} // chart
} // Standard
#endif //CHANNELDECORATOR_H

