#include "Base.h"
class Derived : public Base
{
private:
	int m_val3;
	int m_val4;
public:
	Derived();
	Derived(int a,int b,int c,int d);
	void printSum();
};

