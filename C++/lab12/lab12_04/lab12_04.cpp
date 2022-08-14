#include <iostream>
#include <cstdlib>
using namespace std;

#include "math.h"
#define FLUSH while(cin.get() != '\n')

int main()
{
	cout << "Begin Error class demonstration\n";

	cout << "Enter the first data : ";
	double data1;
	cin >> data1;
	cout << "Enter the second data : ";
	double data2;
	cin >> data2;
	cout << "Enter the operator : ";
	char oper;
	cin >> oper;
	FLUSH;

	try
	{
		double result = math(oper,data1,data2);
		cout << "result" << result << endl;
	}
	catch(Error& error)
	{
		error.printMessage();
		exit(100);
	}
	cout << "Normal end of demonstration\n";
	return 0;
}

