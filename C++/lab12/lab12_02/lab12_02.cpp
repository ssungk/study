#include <iostream>
using namespace std;

void func(int a,int b)
{
	if(b==0)
	{
		throw b;
	}
	cout << "a 나누기 b의 몫은 " << a/b << "나머지는" << a%b << "입니다." << endl;
}

int main(void)
{
	int a,b;

	try
	{
		cout << "두개의 수를 입력해주세요";
		cin >> a >> b;
		func(a,b);
	}
	catch(int ex)
	{
		cout << "b에" << ex << "이 입력되었습니다. 다시 실행하세요" << endl;
	}

	return 0;
}