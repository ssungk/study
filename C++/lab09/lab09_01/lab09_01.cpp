#include <iostream>
using namespace std;


template <class DATATYPE>
DATATYPE abs_Tpl(DATATYPE num)
{
	if(num<0) num = -num;
	return num;// ���밪 ���ϴ� �ڵ�
}

void main()
{
	int a = -5;
	double b = -3.14;
	long int c = -153L;
	cout << "a�� ���밪 : " << abs_Tpl(a) << endl;
	cout << "b�� ���밪 : " << abs_Tpl(b) << endl;
	cout << "c�� ���밪 : " << abs_Tpl(c) << endl;
}