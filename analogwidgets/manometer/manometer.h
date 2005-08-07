#ifndef BARMETER_H
#define BARMETER_H

#include "qmywidgetwithbackground.h"
#include "qmyabstractmeter.h"

    class ManoMeter : public QMyWidgetWithBackground, QMyAbstractMeter
    {
        Q_OBJECT

    public:
    	ManoMeter(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *event);
	void paintBackground(QPainter & painter);
	void initCoordinateSystem(QPainter & painter);
    };
#endif // BARMETER_H
