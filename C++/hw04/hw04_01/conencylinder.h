#include<iostream>
using namespace std;

class conencylinder
{
	private:
		cone m_cone;
		cylinder m_cylinder;

	public:
		conencylinder(void);
		void input();
		void printvolume();
		void printsurface();
		double getvolume();
		double getsurface();
};