/************************************************************************
  			legenddecorator.h - Copyright coder
**************************************************************************/

#ifndef LEGENDDECORATOR_H
#define LEGENDDECORATOR_H

#include "chart/chartdecorator.h"



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
  /** Rysuje ramk� z opisem  przebieg�w zmiennych */
  void paintLegendFrame(QPainter & painter, Chart * chart);
};// class LegendDecorator
} // chart
} // Standard
#endif //LEGENDDECORATOR_H

