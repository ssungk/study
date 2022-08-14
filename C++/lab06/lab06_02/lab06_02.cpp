#include <iostream>
using namespace std;
#include "rectangle.h"

void main()
{
	rectangle arrrect[3] = {rectangle(3,5),rectangle(2,2)};
	arrrect[2].store(5,5);
	int i;
	for(i=0;i<3;i++)
	{
		cout << i << " : "; 
		arrrect[i].printarea();
	}
	return;
}