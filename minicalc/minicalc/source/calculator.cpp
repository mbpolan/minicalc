/*
 *************************** 
 * Mini Calculator         *
 * by KanadaKid            *
 * http://kanada-portal.tk *
 * 3/20/04 - update        *
 ***************************
*/


#include <iostream>
#include <string>
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

main ()
{
	int y, z; // y and z are operation variables
	string x;
	string s1 = "addition";
        string s2 = "subtraction";
	string s3 = "multiply";
	string s4 = "division";
	string s5 = "help";
        string s6 = "quit";
header:
	cout << "\n*********************\n";
	cout << "Mini-Calculator v1.5\n";
	cout << "by KanadaKid\n";
	cout << "*********************\n\n";
subheader:
	cout << "\n------------------";
	cout << "\nType 'help' for the help menu or 'quit' to exit.\n\n";
	cout << "Enter operation key: ";
	cin >> x;
	if ( x == s1 )
		goto add; // Addition
	if ( x == s2 )
		goto sub; // Subtraction
	if ( x == s3 )
		goto mult; // Multiplication
	if ( x == s4 )
		goto div; // Division
	if ( x == s5 )
		goto help; // Display help
	if ( x == s6)
		return 0;
	else
		cout << "\nInvalid operation\n";
		goto subheader;
add:
	cout << "\nADDITION\n";
	cout << "Enter first number: ";
	cin >> y;
	cout << "\nEnter second number: ";
	cin >> z;
	cout << "\nAnswer: " << y << " + " << z << " = " << addition (y, z) << endl;
	goto subheader;

sub:
	cout << "\nSUBTRACTION\n";
	cout << "Enter base number: ";
	cin >> y;
	cout << "\nEnter the number to subtract by: ";
	cin >> z;
	cout << "\nAnswer: " << y << " - " << z << " = " << subtraction (y, z) << endl;
	goto subheader;

mult:
	cout << "\nMULTIPLICATION\n";
	cout << "Enter first number: ";
	cin >> y;
	cout << "\nEnter second number: ";
	cin >> z;
	cout << "\nAnswer: " << y << " x " << z << " = " << multi (y, z) << endl;
	goto subheader;

div:
	cout << "\nDIVISION\n";
	cout << "Enter base number: ";
	cin >> y;
	cout << "\nEnter divisor: ";
	cin >> z;
	cout << "\nAnswer: " << y << " / " << z << " = " << division (y, z) << endl;
	goto subheader;

help:
	cout << "\nThis is a mini console calculator. To do a certain operation,\nDo one of the following things at the main screen: (type the commands without the quotes'')\n";
	cout << "For addition, type 'addition' and hit enter.\n";
	cout << "For subtraction, type 'subtraction' and hit enter.\nFor multiplication, type 'multiply' and hit enter.\nFinally, for division, type 'division' and hit enter.\n\n";
	cout << "To report bugs, please send an email to <genesisX11@verizon.net>. Thanks!\n\n";
	goto subheader;
}
	
