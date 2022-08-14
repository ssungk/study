#include <iostream>
#include <string>
using namespace std;
#include "morse.h"

#define FLUSH while( cin.get() != '\n' )

char menu ( void );
string getInput ( void );
void printOutput ( string& inStr, string& outStr );


int main ( void )
{
	string inStr ;
	string outStr;
	bool done = false;
	char option;
	Morse mCode;
	while( !done )
	{
		option = menu();
		//메뉴에 따라 진행
		//'E'라면 입력 영문을 모르스 부호로 변환
		//'D'라면 입력 모르스 부호를 영문으로 변환
	}
	return 0;
}
char menu( void )
{
	bool validData = true;
	char option;
	//메뉴 출력
	//입력된 메뉴가 올바른지 확인
	//소문자가 입력 되면 대문자로 변환
	//올바른지 않은 메뉴 입력 시 에러 출력
	return option;
}
string getInput ( void ){
	//사용자로부터 입력 받은 문자열을 반환
}
void printOutput ( string& inStr, string& outStr ){
	//inStr, outStr을 화면에 각각 출력
}