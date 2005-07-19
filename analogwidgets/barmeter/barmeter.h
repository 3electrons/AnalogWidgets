#ifndef BARMETER_H
#define BARMETER_H

#include "qmywidgetwithbackground.h"

    class BarMeter : public QMyWidgetWithBackground
    {
        Q_OBJECT
	Q_PROPERTY (int minimum READ minimum WRITE setMinimum )
	Q_PROPERTY (int maximum READ maximum WRITE setMaximum )
	Q_PROPERTY (int value   READ value   WRITE setValue )
	Q_PROPERTY (QString prefix READ prefix WRITE setPrefix)
	Q_PROPERTY (QString suffix READ suffix WRITE setSuffix)
	Q_PROPERTY (QFont valueFont READ valueFont   WRITE setValueFont)
	Q_PROPERTY (int valueOffset READ valueOffset WRITE setValueOffset)
	Q_PROPERTY (QFont digitFont READ digitFont   WRITE setDigitFont)
	Q_PROPERTY (int digitOffset READ digitOffset WRITE setDigitOffset)
	Q_PROPERTY (int nominal READ nominal WRITE setNominal);
	Q_PROPERTY (int critical READ critical WRITE setCritical);


    public:
    	BarMeter(QWidget *parent = 0);

	int  minimum() const   { return m_minimum; }
        void setMinimum(int i)
	{
	  if (m_minimum != i && i < m_maximum )
	     {
	       m_minimum = i;
               calcMaxMin();
               updateWithBackground();
             }
	}
        int  maximum() const   { return m_maximum; }

        void setMaximum(int i)
        {
          if (m_maximum != i && i > m_minimum )
             {
                m_maximum = i;
		calcMaxMin();
                updateWithBackground();
 	     }

        }

        QString prefix() const    { return m_prefix;  }
        void setPrefix(QString s) { m_prefix = s; updateWithBackground(); }

        QString suffix() const    { return m_suffix;  }
        void setSuffix(QString s) { m_suffix = s; updateWithBackground(); }

        int value() const         { return m_value;}

	QFont valueFont() const   { return m_valueFont;        }
	void setValueFont(QFont f){ m_valueFont = f; updateWithBackground(); }

	int valueOffset() const   { return m_valueOffset;       }
	void setValueOffset(int v){ m_valueOffset = v; updateWithBackground();}

	int digitOffset() const   { return m_digitOffset;       }
	void setDigitOffset(int v){ m_digitOffset = v; updateWithBackground();}

	QFont digitFont() const   { return m_digitFont;         }
	void setDigitFont(QFont f){ m_digitFont = f; updateWithBackground();  }

	int nominal() const	  { return m_nominal; 		}
	void setNominal(int i)    { m_nominal = i; 		}

	int critical() const	  { return m_critical;		}
	void setCritical(int i)   { m_critical = i;		}


    public slots:
       	void setValue(int val);


    signals:
    	void valueChanged(int val);


    protected:
        void paintEvent(QPaintEvent *event);
	void paintBackground(QPainter & painter);
	void initCoordinateSystem(QPainter & painter);

	void calcMaxMin();
	/** Starting value on barometer */
	int m_min;
	/** Endgind value on barometer */
	int m_max;
	int m_minimum;
	int m_maximum;
	int m_value;
	int m_valueOffset;
	int m_digitOffset;
	int m_nominal;
	int m_critical;
	QString m_prefix;
	QString m_suffix;
 	QFont m_valueFont;
	QFont m_digitFont;
	
    };
#endif // BARMETER_H
