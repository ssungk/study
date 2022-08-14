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
};