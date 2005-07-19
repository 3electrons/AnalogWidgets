    #include <QtGui>
    #include <math.h>
    #include "wallclock.h"
    #define PI 3.141592653589793238512808959406186204433

    WallClock::WallClock(QWidget *parent)
        : QMyWidgetWithBackground(parent)
    {
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);


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
        setWindowTitle(tr("Analog Clock"));
        resize(220, 220);
    }

    void WallClock::initCoordinateSystem(QPainter & painter)
    {
        int side = qMin(width(), height());
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 220.0, side / 220.0);
    }

    void WallClock::paintBackground(QPainter & painter)
    {

        initCoordinateSystem(painter);
        // Malowanie obwiedni tarczy.

        QLinearGradient linearGrad(QPointF(-100, -100), QPointF(0, 0));
	linearGrad.setSpread(QGradient::ReflectSpread);
        linearGrad.setColorAt(0, Qt::black);
        linearGrad.setColorAt(1, QColor(232,232,232));

        QPen Pen(Qt::black);
        Pen.setWidth(1);
        painter.setPen(Pen);

	// Koperta zegark
        painter.setBrush(QBrush(linearGrad));
        painter.drawEllipse(-109,-109,218,218);
        painter.setBrush(QBrush(Qt::white));
        painter.drawEllipse(-102,-102,204,204);


        painter.setBrush(Qt::black);
        // rysowanie kó³ek godzin i samych godzin
        for (int i = 0; i < 12; ++i) {
            painter.drawEllipse(94, -2, 4, 4);
            painter.rotate(30.0);
        }


	// rysowanie kresek  minut
        painter.setPen(Qt::black);
	Pen.setWidth(2);
	painter.setPen(Pen);
        for (int j = 0; j < 60; ++j) {
            if ((j % 5) != 0)
                painter.drawLine(94, 0, 97, 0);
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

    }// paintBackground


    void WallClock::paintEvent(QPaintEvent *)
    {
        static const int hourHand[8] = { -2, 18, 2, 18, 2, -60, -2, -60 };
        static const int minuteHand[8] = { -2, 28, 2, 28, 2, -80, -2, -80 };
        static const int secondHand[12] = {-1, 0, -1, -90, 1,-90, 1, 0, 4, 35, -4, 35};
        
        // odmalowywuje t³o 
        doUpdateBackground(); 
	 // inicjalizacja paintera
	
	QPainter painter(this);
        initCoordinateSystem(painter);
        
        // Wyliczanie czasu i daty
        QTime time = QTime::currentTime();
        QDate date = QDate::currentDate();
	QString Str;
	QSize Size;

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
        painter.setBrush(Qt::black);
        painter.save();
        painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
        painter.drawConvexPolygon(QPolygon(4, hourHand));
        painter.restore();

        // rysowanie minutnika
        painter.setBrush(Qt::black);
        painter.save();
        painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
        painter.drawConvexPolygon(QPolygon(4, minuteHand));
        painter.restore();

        // Malowanie wskazówki sekundnika
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::red);
        painter.save();
        painter.rotate(6.0 * ( time.second())); //  + time.msec() / 1000.0) );
        painter.drawConvexPolygon(QPolygon(6, secondHand));
        painter.restore();
	// Kó³ko sekundnika
        painter.drawEllipse(-5,-5,10,10);
    }
    
    
