#include<iostream>
using namespace std;

class cylinder
{
	private:
		float m_radius;
		float m_height;

	public:
		cylinder(void);
		cylinder(float, float);
		void input();
		void printvolume();
		void printsurface();
		double getvolume();
		double getsurface();
};