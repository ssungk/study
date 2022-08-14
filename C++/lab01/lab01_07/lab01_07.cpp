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

다음 출력의 의미를 생각해 보자.

출력된 값 78은 i의 0x12345678 중 맨뒤에 78인 것 같습니다.*/