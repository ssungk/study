#include <iostream>
#include <string>
using namespace std;

int main ( void )
{
	string str1 = "string convert test.";
	string str2 ;
	char *ary = new char[str1.length()+1];
	strcpy(ary,str1.c_str());//c_str() 메소드와 strcpy()함수를 이용하여 str1 C++ string object를 ary C string으로 복사
	str2 = ary;//C++ string assignment operator(“=”)를 이용하여 ary C string을 str2 C++ string object로 복사
	cout << "ary : "<< ary << endl;
	cout << "str2: "<< str2 << endl;
	delete[] ary;
	return 0;
}