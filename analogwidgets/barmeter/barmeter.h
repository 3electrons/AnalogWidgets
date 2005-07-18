#ifndef BARMETER_H
#define BARMETER_H

#include <QWidget>
#include <QFont>

    class BarMeter : public QWidget
    {
        Q_OBJECT
	Q_PROPERTY (int minimum READ minimum WRITE setMinimum )
	Q_PROPERTY (int maximum READ maximum WRITE setMaximum )
	Q_PROPERTY (int value   READ value   WRITE setValue )
	Q_PROPERTY (QString prefix READ prefix WRITE setPrefix)
	Q_PROPERTY (QString suffix READ suffix WRITE setSuffix)
	Q_PROPERTY (bool simplified READ simplified  WRITE setSimplified)
	Q_PROPERTY (QFont valueFont READ valueFont   WRITE setValueFont)
	Q_PROPERTY (int valueOffset READ valueOffset WRITE setValueOffset)

    public:
    	BarMeter(QWidget *parent = 0);
	int  minimum() const   { return m_minimum; }
        void setMinimum(int i) { m_minimum = i; update(); }

        int  maximum() const   { return m_maximum; }
        void setMaximum(int i) { m_maximum = i; update(); }

        QString prefix() const    { return m_prefix;  }
        void setPrefix(QString s) { m_prefix = s; update(); }

        QString suffix() const    { return m_suffix;  }
        void setSuffix(QString s) { m_suffix = s; update(); }

	bool simplified() const	  { return m_simplified;        }
        void setSimplified(bool s){ m_simplified = s; update(); }

        int value() const         { return m_value;}

	QFont valueFont() const   { return m_valueFont;        }
	void setValueFont(QFont f){ m_valueFont = f; update(); }

	int valueOffset() const   { return m_valueOffset;       }
	void setValueOffset(int v){ m_valueOffset = v; update();}

    public slots:
       	void setValue(int val);

    signals:
    	void valueChanged(int val);


    protected:
        void paintEvent(QPaintEvent *event);

	int m_minimum;
	int m_maximum;
	int m_value;
	int m_valueOffset;
	QString m_prefix;
	QString m_suffix;
 	bool m_simplified;
	QFont m_valueFont;
    };
#endif // BARMETER_H
