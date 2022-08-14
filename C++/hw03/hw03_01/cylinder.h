#include<iostream>
using namespace std;

class cylinder
{
	private:
		float m_radius;
		float m_height;

	public:
		cylinder(void);
		void input(float, float);
		void printvolume();
		void printsurface();
		float getvolume();
		float getsurface();
		
};