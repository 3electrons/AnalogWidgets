    #include "test.h"
    #include <QFont>
    #include <QPushButton>
    #include <QSlider>
    #include <QString>
    #include <QTimer>
    #include "widgets/manometer.h"
    #include "widgets/wallclock.h"
    #include "widgets/thermometer.h"

    #include "widgettester.h"



// ----------------------------------------------------------------------------------------

    TestWidget::TestWidget(QMainWindow *parent)
        : QMainWindow(parent)
    {
        initialize ();
 	connections();
    }

    void TestWidget::initialize()
    {
	setupUi(this);
	setWindowTitle(QString("Program testowy dla AnalogWidgets"));
	setWindowFlags(Qt::Window);
  	setGeometry(50,50,400, 320);

        // Ustawianie LayOut'ów
	QWidget * widget = stackedWidget->widget(0);
        // Layout of stack 0 widget
	WallClock * clock = new WallClock();
        QVBoxLayout *v_layout = new QVBoxLayout;
        v_layout->addWidget(clock_lab);
        v_layout->addWidget(clock);
	widget->setLayout(v_layout);

         // Layout of stack 1 widget - manometer

	widget = stackedWidget->widget(1);
	bar = new ManoMeter(widget);
	bar->resize(120,120);
	QLayout * layout = new QVBoxLayout();
	layout->addWidget(bar_label);
        layout->addWidget(bar);
 	widget->setLayout(layout);

	// Layout if stack 2 widget - thermometer

	widget = stackedWidget->widget(2);
	thermo = new ThermoMeter();
	thermo->resize(10,100);
	QLayout * layout2 = new QVBoxLayout();
	layout2->addWidget(thermo_lab);
	layout2->addWidget(thermo);
	widget->setLayout(layout2);

 	//connect(HSlider,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));
        //connect(spinBox,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));
	connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(SpinBoxValueChanged(int)));
	connect(comboBox,SIGNAL(activated(int)),this,SLOT(ComboBoxChoiceChanged(int)));
	connect(pushButton,SIGNAL(clicked(void)),this,SLOT(WidgetTest(void)));

	HSlider->setMaximum(1000);
	HSlider->setMinimum(-1000);
	spinBox->setMaximum(1000);
	spinBox->setMinimum(-1000);
	ComboBoxChoiceChanged(comboBox->currentIndex());
    }


    void TestWidget::ComboBoxChoiceChanged(int index)
    {
      int val=0;
      QMyAbstractMeter * meter = bar;
      if (stackedWidget->currentIndex() == 2) meter = thermo;

      switch (index)
      {
       case 0: val = meter->value(); break;
       case 1: val = meter->minimum(); break;
       case 2: val = meter->maximum(); break;
       case 3: val = meter->nominal(); break;
       case 4: val = meter->critical(); break;
       case 5: val = meter->digitOffset(); break;
       case 6: val = meter->valueOffset(); break;
      }
       spinBox->setValue(val);
    }

    void TestWidget::SpinBoxValueChanged(int val)
    {
      QMyAbstractMeter * meter = bar;
      if (stackedWidget->currentIndex() == 2) meter = thermo;

      switch (comboBox->currentIndex())
      {
        case 0:  meter->setValue(val); break;
        case 1:  meter->setMinimum(val); break;
        case 2:  meter->setMaximum(val); break;
        case 3:  meter->setNominal(val); break;
        case 4:  meter->setCritical(val); break;
        case 5:  meter->setDigitOffset(val); break;
        case 6:  meter->setValueOffset(val); break;
      }
    }
    void TestWidget::WidgetTest()
    {
	QMyAbstractMeter * meter;
	switch (stackedWidget->currentIndex())
	{
	  case 1: meter = bar; break;
	  case 2: meter = thermo;break;
	  default: meter = NULL ; return;
        }
	WidgetTester * tester = new WidgetTester(this,meter);
	tester->start();
    }

    void TestWidget::connections()
    {


    }

    void TestWidget::closeEvent ( QCloseEvent * /* event */)
    {
      qApp->quit();
    }
