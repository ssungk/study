#include <iostream>
using namespace std;

class Base
{
private:
	int m_Num1;
	int m_Num2;
public:
	Base();
	inline void print();
	void setNum(int val1,int val2)
	{
		m_Num1 = val1;
		m_Num2 = val2;
	}
};

Base::Base()
{
	m_Num1 = 0;
	m_Num2 = 0;
}

void Base::print()
{
	cout << "�μ��� ���� " << m_Num1 + m_Num2 << "�Դϴ�." << endl;
	return;
}


class Derived : public Base
{
};


int main()
{
	Derived der;
	int num1, num2;

	cout << "�� ���� �Է��ϼ��� : " << endl;
	cin >> num1;
	cin >> num2;

	der.setNum(num1,num2);
	der.print();

	return 0;
}

