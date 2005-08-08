#include <assert.h>
#include "qmyabstractmeter.h"


QMyAbstractMeter::QMyAbstractMeter(QWidget * parent )
 : QMyWidgetWithBackground (parent)
{
}


bool QMyAbstractMeter::calcMaxMin()
{
  int max_tmp = m_max, min_tmp = m_min;
  m_max=m_maximum;
  m_min=m_minimum;

  assert( m_max > m_min );
  assert( m_max - m_min >! 0 );

  int diff = abs(m_max - m_min);
  int scale = 0,inc = 5 , factor = 0 ;
  bool done = false;
  while ( diff > scale ) { factor+=inc; scale = 8 * factor; }
  while (!done)
  {
     m_max=0;
     while ( m_max < m_maximum ) m_max +=factor;
     m_min = m_max - scale;
     if (m_min <= m_minimum ) done = true;
     else { factor+=inc; scale = 8*factor; }
  }
 return (m_max != max_tmp) | (m_min != min_tmp);
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


