#include <iostream>
using namespace std;


class Base
{
protected:
	int m_Num1;
	int m_num2;
public:
	Base();
	virtual void setNum(int val1,int val2) = 0;
	virtual void printSum() = 0;
};

Base::Base()
{
	m_Num1 = 0;
	m_num2 = 0;
}

class Derived : public Base
{
public:
	Derived();
	virtual void setNum(int val1,int val2);
	virtual void printSum();
};

Derived::Derived()
{
}

void Derived::setNum(int val1,int val2)
{
	m_Num1 = val1;
	m_num2 = val2;
}
void Derived::printSum()
{
	cout << "두 수의 합은 " << m_Num1 + m_num2 << "입니다." << endl;
}

int main()
{
//	Base baseObj;

	Derived der;
	int num1, num2;

	cout << "두 수를 입력하세요 : " << endl;
	cin >> num1;
	cin >> num2;

	der.setNum(num1,num2);
	der.printSum();

	return 0;
}