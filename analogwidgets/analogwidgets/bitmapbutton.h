#ifndef BITMAPBUTTON_H
#define BITMAPBUTTON_H

#include <QAbstractButton>
#include <QIcon> 
#include <QTimer> 

class BitmapButton: public QAbstractButton
{
  Q_OBJECT
  Q_PROPERTY (QIcon downIcon READ downIcon WRITE setDownIcon)    

  public:
      BitmapButton(QWidget * parent = 0); 
      QIcon downIcon() const ;
      void setDownIcon(const QIcon & icon);

  protected slots:


  protected: 
    
  void init();
  virtual void paintEvent ( QPaintEvent * event );

  QIcon m_downIcon;

}; // BitmapButton

#endif // BITMAPBUTTON_H

