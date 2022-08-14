#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main( void )
{
	string s1, s2;
	//문자열 검색
	s1 = "01234560123456";
	int index = s1.find("23"); //0번째 위치부터 검색하여 “23”의 substring의 위치를 찾아라.
	cout<< setw(10) << "find : " << s1 << " -> " << index << " : " << s1[index] << endl;
	
	//문자열 추출
	s1 = "0123456";
	s2 = s1.substr(0,3/*파라메터 채우기*/);//0번째부터 3개의 문자를 잘라 할당하라.
	cout << setw(10) << " substr : " << s1 << " (0~2) -> " << s2 << endl ;
	
	//문자열 삽입
	s1 = "0123456";
	s2 = s1;
	s1.insert(0,"add");//"add" 문자열을 0번째에 끼워 넣어라.
	cout << setw(10) << " insert : \"add\" + " << s2 << " = " << s1 << endl ;

	//문자열 추가
	s1 = "0123456";
	s2 = "abcdef";
	cout << setw(10) << " append : " << s1 << " append " << s2 << " = ";
	s1.append(s2);//s2의 0~s2.npos 위치의 문자열을 s1의 맨뒤에 추가하라.
	cout << s1 << endl;

	//문자열 교체
	s1 = "abcdef";
	s2 = "0123456";
	s1.replace(0,1,"5555"); //s1의 0번째 위치에서 1개의 문자를 "5555"로 대체 하라.
	cout << setw(10) << "replace : " << s1 << endl;

	//문자열 삭제
	s1 = "0123456";
	cout << setw(10) << "erase : " << s1 ;
	s1.erase(1,1); //s1의 1번째 위치에서 1개의 문자를 삭제하라.
	cout << " -> " << s1 << endl;

	//문자열 비교
	int nCmp;
	s1 = "1234567";
	s2 = "1234999";
	nCmp = s1.compare(s2);//s1과 s2를 비교 하라.
	cout << setw(10) << "compare : " << ( (nCmp==0) ? "equal" : ( (nCmp<0) ? "less" : "greater" ) ) << endl;
	nCmp = s1.compare(0,4,s2,0,4);//s1의 0~4의 문자열과 s2의 0~4의 문자 열을 비교 하라.
	cout << setw(10) << "compare : " << ( (nCmp==0) ? "equal" : ( (nCmp<0) ? "less" : "greater" ) ) << endl;

}