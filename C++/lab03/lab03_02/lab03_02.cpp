#include<iostream>
using namespace std;

#include "Fraction.h"

void getData(int* pnNumer,int* pnDenom);


int main()
{
		
	cout << "this program creates a fraction.h\n\n";

	int nNumer = 0;
	int nDenom = 0;

	getData(&nNumer,&nDenom);

	CFraction Fr;
	Fr.store(nNumer,nDenom);

	cout << "\n your fraction contains";
	Fr.print();


	cout << "\n\nthank you for using fractions"<< endl;
	return 0;
}

void getData(int* pnNumer,int* pnDenom)
{
	cout << "Please enter the numerator : ";
	cin >> *pnNumer;

	cout << "Please enter the denominator : ";
	cin >> *pnDenom;

	return;
}

