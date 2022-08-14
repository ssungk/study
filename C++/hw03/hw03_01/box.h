#include<iostream>
using namespace std;

class box
{
	private:
		float m_width;
		float m_height;
		float m_length;

	public:
		box(void);
		void input(float, float, float);
		void printvolume();
		void printsurface();
		float getvolume();
		float getsurface();
};