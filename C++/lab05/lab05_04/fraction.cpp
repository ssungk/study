#include <iostream>
using namespace std;
#include "fraction.h"

fraction::fraction()
{
	numerator=0;
	denominator=1;
}
fraction::fraction(int n,int d)
{
	numerator=n;
	denominator=d;
}

fraction::fraction (int nNumer)
{
	numerator = nNumer;
	denominator = 1;
}

fraction:: ~fraction(void)
{
}

void fraction::print()
{
	cout << numerator << "/" << denominator << endl;
	return;
}



fraction fraction::operator = (const fraction& fr)
{
	numerator = fr.numerator;
	denominator = fr.denominator;
	return *this;
}

fraction fraction::operator + (const fraction& fr)
{
	int n = (numerator)*(fr.denominator) + (denominator)*(fr.numerator);
	int d = (denominator)*(fr.denominator);

	
	int gcd = GreatestComDiv(n,d);
	n = n / gcd;
	d = d / gcd;

	if(d < 0)
	{
		d = -d;
		n = -n;
	}
	
	return fraction(n,d);
}

fraction fraction::operator - (const fraction& fr)
{
	int n = (numerator)*(fr.denominator) - (denominator)*(fr.numerator);
	int d = (denominator)*(fr.denominator);

	
	int gcd = GreatestComDiv(n,d);
	n = n / gcd;
	d = d / gcd;

	if(d < 0)
	{
		d = -d;
		n = -n;
	}
	
	return fraction(n,d);
}

fraction fraction::operator * (const fraction& fr)
{
	int n = (numerator)*(fr.numerator);
	int d = (denominator)*(fr.denominator);

	
	int gcd = GreatestComDiv(n,d);
	n = n / gcd;
	d = d / gcd;

	if(d < 0)
	{
		d = -d;
		n = -n;
	}
	
	return fraction(n,d);
}

fraction fraction::operator / (const fraction& fr)
{
	
	int n = (numerator)*(fr.denominator);
	int d = (denominator)*(fr.numerator);
	
	int gcd = GreatestComDiv(n,d);
	n = n / gcd;
	d = d / gcd;

	if(d < 0)
	{
		d = -d;
		n = -n;
	}
	
	return fraction(n,d);
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
