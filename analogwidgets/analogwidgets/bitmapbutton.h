#ifndef BITMAPBUTTON_H
#define BITMAPBUTTON_H

#include <QAbstractButton>
#include <QIcon> 

class BitmapButton: public QAbstractButton
{
  Q_OBJECT
  Q_PROPERTY (QIcon downIcon READ downIcon WRITE setDownIcon)    
      
  public:    
      BitmapButton(QWidget * parent = 0); 

  protected: 
    QIcon downIcon() const ;
    void setDownIcon(const QIcon & icon); 
    
  void init();
  virtual void paintEvent ( QPaintEvent * event ); 

  QIcon m_downIcon; 
  
}; // BitmapButton

#endif // BITMAPBUTTON_H

