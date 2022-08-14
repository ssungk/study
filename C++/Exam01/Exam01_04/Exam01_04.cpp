#include <iostream>
#include "Employee.h";
using namespace std;

int main()
{
	/* 두 명의 사원(employee) 인스턴스를 생성함 */
	Employee emp1, emp2; 

	/* 생성한 인스턴스를 사원 정보(이름, 사번, 월급여액)를 입력하여 초기화함 */
	emp1.initialize("유재석", 33170, 5000000);
	emp2.initialize("박명수", 31092, 1000000);

	/* 첫번째 사원의 정보를 출력함 */
	cout << "[첫째 사원 정보]" << endl;
	emp1.show_data();	

	/* 두번째 사원의 정보를 출력함 */
	cout << "[둘째 사원 정보]" << endl;
	emp2.show_data();	

	return 0;
}