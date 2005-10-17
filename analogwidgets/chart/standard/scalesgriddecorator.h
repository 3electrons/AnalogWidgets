/************************************************************************
  			scalesgriddecorator.h - Copyright coder
**************************************************************************/

#ifndef SCALESGRIDDECORATOR_H
#define SCALESGRIDDECORATOR_H

#include "chartdecorator.h"



namespace chart {
namespace Standard {
/**
 * Class ScalesGridDecorator
 * Klasa domalowywuj�ca Skal� oraz Siatk� wykresu
 */
class ScalesGridDecorator : public ChartDecorator {

public:

 /**
  * Konstruktor
  * @param component Pointer na nast�pny dekorator
  */
  ScalesGridDecorator (ChartDecorator * component ):ChartDecorator(component){}

 /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
  void paint (QPainter & painter, Chart * chart);

protected:
  void paintBackground(QPainter &painter, Chart * chart);
  void paintXScale(QPainter & painter, Chart * chart);
  void paintYScale(QPainter & painter, Chart * chart);
  void paintGrid  (QPainter & painter, Chart * chart);


};
} // chart
} // Standard
#endif //SCALESGRIDDECORATOR_H

