#include <iostream>
using namespace std;
#include "fraction.h"

int main(void)
{
	fraction* pfr;
	pfr = new fraction;
	(*pfr).store(2,3);
	(*pfr).print();

	return 0;
}

