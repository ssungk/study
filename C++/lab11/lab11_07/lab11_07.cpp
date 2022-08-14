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
		return target[index];//source���� �Էµ� c�� Ž���Ͽ� target���� ���� ��ġ������ ���� ����
	}
	return c;//�Էµ� c�� source���� Ž�� ���� �ʴ� �ٸ�, �Է°� ���� ���ڸ� ����
}

string Encode( string& str )
{
	string rst;
	string::iterator iter = str.begin();// iter �� ���� �� ���ھ� ����
	while (iter != str.end()) // iter�� str.end()�� ���� ���� ������ �ݺ�
	{
		rst = rst + findString(strEnglish,strCode,*iter);//findString�Լ� ȣ�� (source:strEnglish, target:strCode, *iter)
		//rst�� findString�Լ����� ��ȯ �� ���ڸ� �߰�
		iter++;//iter ����
	}
	return rst;
}

string Decode( string& str )
{
	string rst;
	string::iterator iter = str.begin();
	while (iter != str.end()) // iter�� str.end()�� ���� ���� ������ �ݺ�
	{
		rst = rst + findString(strCode,strEnglish,*iter);//findString�Լ� ȣ�� (source:strEnglish, target:strCode, *iter)
		//rst�� findString�Լ����� ��ȯ �� ���ڸ� �߰�
		iter++;//iter ����
	}//findString�Լ����� strCode�� source�� strEnglish�� target���� �Ͽ�
	//�Էµ� str�� ��ȣ�� Ǯ�� ����
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