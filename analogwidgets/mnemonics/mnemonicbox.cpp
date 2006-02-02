#include <QtGui> 
#include <iostream>
#include "mnemonicbox.h"

using namespace std; 
MnemonicBox::MnemonicBox(QWidget * parent) : QWidget(parent)
{
  m_type = none; 
  m_mnemonicname = QString("mnemonic"); 
  m_isVisible = true; 
  m_widget = NULL; 
  initChildComponent(); 
  
}

void MnemonicBox::initChildComponent()
{
  
  if (NULL==layout())
  {
      QHBoxLayout * layout = new QHBoxLayout(); 
      layout->setMargin(0);
      layout->setSpacing(0); 
      setLayout(layout);  
  }
  
   if (m_widget)
   {
      layout()->removeWidget(m_widget);
      m_widget->disconnect(); // roz³±cza wszystkie sygna³y 
      delete m_widget; 
      m_widget = NULL; 
   }
  
   if (true==m_isVisible)
   {
      switch (m_type)
      { 
         case int_t    : intType()    ; break;
         case double_t : doubleType() ; break; 
         case bool_t   : boolType()   ; break; 
         case none     : noneType()   ; break;
       }
       layout()->addWidget(m_widget); 
   } // if visible 
   else 
      setLayout(NULL);
    
}

void MnemonicBox::intType()
{
   QSpinBox * box =  new QSpinBox(this); 
   connect (this,SIGNAL(valueChanged(int)),box,SLOT(setValue(int)));
   connect (box,SIGNAL(valueChanged(int)),this,SLOT(setValue(int)));
  
   m_widget = box; 
}

void MnemonicBox::doubleType()
{
   QDoubleSpinBox * box = new QDoubleSpinBox(this);
   
   connect (this,SIGNAL(valueChanged(double)),box,SLOT(setValue(double))); 
   connect (box,SIGNAL(valueChanged(double)),this,SLOT(setValue(double))); 
   
   m_widget = box; 
}

void MnemonicBox::boolType()
{
   QCheckBox * box =  new QCheckBox("",this);
   connect(this,SIGNAL(checkChanged(bool)),box,SLOT(setChecked(bool))); 
   connect(box,SIGNAL(toggled(bool)),this,SLOT(setChecked(bool))); 
   m_widget = box; 
    
}
 
void MnemonicBox::noneType()
{
  QLabel * label = new QLabel(m_mnemonicname,this); 
  label->setAlignment(Qt::AlignHCenter);
  m_widget = label;  
}


int MnemonicBox::intValue () const
{
  return 1;
}
void MnemonicBox::setValue (int value) 
{
 
  emit valueChanged(value); 
  emit valueChanged((double)value);
}


double MnemonicBox::doubleValue () const
{
  return 1.0;
}
void  MnemonicBox::setValue (double value) 
{
  emit valueChanged(value);
  emit valueChanged((int)value); 
}

void MnemonicBox::setChecked (bool value) 
{
  emit checkChanged(value);
}



QString MnemonicBox::mnemonic () const
{
  return m_mnemonicname;
}
void MnemonicBox::setMnemonic (QString value) 
{
  m_mnemonicname = value; 
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




