#ifndef CHART_H
#define CHART_H

#include "qmywidgetwithbackground.h"

    class Chart : public QMyWidgetWithBackground
    {
      Q_OBJECT 
      public:
    	Chart(QWidget *parent = 0);
      protected:
        void paintEvent(QPaintEvent *event); 	 // inherited from QMyWidgetWithBackground 
	void paintBackground(QPainter & painter);// inherited form QMyWidgetWithBackground 
	void initCoordinateSystem(QPainter & painter);
    };
#endif // CHART_H
