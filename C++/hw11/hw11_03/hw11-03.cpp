#include <iostream>
#include <stdexcept>
#include <bitset>
using namespace std;
int main (void)
{
	// bitset �����ڴ� 0�� 1���� �����ϴ� ���ڿ��� �Է¹��� �� �ִ�.
	try
	{
		bitset<5> mybitset (string("01234"));
	}
	catch(exception& error)
	{
		cout << "Invalid argument : " << error.what() << endl;
	}
	return 0;
}