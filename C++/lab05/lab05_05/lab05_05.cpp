#include <iostream>
using namespace std;

#include "fraction.h"

void getData(int&,int&);
void getData(int&);

void getData(int& nNumer, int& nDenom)          
{
	cout << "Please enter the numerator : " ;
	cin >> nNumer;

	cout << "Please enter the denominator : ";
	cin >> nDenom;
	
	return;
}

void getData(int& nNumer)
{
	cout << "Please enter the numerator : " ;
	cin >> nNumer;

	return;
}



int main(void)
{
	fraction fr1(1,5);
	fraction fr2(2,5);
	
	fr1.add(fr2);
	fr2.substract(fr1);
	fr2.add(fr2);
	fr1.substract(fr1);
	fr1.printstatic();
	fr2.printstatic();
	fraction::printstatic();


	return 0;
}