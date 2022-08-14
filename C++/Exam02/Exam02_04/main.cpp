#include <iostream>
using namespace std;

#include "Cart.h"

int main()
{	
	cout << "[Cart management program]" << endl;
	Cart ca1;
	add(ca1, 1001);
	add(ca1, 2001);
	ca1.print();

	Cart ca2(ca1);
	remove(ca2, 1001);
	add(ca2, 2002);
	ca2.print();	

	remove(ca1, 2001);
	remove(ca1, 2002);
	ca1.print();

	remove(ca1, 1001);

	Cart ca3;
	add(ca3, 1001);
	add(ca3, 2001);
	add(ca3, 2001);
	add(ca3, 2002);
	add(ca3, 2002);
	add(ca3, 2002);
	add(ca3, 3001);
	add(ca3, 3002);
	add(ca3, 3003);
	add(ca3, 3003);
	add(ca3, 3003);	
	
	return 0;
}
