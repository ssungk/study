#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string strEnglish = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,?!;";
string strCode = "?Q.W,EMRNTBXYUV!ICOPZA;SDLFKGJH";

char findString( string& source, string& target, const char& c )
{
	size_t index = source.find_first_of(c);
	if(index != string::npos)
	{
		return target[index];//source에서 입력된 c를 탐색하여 target에서 같은 위치에서의 문자 리턴
	}
	return c;//입력된 c가 source에서 탐색 되지 않는 다면, 입력과 같은 문자를 리턴
}

string Encode( string& str )
{
	string rst;
	string::iterator iter = str.begin();// iter 을 통해 한 문자씩 접근
	while (iter != str.end()) // iter이 str.end()와 같지 않을 때까지 반복
	{
		rst = rst + findString(strEnglish,strCode,*iter);//findString함수 호출 (source:strEnglish, target:strCode, *iter)
		//rst에 findString함수에서 반환 된 문자를 추가
		iter++;//iter 증가
	}
	return rst;
}

string Decode( string& str )
{
	string rst;
	string::iterator iter = str.begin();
	while (iter != str.end()) // iter이 str.end()와 같지 않을 때까지 반복
	{
		rst = rst + findString(strCode,strEnglish,*iter);//findString함수 호출 (source:strEnglish, target:strCode, *iter)
		//rst에 findString함수에서 반환 된 문자를 추가
		iter++;//iter 증가
	}//findString함수에서 strCode를 source로 strEnglish를 target으로 하여
	//입력된 str의 암호를 풀어 리턴
	return rst;
}

int main( void )
{
	string msg;
	cout << "Enter your string." << endl;
	getline( cin, msg );
	string enc = Encode( msg );
	string dec = Decode( enc );
	cout << "Encoded string : " << enc << endl;
	cout << "Decoded string : " << dec << endl;
	return 0;
}