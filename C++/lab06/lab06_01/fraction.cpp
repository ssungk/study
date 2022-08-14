#include <iostream>
using namespace std;
#include "fraction.h"

fraction::fraction()
{
	m_pnum = new int;
	m_pdenom = new int;;
}


fraction::~fraction()
{
	delete m_pnum;
	delete m_pdenom;
}


void fraction::print()
{
	cout << *m_pnum << "/" << *m_pdenom << endl;
	return;
}


void fraction::store(int num,int denom)
{
	*m_pnum = num;
	*m_pdenom = denom;
}