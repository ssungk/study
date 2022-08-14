#include "Fraction.h"


SmartPhone::SmartPhone(void)
{ 
	int i;
	for(i=0;i<20;i++)
	{
	m_strName[i]=0;
	}
	m_nMemorySize=0;
}

SmartPhone::SmartPhone(char* strName,int nMemorySize)
{
	store(strName, nMemorySize);
}

void  SmartPhone::change(int nMemorySize)
{
	m_nMemorySize = nMemorySize;
}
void  SmartPhone::changeOSName(char* strName)
{
	int i;
	for(i=0;i<20;i++)
	{
	m_strName[i]=strName[i];
	}
	
}


void SmartPhone::store(char* strName,int nMemorySize)
{
	int i;
	for(i=0;i<20;i++)
	{
		m_strName[i] = strName[i];
	}

	m_nMemorySize = nMemorySize;
	return;
}

void SmartPhone :: print () const
{
	cout << m_strName << endl << m_nMemorySize  << "GByte" << endl;
	return;
}