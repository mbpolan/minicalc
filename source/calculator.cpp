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
#include <string>
#include "functions.h"
using namespace std;

int main (int argc, char *argv[])
{
	while(true)
	{
	int y, z; // y and z are operation variables
	string x; // Used to figure out op
	string xc; // Used only in circle area for unit of measure
	string s[] = { "+", "-", "*", "/",
		       "help", "quit", "%", "c", "!" };
	cout << "\n\n";
	cout << "\n*********************\n";
	cout << "Mini-Calculator v1.7\n";
	cout << "by KanadaKid\n";
	cout << "*********************\n\n";
	cout << "\n------------------------------------------------";
	cout << "\nType 'help' for the help menu or 'quit' to exit."
	     << "\n------------------------------------------------\n\n";
	cout << "Enter operation: ";
	cin >> x;

	if ( x == s[0] )
	{
		cout << "\nADDITION\n";
		cout << "Enter first number: ";
		cin >> y;
		cout << "\nEnter second number: ";
		cin >> z;
		cout << "\nAnswer: " << y << " + " << z << " = " << addition (y, z) << endl;
		continue;
	}

	if ( x == s[1] )
	{
		cout << "\nSUBTRACTION\n";
		cout << "Enter base number: ";
		cin >> y;
		cout << "\nEnter the number to subtract by: ";
		cin >> z;
		cout << "\nAnswer: " << y << " - " << z << " = " << subtraction (y, z) << endl;
		continue;
	}

	if ( x == s[2] )
	{
		cout << "\nMULTIPLICATION\n";
		cout << "Enter first number: ";
		cin >> y;
		cout << "\nEnter second number: ";
		cin >> z;
		cout << "\nAnswer: " << y << " x " << z << " = " << multi (y, z) << endl;
		continue;
	}

	if ( x == s[3] )
	{
		cout << "\nDIVISION\n";
		cout << "Enter base number: ";
		cin >> y;
		cout << "\nEnter divisor: ";
		cin >> z;
		cout << "\nAnswer: " << y << " / " << z << " = " << division (y, z);
		continue;
	}

	if ( x == s[6] )
	{
		cout << "\nPERCENT\n";
		cout << "\nEnter percent: ";
		cin >> y;
		cout << "\nEnter base number: ";
		cin >> z;
		cout << "\n" << y << "% of " << z << " is " << percent(y, z);
		continue;;
	}

	if ( x == s[7] )
	{
		cout << "\nCIRCLE AREA\n"
		<< "Enter radius: ";
		cin >> y;
		cout << "\nEnter unit of measure: ";
		cin >> xc;
		cout << "\nArea: " << 3.14*(y*2) << " " << xc;
		continue;
	}

	if ( x == s[8])
	{
		cout << "\nFACTORIALS\n"
		     << "Enter base number: ";
		cin >> y;
		cout << "Answer: !" << y << " = " << factorial(y);
		continue;
	}
	
	if ( x == s[4] )
	{
		cout << "For addition, type '+' and hit enter.\n";
		cout << "For subtraction, type '-' and hit enter.\nFor multipl"
			"ication, type '*' and hit enter.\nFinally, for division,"
	        	"type '/' and hit enter.\nTo do percents, type '%' and hit enter.\n"
			"To find the area of a circle, type 'c' and hit enter."
			"\nTo find the factorial of a number, type '!' and hit enter.\n\n";
		cout << "To report bugs, please send an email to <genesisX11@verizon.net>. Thanks!\n\n\n\n";
		continue;
	}

	if ( x == s[5])
	{
		break;
	}
	else
	{
		cout << "\nInvalid operation\n";
		continue;
	}
	}
	return 0;
	cout << endl;
}


