#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main( void )
{
	string daysAry[7];//7���� ���Ҹ� ���� string ��ü �迭 daysAry ����
	daysAry[0] = "Sunday";
	daysAry[1] = "Monday";
	daysAry[2] = "Tuesday";
	daysAry[3] = "Wednesday";
	daysAry[4] = "Thursday";
	daysAry[5] = "Friday";
	daysAry[6] = "Saturday";//daysAry �迭�� �� ���Ҹ� ���Ϸ� �ʱ�ȭ

	string strDOW;
	cout << setw(24) << "The days of the week" << endl;
	for( int index = 0 ; index<7 ; index++ ) 
	{
		cout <<  setw(10) << daysAry[index];//daysAry �迭�� index��° ��ü ���
		cout << ", length : ";
		cout << daysAry[index].size();//daysAry�迭�� index��° ��ü�� ���ڿ� ���̸� ���
		cout << endl;
		strDOW += daysAry[index];
		strDOW += " ";//����(" ")�� daysAry �迭�� index��° ��ü�� ������ ���� strDOW�� �߰� ����
	}
	cout << endl << strDOW << endl;
	return 0;
}