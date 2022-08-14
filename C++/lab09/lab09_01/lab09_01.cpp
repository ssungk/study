#include <iostream>
using namespace std;


template <class DATATYPE>
DATATYPE abs_Tpl(DATATYPE num)
{
	if(num<0) num = -num;
	return num;// 절대값 구하는 코드
}

void main()
{
	int a = -5;
	double b = -3.14;
	long int c = -153L;
	cout << "a의 절대값 : " << abs_Tpl(a) << endl;
	cout << "b의 절대값 : " << abs_Tpl(b) << endl;
	cout << "c의 절대값 : " << abs_Tpl(c) << endl;
}