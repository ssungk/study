#include "Fraction.h"

CFunny::CFunny(int nNum)
{
	m_nNum = nNum;
}

CFunny::~CFunny(void)
{
}

void CFunny::Print(void) const
{
	cout << m_nNum << endl;
}
