    #include "test.h"
    #include <QFont>
    #include <QPushButton>
    #include <QSlider> 
    #include <QString> 
    #include "widgets/barmeter.h" 
    #include "widgets/wallclock.h"     

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
 
        // Layout of stack 1 widget 
	widget = stackedWidget->widget(1); 
	BarMeter * bar = new BarMeter(); 
	v_layout = new QVBoxLayout;
	v_layout->addWidget(bar_label); 
        v_layout->addWidget(bar);
	widget->setLayout(v_layout); 
	
	bar->setSuffix(QString(" [bar]")); 
		
 	connect(Hslider,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int))); 
        connect(spinBox,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int))); 

	Hslider->setMaximum(300); 
	spinBox->setMaximum(400); 

     
    } 	
    
    void TestWidget::connections()
    {
    
   
    }
    
    void TestWidget::closeEvent ( QCloseEvent * /* event */)
    {
      qApp->quit();       
    }
