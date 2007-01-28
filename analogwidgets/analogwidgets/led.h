#ifndef QLED_H
#define QLED_H
#include <QColor> 
#include "widgetwithbackground.h"

   /**
   * Klasa reprezentuj±ca diodê w dowolnym kolorze jako dwustabilny element wskazuj±cy 
   */
   class Led : public WidgetWithBackground
   {
     Q_OBJECT 
     Q_PROPERTY( bool checked READ isChecked 	WRITE setChecked)
     Q_PROPERTY( QColor color READ color 	WRITE setColor) 
     
     
     public:  
     
     Led(QWidget *parent = 0);
     virtual ~Led() {};
     
     /** Zdarzenie obs³uguj±ce malowanie kontrolki */ 
     void paintEvent(QPaintEvent * event);
     
     bool isChecked () const ; 
     
     
     QColor color() const; 
     void setColor(QColor); 
     
     public slots: 
     
     void setChecked(bool); 
     
     signals: 
     
     void checkChanged(bool val); 
     
     protected:
     
     /** Inicjuje uk³ad wspó³rzêdnych paintera */
     void initCoordinateSystem(QPainter & painter);
     
     /**
     * Maluje t³o kontrolki w tym przypadku pierwszy plan czyli odblask ¶wiat³a kontrolki
     * @param painter Przestrzeñ kontrolki 
     */
     void paintBackground(QPainter & painter);
    
     protected: 
     
     bool m_checked; 
     QColor m_color; 

   }; 
   
#endif // QLED_H 
