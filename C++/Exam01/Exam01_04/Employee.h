class Employee
{

/* 멤버 변수를 선언함 */
private:		
	char* empName;		// 사원의 이름을 받기 위한 변수
	int empNumber;		// 사원의 번호를 받기 위한 변수
	int empSalary;		// 사원의 월 급여액을 받기 위한 변수

/* 멤버 메소드를 선언함 */
public:
	void initialize(char* name, int number, int salary);	// 사원 정보를 초기화 하는 메소드
	void show_data();										// 사원 정보를 출력하는 메소드
	void copy_name(char* name, int name_space);				// 사원 이름을 입력받아 name 변수에 넣는 메소드

};