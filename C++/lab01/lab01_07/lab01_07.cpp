#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i = 0x12345678;         
	int* pi = &i;

	char c = 'C';
	char* pc = &c;

	float f = 700.5f;
	float* pf = &f;

	bool b = true;
	bool* pb = &b;

	short int s = 456;
	short int* ps = &s;
	
	pc = (char*)&i;
	
	cout << hex << "*pc = " << (int) *pc << endl;

    return 0;
}









/*

���� ����� �ǹ̸� ������ ����.

��µ� �� 78�� i�� 0x12345678 �� �ǵڿ� 78�� �� �����ϴ�.*/