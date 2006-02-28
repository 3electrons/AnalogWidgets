/************************************************************************
  			chartdecorator.h - Copyright coder
**************************************************************************/

#ifndef CHARTDECORATOR_H
#define CHARTDECORATOR_H

class QPainter; // Deklaracja klas
class Chart;

namespace chart {
/**
 * Class ChartDecorator
 * Klasa bazowa dla dekoratorów komponentu Chart.
 */
class ChartDecorator {

public:

  /**
   * Operacja malowania. Zupe³nie abstrakcyjna. Ka¿dy kolejny dekorator ma za zadanie domalowaæ
   * kolejne elementy wykresu takie jak t³o, skala, siatka, sam wykres, legenda, inne rzeczy
   * Maluje kolejne elementy komponentu Chart.
   * @param painter Painter za pomoc± którego ma odbyæ siê malowanie
   * @param chart   Wska¼nik na g³ówny komponent - pozwala wydêbiæ dodatkowe informacje
   */
   virtual void paint (QPainter & painter, Chart * chart)
   {
     if (m_component) m_component->paint(painter,chart);
   }

  /** Konstruktor - parametrem jest inny dekorator.*/
    ChartDecorator (ChartDecorator * component):m_component(component)
    {}

  /** Destruktor wirutalny */
   virtual ~ChartDecorator()
   {
    if (m_component) delete m_component;
    m_component=0;
   }

private:

  /** Wska¼nik do nastêpnego dekoratora. */
   ChartDecorator * m_component;

};
} // namespace chart
#endif //CHARTDECORATOR_H

