#include <iostream>
using namespace std;
#include "fraction.h"

int fraction::naddopcount=0;
int fraction::nsubstractcount=0;

fraction::fraction()
{
	numerator=0;
	denominator=1;
	nsubstractcount=0;
}
fraction::fraction(int n,int d)
{
	numerator=n;
	denominator=d;
	nsubstractcount=0;
}

fraction::fraction (int nNumer)
{
	numerator = nNumer;
	denominator = 1;
	nsubstractcount=0;
}

fraction:: ~fraction(void)
{
}

void fraction::print()
{
	cout << numerator << "/" << denominator << endl;
	return;
}

void fraction::printstatic()
{
	cout << "naddopcount = " << naddopcount << "    nsubstractcount = " << nsubstractcount << endl;
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

void fraction::add(fraction& fr)
{
	numerator = (numerator)*(fr.denominator) + (denominator)*(fr.numerator);
	denominator = (denominator)*(fr.denominator);

	
	int gcd = GreatestComDiv(numerator,denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;

	if(denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
	naddopcount++;

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

void fraction::substract(fraction& fr)
{
	numerator = (numerator)*(fr.denominator) - (denominator)*(fr.numerator);
	denominator = (denominator)*(fr.denominator);

	
	int gcd = GreatestComDiv(numerator,denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;

	if(denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
	nsubstractcount--;

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
