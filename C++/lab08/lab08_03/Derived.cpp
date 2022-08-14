#include <iostream>
using namespace std;
#include "Derived.h"


Derived::Derived()
{
}

Derived::Derived(int a,int b,int c,int d) : Base(a,b)
{
	m_val3 = c;
	m_val4 = d;
}


void Derived::printSum()
{
	cout << "[Derived Class] " << m_val3 << " + " << m_val4 << " = " << m_val3 + m_val4 << endl;
}