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

	cout << "�����Է� : ";
	cin >> a;
	cout << "���� ���ڴ� : " << a << endl;

	cout << "\n�����Է� : ";
	cin >> *p;
	cout << "���� ���ڴ� : " << a << endl;

	cout << "\n�����Է� : ";
	cin >> **q;
	cout << "���� ���ڴ� : " << a << endl;

	cout << "\n�����Է� : ";
	cin >> ***r;
	cout << "���� ���ڴ� : " << a << endl;
	
	return 0;
}