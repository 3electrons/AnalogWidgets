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

     /** Destruktor - usuwa bitmapk�.  */
     ~QMyWidgetWithBackground ();

     /**
      * Operacja odmalowywania kontrolki  -
      * wkleja bitmap� z t�em na kontrolk� -
      * generuj�� j� wcze�niej je�eli zajdzie taka potrzeba.
      */
     void  doUpdateBackground ();

     /** Odmalowywuje kontrolk� bezwarunkowo odmalowywuj�c t�o. */
     void  updateWithBackground ();

  protected:
    /** Wywo�uje paintBackground - odmalowywuj�c t�o na nowo */
    void repaintBackground();

    /**
     * Odmalowywuje t�o kontrolki
     * @param painter urz�dzenie na ktr�ym mamy malowa�.
     * @param background to t�o kontrolki
     */
    virtual void  paintBackground (QPainter & painer) = 0;

  protected:
     /** Bufor na t�o. */
     QPixmap * m_pixmap;
     /**
     * Ustawia t� zmienn� po zmianie w�a�ciwo�ci
     */
     bool m_modified;
};
#endif //QMYWIDGETWITHBACKGROUND_H

