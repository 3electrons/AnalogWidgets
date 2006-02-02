	#ifndef QMNEMONICBOX_H
#define QMNEMONICBOX_H
#include <QString>
#include "qstring.h"

#include <QWidget>
#include <QSpinBox> 
#include <QDoubleSpinBox> 
#include <QCheckBox> 
/**
 * Class MnemonicBox
 * Komponent reprezentuj±cy box jeden z komponentów SpinBox DoubleSpinBox lub CheckBox
 */
class MnemonicBox : public QWidget 
{
   Q_OBJECT 
   Q_PROPERTY ( QString mnemonic 	READ mnemonic 	WRITE setMnemonic  ) 
   Q_PROPERTY ( bool    isVisible 	READ isVisible 	WRITE setIsVisible ) 
   Q_PROPERTY ( int     type            READ type       WRITE setType      )
 public:
   
 
  MnemonicBox (QWidget * parent );
 
  int  intValue () 		const;
  double  doubleValue () 	const;
  bool  checked () 		const;
  bool  isVisible () 		const;
  QString  mnemonic () 		const ;
  
  int type () const {return m_type ;} 
  public slots: 
 
  void  setValue   (int value);
  void  setValue   (double value);
  void  setChecked (bool value);
  void  setMnemonic (QString value);
  void  setIsVisible (bool value);
  
  void  setType(int type)
  {
    if (type>=0 && type<4)
    {
      m_type = type;
      initChildComponent(); 
      update(); 
    }
  } 
    
  signals:
  
  void valueChanged(int val);
  void valueChanged(double val); 
  void checkChanged(bool val); 
  
 protected:
  void paintEvent(QPaintEvent *event); 
  
  /** Inicjuje komponent potomny */ 
  void initChildComponent();
  
  void intType();
  void doubleType();
  void boolType(); 
  void noneType(); 
  
  enum {none = 0x0, int_t=0x1,double_t=0x2,bool_t=0x3 }; 
 
  /** Czy ma byæ widzialnym komponentem czy tylko takim sobie */ 
  bool m_isVisible; 
  
  /** Typ mnemonika none,int_t double itd ... */ 
  int m_type; 
  
  /** Nazwa mnemonika */
  QString m_mnemonicname;
  
  /** Widget potomny */ 
  QWidget * m_widget; 
  
 private:
};
#endif //QMNEMONICBOX_H

