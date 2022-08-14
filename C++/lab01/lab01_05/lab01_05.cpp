#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	int* p;
	int** q;
	int*** r;

	p = &a;
	q = &p;
	r = &q;

	cout << "숫자입력 : ";
	cin >> a;
	cout << "너의 숫자는 : " << a << endl;

	cout << "\n숫자입력 : ";
	cin >> *p;
	cout << "너의 숫자는 : " << a << endl;

	cout << "\n숫자입력 : ";
	cin >> **q;
	cout << "너의 숫자는 : " << a << endl;

	cout << "\n숫자입력 : ";
	cin >> ***r;
	cout << "너의 숫자는 : " << a << endl;
	
	return 0;
}