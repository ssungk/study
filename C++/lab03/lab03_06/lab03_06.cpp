#include<iostream>
using namespace std;

#include "Fraction.h"

void getPhone(char strName[], int& nMemSize);

int main()
{
	cout << "This program creates SmartPhons"<<endl;
	char strName[20] ={0};
	int  nMemorySize = 0 ;

	getPhone(strName, nMemorySize);

	SmartPhone TomPhone(strName,nMemorySize);//�Է� ���� ������ �̿��ϴ� �����ڸ� ���� TomPhone�� ����
	TomPhone.print();

	SmartPhone MyPhone;//�⺻ �����ڸ� ���� MyPhone�� ����

	MyPhone.print();
	getPhone (strName , nMemorySize);//����Ʈ���� OS �̸��� �޸��� ũ�⸦ ȹ��
	MyPhone.change(nMemorySize);
	MyPhone.changeOSName(strName);
	MyPhone.print();
	cout << "\nThinks you for using Smart Phones.\n";
	return 0;
}
void getPhone(char strName[],int& nMemSize)
{
	cout << "Please enter the Phone Name    : ";
	cin >> strName;
	cout << "Please enter the Memory Size   : ";
	cin >> nMemSize;

	return;
}
