#ifndef QMYWIDGETWITHBACKGROUND_H
#define QMYWIDGETWITHBACKGROUND_H

#include <QWidget>

class QPixmap;

class QMyWidgetWithBackground : public QWidget
{
	Q_OBJECT
  public:
     /** Konstruktor */
     QMyWidgetWithBackground(QWidget * parent = 0);

     /** Destruktor - usuwa bitmapkê.  */
     ~QMyWidgetWithBackground ();

     /**
      * Operacja odmalowywania kontrolki  -
      * wkleja bitmapê z t³em na kontrolkê -
      * generuj±æ j± wcze¶niej je¿eli zajdzie taka potrzeba.
      */
     void  doUpdateBackground ();

     /** Odmalowywuje kontrolkê bezwarunkowo odmalowywuj±c t³o. */
     void  updateWithBackground ();

  protected:
    /** Wywo³uje paintBackground - odmalowywuj±c t³o na nowo */
    void repaintBackground();

    /**
     * Odmalowywuje t³o kontrolki
     * @param painter urz±dzenie na ktróym mamy malowaæ.
     * @param background to t³o kontrolki
     */
    virtual void  paintBackground (QPainter & painer) = 0;

  protected:
     /** Bufor na t³o. */
     QPixmap * m_pixmap;
     /**
     * Ustawia t± zmienn± po zmianie w³a¶ciwo¶ci
     */
     bool m_modified;
};
#endif //QMYWIDGETWITHBACKGROUND_H

