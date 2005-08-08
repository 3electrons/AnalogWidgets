    #include "test.h"
    #include <QFont>
    #include <QPushButton>
    #include <QSlider>
    #include <QString>
    #include "widgets/manometer.h"
    #include "widgets/wallclock.h"
    #include "widgets/thermometer.h"


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
 	layout->addWidget(frame);
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
	connect(spinBox,SIGNAL(valueChanged(int)),thermo,SLOT(setValue(int)));

	HSlider->setMaximum(1000);
	HSlider->setMinimum(-1000);
	spinBox->setMaximum(1000);
	spinBox->setMinimum(-1000);
	ComboBoxChoiceChanged(comboBox->currentIndex());
    }

    void TestWidget::ComboBoxChoiceChanged(int index)
    {
      int val=0;
      switch (index)
      {
       case 0: val = bar->value(); break;
       case 1: val = bar->minimum(); break;
       case 2: val = bar->maximum(); break;
       case 3: val = bar->nominal(); break;
       case 4: val = bar->critical(); break;
       case 5: val = bar->digitOffset(); break;
       case 6: val = bar->valueOffset(); break;
      }
       spinBox->setValue(val);
    }

    void TestWidget::SpinBoxValueChanged(int val)
    {
      switch (comboBox->currentIndex())
      {
        case 0:  bar->setValue(val); break;
        case 1:  bar->setMinimum(val); break;
        case 2:  bar->setMaximum(val); break;
        case 3:  bar->setNominal(val); break;
        case 4:  bar->setCritical(val); break;
        case 5:  bar->setDigitOffset(val); break;
        case 6:  bar->setValueOffset(val); break;
      }
    }

    void TestWidget::connections()
    {


    }

    void TestWidget::closeEvent ( QCloseEvent * /* event */)
    {
      qApp->quit();
    }
