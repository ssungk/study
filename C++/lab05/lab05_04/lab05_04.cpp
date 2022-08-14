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
	fraction fr1(3,5);
	fraction fr2(7,10);
	fraction fr3;

	fr3 = fr1+fr2;
	cout << "value of fr3 after fr3 = fr1 + fr2 operation:";
	fr3.print();
	fr3 = fr1-fr2;
	cout << "value of fr3 after fr3 = fr1 - fr2 operation:";
	fr3.print();
	fr3 = fr1*fr2;
	cout << "value of fr3 after fr3 = fr1 * fr2 operation:";
	fr3.print();
	fr3 = fr1/fr2;
	cout << "value of fr3 after fr3 = fr1 / fr2 operation:";
	fr3.print();

	return 0;
}