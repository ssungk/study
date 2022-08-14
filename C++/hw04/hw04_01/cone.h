#include<iostream>
using namespace std;

class cone
{
	private:
		float m_radius;
		float m_height;

	public:
		cone(void);
		cone(float, float);
		void input();
		void printvolume();
		void printsurface();
		double getvolume();
		double getsurface();
};