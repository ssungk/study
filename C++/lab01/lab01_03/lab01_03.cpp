#include <iostream>
#include <iomanip>
using namespace std;

void swapvalue (int,int);
void swapref (int&,int&);
void swapaddr (int*,int*);


int main()
{
	int x = 5;
	int y = 7;

	int *px = &x;  
	int *py = &y; 

	swapvalue (x, y);     
	cout << "swapValue()함수 호출 후 "<< setw(5) << x << setw(5) << y << endl;

	swapref (x, y);     
	cout << "swapRef()함수 호출 후   "<< setw(5) << x << setw(5) << y << endl;

	swapaddr (px, py);   
	cout << "swapAddr()함수 호출 후  "<< setw(5) << x << setw(5) << y << endl;

	swapaddr (&x, &y);   
	cout << "swapAddr()함수 호출 후  "<< setw(5) << x << setw(5) << y << endl;    


	return 0;
}
void swapvalue (int x,int y)
{
	int temp = x;
	x = y;
	y = temp;

	return;
}
void swapref (int& x,int& y)
{
	int temp = x;
	x = y;
	y = temp;
	
	return;
}
void swapaddr (int* px,int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
	
	return;
}