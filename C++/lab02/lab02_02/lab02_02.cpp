#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ary[5] = {10, 20, 30, 40, 50}; // �迭�� ����� �ʱ�ȭ
	cout << setw(15) << "Print Element";

	for( int i=0; i<5; i++ )
	{
	cout << setw(10) << ary[i]; // �迭�� ���� ���(�迭 ÷�� ������)
	}
	cout << endl;

	cout << setw(15) << "Address of Element";
	for( int i=0; i<5; i++ )
	{
	cout << setw(10) << &ary[i] ; // �迭�� ���� �ּ� ���(�迭 ÷�� ������, �ּ� ������)
	}
	cout << endl;

	cout << setw(10) << "Ary = " << ary << endl; // '�迭��'�� ���
	cout << setw(10) << "&Ary[0] = " << &ary[0] << endl; // 'ù ��° ����'�� �ּ� ���
	int* pary = ary; // �����͸� �迭�� �̸����� �ʱ�ȭ
	cout << setw(10) << "pAry = " << pary << endl; // �����ͷμ��� �迭 �̸� ���
	cout << setw(10) << "*pAry = " << *pary << endl; // ���� ������(*)�� ���� �迭�� ù ��° ��� ����
	cout << setw(10) << "*Ary = " << *ary << endl; // �迭�� ���� ������(*)�� ���� ������
	cout << setw(10) << "pAry[0] = " << pary[0] << endl; // �����͸� �̿��� �迭 ÷�� ������([])

	return 0;
}