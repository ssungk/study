#include <iostream>
using namespace std;

template <class TYPE>
TYPE max (TYPE x, TYPE y)
{
	return (x > y) ? x : y ;
}

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int num, int den) :numerator(num), denominator(den){}
	int compare(Fraction fr2);
	void print() { cout << numerator << "/" << denominator << endl;}
};

int Fraction::compare(Fraction fr2)
{
	if (numerator*fr2.denominator - fr2.numerator*denominator > 0)
		return 1;
	else
		return -1;
}

Fraction max (Fraction x, Fraction y)
{
	if(x.compare(y)>0)
		return x;
	else
		return y;
}

void main()
{
	Fraction fr1(3,5);
	Fraction fr2(1,2);
	cout << "Max fraction is : ";
	max(fr1, fr2).print();
}