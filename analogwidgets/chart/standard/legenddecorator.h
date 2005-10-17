/************************************************************************
  			legenddecorator.h - Copyright coder
**************************************************************************/

#ifndef LEGENDDECORATOR_H
#define LEGENDDECORATOR_H

#include "chartdecorator.h"



namespace chart {
namespace Standard {
/**
 * Class LegendDecorator
 * Klasa domalowywuj�ca legend� do wykresu.
 */
class LegendDecorator : public ChartDecorator {

public:

 /**
  * Konstruktor
  * @param component Pointer na nast�pny dekorator
  */
  LegendDecorator (ChartDecorator * component ):ChartDecorator(component){}

 /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
  void paint (QPainter & painter, Chart * chart);

private:

};
} // chart
} // Standard
#endif //LEGENDDECORATOR_H

