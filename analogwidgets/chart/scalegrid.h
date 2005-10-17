/************************************************************************
  			scalegridproperties.h - Copyright coder
**************************************************************************/

#ifndef SCALEGRIDPROPERTIES_H
#define SCALEGRIDPROPERTIES_H

class QPen;

namespace chart {
/** Struktura zawieraj±ca dane na temat skali oraz siatki */
class ScaleGrid {

public:
   /** Zastosowany font skali */
   QFont m_font;
   /** Rodzaj u¿ytego pióra do rysowania skali siatki oraz kolor */
   QPen m_pen;

   /** Ilo¶æ pionowych "drutów" w siatce wykresu */
   unsigned int  m_xMesh;
   /** Ilo¶æ poziomych "drutów" w siatce wykresu */
   unsigned int m_yMesh;
   /** Ilo¶æ pionowych "pod-drutów" w siatce wykresu */
   unsigned int m_xSubMesh;
   /** Ilo¶æ poziomych "pod-drutów" w siatce wykresu */
   unsigned int m_ySubMesh;
  /** Minimalna warto¶æ na skali */
   double min;
  /** Maksymalna warto¶æ na skali*/
   double max;
   /** minimalna wy¶wietlana warto¶æ na skali */
   double m_min;
   /** Maksymalna wy¶wietlana warto¶æ na skali */
   double m_max;

  /** Konstruktor domy¶lny */
  ScaleGrid ( )
  {
    m_xMesh=10; m_xSubMesh=1;
    m_yMesh=8;  m_ySubMesh=1;
    min=0; max=1000; m_min=min; m_max=max;
  }

};
} // namespace chart
#endif //SCALEGRIDPROPERTIES_H

