#ifndef QMNEMONICBOX_H
#define QMNEMONICBOX_H
#include <QString>
#include "qstring.h"

#include <QWidget>
#include <QSpinBox> 
#include <QDoubleSpinBox> 
#include <QCheckBox> 
#include <map> 

using namespace std; 
class MnemonicBox; 

typedef map<string,MnemonicBox *>  mnemonic_map; 
 
// Deklaracja wartwy po³±czeniowej z mnemonikiem 
namespace protocols
{
 class MnemonicBridge; 
}

/** Klasa do sygnalizowania globalnych zdarzeñ o mnemonikach */
class GlobalMnemonicBox : public QObject 
{ 
  Q_OBJECT
  public: 
  GlobalMnemonicBox(QObject * parent = NULL); 
  
  public slots: 
  
  void setOnline(bool i=true);
  void setOffline (bool i = true); 
  void updateAll(); 
  
  signals: 
  void setedOnline();
  void setedOffline();
  void allUpdated(); 
  
};

/**
 * Class MnemonicBox
 * Komponent reprezentuj±cy box jeden z komponentów SpinBox DoubleSpinBox lub CheckBox
 */
class MnemonicBox : public QWidget 
{
   Q_OBJECT 
   Q_PROPERTY ( QString server      	READ server         	WRITE setServer    ) 
   Q_PROPERTY ( QString mnemonic 	READ mnemonic 		WRITE setMnemonic  ) 
   Q_PROPERTY ( bool    online      	READ isOnline       	WRITE setOnline    ) 
   Q_PROPERTY ( bool    isVisible 	READ isVisible 	 	WRITE setIsVisible ) 

  
 public:
   /** Obiekt do globalnego zarz±dzania mnemonikami */ 
   static GlobalMnemonicBox global; 
   
   /** Mapa wszystkich mnenomików */ 
   static mnemonic_map widgets; 
 
  MnemonicBox (QWidget * parent );
  
  ~MnemonicBox(); 
   
  void  setServer  (QString value); 
  QString server   (); 

 
  int  intValue () 		const;
  double  doubleValue () 	const;
  bool  checked () 		const;
  bool  isVisible () 		const;
  bool  isOnline()              const; 
  QString  mnemonic () 		const ;
  
  QWidget * childWidget(); 
  
  
   static unsigned int intervalTime();
   static void setIntervalTime(unsigned int i);
   
   
     
   protocols::MnemonicBridge * bridge(); 
  
  public slots: 
 
 
  void  updateValue(); 
  
  void  setValue   (int value);
  void  setValue   (double value);
  void  setChecked (bool value);
  void  setMnemonic (QString value);
  void  setIsVisible (bool value);
  void  setDefault();  
  void  setOnline(bool i=true);
  void  setOffline(bool i=true);
  void  updateAll(); 
  
    
  signals:
  
  void valueChanged(int val);
  void valueChanged(double val); 
  void checkChanged(bool val); 
  
  
 protected:
  
  void clean(); 
  
  void paintEvent(QPaintEvent *event); 
  
  /** Inicjuje komponent potomny */ 
  void initChildComponent();
  
  void initBridge(); // inicjuje po³±czenie z engimem komunikacji 
  void initWidget(); // inicjuje widget na podstawie typu oraz tego czy jest zdefinowany jaki¶ widget do tej porty 
  
  
  void intType();
  void doubleType();
  void boolType(); 
  void noneType(); 
  
  static unsigned int m_intervalTime; 
  
  
  enum {none = 0x0, int_t=0x1,double_t=0x2,bool_t=0x3 }; 
 
  /** Czy ma byæ widzialnym komponentem czy tylko takim sobie */ 
  bool m_isVisible; 
  
  /** Typ mnemonika none,int_t double itd ... */ 
  int m_type; 
  
  /** czy zmienna mnemonic jest tylko do oczytu */ 
  bool m_readOnly; 
  
  /** Nazwa mnemonika */
  QString m_mnemonicname;
  /** Warto¶æ domy¶lna */ 
  QString m_default; 
  
  /** Widget potomny */ 
  QWidget * m_widget; 
  
  protocols::MnemonicBridge * m_bridge; 
 
 private:
 
};
#endif //QMNEMONICBOX_H

