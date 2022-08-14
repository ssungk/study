#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	string s1("This is the string");

	cout << "Testing out_of_rane exception\n";
	int position;
	cout << "Input position : ";
	cin >> position;

	try
	{
		cout << "s1(position) contains : " << s1.at(position) << endl;
	}
	catch(exception & err)
	{
		cout << err.what() << endl;
	}
	cout << "End of exception test\n";

	return 0;
}


