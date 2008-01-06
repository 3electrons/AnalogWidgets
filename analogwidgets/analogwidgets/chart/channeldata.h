/***************************************************************************
 *   Copyright (C) 2006-2008 by Tomasz Ziobrowski                          *
 *   http://www.3electrons.com                                             *
 *   e-mail: t.ziobrowski@3electrons.com                                   *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef CHANNELDATA_H
#define CHANNELDATA_H
#include <utility>

namespace chart
{
  class ChannelData
  {
    public:
    /**
    * Inicjuje kana³ danych w taki sposób by zwraca³ pozycjê pierwszego elementu
    * po wywo³aniu metody next
    * @return True je¿eli pojemnik zawiera dane w przeciwnym wypadku zwraca false
    */
    virtual bool init() = 0 ; // ustawia pojemnik na pierwszym elemencie ...
    /**
    * Ustawia warto¶ci x oraz y kolejnych punktów danych zaczynaj±c od pierwszego
    * tak d³ugo dopóki s± jakie¶ elementy zwracaj±c warto¶æ true tak d³ugo a¿
    * znajduje siê co¶ jeszcze w tym strumieniu
    * @return Zwraca warto¶æ false gdy osi±gnie koniec strumienia danych
    */
    virtual bool next(double & x, double & y) = 0;
    
    /** Zwraca ilo¶æ elementów */
    virtual int size() = 0;
    /** Destruktor wirtualny by mozna bylo ³adnie posprz±taæ */
    virtual ~ChannelData()
    { ; }
    
    virtual std::pair<double,double> findX(double x)=0; 

  };// class ChannelData
}; // namespace chart
#endif // CHANNELDATA_H
