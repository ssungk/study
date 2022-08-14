#include <exception>
using namespace std;

class Arithmetic : public exception
{
public:
	virtual const char* what() const throw()
	{ return "**Error: type Arithmetic\n";}
};
class DivbyZero : public Arithmetic
{
public:
	virtual const char* what() const throw()
	{ return "**Error : 100 divisor\n";}
};
class DivbyNeg : public Arithmetic
{
public:
	virtual const char* what() const throw()
	{ return "**Error : 101 negative divisor\n";}
};
class BadOperator : public Arithmetic
{
public:
	virtual const char* what() const throw()
	{ return "**Error : 102 incakud operator\n";}
};
