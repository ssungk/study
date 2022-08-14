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
	cout << "클래스 A 생성자 실행" << endl;
}
A::A(int n)
{
	m_id = n;
	cout << "클래스 A 생성자 실행" << endl;
}

A::~A()
{
	cout << "클래스 A 소멸자 실행" << endl;
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
	cout << "클래스 B 생성자 실행" << endl;
}

B::B(int num) : A(num)
{
	m_id=num;

	cout << "클래스 B 생성자 실행" << endl;
}

B::~B()
{
	cout << "클래스 B 소멸자 실행" << endl;
}


int main()
{
	cout << "## 클래스의 생성자와 소멸자 실행순서 ##" << endl;
	B b(10);
	cout << "클래스 A를 상속받은것이므로 A생성자가 먼저 수행되고 B의 생성자가 수행된다 그리고 소멸자는 생성자순서의 역순이다" << endl;
	return 0;
}

