#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Enter the dividend : ";
	double dividend;
	cin >> dividend;
	cout << "Enter the divisor : ";
	double divisor;
	cin >> divisor;

	try
	{
		if(divisor == 0.00)
			throw divisor;
		double qutient = dividend / divisor;
		cout << "Quoitent : " << qutient << endl;
	}
	catch(double& error)
	{
		cout << "**Error 100: divisor 0\n";
		return 1;
	}
	return 0;
}