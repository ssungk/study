#include <iostream>
using namespace std;

class Error
{
public:
	virtual void printMessage()
	{
		cout << "**Error : type Error\n";
	}
};
class Arithmetic : public Error
{
public:
	virtual void printMessage()
	{
		cout << "**Error : type Arithmetic\n";
	}
};
class DivbyZero : public Arithmetic
{
public:
	virtual void printMessage()
	{
		cout << "**Error : 100 divisor\n";
	}
};
class DivbyNeg : public Arithmetic
{
public:
	virtual void printMessage()
	{
		cout << "**Error : 101 negative divisor\n";
	}
};
class BadOperator : public Arithmetic
{
public:
	virtual void printMessage()
	{
		cout << "**Error : 102 incakud operator\n";
	}
};
