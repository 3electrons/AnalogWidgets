#ifndef WIDGETTESTER_H
#define WIDGETTESTER_H
 #include <QtCore>
 class QMyAbstractMeter;

    class WidgetTester: public QObject
    {
      Q_OBJECT

      QMyAbstractMeter * m_meter;
      QTimer  * incTimer, * decTimer, *stopTimer;
      int inc;
      int dec;
     public:
	WidgetTester(QObject * parent,QMyAbstractMeter * meter);

        void start();

	private slots:
	void Increment();

	void Decrement();
    };//
#endif // WIDGETTESTER_H
