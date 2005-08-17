#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "qmyabstractmeter.h"

    class ThermoMeter : public QMyAbstractMeter
    {
      Q_OBJECT 
      public:
    	ThermoMeter(QWidget *parent = 0);
      protected:
        void paintEvent(QPaintEvent *event); 	  // inherited form QMyWidgetWithBackground
	void paintBackground(QPainter & painter); // inherited form QMyWidgetWithBackground
	void initCoordinateSystem(QPainter & painter);
    };
#endif // THERMOMETER_H
