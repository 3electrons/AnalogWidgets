#include <QtGui> 
#include <QDomDocument> 
#include <QDomElement> 

#include <iostream>

#include "defines.h"
#include "mnemonicbox.h"
#include "comm/engine.h" // z Bartkom/src/comm/


using namespace std; 
using namespace comm; 


/**********************************************************************************************
 				GlobalMnemonicBox - Konstruktor
**********************************************************************************************/
GlobalMnemonicBox::GlobalMnemonicBox(QObject * parent ):QObject(parent) 
{
 ;
}    
/**********************************************************************************************
 				GlobalMnemonicBox - setOnline
**********************************************************************************************/
void GlobalMnemonicBox::setOnline(bool i)
{ 
   if (i && protocols::MnemonicBridge::isOffline())
   {
    // qDebug("setOnline()"); 
     protocols::MnemonicBridge::setOnline(); 
     emit setedOnline(true);
    
     updateAll(); 
   }
   else setOffline(!i);
}

/**********************************************************************************************
 				GlobalMnemonicBox - setOffline
**********************************************************************************************/
void GlobalMnemonicBox::setOffline (bool i)
{
  if (i && protocols::MnemonicBridge::isOnline())
  {
   // qDebug("setOffline()");
    protocols::MnemonicBridge::setOffline(); 
    emit setedOnline(false);  
  }
  else  setOnline(!i);  
}
/**********************************************************************************************
 				GlobalMnemonicBox - updateAll 
**********************************************************************************************/
void GlobalMnemonicBox::updateAll()
{
 // setOnline(i); 
  mnemonic_map::iterator i  = MnemonicBox::widgets.begin(); 
  while (i!=MnemonicBox::widgets.end())
  (i++).value()->updateValue();   
  emit allUpdated(); 
}


/**********************************************************************************************
  					  designMode
**********************************************************************************************/
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

/**********************************************************************************************
  					  bridgeValue 
**********************************************************************************************/
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
    if (protocols::MnemonicBridge::isOnline())
      usleep(MnemonicBox::intervalTime()); 
  }
  catch (comm_error & e)
  {
    string s = bridge->property("name");
    s+=" "; s+=e.what(); 
    common::log()<<"* Communication error:"<<s<<endl;
    QMessageBox::critical(NULL,"Blad odczytu",s.c_str()); 
    v = bridge->lastValue();
    MnemonicBox::global.setOffline();  
  }
  return v;   
}

/**********************************************************************************************
  					  setBridgeValue 
**********************************************************************************************/
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
    if (protocols::MnemonicBridge::isOnline())
      usleep(MnemonicBox::intervalTime()); 
    status = true; 
  }
  catch (exception & e) 
  {
    string s = bridge->property("name");
    s+=" "; s+=e.what(); 
    common::log()<<"* Communication error:"<<s<<endl;
    QMessageBox::critical(NULL,"Blad zapisu",s.c_str()); 
    v = bridge->lastValue(); 
    MnemonicBox::global.setOffline(); 
  }
  return status; 
}
/**********************************************************************************************
				  MnemonicBox - setValue( Value ) 
**********************************************************************************************/
void setValue(int type, MnemonicBox * box, common::Value & v) 
{
   try
   {
     if (!v.empty())
     {
       switch (type) 
       {
         case MnemonicBox::Int   : box->setValue(v.toInt()); 	 break;
         case MnemonicBox::Double: box->setValue(v.toDouble());break;
         case MnemonicBox::Bool  : box->setValue(v.toBool());	 break; 
         case MnemonicBox::None  :    break;
       }
     }
   }
   catch (exception & e)
   {  
     ; // common::log()<<"FAIL - setting mnemonic */ 
   }
}

/**********************************************************************************************
				  MnemonicBox - implementacja 
**********************************************************************************************/

unsigned int MnemonicBox::m_intervalTime=2000; 

GlobalMnemonicBox MnemonicBox::global; 

