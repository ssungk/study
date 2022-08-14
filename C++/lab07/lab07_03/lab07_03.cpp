#include <iostream>
using namespace std;
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"


int main()
{
	Derived2 der;
	der.initialize(10, 20, 30);
	der.printVal();

	return 0;
}

