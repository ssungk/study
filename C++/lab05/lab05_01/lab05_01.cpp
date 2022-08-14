#include <iostream>
using namespace std;
#include "fraction.h"

void fraction::print()
{
	cout << numerator << "/" << denominator << endl;
	return;
}

int main(void)
{
	fraction fr1;
	fr1.store(2,3);
	fr1.print();

	return 0;
}