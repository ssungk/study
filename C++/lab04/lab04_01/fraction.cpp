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

CFraction:: ~CFraction(void)
{
}

