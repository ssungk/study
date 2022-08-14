#include <iostream>
using namespace std;
#include "fraction.h"

fraction::fraction()
{
	numerator=0;
	denominator=0;
}
fraction::fraction(int n,int d)
{
	numerator=n;
	denominator=d;
}

void fraction::print()
{
	int gcd = GreatestComDiv(numerator,denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;

	cout << numerator << "/" << denominator << endl;
	return;
}

fraction fraction::operator = (const fraction& fr)
{
	numerator = fr.numerator;
	denominator = fr.denominator;
	return *this;
}

fraction fraction::operator += (const fraction& fr)
{
	numerator = (numerator * fr.denominator)+( fr.numerator*denominator) ;
	denominator *= fr.denominator;
	return *this;
}
fraction fraction::operator++()
{
	numerator += denominator;
	return *this;
}
fraction fraction::operator++(int)
{
	const fraction save(*this);
	numerator += denominator;
	return save;
}

int fraction::GreatestComDiv(int nNumer,int nDenom)
{
	if (nDenom == 0)
	{
		return nNumer;
	}
	return GreatestComDiv(nDenom,nNumer % nDenom);
}