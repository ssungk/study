#include <iostream>
using namespace std;
#include "rectangle.h"


void store(int nwidth,int nheight);
void printarea();
void main()
{
	rectangle arrrect[3] = {rectangle(3,5),rectangle(2,2)};
	arrrect[2];store(5,5);
	int i;
	for(i=0;i<3;i++)
	{
		cout << i << " : "; 
		printarea();
	}
	return;
}

void store(int nwidth,int nheight)
{
	m_nwidth = nwidth;
	m_nheight = nheight;
}
void printarea()
{
	cout << "Area = " << m_nwidth * m_nheight << endl;
}
