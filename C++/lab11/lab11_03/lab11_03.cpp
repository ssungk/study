#include <iostream>
#include <string>
using namespace std;

int main( void )
{
	string name1;
	string name2;
	string lastname ;
	string firstname;
	cout << "Enter your name ( Example : \"Hong Gil Dong\" ): ";
	getline(cin,name1);//������ ���Ե� ���� �̸��� getline�Լ��� �̿��Ͽ� name1�� ����
	cout << "Your name is " << name1 << endl << endl;
	cout << "Enter your name ( Example : \"Gil Dong, Hong\" ) :";
	getline(cin,firstname,',');//getline �Լ��� �̿� ","�� ���� �� �̸��� �о� firstname�� ����
	getline(cin,lastname);//getline �Լ��� �̿� ���� �о� lastname�� ����
	cout << "Your name is " << lastname << " "<< firstname << endl << endl;
	cout << "Enter your name ( Example : \"Hong Gil Dong\" ): ";
	cin >> name2;
	cout << "Your name is " << name2 << endl;
	//name2���� ������ ���Ե� ��� ���鿡�� �бⰡ �ߴ� ���� Ȯ�� �Ѵ�.
	return 0;
}