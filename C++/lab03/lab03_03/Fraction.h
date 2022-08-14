#include <iostream>
using namespace std;

class CFraction
{
	private:
		int m_nNumerator;// ����
		int m_nDenominator;// �и�
	public:
		CFraction ( void );
		CFraction (int nNumer);
		CFraction (int nNumer,int nDenom);
		CFraction (const CFraction&fr);
		void store(int nNumer,int nDenom);
		void print () const;
};