#include <iostream>
using namespace std;
#include "Base.h"

Base::Base()
{
	m_val1 = 0;
	m_val2 = 0;
}
Base::Base(int a,int b) : m_val1(a), m_val2(b) 
{
}

void Base::printSum()
{
	cout << "[Base Class] " << m_val1 << " + " << m_val2 << " = " << m_val1 + m_val2 << endl;
}
