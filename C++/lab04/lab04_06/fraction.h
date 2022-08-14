#include <iostream>
using namespace std;

class CFraction
{
private:
	int m_nNumerator;
	int m_nDenominator;
	int GreatestComDiv( int nNumer, int nDenom );
public:
	CFraction (void); 
	CFraction (int nNumer); 
	CFraction (int nNumer, int nDenom); 
	~CFraction();
	void store (int nNumer, int nDenom);
	void print () const;
//	void add(const CFraction& fr);
//	void subtract(const CFraction& fr);
//	void multiply(const CFraction& fr);
//	void divide(const CFraction& fr);
	friend CFraction add(const CFraction& fr1,const CFraction& fr2);
	friend CFraction subtract(const CFraction& fr1,const CFraction& fr2);
	friend CFraction multiply(const CFraction& fr1,const CFraction& fr2);
	friend CFraction divide(const CFraction& fr1,const CFraction& fr2);
};