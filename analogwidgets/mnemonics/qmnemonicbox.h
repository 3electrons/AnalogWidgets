#ifndef QMNEMONICBOX_H
#define QMNEMONICBOX_H
#include <QString>
#include "qstring.h"

#include <QWidget>
/**
 * Class QMnemonicBox
 * Komponent reprezentuj±cy box jeden z komponentów SpinBox DoubleSpinBox lub CheckBox
 */
class QMnemonicBox : public QWidget 
{

public:
 
 
  QMnemonicBox ( );
 
  int  intValue ();
  double  doubleValue ();
  bool  checked ();
  bool  visible ();
  QString  mnemonic ();
 
  setIntValue (int value);
  setDoubleValue (double value);
  setChecked (bool value);
  setMnemonic (QString value);
  setVisible (bool value);
    
  
protected:
  int m_type; 
  
private:
};
#endif //QMNEMONICBOX_H

