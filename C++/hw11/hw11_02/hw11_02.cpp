#include <exception>
#include <string>
#include <iostream>
using namespace std;
static void f()
{
	throw runtime_error("runtime error called");
}
int main ()
{
	string s ;
	try
	{
		s.replace(100, 1, 1, 'c');
	}
	catch(exception& error)
	{
		cout << "Got an exception : " << error.what() << endl;
	}
	try
	{
		f();
	}
	catch(exception& error)
	{
		cout << "Got an exception : " << error.what() << endl;
	}

	return 0;
}