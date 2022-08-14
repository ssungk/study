#include <iostream>
using namespace std;
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"

Base::Base()
{
	Num1 = 0;
}

void Base::set(int n)
{
	Num1 = n;
}

void Base::print()
{
	cout << Num1;
}