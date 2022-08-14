#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int dsize;

	cout << "Enter a size of the array : ";
	cin >> dsize;
	
	int* dary = new int [dsize]; // (코드 작성) 동적 배열 할당
	
	cout << "Enter a number each Element : ";

	int i;
	int j;

	for(i=0;i<dsize;i++)
	{
		cin >> j;
		*(dary+i) = j;
	}// (코드 작성) 배열 채우기(포인터 간접 연산자 활용)
	

	for(i=0;i<dsize;i++)
	{
		cout << dary[i] << "  ";
	}// (코드 작성) 배열 출력하기(포인터에 배열 첨자 연산자 활용)

	cout << endl;
	
		
	delete[] dary; // (코드 작성) 동적 배열 메모리 해제
	
	return 0;
}

