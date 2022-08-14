#include <iostream>
using namespace std;
#include "datetime.h"

void main()
{
	datetime t1;
	datetime t2(1999,1,1,0,0,0);
	datetime t3(t2);

	t1.setcurrenttime();
	t1.printdatetime();
	cout << endl;

	t1.adddays(100);
	cout << "현재로부터 100일 뒤는 ";
	t1.printdate();
	cout << " 입니다." << endl;
	cout << endl;


	cout << "t1과 t2의 날짜는 총" << t1.gettotalday() - t2.gettotalday() << "일 차이입니다." << endl;

	t1.setcurrenttime();
	t1.subdays(50);
	cout << "금일로부터 50일 이전의 날짜 : ";
	t1.printdate();
	cout << endl;

}

bool IsLeapYear(int nYear)
{ 
	if(((nYear%4)==0)&&((nYear%100)!=0)||((nYear%400)==0))
	{
		return true ;
	}
	return false ; 
}