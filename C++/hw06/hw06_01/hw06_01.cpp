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
	cout << "����κ��� 100�� �ڴ� ";
	t1.printdate();
	cout << " �Դϴ�." << endl;
	cout << endl;


	cout << "t1�� t2�� ��¥�� ��" << t1.gettotalday() - t2.gettotalday() << "�� �����Դϴ�." << endl;

	t1.setcurrenttime();
	t1.subdays(50);
	cout << "���Ϸκ��� 50�� ������ ��¥ : ";
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