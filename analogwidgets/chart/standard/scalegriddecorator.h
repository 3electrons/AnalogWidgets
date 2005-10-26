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
 * Klasa domalowywuj±ca Skalê oraz Siatkê wykresu
 */
class ScalesGridDecorator : public ChartDecorator {

public:

 /**
  * Konstruktor
  * @param component Pointer na nastêpny dekorator
  */
  ScalesGridDecorator (ChartDecorator * component ):ChartDecorator(component){}

 /** Operacja malowania. Maluje kolejne elementy komponentu Chart. */
  void paint (QPainter & painter, Chart * chart);

protected:

  void paintBackground(QPainter &painter, Chart * chart);
  void paintXScale(QPainter & painter, Chart * chart);
  void paintYScale(QPainter & painter, Chart * chart);
  void paintXGrid  (QPainter & painter, Chart * chart);
  void paintYGrid  (QPainter & painter, Chart * chart);

 //double YScaleHeight();
 private:
  double xScaleHeight;
  double yScaleHeight;
  double yScaleWidth;

};
} // chart
} // Standard
#endif //SCALESGRIDDECORATOR_H

