#include <assert.h>
#include "qmyabstractmeter.h"
#include "functions.h" 

QMyAbstractMeter::QMyAbstractMeter(QWidget * parent )
 : QMyWidgetWithBackground (parent)
{
}


bool QMyAbstractMeter::calcMaxMin()
{
 return range(m_minimum,m_maximum,m_min,m_max,8); 
}

void QMyAbstractMeter::setValue( int val )
{
  if ( m_value != val )
  {
    m_value = val;
    update(); // Ciekawe czy tak jest lepiej ??
    // to znaczy najpierw odmalowaæ a potem generowaæ sygna³ ? 
    emit valueChanged(val);
  }
}

void QMyAbstractMeter::setMinimum(int i)
{
  if ((m_minimum != i) && (i < m_maximum - 7 ) )
  {
    m_minimum = i;
    if (calcMaxMin()) updateWithBackground();
  }
}

void QMyAbstractMeter::setMaximum(int i)
{
  if ((m_maximum != i) && (i > m_minimum + 7) )
  {
    m_maximum = i;
    if (calcMaxMin()) updateWithBackground();
  }
}


