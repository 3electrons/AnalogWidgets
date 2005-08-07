#ifndef QMYABSTRACTMETER_H
#define QMYABSTRACTMETER_H

#include <QtGui>

   /**
   * Klasa abstrakcyjna dla wszelkiego rodzaju kontrolek mirz±co wskazuj±cych
   * Zapewnia podstawowy interfejs do tego typu komponentów/ obiektów
   */
   class QMyAbstractMeter : public QObject
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

    	QMyAbstractMeter(QWidget *parent = 0);
	virtual ~QMyAbstractMeter() {};

	int  minimum() const   { return m_minimum; }
        void setMinimum(int i);
        int  maximum() const   { return m_maximum; }

        void setMaximum(int i);

        QString prefix() const    { return m_prefix;  }
        void setPrefix(QString s) { m_prefix = s; propertyUpdated(); }

        QString suffix() const    { return m_suffix;  }
        void setSuffix(QString s) { m_suffix = s; propertyUpdated(); }

        int value() const         { return m_value;}

	QFont valueFont() const   { return m_valueFont;        }
	void setValueFont(QFont f){ m_valueFont = f; propertyUpdated(); }

	int valueOffset() const   { return m_valueOffset;       }
	void setValueOffset(int v){ m_valueOffset = v; propertyUpdated();}

	int digitOffset() const   { return m_digitOffset;       }
	void setDigitOffset(int v){ m_digitOffset = v; propertyUpdated();}

	QFont digitFont() const   { return m_digitFont;         }
	void setDigitFont(QFont f){ m_digitFont = f; propertyUpdated();  }

	int nominal() const	  { return m_nominal; 		}
	void setNominal(int i)    { m_nominal = i; propertyUpdated();}

	int critical() const	  { return m_critical;		}
	void setCritical(int i)   { m_critical = i; propertyUpdated();}


    public slots:
       	void setValue(int val);


    signals:
    	void valueChanged(int val);

    protected:


	/** Metoda wywo³ywana podczas uaktualniania w³a¶ciwo¶ci */
	virtual void propertyUpdated() = 0;
        /**
         * Oblicza warto¶ci m_max oraz m_min wy¶wietlane na skali
	 * @return Warto¶æ true je¿eli która¶ ze zmiennych m_max lub m_min
	 * zosta³a uaktualniona.
	*/
	bool calcMaxMin();
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
   };// QMyAbstractMeter


#endif // _ABSTRACTMETER_H_
