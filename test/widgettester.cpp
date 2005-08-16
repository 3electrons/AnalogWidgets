#include "widgettester.h"
#include "widgets/qmyabstractmeter.h"


	WidgetTester::WidgetTester(QObject * parent,QMyAbstractMeter * meter):QObject(parent)
	{

	  m_meter = meter;

          int range = (m_meter ->maximum() - m_meter->minimum());
	  int inc_delay = 250;
          int dec_delay = 1000;
	  int stop_delay = 100;


          inc = range / (inc_delay / 5 );
	  dec = range / (dec_delay / 5 );

	  if (!inc) inc = 1;
          if (!dec) dec = 1;
          incTimer = new QTimer(parent);
	  decTimer = new QTimer(parent);
	  stopTimer = new QTimer(parent);
	  stopTimer->setInterval(stop_delay);
	  stopTimer->setSingleShot(true);

	 decTimer->setInterval(5);
	 connect(incTimer, SIGNAL(timeout()),this,SLOT(Increment()));
	 connect(stopTimer,SIGNAL(timeout()),decTimer,SLOT(start()));
	 connect(decTimer, SIGNAL(timeout()),this,SLOT(Decrement()));
        }

        void WidgetTester::start()
        {
	 m_meter->setValue(m_meter->minimum());
         incTimer->start(5);

        }

	void WidgetTester::Increment()
        {
	 m_meter->setValue(m_meter->value()+inc); // meter->value()+inc);
	 if (m_meter->value() > m_meter->maximum() )
         {
           incTimer->stop();
	   stopTimer->start();
         }

	}

	void WidgetTester::Decrement()
	{
	  m_meter->setValue(m_meter->value()-dec);
	 if (m_meter->value() < m_meter->minimum() )
	 {
           decTimer->stop();
	   m_meter->setValue(m_meter->minimum());
         }
	}
