#ifndef COUNTER_H
#define COUNTER_H 

#include <QWidget> 
#include <QString> 


class QSvgRenderer; 

class Counter: public QWidget
{
 Q_PROPERTY (int value READ value WRITE setValue) 
 Q_PROPERTY (int digits READ digits WRITE setDigits) 
 Q_PROPERTY (QString digitsFile READ digitsFile WRITE setDigitsFile) 

 Q_OBJECT
  public:
  Counter (QWidget * parent = NULL); 

  int digits() const;
  int value() const;
  QString digitsFile() const; 
  public slots: 

  void setValue(int);
  void setDigits(int);
  void setDigitsFile(const QString & ); 

  protected:
   void paintEvent (QPaintEvent *); 
   void init();
   
   int m_digits; 
   int m_value;
   QString m_digitsFile;
   QSvgRenderer * m_svg;

}; // class Counter 
#endif // COUNTER_H 
