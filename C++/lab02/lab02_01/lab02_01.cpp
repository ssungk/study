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

	cout << setw(15) << "Size of Memory";
	for( int i=0; i<5; i++ )
	{
		cout << setw(10) << sizeof(ary[i]); // 배열 각 원소의 메모리 사이즈 출력(sizeof() 함수
	}
	cout << endl;

	char *answer = "주소 공간의 크기는 4이고 주소와의 간격또한 4로 같습니다.";
	cout << answer << endl;
	return 0;
}