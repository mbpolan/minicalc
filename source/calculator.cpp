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
#include <string>
#include "functions.h"
using namespace std;

int main (int argc, char *argv[])
{
	bool quit = true; // the QUIT flag (must be flagged FALSE to exit while())
	// make the class object
	operations calc;
	while(quit == true) {
	double y, z; // y and z are operation variables
	int percentVar, percentVar2; // only for %
	std::string x; // use for operations
	// now we must define the opertaions using string s[]
	std::string s[] = { "+", "-", "*", "/",
		       "help", "quit", "%", "c", "!" };
	cout << "\n\n*********************\n"
		"Mini-Calculator v1.7.1\n"
		"byKanadaKid\n"
		"*********************\n\n\n"
		"------------------------------------------------\n"
		"Type 'help' for the help menu or 'quit' to exit.\n"
		"------------------------------------------------\n\nEnter operation: ";
	cin >> x;

	if ( x == s[0] ) {
		cout << "\nADDITION\n";
		cout << "Enter first number: ";
		cin >> y;
		cout << "\nEnter second number: ";
		cin >> z;
		system("clear");
		cout << "\nAnswer: " << y << " + " << z << " = " << calc.addition (y, z) << endl;
		continue;
	}

	if ( x == s[1] ) {
		cout << "\nSUBTRACTION\n";
		cout << "Enter base number: ";
		cin >> y;
		cout << "\nEnter the number to subtract by: ";
		cin >> z;
		system("clear");
		cout << "\nAnswer: " << y << " - " << z << " = " << calc.subtraction (y, z) << endl;
		continue;
	}

	if ( x == s[2] ) {
		cout << "\nMULTIPLICATION\n";
		cout << "Enter first number: ";
		cin >> y;
		cout << "\nEnter second number: ";
		cin >> z;
		system("clear");
		cout << "\nAnswer: " << y << " x " << z << " = " << calc.multi (y, z) << endl;
		continue;
	}

	if ( x == s[3] ) {
		cout << "\nDIVISION\n";
		cout << "Enter base number: ";
		cin >> y;
		cout << "\nEnter divisor: ";
		cin >> z;
		system("clear");
		cout << "\nAnswer: " << y << " / " << z << " = " << calc.division (y, z);
		continue;
	}

	if ( x == s[6] ) {
		cout << "\nPERCENT\n";
		cout << "\nEnter percent: ";
		cin >> percentVar;
		cout << "\nEnter base number: ";
		cin >> percentVar2;
		system("clear");
		cout << "\n" << percentVar << "% of " << percentVar2 << " is " << calc.percent(percentVar, percentVar2);
		continue;
	}

	if ( x == s[7] ) {
		cout << "\nCIRCLE AREA\n"
		<< "Enter radius: ";
		cin >> y;
		cout << "\nEnter unit of measure: ";
		cin >> x;
		system("clear");
		cout << "\nArea: " << 3.14*(y*2) << " " << x;
		continue;
	}

	if ( x == s[8]) {
		cout << "\nFACTORIALS\n"
		     << "Enter base number: ";
		cin >> y;
		system("clear");
		cout << "Answer: !" << y << " = " << calc.factorial(y);
		continue;
	}
		
	if ( x == s[4] ) {
		// help body
		cout << "For addition, type '+' and hit enter.\nFor subtraction, type '-' and hit enter.\nFor multiplication, type '*' and hit enter.\nFinally, for division, type '/' and hit enter.\nTo do percents, type '%' and hit enter.\n To find the area of a circle, type 'c' and hit enter.\nTo find the factorial of a number, type '!' and hit enter.\n\nTo report bugs, please send an email to <genesisX11@verizon.net>. Thanks!\nOfficial homepage at minicalc.sf.net\n\n";
		continue;
	}

	if ( x == s[5]) {
		cout <<"\nQuitting...\n";
		quit = false;
	}
	// if an invalid operation is preformed, resort to this
	else
	{
		cout << "\nInvalid operation\n";
		continue;
	}
    }
	return 0; // kill the program
	cout << endl;
}
