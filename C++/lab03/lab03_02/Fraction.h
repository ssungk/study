#include <iostream>
using namespace std;

class CFraction
{
	private:
		int m_nNumerator;// ����
		int m_nDenominator;// �и�
	public:
		void store(int nNumer,int nDenom);
		void print () const;
};