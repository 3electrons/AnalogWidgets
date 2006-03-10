#include <QtGui> 
#include <iostream>

#include "defines.h"
#include "mnemonicbox.h"
#include "comm/engine.h" // z Bartkom/src/comm/


using namespace std; 
using namespace comm; 

//#define READ 0x0
//..#define WRITE 0x1



/** 
* Ustawia tryb designMode lub nie jest domyslnie zerem 
*/ 
bool set = false; 
bool & designMode(bool val=false,bool modify=false)
{
  static bool mode;
  if (!set && !modify ) { mode = false; set = true ; }  
  if (modify) { mode = val; set = true ; }   
  
  return mode; 
}


/** 
* Pobiera wartos� mnemonika - w zale�no�ci od tego czy jest w trybie 
* projektowania czy aplikacji rzuca wyjatek lub wpisuje go na standardowe wyj�cie 
*/ 
common::Value bridgeValue(protocols::MnemonicBridge * bridge) 
{
  common::Value v("");
  try
  {
    v = bridge->value(); 
    usleep(2000); 
  }
  catch (comm_error & e)
  {
    string s = bridge->property("name");
    s+=" "; s+=e.what(); 
    common::log()<<"* Communication error:"<<s<<endl;
    QMessageBox::critical(NULL,"Blad odczytu",s.c_str()); 
    v = bridge->lastValue(); 
  }
  return v.str(); 
}


/** 
* Ustawia wartos� mnemonika - w zale�no�ci od tego czy jest w trybie 
* projektowania czy aplikacji rzuca wyjatek lub wpisuje go na standardowe wyj�cie 
*/ 


bool setBridgeValue(common::Value & v , protocols::MnemonicBridge * bridge)
{
  bool status = false; 
  try
  {
    bridge->setValue(v.str());
    status = true; 
  }
  catch (exception & e) 
  {
    string s = bridge->property("name");
    s+=" "; s+=e.what(); 
    common::log()<<"* Communication error:"<<s<<endl;
    QMessageBox::critical(NULL,"Blad zapisu",s.c_str()); 
    v = bridge->lastValue(); 
  }
  return status; 
}

mnemonic_map MnemonicBox::widgets; 

MnemonicBox::MnemonicBox(QWidget * parent) : QWidget(parent)
{
  m_type = none; 
  m_mnemonicname = QString("mnemonic"); 
  m_isVisible = true; 
  m_widget = NULL; 
  m_bridge = NULL; 
  m_readOnly = true; 
  initWidget();          
}

MnemonicBox::~MnemonicBox()
{
  clean();
}


void MnemonicBox::setServer  (QString value)
{
   comm::ReinitEngine( value.toLocal8Bit().data() );
   if (none==m_type)
   {
      MnemonicBox * box;
      mnemonic_map::iterator i=widgets.begin();
      while (i!=widgets.end())
      {
        box = (*i).second; 
        //cout<<"Box:"<<box<<endl; 
        if (box)
        if ( none==box->m_type) box->initChildComponent();
        i++; 
      }
      
     // initChildComponent(); 
   }
}

QString MnemonicBox::server   ()
{
  QString Str ( comm::EngineConfigFile().c_str()); 
  return Str; 
}

void MnemonicBox::initChildComponent()
{
  initBridge();
  initWidget();          
}// initChildComponent  
 
void MnemonicBox::initBridge()
{
  if (m_bridge) 
  { 
    delete m_bridge; 
    m_bridge = NULL; 
    m_type = none;
  }
    
  try
  {
     m_bridge = CreateMnemonicBridge(m_mnemonicname.toLocal8Bit().data()); 
     string type = m_bridge->property("type");
     common::Value v = m_bridge->property("readonly"); 
     //cout<<"ReadOnly:"<<v.str()<<endl; 
     m_readOnly = v; 
     char *types[]={"int","double","bool"}; 
     int  m_types[]={int_t,double_t,bool_t}; 
     for (int i=0;i<3;i++)
     if (type==types[i]) m_type = m_types[i]; 
  }
  catch (exception & e)
  {
     common::log()<<"FAIL - init menmonicbox "<<m_mnemonicname.toLocal8Bit().data()<<" error:"<<e.what()<<endl; 
  } 
}// initBridge 

