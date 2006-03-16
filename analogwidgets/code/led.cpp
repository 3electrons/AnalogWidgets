#include <QtGui> 
#include "led.h" 


     Led::Led(QWidget * parent):QMyWidgetWithBackground(parent)
     {
        m_checked = true; 
        m_color = Qt::red; 
        resize(330,330);      
     }
     
     
     bool Led::isChecked () const 
     {
       return m_checked; 
     }
     
     
     void Led::setChecked(bool i) 
     {
       m_checked = i; 
       updateWithBackground();
       checkChanged( m_checked ); 
     }
     
     
     QColor Led::color() const
     {
       return m_color; 
     }
     
     
     void Led::setColor(QColor i)
     { 
       m_color = i; 
       updateWithBackground(); 
     }
     
     // Maluje ca³± diodê - ko³o o kolorze bazowym a na to nak³ada odblask. 
     void Led::paintEvent(QPaintEvent * /* event*/ )
     {
       QPainter painter(this); 
       initCoordinateSystem(painter); 
       // *** Draw circle */ 
       int h,s,v,a; 
       QColor c,back = color(); 
       c=back; 
       
       // Kolor diody 
       if (!m_checked || !isEnabled()) 
       { 
         back.getHsv(&h,&s,&v,&a);
         s*=0.20; 
         back.setHsv(h,s,v,a); 
        }
       painter.setBrush(back); 
       
       // obwudka diody 
       QPen pen;
       // przyciemnienie obwudki 
       c.getHsv(&h,&s,&v,&a); 
       s*=0.5; 
       c.setHsv(h,s,v,a);  

       pen.setColor(c); 
       pen.setWidthF(3.0); 
          
       painter.drawEllipse(-149,-149,299,299);
       painter.end(); 
       
       // odblask ¶wiat³a diody 
       drawBackground(); // to maluje na tym co dotychczas to co jest w bitmapce 
     }


     // Rysuje odblask swiat³a na diodzie 
     void Led::paintBackground(QPainter & painter)
     {
        initCoordinateSystem(painter); 
        painter.setPen(Qt::NoPen); 
        QRadialGradient shine(QPointF(-40.0,-40.0),120.0,QPointF(-40,-40));
        QColor white1(255,255,255,200);
        QColor white0(255,255,255,0);
        
        shine.setColorAt(0.0,white1); 
        shine.setColorAt(1.0,white0); 
        
        painter.setBrush(shine); 
        painter.drawEllipse(-147,-147,297,297); 
             
     }
     
     void Led::initCoordinateSystem(QPainter & painter)
     {
       int side = qMin(width(), height());
        // inicjalizacja paintera
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 330.0, side / 330.0);
     }
     
     
