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
* Pobiera wartosæ mnemonika - w zale¿no¶ci od tego czy jest w trybie 
* projektowania czy aplikacji rzuca wyjatek lub wpisuje go na standardowe wyj¶cie 
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
    common::log<<"* Communication error:"<<s<<endl;
    QMessageBox::critical(NULL,"Blad odczytu",s.c_str()); 
    v = bridge->lastValue(); 
  }
  return v.str(); 
}


/** 
* Ustawia wartosæ mnemonika - w zale¿no¶ci od tego czy jest w trybie 
* projektowania czy aplikacji rzuca wyjatek lub wpisuje go na standardowe wyj¶cie 
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
    common::log<<"* Communication error:"<<s<<endl;
    QMessageBox::critical(NULL,"Blad zapisu",s.c_str()); 
    v = bridge->lastValue(); 
  }
  return status; 
}






mnemonic_dict MnemonicBox::widgets; 


MnemonicBox::MnemonicBox(QWidget * parent) : QWidget(parent)
{
  m_type = none; 
  m_mnemonicname = QString("mnemonic"); 
  m_isVisible = true; 
  m_widget = NULL; 
  m_bridge = NULL; 
  initChildComponent(); 
}


void MnemonicBox::setServer  (QString value)
{
   comm::EngineConfigFile( value.toLocal8Bit().data() );
}

QString MnemonicBox::server   ()
{
  QString Str ( comm::EngineConfigFile().c_str()); 
  return Str; 
}

void MnemonicBox::initChildComponent()
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
   char *types[]={"int","double","bool"}; 
   int  m_types[]={int_t,double_t,bool_t}; 
   for (int i=0;i<3;i++)
   if (type==types[i]) m_type = m_types[i]; 
  }
  
  catch (exception & e)
  {
   common::log<<"FAIL - init menmonicbox "<<m_mnemonicname.toLocal8Bit().data()<<" error:"<<e.what()<<endl; 
  } 
       
    QLayout * layout = this->layout();
    if (NULL==layout)
    {
      layout = new QHBoxLayout(); 
      layout->setMargin(0);
      layout->setSpacing(0);       
      setLayout(layout);
    }
     
     if (m_widget)
     {
       layout->removeWidget(m_widget);
       m_widget->disconnect(); // roz³±cza wszystkie sygna³y 
       delete m_widget; 
       m_widget = NULL; 
     }
      
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
     catch (exception & e)
     {
       // usuniêcie nieudanego widgetu ... z który ma ¼le zainicjowan± w³a¶ciow¶æ 
      
       m_widget->disconnect(); // roz³±cza wszystkie sygna³y 
       delete m_widget; 
       m_widget = NULL; 
       m_type=none; 
       noneType(); 
       common::log<<"FAIL - create mnemonicbox:"<<m_bridge->property("name")<<" error:"<<e.what()<<endl;
     }
     // Komponent jest utworzony i dostêpny by mo¿na by³o ustawiaæ jego warto¶ci odpowiednio. 
     layout->addWidget(m_widget); 
     
     
   
   m_widget->setVisible(m_isVisible);  
   
    // if visible 
  
}// initChildComponent  
 
 


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
    else // pobierz warto¶æ z mnemonika  
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
}


void MnemonicBox::updateValue()
{
  if (! m_bridge) return; 
  
  common::Value v = bridgeValue(m_bridge);
  
  if (!v.empty())
   switch (m_type)
   {
    case int_t   : setValue(v.toInt()) ; break; 
    case double_t: setValue(v.toDouble()) ; break; 
    case bool_t  : setChecked(v); break;
   }
  
}

void MnemonicBox::setValue (int value) 
{
  if (!m_bridge) return; 
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
  if (!m_bridge) return; 
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
  if (!m_bridge) return; 
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
  if (!m_bridge) return 1.0;
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
  string str = m_mnemonicname.toLocal8Bit().data();
  widgets[str]=NULL;
  
  m_mnemonicname = value; 
  str = m_mnemonicname.toLocal8Bit().data();
  
  widgets[str]=this; 
  
  initChildComponent();
  setObjectName(value); 
  
  update(); 
}


bool MnemonicBox::isVisible () const {  return m_isVisible;  }

void MnemonicBox::setIsVisible (bool value) 
{ 
   m_isVisible = value ; 
   initChildComponent();
   update();
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





