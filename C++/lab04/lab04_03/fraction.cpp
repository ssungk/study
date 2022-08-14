#include <iomanip>
#include "Fraction.h"

CFraction::CFraction(void)
{
	m_nNumerator     =0; 
	m_nDenominator   =1; 
}

CFraction::CFraction (int nNumer)
{
	m_nNumerator = nNumer;
	m_nDenominator = 1;
}

CFraction::CFraction (int nNumer, int nDenom)
{
	if(nDenom==0)
	{
		cout << "can not divide by 0" << endl;
		exit(100);
	}
		
	int gcd = GreatestComDiv(nNumer,nDenom);
	nNumer = nNumer / gcd;
	nDenom = nDenom / gcd;

	if(nDenom < 0)
	{
		nDenom = -nDenom;
		nNumer = -nNumer;
	}

	m_nNumerator = nNumer;
	m_nDenominator = nDenom;
}

void CFraction::store (int nNumer, int nDenom)
{
	if(nDenom==0)
	{
		cout << "can not divide by 0" << endl;
		exit(100);
	}

	int gcd = GreatestComDiv(nNumer,nDenom);
	nNumer = nNumer / gcd;
	nDenom = nDenom / gcd;

	if(nDenom < 0)
	{
		nDenom = -nDenom;
		nNumer = -nNumer;
	}
		
	m_nNumerator = nNumer;
	m_nDenominator = nDenom;

	return;
}

void CFraction::print () const
{
	cout << m_nNumerator << "/" << m_nDenominator ;
	return;
}

int  CFraction::GreatestComDiv(int nNumer,int nDenom)
{
	if (nDenom == 0)
	{
		return nNumer;
	}
    return GreatestComDiv(nDenom,nNumer % nDenom);
}

void CFraction::printThisValue(void)
{
		cout << setw(20) << "this = 0x" << this << endl;
}
void CFraction::printThisValueWithArgument(const CFraction &dummyFr)
{
	cout << setw(20) << "this = 0x" << this << endl;
	cout << setw(20) << "&dummyFr = 0x" << &dummyFr << endl;
}

CFraction:: ~CFraction(void)
{
}

