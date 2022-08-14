#include <string>
#include <iostream>
using namespace std;

int main()
{
	try
	{
		string str( "Program" );
		string rstr( "ming" );
		str.append( rstr, 5, 3 );
		cout << str << endl;
	}
	catch(exception& error)
	{
		cout << "Caught : " << error.what() << endl;
	}
}