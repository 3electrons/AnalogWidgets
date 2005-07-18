    #include <QtGui>
    #include <math.h>
    #include "wallclock.h"
    #define PI 3.141592653589793238512808959406186204433

    WallClock::WallClock(QWidget *parent)
        : QWidget(parent)
    {
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);

        setWindowTitle(tr("Analog Clock"));
        resize(200, 200);

        setDigitOffset(75);
	setDateOffset(0);
	setTimeOffset(-12);
	setDayOffset(9);



        setDigitColor(QColor(0,0,0));
        setDateColor(QColor(0,0,0));
        setTimeColor(QColor(0,0,192));
        setDayColor(QColor(0,96,0));

        m_digitFont.setPointSize(23);
        m_dateFont.setPointSize(21);
        m_timeFont.setPointSize(30);
        m_dayFont.setPointSize(16);

	// QWidget
        setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);

    }

    void WallClock::paintEvent(QPaintEvent *)
    {
        static const int hourHand[8] = { -2, 18, 2, 18, 2, -60, -2, -60 };
        static const int minuteHand[8] = { -2, 28, 2, 28, 2, -80, -2, -80 };
        static const int secondHand[12] = {-1, 0, -1, -90, 1,-90, 1, 0, 4, 35, -4, 35};
        QColor hourColor(0, 0, 0);
        QColor minuteColor(0, 0, 0);
        QColor secondColor(255,0,0);
        //QColor timeColor(0,131,255);

        int side = qMin(width(), height());
        QTime time = QTime::currentTime();
        QDate date = QDate::currentDate();

        // inicjalizacja paintera
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 207.0, side / 207.0);

        // Malowanie obwiedni tarczy.

        QLinearGradient linearGrad(QPointF(-100, -100), QPointF(204, 204));
        linearGrad.setColorAt(0, Qt::black);
        linearGrad.setColorAt(1, Qt::white);

        QBrush Brush(linearGrad);
        //Brush.setColor(Qt::white);
        //Brush.setStyle(Qt::SolidPattern);
        QPen Pen; Pen.setWidth(2); Pen.setColor(hourColor);
        painter.setPen(Pen);

        painter.setBrush(Brush);
        painter.drawEllipse(-102,-102,204,204);

        painter.setPen(Qt::NoPen);
        painter.setBrush(hourColor);
        // rysowanie kó³ek godzin i samych godzin
        for (int i = 0; i < 12; ++i) {
            painter.drawEllipse(94, -2, 4, 4);
            painter.rotate(30.0);
        }

        // rysowanie kresek  minut
        painter.setPen(minuteColor);
        for (int j = 0; j < 60; ++j) {
            if ((j % 5) != 0)
                painter.drawLine(95, 0, 98, 0);
            painter.rotate(6.0);
        }

	QSize Size;
	QString Str;
        // Rysowanie cyfr na tarczy
        if (digitOffset()!=0.0)
        {
          painter.setFont(digitFont());
          painter.setPen(digitColor());
	  for ( int z = 1; z <= 12; ++z) {
            QString hour = QString("%1").arg(z);
            Size = painter.fontMetrics().size(Qt::TextSingleLine, hour);
            painter.save();
            painter.translate(digitOffset() * cos(PI*z/6.0-PI/2.0),digitOffset() * sin(PI*z/6.0-PI/2.0));
            painter.setPen(digitColor());
            painter.drawText( Size.width()/ -2, Size.height() / 4, hour);
            painter.restore();
          }
        }
        if (timeOffset()!=0.0)
        {
          // Rysowanie tekstów - godziny
          painter.setFont(timeFont());
          painter.setPen(timeColor());
          Str = time.toString("hh:mm");
          Size = painter.fontMetrics().size(Qt::TextSingleLine, Str );
          painter.drawText( Size.width() / -2, Size.height()+ timeOffset() ,Str);
        }

        if (dateOffset()!=0.0)
        {
          // Rysowanie daty
          painter.setFont(dateFont());
          painter.setPen(dateColor());
          Str = date.toString("dd.MM.yyyy");
          Size = painter.fontMetrics().size(Qt::TextSingleLine, Str);
          painter.drawText( Size.width() / -2,static_cast<int>(0 - dateOffset()), Str);
        }
        if (dayOffset()!=0.0)
        {
          // Dzieñ tygodnia
          painter.setFont(dayFont());
          painter.setPen(dayColor());
          Str =  date.toString("dddd");
          Size = painter.fontMetrics().size(Qt::TextSingleLine, Str);
          painter.drawText( Size.width() / -2,static_cast<int>( 0 - dayOffset()) , Str);
        }

        // rysowanie wskazówki godzin
        painter.setPen(Qt::NoPen);
        painter.setBrush(hourColor);
        painter.save();
        painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
        painter.drawConvexPolygon(QPolygon(4, hourHand));
        painter.restore();

        // rysowanie minutnika
        painter.setBrush(minuteColor);
        painter.save();
        painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
        painter.drawConvexPolygon(QPolygon(4, minuteHand));
        painter.restore();

        // Malowanie wskazówki sekundnika
        painter.setPen(Qt::NoPen);
        painter.setBrush(secondColor);
        painter.save();
        painter.rotate(6.0 * ( time.second())); //  + time.msec() / 1000.0) );
        painter.drawConvexPolygon(QPolygon(6, secondHand));
        painter.restore();
        painter.drawEllipse(-5,-5,10,10);
    }

