#include "Fraction.h"

/*CFraction::CFraction ( void )
{ 
	m_nNumerator = 0;// ����
	m_nDenominator = 1;// �и� 
}
*/
//�ǽ�1��

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