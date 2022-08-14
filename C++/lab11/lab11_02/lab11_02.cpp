#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s0 ("Initial string");
	// constructors used in the same order as described above:
	string s1;//�⺻ �����ڸ� �̿��� s1 ��ü ����
	string s2(s0);//s0 ��ü�� �����ϴ� s2 ��ü ����
	string s3(s0,8,3);//s0 ��ü �� 8��° ���ں��� 3���� ���ڷ� �ʱ�ȭ�ϴ� s3 ��ü ����
	string s4("A character sequence",6);//"A character sequence"�� ���ڿ� �� 6���� ���ڷ� �ʱ�ȭ�ϴ� s4 ��ü ����
	string s5("Another character sequence");//"Another character sequence"�� ���ڿ��� �ʱ�ȭ�ϴ� s5 ��ü ����
	string s6(10,'x');//'x'���� 10���� �ʱ�ȭ�ϴ� s6 ��ü ����
	string s7 ( s0.begin(), s0.end()-4 );
	//template class Iterator�� ���� �� ���۰� ������ �ʱ�ȭ�ϴ� ��ü s7 ����*/
	cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
	cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
	cout << "\ns7: " << s7 << endl;
	return 0;
}