#ifndef BARMETER_H
#define BARMETER_H

#include "qmyabstractmeter.h"

    class ManoMeter : public QMyAbstractMeter
    {
      public:
    	ManoMeter(QWidget *parent = 0);
      protected:
        void paintEvent(QPaintEvent *event); 	 // inherited from QMyWidgetWithBackground 
	void paintBackground(QPainter & painter);// inherited form QMyWidgetWithBackground 
	void initCoordinateSystem(QPainter & painter);
    };
#endif // BARMETER_H
