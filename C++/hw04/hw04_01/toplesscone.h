#include<iostream>
using namespace std;

class toplesscone
{
	private:
		cone m_conelarge;
		cone m_conehide;

	public:
		toplesscone(void);
		toplesscone(cone& conelarge,cone& conehide);
		void input();
		void printvolume();
		void printsurface();
		double getvolume();
		double getsurface();
		friend void maketoplesscone(toplesscone &topless);
};