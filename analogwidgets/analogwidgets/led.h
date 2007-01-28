#ifndef QLED_H
#define QLED_H
#include <QColor> 
#include "widgetwithbackground.h"

   /**
   * Klasa reprezentuj�ca diod� w dowolnym kolorze jako dwustabilny element wskazuj�cy 
   */
   class Led : public WidgetWithBackground
   {
     Q_OBJECT 
     Q_PROPERTY( bool checked READ isChecked 	WRITE setChecked)
     Q_PROPERTY( QColor color READ color 	WRITE setColor) 
     
     
     public:  
     
     Led(QWidget *parent = 0);
     virtual ~Led() {};
     
     /** Zdarzenie obs�uguj�ce malowanie kontrolki */ 
     void paintEvent(QPaintEvent * event);
     
     bool isChecked () const ; 
     
     
     QColor color() const; 
     void setColor(QColor); 
     
     public slots: 
     
     void setChecked(bool); 
     
     signals: 
     
     void checkChanged(bool val); 
     
     protected:
     
     /** Inicjuje uk�ad wsp�rz�dnych paintera */
     void initCoordinateSystem(QPainter & painter);
     
     /**
     * Maluje t�o kontrolki w tym przypadku pierwszy plan czyli odblask �wiat�a kontrolki
     * @param painter Przestrze� kontrolki 
     */
     void paintBackground(QPainter & painter);
    
     protected: 
     
     bool m_checked; 
     QColor m_color; 

   }; 
   
#endif // QLED_H 
