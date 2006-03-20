#ifndef QMNEMONICBOX_H
#define QMNEMONICBOX_H

#include <QString>
#include <QWidget>
#include <QSpinBox> 
#include <QDoubleSpinBox> 
#include <QCheckBox>
#include <QSet>  
#include <QMap> 
#include "comm/engine.h" // z Bartkom/src/comm/

using namespace std; 
class MnemonicBox; 

typedef QMap<QString,MnemonicBox *>  mnemonic_map; 
 
// Deklaracja warstwy po³±czeniowej z mnemonikiem 
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
  void setedOnline(bool i=true);
  void allUpdated(); 
  void updatingProgress(int i); 
  
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
 
  MnemonicBox (QWidget * parent );
  
  ~MnemonicBox(); 
   
  void  setServer  (QString value); 
  
  QString server   (); 
  QString mnemonic() 		const ;
  QString strValue()            const; 
  int     intValue () 		const;
  double  doubleValue () 	const;
  
  bool    checked () 		const;
  bool    isVisible () 		const;
  bool    isOnline()            const; 
  
  QWidget * childWidget(); 
  
  /** Zwraca interwa³ czasowy pomiêdzy operacjami odczyt/zapis */ 
  static unsigned int intervalTime();
  
  /** Ustawia interwa³ czasowy pomiêdzy operacjami odczyt/zapis */ 
  static void setIntervalTime(unsigned int i);
   
  /**
  * Odczytuje wskazane mnemniki na li¶cie z pliku 
  * @param fileName - plik z warto¶ciami mnemoników 
  * @param mnemonics - Mnemoniki które maj± byæ odczytane - je¿eli lista jest pusta 
  *                    lub  mnemonics jest NULL'em odczytywane s± wszystkie mnemoniki 
  *		       z pliku po kolei
  */ 
  static void loadMnemonics(QString fileName,QSet<QString> * mnemonics = NULL); 
  
  
  /** 
  * Zapisuje wskazane mnemoniki do podanego pliku 
  * @param fileName - Nazwa pliku 
  * @param mnemonics - Mnemoniki - je¿eli wska¼nik na listê jest NULL'em 
  *                    wówczas zapisuje wszystkie mnemoniki w przeciwnym 
  *                    wypadku zapisuje tylko mnemoniki z listy - o ile lista nie jest pusta
  */ 
  static void saveMnemonics(QString fileName,QSet<QString> * mnemonics = NULL);   
   
  /** Zwraca referencjê do "mostka" mnemonika */    
  protocols::MnemonicBridge * bridge(); 
  
  public slots: 
  
  void  setValue    (int     value);
  void  setValue    (double  value);
  
  void  setValue    (QString value); 
  void  setMnemonic (QString value);
  
  void  setChecked   (bool value);
  void  setIsVisible (bool value);
  void  setOnline    (bool i=true);
  void  setOffline   (bool i=true);
  
  void  setDefault();  
  void  updateValue();   
  void  updateAll(); 

    
  signals:
  
  void valueChanged(int val);
  void valueChanged(double val); 
  void checkChanged(bool val); 
  
  
 protected:
  
   /** Ustawia warto¶æ na podstawie common::Value */ 
   void setValue( common::Value & v); 
   
   
   /** Wyrejestrowywuje siê z listy widgetów typu MnemonicBox */
   void unRegister(); 
  
  
   /** Maluje kontrolkê - tylko dla typu none maluje ramkê itd */ 
   void paintEvent(QPaintEvent *event); 
  
  
   /** Inicjuje komponent potomny */ 
   void initChildComponent();
  
  
   /** Inicjuje po³±czenie z engimem komunikacji */
   void initBridge(); 
   
   
   /** Inicjuje widget na podstawie typu oraz tego czy jest zdefinowany jaki¶ widget do tej porty */
   void initWidget(); 
  
   
   /** Tworzy widget do obs³ugi typu int */ 
   void intType();
   
   /** Tworzy widget do obs³ugi typu double */ 
   void doubleType();
   
   /** Tworzy widget do obs³ugi typu bool */ 
   void boolType(); 
   
   /** Tworzy "pusty" widget (gdy typ widgetu nie jest okre¶lony)*/ 
   void noneType(); 
  
  public: 
  
   /** Obiekt do globalnego zarz±dzania mnemonikami */ 
   static GlobalMnemonicBox global; 
   
   /** Mapa wszystkich mnenomików */ 
   static mnemonic_map widgets; 
  
  protected: 
  
   /** Czas operacji oczytu i zapisu */ 
   static unsigned int m_intervalTime; 
     
   /** Typ enumeryczny dla typu kontrolki */ 
   enum {none = 0x0, int_t=0x1,double_t=0x2,bool_t=0x3 }; 
 
   /** Czy ma byæ widzialnym komponentem czy tylko takim sobie */ 
   bool m_isVisible; 
  
   /** czy zmienna mnemonic jest tylko do oczytu */ 
   bool m_readOnly; 

   /** Typ mnemonika none,int_t double itd ... */ 
   int m_type; 
  
   /** Nazwa mnemonika */
   QString m_mnemonicname;
   
   /** Warto¶æ domy¶lna dla mnemonika */ 
   QString m_default; 
  
   /** Widget potomny */ 
   QWidget * m_widget; 
  
   /** Mostek do mnemonika w engine comm */ 
   protocols::MnemonicBridge * m_bridge; 
 
};
#endif //QMNEMONICBOX_H

