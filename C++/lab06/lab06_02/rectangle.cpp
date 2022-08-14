#include <iostream>
using namespace std;
#include "rectangle.h"

rectangle::rectangle()
{
	m_nwidth = 0;
	m_nheight = 0;
}
rectangle::rectangle(int nwidth,int nheight)
{
	m_nwidth = nwidth;
	m_nheight = nheight;
}

void rectangle::store(int nwidth,int nheight)
{
	m_nwidth = nwidth;
	m_nheight = nheight;
}
void rectangle::printarea()
{
	cout << "Area = " << m_nwidth * m_nheight << endl;
}
