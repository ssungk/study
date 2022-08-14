#include "Fraction.h"

/*CFraction::CFraction ( void )
{ 
	m_nNumerator = 0;// 분자
	m_nDenominator = 1;// 분모 
}
*/
//실습1번

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