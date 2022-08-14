#include <iostream>
using namespace std;

class SmartPhone
{
	private:
		char m_strName[20];
		int m_nMemorySize;
	public:
		SmartPhone(void);
		SmartPhone(char* strName,int nMemorySize);
		void change(int nMemorySize);
		void changeOSName(char* strName);
		void store(char* strName,int nMemorySize);
		void print () const;
};



/*- 데이터 :
20바이트 크기의 운영체제 이름
수치로 표현된 메모리 크기

- 생성자 (public) :
경우에 따라 데이터를 초기화 하는 생성자를 두 개 작성 
기본 생성자 : 운영체제 이름의 모든 바이트와 메모리의 크기를 0으로 초기화
운영체제 이름과 메모리의 크기를 매개변수로 입력 받아 멤버 변수에 저장

- 메소드(public) :
메모리 크기를 변경하는 메소드 changeMemSize()
운영체제 이름을 변경하는 메소드 changeOSName()
SmartPhone 정보를 출력하는 메소드 print()

메소드(private) :
20바이트 크기의 운영체제 이름 모든 바이트를 0으로 초기화 하는 메소드
입력 받은 운영체제 이름을 멤버 변수에 저장.


private:
		int m_nNumerator;// 분자
		int m_nDenominator;// 분모
	public:
		CFraction ( void );
		CFraction (int nNumer);
		CFraction (int nNumer,int nDenom);
		CFraction (const CFraction&fr);
		~CFraction(void);
		void store(int nNumer,int nDenom);
		void print () const;

*/