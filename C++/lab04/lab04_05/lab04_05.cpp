#include <iostream>
using namespace std;
#include "Fraction.h"

void getData(int&,int&);
void getData(int&);

int main()
{
	cout << "fraction computer." << endl;

	int nNumer = 0;
	int nDenom = 0;
	int nMenu = 1;

	while(nMenu)
	{
		cout << "please choose a operator item" << endl;
		cout << "0. exit" << endl << "1. add" << endl << "2. subtract" << endl << "3. multiply" << endl << "4. divide" << endl;
		cout << "operator item : ";
		cin >> nMenu;

		if(nMenu == 0) continue;

		if(nMenu < 0 || 4 < nMenu)
		{
			cout << "please choose the correct menu item!" << endl;
			continue;
		}

		cout << "please enter the first fraction." << endl;
		getData(nNumer, nDenom);
		CFraction fr1(nNumer, nDenom);

		cout << "please enter the second fraction." << endl;
		getData(nNumer, nDenom);
		CFraction fr2(nNumer, nDenom);
		cout << endl;

		switch(nMenu)
		{
		case 1:
			fr1.print();
			cout << " + ";
			fr2.print();
			cout << " = ";
			fr1.add(fr2);//内靛
			fr1.print();
			cout << endl;
			break;

		case 2:
			fr1.print();
			cout << " - ";
			fr2.print();
			cout << " = ";
			fr1.subtract(fr2);//内靛
			fr1.print();
			cout << endl;
			break;

		case 3:
			fr1.print();
			cout << " * ";
			fr2.print();
			cout << " = ";
			fr1.multiply(fr2);//内靛
			fr1.print();
			cout << endl;
			break;

		case 4:
			fr1.print();
			cout << " / ";
			fr2.print();
			cout << " = ";
			fr1.divide(fr2);//内靛
			fr1.print();
			cout << endl;
			break;
		default:
			break;
		}

		cout << endl << endl;
	}
	cout<< "\nThank you for using fraction." << endl;
	
	return 0;
}



void getData(int& nNumer, int& nDenom)          
{
	cout << "Please enter the numerator : " ;
	cin >> nNumer;

	cout << "Please enter the denominator : ";
	cin >> nDenom;
	
	return;
}

void getData(int& nNumer)
{
	cout << "Please enter the numerator : " ;
	cin >> nNumer;

	return;
}