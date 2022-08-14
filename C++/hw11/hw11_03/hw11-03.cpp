#include <iostream>
#include <stdexcept>
#include <bitset>
using namespace std;
int main (void)
{
	// bitset 생성자는 0과 1만을 포함하는 문자열을 입력받을 수 있다.
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