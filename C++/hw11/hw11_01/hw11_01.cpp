#include <iostream>
#include <exception>
#include <vector>
using namespace std;

int main (void)
{
	vector<int> myvector;
	try
	{
		myvector.resize(myvector.max_size()+1);
	}
	catch(exception& error)
	{
		cout << "Length error : " << error.what() << endl;
	}

	return 0;
}