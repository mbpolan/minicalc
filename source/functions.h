/***************************************************************************
 *   Copyright (C) 2004 by KanadaKid                                       *
 *   genesisX11@verizon.net                                                *
 *   Updated (7/17/04)                                                     *
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

#include <iostream>
using namespace std;

// define functions for operations in calculator.cpp

class operations {
	public:
		// constructor / destructor
		operations() { };
		~operations() { };
		double addition (double a, double b) {return a+b;}
		double subtraction (double a, double b) {return a-b;}
		double multi (double a, double b) {return a*b;}
		double division (double a, double b) {return a/b;}
		long int percent (long int a, long int b) {return a%b;}
		double factorial (double a);
	
};
double operations::factorial (double a) {
	if (a > 1)
		return ( a * factorial (a-1));
	else
		return (1);
};
