#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	char s1[12]={'S','t','r','i', 'n', 'g', ' ', 't', 'e', 's', 't', '\0'};
	cout << "s1 : " << s1 << endl;//s1 ���, ������ '\0'�� ������ ���ڿ� ������� ����.

	s1[6]=0;
	cout << "s1 : " << s1 << endl;//s1 ���, ����� ������ ���� �غ���.

	char s2[12] = "String test";
	cout << "s2 : " << s2 << endl;//s2 ���

	cout << endl;
	cout << "s1       |       s2" << endl;
	cout << "_________________" << endl;
	for( int i=0 ; i<12 ; i++ )
	{
		cout << setw(3) << (int)s1[i] << setw(8) << " | " << setw(8) << (int)s2[i] << endl; 

		//s1�� s2�� i��° ��Ҹ� int������ ��ȯ�Ͽ� ���
		//int�� ��ȯ ������� ���ڿ� ������ �־��\0����
		//�ǹ̸� Ȯ���϶�
	}
	return 0;
}