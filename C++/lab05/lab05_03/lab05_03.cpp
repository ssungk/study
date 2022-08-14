#include <iostream>
using namespace std;

#include "fraction.h"

int main(void)
{
	fraction fr1(3,5);
	fraction fr2;
	fr2 = fr1;
	cout << "value of fr2 after fr2 = fr1 operation:";
	fr2.print();
	fr2 += fr1;
	cout << "value of fr2 after fr2 += fr1 opreration:";
	fr2.print();
	fr2++;
	cout << "value of fr2 after fr2 ++ opreration:";
	fr2.print();
	++fr2;
	cout << "value of fr2 after ++ fr2 opreration:";
	fr2.print();
	return 0;
}