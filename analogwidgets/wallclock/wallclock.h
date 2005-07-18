#ifndef WALLCLOCK_H
#define WALLCLOCK_H

#include <QWidget>
#include <QFont>
#include <QVariant>
#include <QMetaProperty>

    class WallClock : public QWidget
    {
        Q_OBJECT
	Q_PROPERTY (QFont digitFont READ digitFont WRITE setDigitFont)
	Q_PROPERTY (QFont dateFont  READ dateFont  WRITE setDateFont)
	Q_PROPERTY (QFont timeFont  READ timeFont  WRITE setTimeFont)
	Q_PROPERTY (QFont dayFont   READ dayFont   WRITE setDayFont)

	Q_PROPERTY (int digitOffset READ digitOffset WRITE setDigitOffset) //RESET resetDigitOffset)
	Q_PROPERTY (int dateOffset  READ dateOffset  WRITE setDateOffset ) //RESET resetDateOffset )
	Q_PROPERTY (int timeOffset  READ timeOffset  WRITE setTimeOffset ) //RESET resetTimeOffset )
	Q_PROPERTY (int dayOffset   READ dayOffset   WRITE setDayOffset  ) //RESET resetDayOffset  )

	Q_PROPERTY (QColor digitColor READ digitColor WRITE setDigitColor)
	Q_PROPERTY (QColor dateColor  READ dateColor  WRITE setDateColor)
	Q_PROPERTY (QColor timeColor  READ timeColor  WRITE setTimeColor)
	Q_PROPERTY (QColor dayColor   READ dayColor   WRITE setDayColor)


    public:
	WallClock(QWidget *parent = 0);
	~WallClock();

    	QFont digitFont() const    { return m_digitFont;}
  	QFont timeFont () const    { return m_timeFont; }
    	QFont dateFont () const    { return m_dateFont; }
    	QFont dayFont  () const    { return m_dayFont;  }

    	void setDigitFont(QFont f) {        m_digitFont = f; update();}
    	void setTimeFont (QFont f) {        m_timeFont  = f; update();}
    	void setDateFont (QFont f) {        m_dateFont  = f; update();}
	void setDayFont  (QFont f) {        m_dayFont   = f; update();}

	int     digitOffset () const { return m_digitOffset; }
	int      dateOffset () const { return m_dateOffset;  }
	int      timeOffset () const { return m_timeOffset;  }
	int      dayOffset  () const { return m_dayOffset;   }
	void  setDigitOffset(int i)  {        m_digitOffset = i; update();}
	void  setDateOffset (int i)  {        m_dateOffset  = i; update();}
	void  setTimeOffset (int i)  {        m_timeOffset  = i; update();}
	void  setDayOffset  (int i)  {        m_dayOffset   = i; update();}

	QColor    digitColor() const  { return m_digitColor;   }
	QColor    dateColor() const   { return m_dateColor;    }
	QColor    timeColor() const   { return m_timeColor;    }
	QColor    dayColor()  const   { return m_dayColor;     }

	void   setDigitColor(QColor c){        m_digitColor = c; update();}
	void   setDateColor(QColor c) {        m_dateColor = c;  update();}
	void   setTimeColor(QColor c) {        m_timeColor = c;  update();}
	void   setDayColor (QColor c) {        m_dayColor  = c;  update();}



    protected:


        void paintEvent(QPaintEvent *event);
	void paintBackground(QPainter & painter, const QBrush & background);
	void initCoordinateSystem(QPainter & painter);


	int resetDigitOffset() const { return 75; }
	int resetDateOffset()  const { return 0;  }
	int resetTimeOffset()  const { return -12;}
	int resetDayOffset()   const { return 29; }


        QFont m_digitFont;
        QFont m_dateFont;
        QFont m_timeFont;
        QFont m_dayFont;

        int   m_digitOffset;
        int   m_dateOffset;
        int   m_timeOffset;
        int   m_dayOffset;

        QColor m_digitColor;
        QColor m_dateColor;
        QColor m_timeColor;
        QColor m_dayColor;
	QPixmap * pixmap;
    };
#endif // WALLCLOCK_H
