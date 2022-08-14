#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	char s1[12]={'S','t','r','i', 'n', 'g', ' ', 't', 'e', 's', 't', '\0'};
	cout << "s1 : " << s1 << endl;//s1 출력, 마지막 '\0'가 없으면 문자열 보장되지 않음.

	s1[6]=0;
	cout << "s1 : " << s1 << endl;//s1 출력, 결과의 원인을 생각 해보라.

	char s2[12] = "String test";
	cout << "s2 : " << s2 << endl;//s2 출력

	cout << endl;
	cout << "s1       |       s2" << endl;
	cout << "_________________" << endl;
	for( int i=0 ; i<12 ; i++ )
	{
		cout << setw(3) << (int)s1[i] << setw(8) << " | " << setw(8) << (int)s2[i] << endl; 

		//s1과 s2의 i번째 요소를 int형으로 변환하여 출력
		//int형 변환 출력으로 문자열 관리에 있어서‘\0’의
		//의미를 확인하라
	}
	return 0;
}