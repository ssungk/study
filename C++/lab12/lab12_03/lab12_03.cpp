#include <iostream>
using namespace std;

void func(){throw 100;}
void func2(){func();}
void func3(){func2();}
void func4(){func3();}

int main(void)
{
	try
	{
		func4();
	}
	catch(int ex)
	{
			cout << "����ó���Է� : " << ex << "�� �ԷµǾ����ϴ�." << endl;
	}
	return 0;
}