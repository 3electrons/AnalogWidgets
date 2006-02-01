#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/**
* Szablonowa funkcja do wyznaczania skali w zadanym przedziale o wyznaczonej ilo�ci punkt�w skali.
* Na podstawie warto�ci minimalnej oraz maksymalnej, jak� chcemy osi�gna� ustawia
* warto�ci m_min oraz m_max w taki spos�b ca�y przedzia� skali (m_max-m_min) by� podzielny
* przez ilo�� punkt�w skali a odleg�o�� pomi�dzy punktami skali by�a wartosci� kt�ra jest
* wieloktorno�ci� liczby 5. Dodatkowo isnieje mo�liwo�� przesuni�cia skali w lewo lub prawo by
* rozpoczyna�a si� jak najbli�ej warto�ci minimalnej lub ko�czy�a jak najbli�ej warto�ci
* maksymalnej.
*
* @param m_minimum - warto�� minilana na skali jaka ma by� widoczna
* @param m_maximum - warto�� maksymalna na skali jaka ma by� widoczna
* @param m_min     - wyliczona warto�� pocz�tkowa skali
* @param m_max     - wyliczona warto�� ko�cowa skali
* @param stesp     - ilo�� w�z��w jak� ma mie� skala
* @param left      - czy skala ma by� wyr�wnana do lewej czy do prawej (domy�lnie do prawej).
* @return Funkcja zwraca warto�� true je�eli warto�ci m_min oraz m_max w wyniku zmiany zakresu
* zmieni�y swoj� warto��.  Na podstawie tej warto�ci wiadomo czy nale�y np. przerysowa� skal�
* - podaj�c wcze�niej poprzednie warto�ci zakresu skali.
*/
#include <assert.h>
#include <cmath>

using namespace std;

template <typename T>
bool range(T m_minimum,T m_maximum, T & m_min, T & m_max,unsigned int steps, bool left = false,double inc = 5.0)
{
  T max_tmp = m_max, min_tmp = m_min;
  m_max=m_maximum;
  m_min=m_minimum;
  assert( m_max > m_min );
//  assert( (m_max - m_min) > 0 );

  T diff = abs(m_max - m_min);
  T scale = 0, factor = 0 ;

  while (inc * steps > (m_maximum-m_minimum))
  if (inc/10 > 0 ) inc/=10;
  else break;

  bool done = false;
  while ( diff > scale ) 
   { factor+=static_cast<T>(inc);  scale = factor * steps;  }
   
  while (!done)
  {
     m_max=0;
     while ( m_max < m_maximum ) m_max +=factor;
     m_min = m_max - scale;
     if (m_min <= m_minimum ) done = true;
     else { factor+=static_cast<T>(inc); scale = factor * steps; }
  }
  // Wprowadzenie koretkty by skala nie przesuwa�a si� w lewo na osi X
  if (left)
  	while (m_min + factor <= m_minimum)
  	{
	   	m_min+=factor;
   		m_max+=factor;
  	}

 return (m_max != max_tmp) | (m_min != min_tmp);
}


#endif // _FUNCTIONS_H_
