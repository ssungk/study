#include <bitset>
#include <iostream>
using namespace std;
int main()
{
	try
	{
		bitset< 33 > bitset;
		bitset[32] = 1;
		bitset[0] = 1;
		unsigned long x = bitset.to_ulong( );
	}
	catch(exception& error)
	{
		cout << "Caught" << error.what() << endl;
		cout << "Type " << typeid(error).name() << endl;
	}
}