mnemonic_map MnemonicBox::widgets; 

/**********************************************************************************************
				  MnemonicBox - Konstruktor
**********************************************************************************************/
MnemonicBox::MnemonicBox(QWidget * parent) : QWidget(parent)
{
  m_type = None; 
  m_mnemonicname = QString("mnemonic"); 
  m_isVisible = true; 
  m_widget = NULL; 
  m_bridge = NULL; 
  m_readOnly = true; 
  initWidget();          
}

/**********************************************************************************************
				  MnemonicBox - Destruktor
**********************************************************************************************/
MnemonicBox::~MnemonicBox()
{
  unRegister();
}

/**********************************************************************************************
				  MnemonicBox - setServer
**********************************************************************************************/
void MnemonicBox::setServer  (QString value)
{
   comm::ReinitEngine( value.toLocal8Bit().data() );
   if (None==m_type)
   {
      MnemonicBox * box;
      mnemonic_map::iterator i=widgets.begin();
      while (i!=widgets.end())
      {
        box = i.value(); 
        //cout<<"Box:"<<box<<endl; 
        if (box)
        if (None==box->m_type) box->initChildComponent();
        i++; 
      }
      
     // initChildComponent(); 
   }
}
/**********************************************************************************************
				  MnemonicBox - server
**********************************************************************************************/
QString MnemonicBox::server   ()
{
  QString Str ( comm::EngineConfigFile().c_str()); 
  return Str; 
}
/**********************************************************************************************
				  MnemonicBox - loadMnemonics`
**********************************************************************************************/
void MnemonicBox::loadMnemonics(QString fileName,QSet<QString> * mnemonics )
{
 

}
/**********************************************************************************************
				  MnemonicBox - saveMnemonics
**********************************************************************************************/
void MnemonicBox::saveMnemonics(QString fileName,QSet<QString> * mnemonics)
{
  
  QDomDocument doc;   
  QDomElement root = doc.createElement("MnemonicBox"); 
  QDomElement mnemonic_values = doc.createElement("mnemonic_values"); 
  
  doc.appendChild(root); 
  root.appendChild(mnemonic_values); 
    
  MnemonicBox * box; 
  if (mnemonics && mnemonics->size()) 
  { 
    QSet<QString>::const_iterator s;
    s=mnemonics->begin(); 
    while (s!=mnemonics->end())
    {
      box = widgets[*s];
      
      QDomElement value = doc.createElement("mnemonic"); 
      value.setAttribute("value",box->strValue()); 
      value.setAttribute("name",box->mnemonic());      
      mnemonic_values.appendChild(value); 
      
      s++; 
    } 
  } 
  else 
  {
     mnemonic_map::iterator i = widgets.begin(); 
     while (i!=widgets.end())
     {
      box = i.value(); 
      
      QDomElement value = doc.createElement("mnemonic"); 
      value.setAttribute("value",box->strValue()); 
      value.setAttribute("name",box->mnemonic());
      mnemonic_values.appendChild(value); 
        
      i++;
     }
  }
  QFile file(fileName); 
  file.open(QIODevice::WriteOnly); 
  QTextStream out(&file); 
  doc.save(out,4); 
  file.close(); 
  
 // if (mnemonics)
}
/**********************************************************************************************
				  MnemonicBox - initChildComponent 
**********************************************************************************************/
void MnemonicBox::initChildComponent()
{
  initBridge();
  initWidget();          
}// initChildComponent  

