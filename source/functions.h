/***************************************************************************
 *   Copyright (C) 2004 by KanadaKid                                       *
 *   genesisX11@verizon.net                                                *
 *   Updated (6/12/04)                                                     *
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

// Define functions for operations
int addition (int a, int b)
{
	int c;
	c=a + b;
	return c;
}

int subtraction (int d, int e)
{
	int f;
	f=d - e;
	return f;
}

int multi (int g, int h)
{
	int i;
	i=g * h;
	return i;
}

int division (int j, int k)
{
	int l;
	l=j / k;
	return l;
}

int percent (int m, int n)
{
	int o;
	o = m % n;
	return o;
}

long factorial (long p)
{
	if (p > 1)
		return ( p * factorial (p-1));
	else
		return (1);
}
		
// End of file
