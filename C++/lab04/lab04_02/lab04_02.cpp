#include <iostream>
using namespace std;
#include "Fraction.h"

void getData(int&,int&);
void getData(int&);

int main()
{
	cout << "This program creates a fraction" << endl;

	int nNumer = 0;
	int nDenom = 0;
	
	getData(nNumer, nDenom);

	CFraction fr1 (nNumer,nDenom);
	cout << "fr1 contains : ";
	fr1.print();
	cout << endl;

	CFraction fr2;
	getData(nNumer, nDenom);
	fr2.store(nNumer, nDenom);
	cout << "fr2 contains  :";
	fr2.print();
	
	cout<< "\nThank you for using fraction." << endl;
			
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