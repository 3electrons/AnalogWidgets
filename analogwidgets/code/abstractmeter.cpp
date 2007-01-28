#include <assert.h>
#include "abstractmeter.h"
#include "functions.h" 

AbstractMeter::AbstractMeter(QWidget * parent )
 : WidgetWithBackground (parent)
{
  m_min=m_minimum=0.0;
  m_max=m_maximum=1.0;
  m_digitOffset=1.0;
  m_nominal=0.25;
  m_critical=0.75; 
} 


bool AbstractMeter::calcMaxMin()
{
 return range(m_minimum,m_maximum,m_min,m_max,8); 
}

void AbstractMeter::setValue( double val )
{
  if ( m_value != val )
  {
    m_value = val;
    update(); 
    emit valueChanged(val);
    emit valueChanged((int)val); 
  }
}

void AbstractMeter::setValue( int val )
{
  if ( m_value != val )
  {
    m_value = val;
    update(); // Ciekawe czy tak jest lepiej ??
    // to znaczy najpierw odmalowaæ a potem generowaæ sygna³ ? 
    emit valueChanged(val);
    emit valueChanged(double(val));
  }
}

void AbstractMeter::setMinimum(double i)
{
  if ((m_maximum - i) > 0.00001 )
  {
    m_minimum = i;
    if (calcMaxMin()) updateWithBackground();
  }
}

void AbstractMeter::setMaximum(double i)
{
  if ( (i - m_minimum) > 0.00001 )
  {
    m_maximum = i;
    if (calcMaxMin()) updateWithBackground();
  }
}


