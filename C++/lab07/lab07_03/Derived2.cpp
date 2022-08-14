#include <iostream>
using namespace std;
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"


Derived2::Derived2()
{
	Num3 = 0;
}

void Derived2::initialize(int a,int b,int c)
{
	set(a);
	Num2 = b;
	Num3 = c;
}

void  Derived2::printVal()
{
	cout << "입력한 값은 "; 
	print();
	cout << ", " << Num2 << ", " << Num3 << " 입니다." << endl;
}