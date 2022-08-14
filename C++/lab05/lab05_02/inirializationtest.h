#include <iostream>
using namespace std;

class inirializationtest
{
private:
	int nfirst;
	int nsecond;
public:
	inirializationtest(int nf,int ns);
	void print(void);

};

inirializationtest::inirializationtest(int nf,int ns) :	nfirst (nf), nsecond (ns)
{

}


void inirializationtest::print(void)
{
	cout << "nfirst = " << nfirst << endl;
	cout << "nsecond = " << nsecond << endl;
}