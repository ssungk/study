#include <iostream>
using namespace std;

#include "Employee.h"

void Employee::initialize(char* name, int number, int salary)
{
	/* 시험 문제로써 이 부분을 작성함 */
	
	int name_space = strlen(name) + 1;
	empName = new char[name_space];
	copy_name(name, name_space);
	empNumber = number;
	empSalary = salary;
	
}

void Employee::show_data()
{
	/* 시험 문제로써 이 부분을 작성함 */
	
	cout << "사원 이름 : " << empName << endl;
	cout << "사원 번호 : " << empNumber << endl;
	cout << "월 급여액 : " << empSalary << endl << endl;
	
}

void Employee::copy_name(char* name, int name_space)
{
	/* 시험 문제로써 이 부분을 작성함 */
	
	int nCount = 0;
	while(nCount < name_space)
	{
		empName[nCount] = name[nCount];
		nCount++;
	}
	
}
	