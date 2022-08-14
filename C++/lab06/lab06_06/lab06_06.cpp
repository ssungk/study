#include <iostream>
using namespace std;

typedef int* PINT;
typedef int INT;
typedef unsigned long U32;
typedef unsigned short U16;
typedef unsigned char U8;

void main()
{
	PINT pint;
	pint = new int [3];

	U32 uA = -1;
	U16 uB = -1;
	U8 uC = -1;

	pint[0] = uA;
	pint[1] = uB;
	pint[2] = uC;

	cout << "U32's-1 : " << pint[0] << endl;
	cout << "U16's-1 : " << pint[1] << endl;
	cout << "U8's-1 : " << pint[2] << endl;

	return;
}