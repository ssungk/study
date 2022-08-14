#include <iostream>
using namespace std;

#include "Cart.h"

void add(Cart& ca, int pID)
{
	if( ca.nProducts < 10 )
	{
		ca.productID[ca.nProducts] = pID;				
		ca.nProducts++;
		cout<< "...Add " << pID << "...done!" << endl;	
	}
	else
	{
		cout<< "...Add " << pID << "...fail! - The cart is FULL!" << endl;	
	}
	
}
void remove(Cart& ca, int pID)
{
	if( ca.nProducts != 0 )
	{		
		for(int i=0; i<ca.nProducts; i++)
		{
			if(ca.productID[i] == pID)
			{				
				for(int j=i; j<ca.nProducts; j++)
				{
					ca.productID[j] = ca.productID[j+1];
				}
			}
		}
		ca.productID[ca.nProducts] = 0;		

		ca.nProducts--;
		cout<< "...Remove " << pID << "...done!" << endl;
	}
	else
	{
		cout<< "...Remove " << pID << "...fail! - The cart is EMPTY!" << endl;
	}
}