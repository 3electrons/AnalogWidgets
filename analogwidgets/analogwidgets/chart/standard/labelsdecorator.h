/************************************************************************
  			labelsdecorator.h - Copyright coder
**************************************************************************/

#ifndef LABELSDECORATOR_H
#define LABELSDECORATOR_H

#include "chart/chartdecorator.h"



namespace chart {
namespace Standard {
/**
 * Class LabelsDecorator
 * Klasa domalowywuj±ca etykiety do konkretnych wskazanych punktów na wykresie.
 */
class LabelsDecorator : public ChartDecorator {

public:

 /**
  * Konstruktor
  * @param component Pointer na nastêpny dekorator
  */
  LabelsDecorator (ChartDecorator * component ):ChartDecorator(component){}

 /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
  void paint (QPainter & painter, Chart * chart);

private:

};
} // chart
} // Standard
#endif //LABELSDECORATOR_H