/**********************************************************************************************
				  MnemonicBox - initBridge 
**********************************************************************************************/
void MnemonicBox::initBridge()
{
  if (m_bridge) 
  { 
    delete m_bridge; 
    m_bridge = NULL; 
    m_type = None;
  }
    
  try
  {
     m_bridge = CreateMnemonicBridge(m_mnemonicname.toLocal8Bit().data()); 
     string type = m_bridge->property("type");
     common::Value v = m_bridge->property("readonly"); 
     m_default = m_bridge->property("default").c_str(); 
     //cout<<"ReadOnly:"<<v.str()<<endl; 
     m_readOnly = v; 
     char *types[]={"int","double","bool"}; 
     int  m_types[]={Int,Double,Bool}; 
     for (int i=0;i<3;i++)
     if (type==types[i]) m_type = m_types[i]; 
  }
  catch (exception & e)
  {
     common::log()<<"FAIL - init menmonicbox "<<m_mnemonicname.toLocal8Bit().data()<<" error:"<<e.what()<<endl; 
  } 
}// initBridge 
/**********************************************************************************************
				  MnemonicBox - initWidget
**********************************************************************************************/
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
     
     
    // zgrabne usuniêcie starego widgetu je¿eli istnieje  
     if (m_widget)
     {
       layout->removeWidget(m_widget);
       m_widget->disconnect(); // roz³±cza wszystkie sygna³y 
       delete m_widget; 
       m_widget = NULL; 
     }
      
     // utworzenie nowego widgetu  
     try 
     {
       switch (m_type)
       { 
         case Int      : intType()    ; break;
         case Double   : doubleType() ; break; 
         case Bool     : boolType()   ; break; 
         case None     : noneType()   ; break; 
       }
     }
     // usuniêcie nieudanego widgetu ... z który ma ¼le zainicjowan± w³a¶ciow¶æ 
     catch (exception & e)
     {
       m_widget->disconnect(); // roz³±cza wszystkie sygna³y 
       delete m_widget; 
       m_widget = NULL; 
       m_type=None; 
       noneType(); 
       common::log()<<"FAIL - create MnemonicBox:"<<m_bridge->property("name")<<" error:"<<e.what()<<endl;
     }
     // wrzucenie do layout'a
     layout->addWidget(m_widget); 
     m_widget->setVisible(m_isVisible); 
            
    
     
        setFocusPolicy(Qt::StrongFocus); 
        setFocusProxy(m_widget); 
        
}// initWidget 

