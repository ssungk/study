#include <iostream>
using namespace std;

#include "Cart.h"

const PRODUCT Cart::productPriceAry[] = {{1001, 1000}, {2001, 5000}, {2002, 7500}, {3001, 5000}, {3002, 10000}, {3003, 3000}};	

Cart::Cart()
{
	nProducts = 0;
	productID = new int[10];	
}

Cart::Cart(int num)
{
	nProducts = 0;
	productID = new int[num];	
}

Cart::Cart(const Cart& ca)
{
	nProducts = ca.nProducts;
	productID = ca.productID;
}

void Cart::print()
{
	if( nProducts != 0 )
	{
		cout << endl << "PID     Price" << endl;
		cout << "==============" << endl;
		for(int i=0; i<nProducts; i++)
		{
			cout << productID[i] << "     ";
			for(int j=0; j<6; j++)
			{	
				if( productID[i] == productPriceAry[j].pID )
				{
					cout << productPriceAry[j].price << endl;
				}
			}			
		}	
		cout << endl;
	}
	else
	{
		cout << "...No items in the cart!!"<< endl;
	}	
}