#include <iostream>
using namespace std;

void func(int a,int b)
{
	if(b==0)
	{
		throw b;
	}
	cout << "a ������ b�� ���� " << a/b << "��������" << a%b << "�Դϴ�." << endl;
}

int main(void)
{
	int a,b;

	try
	{
		cout << "�ΰ��� ���� �Է����ּ���";
		cin >> a >> b;
		func(a,b);
	}
	catch(int ex)
	{
		cout << "b��" << ex << "�� �ԷµǾ����ϴ�. �ٽ� �����ϼ���" << endl;
	}

	return 0;
}