/**********************************************************************************************
				  MnemonicBox - intType
*********************************************************************************************/
void MnemonicBox::intType()
{    
  if (m_bridge)
  {
      QSpinBox * box =  new QSpinBox(this); 
   
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
     if (designMode()) 
         setDefault(); 
     else 
      {
         v = bridgeValue(m_bridge);  
         if(v.empty()) v=0; 
         box->setValue(v); 
      }
        
      m_widget = box; 
      connect (this,SIGNAL(valueChanged(int)),box,SLOT(setValue(int)));
      connect (box,SIGNAL(valueChanged(int)),this,SLOT(setValue(int)));
   }
}// intType
/**********************************************************************************************
				  MnemonicBox - doubleType
**********************************************************************************************/
void MnemonicBox::doubleType()
{
  if (m_bridge)
  {
       QDoubleSpinBox * box = new QDoubleSpinBox(this);
 
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
     if (designMode()) 
         setDefault();       
     else 
      {
         v = bridgeValue(m_bridge);  
         if (v.empty()) v=0.0; 
         box->setValue(v); 
      }
       
     
   m_widget = box; 
   connect (this,SIGNAL(valueChanged(double)),box,SLOT(setValue(double))); 
   connect (box,SIGNAL(valueChanged(double)),this,SLOT(setValue(double))); 
 } // if m_bridge 
}// doubleType
/**********************************************************************************************
				  MnemonicBox - boolType
**********************************************************************************************/
void MnemonicBox::boolType()
{   
 if (m_bridge)
 {
    QCheckBox * box =  new QCheckBox(this);
     common::Value v(""); 
     // default 
     if (designMode()) 
          setDefault(); 
     else 
      {
         v = bridgeValue(m_bridge);  
         if (v.empty()) v=false; 
         box->setChecked(v); 
      }
   
    m_widget = box; 
   connect(this,SIGNAL(checkChanged(bool)),box,SLOT(setChecked(bool))); 
   connect(box,SIGNAL(toggled(bool)),this,SLOT(setChecked(bool))); 
  
 }    
}// boolType 
/**********************************************************************************************
				  MnemonicBox - noneType
**********************************************************************************************/
void MnemonicBox::noneType()
{
  QLabel * label = new QLabel(m_mnemonicname,this); 
  label->setAlignment(Qt::AlignHCenter);
  m_widget = label;  
  m_widget->resize(m_widget->width(),16); 
  m_type=None; 
}
/**********************************************************************************************
				  MnemonicBox - updateValue
**********************************************************************************************/
void MnemonicBox::updateValue()
{
  if (! m_bridge) return; 
  
  common::Value v = bridgeValue(m_bridge);
  ::setValue(m_type,this,v); 
  if (v.empty()) return; 
  switch (m_type)
  {
    case Int:
    case Double: 
          emit valueChanged(v.toDouble());
          emit valueChanged(v.toInt()); 
          break; 
    case Bool:
          emit checkChanged(v.toBool());
          break;          
  }
}
/**********************************************************************************************
				  MnemonicBox - setValue ( QString ) 
**********************************************************************************************/
void MnemonicBox::setValue (QString value)
{
   if (!m_bridge || m_readOnly) return; 
   common::Value v = value.toLocal8Bit().data(); 
   ::setValue(m_type,this,v); 
}
/**********************************************************************************************
				  MnemonicBox - setValue( int )
**********************************************************************************************/
void MnemonicBox::setValue (int value) 
{
  if (!m_bridge || m_readOnly) return; 
  common::Value v1 = m_bridge->lastValue(),v2 = value; 
  
  if (v1!=v2) // bo lastValue jest to samo
  {
   setBridgeValue(v2,m_bridge);
   if (v2.empty()) v2 = 0.0; 
   emit valueChanged(v2.toInt()); 
   emit valueChanged(v2.toDouble()); 
  }  
}
/**********************************************************************************************
				  MnemonicBox - setValue( double )
**********************************************************************************************/
void  MnemonicBox::setValue (double value) 
{
  if (!m_bridge || m_readOnly) return; 
  common::Value v1=m_bridge->lastValue(),v2 = value; 
  if (v1!=v2 ) 
  {
   setBridgeValue(v2,m_bridge);
   if (v2.empty()) v2 = 0.0; 
   emit valueChanged(v2.toInt());
   emit valueChanged(v2.toDouble()); 
  }   
}
/**********************************************************************************************
				  MnemonicBox - setChecked ( bool )
**********************************************************************************************/
void MnemonicBox::setChecked (bool value) 
{
  if (!m_bridge || m_readOnly) return; 
  common::Value v1 = m_bridge->lastValue(),v2 = value; 
  if (v1!=v2 )
  {
   setBridgeValue(v2,m_bridge);
   if (v2.empty()) v2 = false;   
   emit checkChanged(v2.toBool());
  }
}
/**********************************************************************************************
				  MnemonicBox - strValue
**********************************************************************************************/
QString MnemonicBox::strValue() const 
{
   QString str("0"); 
   if (!m_bridge) return str; 
   common::Value v = m_bridge->lastValue(); 
   if (v.empty()) v = 0; 
   str = v.c_str(); 
   return str;  
}
/**********************************************************************************************
				  MnemonicBox - intValue
**********************************************************************************************/
int MnemonicBox::intValue () const
{
  if (!m_bridge) return 0; 
  common::Value v = m_bridge->lastValue(); 
  if (v.empty()) v = 0; 
  return v; 
}
/**********************************************************************************************
				  MnemonicBox - doubleValue
**********************************************************************************************/
double MnemonicBox::doubleValue () const
{
  if (!m_bridge) 
    return 1.0;
  common::Value v =  m_bridge->lastValue(); 
  if (v.empty()) v = 0.0;; 
  return v;
}
/**********************************************************************************************
				  MnemonicBox - checked
**********************************************************************************************/
bool MnemonicBox::checked() const
{
  if (!m_bridge) return false; 
  common::Value v =  m_bridge->lastValue(); 
  if (v.empty()) v = false; 
  return v; 
}
/**********************************************************************************************
				  MnemonicBox - mnemonic
**********************************************************************************************/
QString MnemonicBox::mnemonic () const
{
  return m_mnemonicname;
}
/**********************************************************************************************
				  MnemonicBox - setMnemonic
**********************************************************************************************/
void MnemonicBox::setMnemonic (QString value) 
{
  if (value!="mnemonic")
  {
    unRegister(); 
    setToolTip(value); 
    m_mnemonicname = value; 
    widgets[value]=this; 
    setObjectName(value); 
    initChildComponent(); 
    update(); 
  }
}
/**********************************************************************************************
				  MnemonicBox - isVisible
**********************************************************************************************/
bool MnemonicBox::isVisible () const 
{  
  return m_isVisible;  
}
/**********************************************************************************************
				  MnemonicBox - setIsVisible
**********************************************************************************************/
void MnemonicBox::setIsVisible (bool value) 
{ 
   m_isVisible = value ; 
   initChildComponent();
   update();
}
/**********************************************************************************************
				  MnemonicBox - setDefault 
**********************************************************************************************/
void  MnemonicBox::setDefault() // slot 
{
   common::Value v("");
   
   v = m_default.toLocal8Bit().data();
   ::setValue(m_type,this,v); 
}
/**********************************************************************************************
				  MnemonicBox - childWidget
**********************************************************************************************/
QWidget * MnemonicBox::childWidget()
{
  return m_widget; 
}
/**********************************************************************************************
				  MnemonicBox - unRegister
**********************************************************************************************/
void MnemonicBox::unRegister()
{

  if (m_mnemonicname!="mnemonic")
  {
   if (widgets[m_mnemonicname])
   {
    //// widgets[str]=NULL; 
     widgets.erase(widgets.find(m_mnemonicname)); //]=NULL;
   }
  }
}
/**********************************************************************************************
				  MnemonicBox - paintEvent
**********************************************************************************************/
void MnemonicBox::paintEvent(QPaintEvent * /*event*/)
{
  if (None==m_type && m_isVisible)
  {
      QPainter painter(this); 
      painter.setPen(Qt::black); 
      painter.drawRect(0,0,width()-1,height()-1); 
  }
}// paintEvent 
/**********************************************************************************************
				  MnemonicBox - intervalTime
**********************************************************************************************/
unsigned int MnemonicBox::intervalTime()
{
  return m_intervalTime; 
}
/**********************************************************************************************
				  MnemonicBox - setIntervalTime 
**********************************************************************************************/
void MnemonicBox::setIntervalTime(unsigned int i)
{
  m_intervalTime = i;   
}
/**********************************************************************************************
				  MnemonicBox - setOnline
**********************************************************************************************/
void MnemonicBox::setOnline(bool i)
{
   global.setOnline(i); 
}
/**********************************************************************************************
				  MnemonicBox - setOffline
**********************************************************************************************/
void MnemonicBox::setOffline(bool i)
{
  global.setOffline( i ); 
}
/**********************************************************************************************
				  MnemonicBox - isOnline
**********************************************************************************************/
bool MnemonicBox::isOnline() const
{
  return protocols::MnemonicBridge::isOnline(); 
}
/**********************************************************************************************
				  MnemonicBox - updateAll
**********************************************************************************************/
void MnemonicBox::updateAll()
{
  global.updateAll(); 
}
/**********************************************************************************************
				  MnemonicBox - bridge
**********************************************************************************************/
protocols::MnemonicBridge * MnemonicBox::bridge()
{
  return m_bridge; 
} 
