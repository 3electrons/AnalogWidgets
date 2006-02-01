
    #include "test.h"
    #include <QFont>
    #include <QPushButton>
    #include <QSlider>
    #include <QString>
    #include <QTimer>

    #include "manometer/manometer.h"
    #include "wallclock/wallclock.h"
    #include "thermometer/thermometer.h"
    #include "chart/chart.h"
    #include "chart/datacontainers.h"


    #include "widgettester.h"

    #include <iostream>
    #include <fstream>
    #include <list>
    #include <vector>
    //#include <pair>

    using namespace std;

    typedef vector<int> vint;
    typedef list <int>  lint;
    typedef list <double> ldouble;
    typedef list< pair<double,double> > lpair;

    lpair position;
    vint  velocity;
    vint  times;
    lint  press1;
    lint  press2;
    ldouble press3;

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

	// Layout of stack 3 widget - chart
	widget = stackedWidget->widget(3);
	chart = new Chart();
	QLayout * layout3 = new QVBoxLayout();
	layout3->addWidget(chart_lab);
	layout3->addWidget(chart);
        QLayout * wert = new QHBoxLayout(); 
        wert->addWidget(chartPosition); 
        wert->addWidget(zoomBox); 
	layout3->addItem(wert);
	layout3->addWidget(sizeSlider);
	layout3->addWidget(injCombo);
	widget->setLayout(layout3);

 // za³adowanie listy wtrysków do CobmboBox'a
        QDir dir("wtr");
        dir.setFilter(QDir::Files);
	dir.setSorting(QDir::Name);
        dir.setNameFilters ( QStringList(QString("*.wtr")) );
	injCombo->addItems(dir.entryList());
// Zainicjowanie danymi obiektu typu chart

	QPen vPen;
	vPen.setColor(Qt::red);
   	vPen.setWidthF(2.0);
	vPen.setColor(Qt::green);
        Channel cisnienie2 (0,350,new DoubleDataContainer<vint,lint>(times,press2),
			   "[bar] Ci¶nienie pod t³okiem",vPen);
	vPen.setColor(Qt::magenta);
        Channel cisnienie3 (0,350,new DoubleDataContainer<vint,ldouble>(times,press3),
			   "[bar] Ci¶nienie wyliczone",vPen);
	vPen.setColor(Qt::cyan);
	Channel cisnienie (0,350,new DoubleDataContainer<vint,lint>(times,press1),
			   "[bar] Ci¶nienie nad t³okiem",vPen);
	vPen.setColor(Qt::yellow);
        Channel pozycja(0,230,new PairDataContainer<lpair>(position),
			  "[mm] Pozycja",vPen);
	//vPen.setStyle(Qt::DashDotLine);
	vPen.setColor(Qt::red);
        Channel predkosc  (0,300, new DoubleDataContainer<vint,vint>(times,velocity),
			  "[cm/s] Prêdko¶æ",vPen) ;//QPen(Qt::red));


        cisnienie2.showScale = cisnienie3.showScale = false;
	//pozycja.showScale = predkosc.showScale = false ;
	//chart->scaleGrid().showScale=false;
	//chart->scaleGrid().showGrid=false;
	chart->addChannel(cisnienie2);
	chart->addChannel(cisnienie3);
	chart->addChannel(cisnienie);
	chart->addChannel(pozycja);
	chart->addChannel(predkosc);




//
 	//connect(HSlider,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));
        //connect(spinBox,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));
	connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(SpinBoxValueChanged(int)));
	connect(comboBox,SIGNAL(activated(int)),this,SLOT(ComboBoxChoiceChanged(int)));
	connect(pushButton,SIGNAL(clicked(void)),this,SLOT(WidgetTest(void)));
	connect(chartPosition,SIGNAL(valueChanged(int)),this,SLOT(movePosition(int)));
	connect(sizeSlider,SIGNAL(sliderMoved(int)),this,SLOT(setSize(int)));
	connect(injCombo, SIGNAL(activated( const QString & )), this,SLOT(loadInjection(const QString& ))) ;
	connect(zoomBox,SIGNAL(valueChanged(double)),chart,SLOT(setZoom(double))); 
	HSlider->setMaximum(1000);
	HSlider->setMinimum(-1000);
	spinBox->setMaximum(1000);
	spinBox->setMinimum(-1000);
	ComboBoxChoiceChanged(comboBox->currentIndex());
    }

    void TestWidget::movePosition(int val)
    {
     // cout<<"Position:"<<val<<endl;
      chart->setPosition(val);
    }
    void TestWidget::setSize(int val)
    {
      chart->setSize(val);
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

  void TestWidget::loadInjection(const QString &  file )
    {
        char buffer[1024];
	std::string f("wtr/");
	 f+=file.toLocal8Bit().data() ;
	fstream filein(f.data());
        if (!filein.good())
         {
            cout<<"Nie udane otwarcie pliku:"<<f<<endl;
            return;
         }

	for (int i=0;i<11;i++)
        {
           filein.getline(buffer,1023,'\n'); // pominiecie nag³ówka
           //cout<<buffer<<endl;
         }
	double pos,vel,p1,p2,p3;
	times.clear(); // vint
	velocity.clear(); // vint
 	press1.clear(); // vint;
        press2.clear();
	press3.clear();
	position.clear(); //lpair
        int time = 0;
        while (!filein.eof())
        {
          filein>>pos;
          filein>>p3;
          filein>>p1;
          filein>>p2;
          filein>>vel;
          times.push_back(time);
          position.push_back( pair<double,double>(time,pos));
	  velocity.push_back(vel);
	  press1.push_back(p1);
	  press2.push_back(p2);
	  press3.push_back(p3);


          //filein>>buffer;
         // cout<<time<<"  p:"<<pos<<" v:"<<vel<<" p1:"<<p1<<endl; //" "<<p2<<" "<<p3<<endl;
	  ++time;
        }
        chart->update();
    }

    void TestWidget::closeEvent ( QCloseEvent * /* event */)
    {
      qApp->quit();
    }
