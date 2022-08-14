#include <iostream>
using namespace std;

class CFraction
{
	private:
		int m_nNumerator;// 분자
		int m_nDenominator;// 분모
	public:
		void store(int nNumer,int nDenom);
		void print () const;
};