void MnemonicBox::initWidget()
{
    
    // Pozyskanie layout'u 
    QLayout * layout = this->layout();
    if (NULL==layout)
    {
      layout = new QHBoxLayout(); 
      layout->setMargin(0);
      layout->setSpacing(0);       
      setLayout(layout);
    }
     
     
    // zgrabne usuni�cie starego widgetu je�eli istnieje  
     if (m_widget)
     {
       layout->removeWidget(m_widget);
       m_widget->disconnect(); // roz��cza wszystkie sygna�y 
       delete m_widget; 
       m_widget = NULL; 
     }
      
     // utworzenie nowego widgetu  
     try 
     {
      switch (m_type)
      { 
         case int_t    : intType()    ; break;
         case double_t : doubleType() ; break; 
         case bool_t   : boolType()   ; break; 
         case none     : noneType()   ; break; 
       }
     }
     // usuni�cie nieudanego widgetu ... z kt�ry ma �le zainicjowan� w�a�ciow�� 
     catch (exception & e)
     {
       m_widget->disconnect(); // roz��cza wszystkie sygna�y 
       delete m_widget; 
       m_widget = NULL; 
       m_type=none; 
       noneType(); 
       common::log()<<"FAIL - create mnemonicbox:"<<m_bridge->property("name")<<" error:"<<e.what()<<endl;
     }
     // wrzucenie do layout'a
     layout->addWidget(m_widget); 
      
     m_widget->setVisible(m_isVisible);        
}// initWidget 
 


void MnemonicBox::intType()
{    
  if (m_bridge)
  {
      QSpinBox * box =  new QSpinBox(); 
   
     // minimum 
     common::Value v = m_bridge->property("min"); 
     box->setMinimum(v);
   
     // maximum; 
     v = m_bridge->property("max"); 
     box->setMaximum(v); 

     // step 
     v = m_bridge->property("step");
     box->setSingleStep(v);
     
     // default 
     v = m_bridge->property("default");
        if (!v.empty())
          box->setValue(v); 
        else 
        {
          v=bridgeValue(m_bridge);
          if (!v.empty())
          box->setValue(v); 
        }
      m_widget = box; 
      connect (this,SIGNAL(valueChanged(int)),box,SLOT(setValue(int)));
      connect (box,SIGNAL(valueChanged(int)),this,SLOT(setValue(int)));
   }
}// intType

void MnemonicBox::doubleType()
{
  if (m_bridge)
  {
       QDoubleSpinBox * box = new QDoubleSpinBox();
 
      // liczba cyfr po przecinku 
      common::Value v = m_bridge->property("digits"); 
      box->setDecimals(v); 
   
      // minimum
      v = m_bridge->property("min");
      box->setMinimum(v);
   
      // maximum; 
      v = m_bridge->property("max"); 
      box->setMaximum(v); 
   
     // step
     v = m_bridge->property("step");
     box->setSingleStep(v);
   
     // default 
     v = m_bridge->property("default");
       if (!v.empty())
         box->setValue(v); 
       else 
       {
         v=bridgeValue(m_bridge); 
         if (!v.empty())
         box->setValue(v); 
       }
   m_widget = box; 
   connect (this,SIGNAL(valueChanged(double)),box,SLOT(setValue(double))); 
   connect (box,SIGNAL(valueChanged(double)),this,SLOT(setValue(double))); 
 } // if m_bridge 
}// doubleType

void MnemonicBox::boolType()
{   
 if (m_bridge)
 {
    QCheckBox * box =  new QCheckBox("");
    // default 
    common::Value v = m_bridge->property("default");
    if (!v.empty())
      box->setChecked(v); 
    else // pobierz warto�� z mnemonika  
    {
      v = bridgeValue(m_bridge);
      if (!v.empty())
      box->setChecked(v); 
    }
    m_widget = box; 
   connect(this,SIGNAL(checkChanged(bool)),box,SLOT(setChecked(bool))); 
   connect(box,SIGNAL(toggled(bool)),this,SLOT(setChecked(bool))); 
  
 }    
}// boolType 
 
