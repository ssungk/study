#include <iostream>
using namespace std;

class A
{
protected:
	int m_id;
public:
	A();
	A(int n);
	~A();
};

A::A()
{
	cout << "Ŭ���� A ������ ����" << endl;
}
A::A(int n)
{
	m_id = n;
	cout << "Ŭ���� A ������ ����" << endl;
}

A::~A()
{
	cout << "Ŭ���� A �Ҹ��� ����" << endl;
}

class B : public A
{
	public:
	B();
	B(int num);
	~B();
};

B::B()
{
	cout << "Ŭ���� B ������ ����" << endl;
}

B::B(int num) : A(num)
{
	m_id=num;

	cout << "Ŭ���� B ������ ����" << endl;
}

B::~B()
{
	cout << "Ŭ���� B �Ҹ��� ����" << endl;
}


int main()
{
	cout << "## Ŭ������ �����ڿ� �Ҹ��� ������� ##" << endl;
	B b(10);
	cout << "Ŭ���� A�� ��ӹ������̹Ƿ� A�����ڰ� ���� ����ǰ� B�� �����ڰ� ����ȴ� �׸��� �Ҹ��ڴ� �����ڼ����� �����̴�" << endl;
	return 0;
}

