#include <iostream>
using namespace std;

#include "Cart.h"

int main()
{
	PRODUCT productPriceAry[] = {{1001, 1000}, {2001, 5000}, {2002, 7500}, {3001, 5000}, {3002, 10000}, {3003, 3000}};	
	cout << "[Cart management program]" << endl;
	Cart ca1;
	ca1.add(1001);
	ca1.add(2001);
	ca1.print();

	Cart ca2(ca1);
	ca2.remove(1001);
	ca2.add(2002);
	ca2.print(productPriceAry);	

	ca1.remove(2001);
	ca1.remove(2002);
	ca1.print();

	ca1.remove(1001);

	Cart ca3;
	ca3.add(1001);
	ca3.add(2001);
	ca3.add(2001);
	ca3.add(2002);
	ca3.add(2002);
	ca3.add(2002);
	ca3.add(3001);
	ca3.add(3002);
	ca3.add(3003);
	ca3.add(3003);
	ca3.add(3003);	
	
	return 0;
}
