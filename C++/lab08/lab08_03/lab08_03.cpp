#include <iostream>
using namespace std;
#include "Base.h"
#include "Derived.h"




int main()
{
	Base baseObj(10, 20);
	Derived derObj(30,50,70,90);


	baseObj.printSum();
	derObj.printSum();

	baseObj = derObj;
//	derObj = baseObj; 


	cout << endl << "After assign derived object to base object.." << endl << endl;

	baseObj.printSum();
	derObj.printSum();

	
	return 0;
}