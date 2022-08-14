#include <iostream>
using namespace std;
#include "Fraction.h"

void getData(int&,int&);

void store(int nNumer,int nDenom,CFraction &fr)
{
	if(nDenom==0)
	{
		cout << "can not divide by 0" << endl;
		exit(100);
	}

	int gcd = fr.GreatestComDiv(nNumer,nDenom);
	nNumer = nNumer / gcd;
	nDenom = nDenom / gcd;

	if(nDenom < 0)
	{
		nDenom = -nDenom;
		nNumer = -nNumer;
	}
		
	fr.m_nNumerator = nNumer;
	fr.m_nDenominator = nDenom;
}

void print(const CFraction &fr)
{
	cout << fr.m_nNumerator << "/" << fr.m_nDenominator ;
	return;
}

int main()
{
	cout << "this program creates a fraction." << endl;
	int nNumer = 0;
	int nDenom = 0;
	getData(nNumer,nDenom);

	CFraction fr1;
	store(nNumer,nDenom,fr1);
	cout << "fr1 contains : ";
	print(fr1);

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

