#include <iostream>
#include <string>
using namespace std;

int main ( void )
{
	string str1 = "string convert test.";
	string str2 ;
	char *ary = new char[str1.length()+1];
	strcpy(ary,str1.c_str());//c_str() �޼ҵ�� strcpy()�Լ��� �̿��Ͽ� str1 C++ string object�� ary C string���� ����
	str2 = ary;//C++ string assignment operator(��=��)�� �̿��Ͽ� ary C string�� str2 C++ string object�� ����
	cout << "ary : "<< ary << endl;
	cout << "str2: "<< str2 << endl;
	delete[] ary;
	return 0;
}