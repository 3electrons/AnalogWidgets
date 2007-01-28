#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "abstractmeter.h"

    class ThermoMeter : public AbstractMeter
    {
      Q_OBJECT 
      public:
    	ThermoMeter(QWidget *parent = 0);
      protected:
        void paintEvent(QPaintEvent *event); 	  // inherited form WidgetWithBackground
	void paintBackground(QPainter & painter); // inherited form WidgetWithBackground
	void initCoordinateSystem(QPainter & painter);
    };
#endif // THERMOMETER_H
