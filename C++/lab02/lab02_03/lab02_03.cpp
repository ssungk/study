#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ary[5] = {10, 20, 30, 40, 50};
	int* pary = ary;
	// ������ ��� ���� ǥ���� Ȱ���� ���

	cout << setw(23) << "������ �������";
	for(int k=0; k<5; k++ )
	{
	cout << setw(9) << "pAry+" << k;
	}
	cout << endl;

	cout << setw(23) << "������ ������� ���";
	for(int k=0; k<5; k++ )
	{
	cout << setw(10) << pary+k;
	}
	cout << endl;// (�ڵ� �ۼ�) ������ ������� ��� ���

	cout << setw(23) << "�迭 ������ ������";
	for(int k=0; k<5; k++ )
	{
	cout << setw(10) << ary[k];
	}
	cout << endl;// (�ڵ� �ۼ�)�迭 ������ ������ ���� �迭 ���� ���

	cout << setw(23) << "�����Ϳ� �迭 ÷�� ����";
	for(int k=0; k<5; k++ )
	{
	cout << setw(10) << *(pary+k);
	}
	cout << endl;// (�ڵ� �ۼ�)�����͸� �̿��� �迭 ÷�� ����

	return 0;
}