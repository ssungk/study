#include "fraction.h"

CFraction add(const CFraction& fr1,const CFraction& fr2)
{
	int n = (fr1.m_nNumerator)*(fr2.m_nDenominator) + (fr1.m_nDenominator)*(fr2.m_nNumerator);
	int d = (fr1.m_nDenominator)*(fr2.m_nDenominator);

	return CFraction(n,d);
}
CFraction subtract(const CFraction& fr1,const CFraction& fr2 )
{
	int n = (fr1.m_nNumerator)*(fr2.m_nDenominator) - (fr1.m_nDenominator)*(fr2.m_nNumerator);
	int d = (fr1.m_nDenominator)*(fr2.m_nDenominator);//�ڵ� �߰� : return fr1 = fr1 - fr2
			
	return CFraction(n,d);
}
CFraction multiply(const CFraction& fr1,const CFraction& fr2 )
{
	int n = (fr1.m_nNumerator)*(fr2.m_nNumerator);
	int d = (fr1.m_nDenominator)*(fr2.m_nDenominator);//�ڵ� �߰� : return fr1 = fr1 * fr2

	return CFraction(n,d);
}
CFraction divide(const CFraction& fr1,const CFraction& fr2 )
{
	int n = (fr1.m_nNumerator)*(fr2.m_nDenominator);
	int d = (fr1.m_nDenominator)*(fr2.m_nNumerator);//�ڵ� �߰� : return fr1 = fr1 / fr2

	return CFraction(n,d);
}
