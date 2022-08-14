#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ary[5] = {10, 20, 30, 40, 50}; // 배열의 선언과 초기화
	cout << setw(15) << "Print Element";

	for( int i=0; i<5; i++ )
	{
	cout << setw(10) << ary[i]; // 배열의 원소 출력(배열 첨자 연산자)
	}
	cout << endl;

	cout << setw(15) << "Address of Element";
	for( int i=0; i<5; i++ )
	{
	cout << setw(10) << &ary[i] ; // 배열의 원소 주소 출력(배열 첨자 연산자, 주소 연산자)
	}
	cout << endl;

	cout << setw(10) << "Ary = " << ary << endl; // '배열명'의 출력
	cout << setw(10) << "&Ary[0] = " << &ary[0] << endl; // '첫 번째 원소'의 주소 출력
	int* pary = ary; // 포인터를 배열의 이름으로 초기화
	cout << setw(10) << "pAry = " << pary << endl; // 포인터로서의 배열 이름 출력
	cout << setw(10) << "*pAry = " << *pary << endl; // 간접 연산자(*)를 통해 배열의 첫 번째 요소 접근
	cout << setw(10) << "*Ary = " << *ary << endl; // 배열명에 간접 연산자(*)을 통한 역참조
	cout << setw(10) << "pAry[0] = " << pary[0] << endl; // 포인터를 이용한 배열 첨자 연산자([])

	return 0;
}