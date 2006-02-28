#ifndef QMYABSTRACTMETER_H
#define QMYABSTRACTMETER_H

#include "qmywidgetwithbackground.h"

   /**
   * Klasa abstrakcyjna dla wszelkiego rodzaju kontrolek mirz±co wskazuj±cych
   * Zapewnia podstawowy interfejs do tego typu komponentów/ obiektów
   */
   class QMyAbstractMeter : public QMyWidgetWithBackground
   {
	// @TODO zrobiæ szablon by mo¿na te¿ by³o pu¿ywaæ typu double dla dok³adych wskazañ
	Q_OBJECT
	Q_PROPERTY (double minimum READ minimum WRITE setMinimum )
	Q_PROPERTY (double maximum READ maximum WRITE setMaximum )
	Q_PROPERTY (double value   READ value   WRITE setValue )
	Q_PROPERTY (double nominal READ nominal WRITE setNominal);
	Q_PROPERTY (double critical READ critical WRITE setCritical);

	Q_PROPERTY (QString prefix READ prefix WRITE setPrefix)
	Q_PROPERTY (QString suffix READ suffix WRITE setSuffix)
	Q_PROPERTY (QFont valueFont READ valueFont   WRITE setValueFont)
	Q_PROPERTY (double valueOffset READ valueOffset WRITE setValueOffset)
	Q_PROPERTY (QFont digitFont READ digitFont   WRITE setDigitFont)
	Q_PROPERTY (double digitOffset READ digitOffset WRITE setDigitOffset)


    public:

    	QMyAbstractMeter(QWidget *parent = 0);
	virtual ~QMyAbstractMeter() {};

	double  minimum() const   { return m_minimum; }
        void setMinimum(double i);
        double  maximum() const   { return m_maximum; }
        void setMaximum(double i);
        double value() const         { return m_value;}

	double nominal() const	  { return m_nominal; 		}
	void setNominal(double i)    { m_nominal = i; updateWithBackground();}
	double critical() const	  { return m_critical;		}
	void setCritical(double i)   { m_critical = i; updateWithBackground();}

	QFont valueFont() const   { return m_valueFont;        }
	void setValueFont(QFont f){ m_valueFont = f; updateWithBackground(); }

	double valueOffset() const   { return m_valueOffset;       }
	void setValueOffset(double v){ m_valueOffset = v; updateWithBackground();}

	double digitOffset() const   { return m_digitOffset;       }
	void setDigitOffset(double v){ m_digitOffset = v; updateWithBackground();}

	QFont digitFont() const   { return m_digitFont;         }
	void setDigitFont(QFont f){ m_digitFont = f; updateWithBackground();  }

        QString prefix() const    { return m_prefix;  }
        void setPrefix(QString s) { m_prefix = s; updateWithBackground(); }

        QString suffix() const    { return m_suffix;  }
        void setSuffix(QString s) { m_suffix = s; updateWithBackground(); }

    public slots:
       	void setValue(int val);
        void setValue(double val); 
    signals:
    	void valueChanged(int val);
    	void valueChanged(double val);

    protected:

       /**
         * Oblicza warto¶ci m_max oraz m_min wy¶wietlane na skali
	 * @return Warto¶æ true je¿eli która¶ ze zmiennych m_max lub m_min
	 * zosta³a uaktualniona.
	 */
	bool calcMaxMin();
	/** Starting value on barometer */
	double m_min;
	/** Endgind value on barometer */
	double m_max;
	double m_minimum;
	double m_maximum;
	double m_value;
	double m_nominal;
	double m_critical;

	double m_valueOffset;
	double m_digitOffset;
 	QFont m_valueFont;
	QFont m_digitFont;
	QString m_prefix;
	QString m_suffix;

   };// QMyAbstractMeter

#endif // _ABSTRACTMETER_H_
