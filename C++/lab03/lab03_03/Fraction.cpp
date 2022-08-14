#include "Fraction.h"

CFraction::CFraction ( void )
{ 
	m_nNumerator = 0;// ����
	m_nDenominator = 1;// �и� 
}


CFraction::CFraction (int nNumer)
{
	m_nNumerator = nNumer;
	m_nDenominator = 1;
	
	return;
}

CFraction::CFraction (int nNumer, int nDenom)
{
	store(nNumer, nDenom);
}

CFraction::CFraction (const CFraction& fr)
{
	m_nNumerator = fr.m_nNumerator;
	m_nDenominator = fr.m_nDenominator;

	return;
}

void CFraction :: store(int nmumer,int denom)
{
	m_nNumerator = nmumer;
	m_nDenominator = denom;
	return;
}

void CFraction :: print () const
{
	cout << m_nNumerator<< "/" << m_nDenominator;
	return;
}