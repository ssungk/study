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
		//�޴��� ���� ����
		//'E'��� �Է� ������ �𸣽� ��ȣ�� ��ȯ
		//'D'��� �Է� �𸣽� ��ȣ�� �������� ��ȯ
	}
	return 0;
}
char menu( void )
{
	bool validData = true;
	char option;
	//�޴� ���
	//�Էµ� �޴��� �ùٸ��� Ȯ��
	//�ҹ��ڰ� �Է� �Ǹ� �빮�ڷ� ��ȯ
	//�ùٸ��� ���� �޴� �Է� �� ���� ���
	return option;
}
string getInput ( void ){
	//����ڷκ��� �Է� ���� ���ڿ��� ��ȯ
}
void printOutput ( string& inStr, string& outStr ){
	//inStr, outStr�� ȭ�鿡 ���� ���
}