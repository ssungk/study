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

	SmartPhone TomPhone(strName,nMemorySize);//입력 받은 정보를 이용하는 생성자를 통해 TomPhone을 선언
	TomPhone.print();

	SmartPhone MyPhone;//기본 생성자를 통해 MyPhone을 선언

	MyPhone.print();
	getPhone (strName , nMemorySize);//스마트폰의 OS 이름과 메모리의 크기를 획득
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
