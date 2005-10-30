/************************************************************************
  			channeldecorator.h - Copyright coder
**************************************************************************/

#ifndef CHANNELDECORATOR_H
#define CHANNELDECORATOR_H

#include "chartdecorator.h"



namespace chart {
namespace Standard {
/**
 * Class ChannelDecorator
 * Implementacja rysowania kana³ów z danymi dla komponentu Chart
 */
class ChannelDecorator : public ChartDecorator {

public:

  /**
  * Konstruktor
  * @param component Pointer na nastêpny dekorator
  */
  ChannelDecorator (ChartDecorator * component ):ChartDecorator(component){}

  /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
   void paint (QPainter & painter, Chart * chart);

private:
   void translateToChannel (QPainter & painter, Chart * chart, Channel & channel);



};// class ChannelDecorator
} // chart
} // Standard
#endif //CHANNELDECORATOR_H

