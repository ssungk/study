#include<iostream>
using namespace std;

#include "Fraction.h"

int main()
{
	CFunny fn1(4);
	fn1.Print();
	
	int nNum;
	cin >> nNum;
	CFunny fn2(nNum);
	fn2.Print();

	CFunny fn3(fn2);
	fn3.Print();

	return 0;
}


