#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	int b = 3;
	int c = 7;

	int* p = &b;
	int* q;
	int* r;

	q = p;
	r = p;

	p = &a;
	*p = 5;

	r = &c;
	*r = a + b + c;

	cout << "a = " << *p << "(" << p <<")" << endl;
	cout << "b = " << *q << "(" << q <<")" << endl;
	cout << "c = " << *r << "(" << r <<")" << endl;

	return 0;
}