void MnemonicBox::noneType()
{
  QLabel * label = new QLabel(m_mnemonicname); 
  label->setAlignment(Qt::AlignHCenter);
  m_widget = label;  
  m_widget->resize(m_widget->width(),16); 
  m_type=none; 
}


void MnemonicBox::updateValue()
{
  if (! m_bridge) return; 
  
  common::Value v = bridgeValue(m_bridge);
  
  if (!v.empty())
   switch (m_type)
   {
    case int_t   : 
       		setValue(v.toInt());
     		emit valueChanged(v.toInt()); 
     		emit valueChanged(v.toDouble()); 
    	     	break; 
    case double_t: 
        	setValue(v.toDouble()) ;
           	emit valueChanged(v.toInt()); 
		emit valueChanged(v.toDouble()); 
		break; 
    case bool_t  : 
    		setChecked(v); 
    		emit checkChanged(v.toBool());
    		break;
   }
}

void MnemonicBox::setValue (int value) 
{
  if (!m_bridge || m_readOnly) return; 
  common::Value v1 = m_bridge->lastValue(),v2 = value; 
  
  if (v1!=v2)
  {
   setBridgeValue(v2,m_bridge);
   if (v2.empty()) v2 = 0.0; 
   emit valueChanged(v2.toInt()); 
   emit valueChanged(v2.toDouble()); 
  }
  
}

void  MnemonicBox::setValue (double value) 
{
  if (!m_bridge || m_readOnly) return; 
  common::Value v1=m_bridge->lastValue(),v2 = value; 
  if (v1!=v2) 
  {
   setBridgeValue(v2,m_bridge);
   if (v2.empty()) v2 = 0.0; 
   emit valueChanged(v2.toInt());
   emit valueChanged(v2.toDouble()); 
  }
   
   
}

void MnemonicBox::setChecked (bool value) 
{
  if (!m_bridge || m_readOnly) return; 
  common::Value v1 = m_bridge->lastValue(),v2 = value; 
  if (v1!=v2)
  {
   setBridgeValue(v2,m_bridge);
   if (v2.empty()) v2 = false;   
   emit checkChanged(v2.toBool());
  }
}


int MnemonicBox::intValue () const
{
  if (!m_bridge) return 1; 
  common::Value v = m_bridge->lastValue(); 
  if (v.empty()) v = 0; 
  return v; 
}

double MnemonicBox::doubleValue () const
{
  if (!m_bridge) 
    return 1.0;
  common::Value v =  m_bridge->lastValue(); 
  if (v.empty()) v = 0.0;; 
  return v;
}

bool MnemonicBox::checked() const
{
  if (!m_bridge) return false; 
  common::Value v =  m_bridge->lastValue(); 
  if (v.empty()) v = false; 
  return v; 
}

	
QString MnemonicBox::mnemonic () const
{
  return m_mnemonicname;
}
void MnemonicBox::setMnemonic (QString value) 
{
  if (value!="mnemonic")
  {
    clean(); 
  
    m_mnemonicname = value; 
    string str = m_mnemonicname.toLocal8Bit().data();
  
    widgets[str]=this; 
  
    setObjectName(value); 
    initChildComponent();
 
    update(); 
  }
}


bool MnemonicBox::isVisible () const {  return m_isVisible;  }

void MnemonicBox::setIsVisible (bool value) 
{ 
   m_isVisible = value ; 
   initChildComponent();
   update();
}

QWidget * MnemonicBox::childWidget()
{
  return m_widget; 
}

void MnemonicBox::clean()
{
  
  string str = m_mnemonicname.toLocal8Bit().data();
  if (str!="mnemonic")
  {
   if (widgets[str])
   {
    //// widgets[str]=NULL; 
     widgets.erase(widgets.find(str)); //]=NULL;
   }
  }
}

void MnemonicBox::paintEvent(QPaintEvent * /*event*/)
{
  if (none==m_type && m_isVisible)
  {
      QPainter painter(this); 
      painter.setPen(Qt::black); 
      painter.drawRect(0,0,width()-1,height()-1); 
  }
}// paintEvent 





