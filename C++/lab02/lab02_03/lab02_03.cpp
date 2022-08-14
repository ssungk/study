#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ary[5] = {10, 20, 30, 40, 50};
	int* pary = ary;
	// 포인터 산술 연산 표현을 활용한 출력

	cout << setw(23) << "포인터 산술연산";
	for(int k=0; k<5; k++ )
	{
	cout << setw(9) << "pAry+" << k;
	}
	cout << endl;

	cout << setw(23) << "포인터 산술연산 결과";
	for(int k=0; k<5; k++ )
	{
	cout << setw(10) << pary+k;
	}
	cout << endl;// (코드 작성) 포인터 산술연산 결과 출력

	cout << setw(23) << "배열 포인터 역참조";
	for(int k=0; k<5; k++ )
	{
	cout << setw(10) << ary[k];
	}
	cout << endl;// (코드 작성)배열 포인터 역참조 통한 배열 원소 출력

	cout << setw(23) << "포인터에 배열 첨자 연산";
	for(int k=0; k<5; k++ )
	{
	cout << setw(10) << *(pary+k);
	}
	cout << endl;// (코드 작성)포인터를 이용한 배열 첨자 연산

	return 0;
}