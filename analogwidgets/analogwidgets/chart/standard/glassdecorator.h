/************************************************************************
  			glassdecorator.h - Copyright coder
**************************************************************************/

#ifndef GLASSDECORATOR_H
#define GLASSDECORATOR_H

#include "chartdecorator.h"



namespace chart {
namespace Standard {
/**
 * Class GlassDecorator
 * Klasa domalowywuj�ca elegancki efekt odblasku szk�a ponad wykresem
 */
class GlassDecorator : public ChartDecorator {

public:

 /**
  * Konstruktor
  * @param component Pointer na nast�pny dekorator
  */
  GlassDecorator (ChartDecorator * component ):ChartDecorator(component){}

  /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
  void paint (QPainter & painter, Chart * chart);

private:

};
} // chart
} // Standard
#endif //GLASSDECORATOR_H

