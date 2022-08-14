#include <iostream>
using namespace std;

#include "Employee.h"

void Employee::initialize(char* name, int number, int salary)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */
	
	int name_space = strlen(name) + 1;
	empName = new char[name_space];
	copy_name(name, name_space);
	empNumber = number;
	empSalary = salary;
	
}

void Employee::show_data()
{
	/* ���� �����ν� �� �κ��� �ۼ��� */
	
	cout << "��� �̸� : " << empName << endl;
	cout << "��� ��ȣ : " << empNumber << endl;
	cout << "�� �޿��� : " << empSalary << endl << endl;
	
}

void Employee::copy_name(char* name, int name_space)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */
	
	int nCount = 0;
	while(nCount < name_space)
	{
		empName[nCount] = name[nCount];
		nCount++;
	}
	
}
	