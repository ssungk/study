#include<iostream>
using namespace std;

class sphere
{
	private:
		float m_radius;

	public:
		sphere(void);
		sphere(float);
		void input();
		void printvolume();
		void printsurface();
		float getvolume();
		float getsurface();
};