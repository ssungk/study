#include <iostream>
using namespace std;

#include "Cart.h"

Cart::Cart()
{
	nProducts = 0;
	for(int i=0; i<10; i++) productID[i] = 0;
}

Cart::Cart(const Cart& ca)
{
	nProducts = ca.nProducts;
	for(int i=0; i<10; i++) productID[i] = ca.productID[i];
}

void Cart::add(int pID)
{
	if( nProducts < 10 )
	{
		productID[nProducts] = pID;				
		nProducts++;
		cout<< "...Add " << pID << "...done!" << endl;
	}
	else
	{
		cout<< "...Add " << pID << "...fail! - The cart is FULL!" << endl;		
	}
	
}
void Cart::remove(int pID)
{
	if( nProducts != 0 )
	{		
		for(int i=0; i<nProducts; i++)
		{
			if(productID[i] == pID)
			{				
				for(int j=i; j<nProducts; j++)
				{
					productID[j] = productID[j+1];
				}
			}
		}
		productID[nProducts] = 0;		

		nProducts--;
		cout<< "...Remove " << pID << "...done!" << endl;
	}
	else
	{
		cout<< "...Remove " << pID << "...fail! - The cart is EMPTY!" << endl;
	}
}

void Cart::print()
{
	if( nProducts != 0 )
	{
		cout << endl << "PID" << endl;
		cout << "====" << endl;
		for(int i=0; i<nProducts; i++)
		{
			cout << productID[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "...No items in the cart!!" << endl;
	}	
}

void Cart::print(PRODUCT productPriceAry[])
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