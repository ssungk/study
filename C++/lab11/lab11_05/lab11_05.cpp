#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main( void )
{
	string daysAry[7];//7개의 원소를 갖는 string 객체 배열 daysAry 선언
	daysAry[0] = "Sunday";
	daysAry[1] = "Monday";
	daysAry[2] = "Tuesday";
	daysAry[3] = "Wednesday";
	daysAry[4] = "Thursday";
	daysAry[5] = "Friday";
	daysAry[6] = "Saturday";//daysAry 배열의 각 원소를 요일로 초기화

	string strDOW;
	cout << setw(24) << "The days of the week" << endl;
	for( int index = 0 ; index<7 ; index++ ) 
	{
		cout <<  setw(10) << daysAry[index];//daysAry 배열의 index번째 객체 출력
		cout << ", length : ";
		cout << daysAry[index].size();//daysAry배열의 index번째 객체의 문자열 길이를 출력
		cout << endl;
		strDOW += daysAry[index];
		strDOW += " ";//공백(" ")과 daysAry 배열의 index번째 객체를 결합한 것을 strDOW에 추가 대입
	}
	cout << endl << strDOW << endl;
	return 0;
}