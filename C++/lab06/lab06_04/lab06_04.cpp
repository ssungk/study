#include <iostream>
using namespace std;

union share4bytes
{
	char charr[4];
	int nnumlong;
	short nnumshort[2];
	
};

void main()
{
	share4bytes data = {'A','B','C','\0'};

	cout << data.charr << endl;

	cout << "0x" << hex << data.nnumlong << endl;

	cout << "0x" << hex << data.nnumshort[0] << endl;
	cout << "0x" << hex << data.nnumshort[1] << endl;


	return;
}