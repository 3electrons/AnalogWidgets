/************************************************************************
  			scalegridproperties.h - Copyright coder
**************************************************************************/

#ifndef SCALEGRIDPROPERTIES_H
#define SCALEGRIDPROPERTIES_H

class QPen;

namespace chart {
/** Struktura zawieraj�ca dane na temat skali oraz siatki */
class ScaleGrid {

public:
   /** Zastosowany font skali */
   QFont m_font;
   /** Rodzaj u�ytego pi�ra do rysowania skali siatki oraz kolor */
   QPen m_pen;

   /** Ilo�� pionowych "drut�w" w siatce wykresu */
   unsigned int  m_xMesh;
   /** Ilo�� poziomych "drut�w" w siatce wykresu */
   unsigned int m_yMesh;
   /** Ilo�� pionowych "pod-drut�w" w siatce wykresu */
   unsigned int m_xSubMesh;
   /** Ilo�� poziomych "pod-drut�w" w siatce wykresu */
   unsigned int m_ySubMesh;
  /** Minimalna warto�� na skali */
   double min;
  /** Maksymalna warto�� na skali*/
   double max;
   /** minimalna wy�wietlana warto�� na skali */
   double m_min;
   /** Maksymalna wy�wietlana warto�� na skali */
   double m_max;

  /** Czy ma by� narysowana siatka dla ca�ej skali */
   bool m_showGrid;
  /** Konstruktor domy�lny */
  ScaleGrid ( )
  {
    m_xMesh=7; m_xSubMesh=4;
    m_yMesh=7;  m_ySubMesh=3;
    min=0; max=1000; m_min=min; m_max=max;
    m_showGrid=true;
    m_font.setPointSize(10);
  }

};
} // namespace chart
#endif //SCALEGRIDPROPERTIES_H

