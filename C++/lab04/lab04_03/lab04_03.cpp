#include <iostream>
#include <iomanip>
using namespace std;
#include "Fraction.h"

void getData(int&,int&);
void getData(int&);

int main()
{
	int nNumer = 0;
	int nDenom = 0;
	
	getData(nNumer, nDenom);

	CFraction fr1 (nNumer,nDenom);
	cout << "fr1 contains : ";
	fr1.print();
	cout << endl;
	cout << setw(20) << "&fr1 = 0x" << &fr1 << endl;
	fr1.printThisValue();

	CFraction fr2(fr1);
	cout << "fr2 contains : ";
	fr2.print();
	cout << endl;
	cout << setw(20) << "&fr2 = 0x" << &fr2 << endl;
	fr2.printThisValue();
	cout << endl << endl;
			
	CFraction fr3(fr1);
	CFraction fr4(fr1);
	cout << setw(20) << "&fr3 = 0x" << &fr3 << endl;
	cout << setw(20) << "&fr4 = 0x" << &fr4 << endl;
	fr3.printThisValueWithArgument(fr4);
	
	return 0;
}

void getData(int& nNumer, int& nDenom)          
{
	cout << "Please enter the numerator : " ;
	cin >> nNumer;

	cout << "Please enter the denominator : ";
	cin >> nDenom;
	
	return;
}

void getData(int& nNumer)
{
	cout << "Please enter the numerator : " ;
	cin >> nNumer;

	return;
}