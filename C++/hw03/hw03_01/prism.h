#include<iostream>
using namespace std;

class prism
{
	private:
		float m_base;
		float m_height;
		float m_length;

	public:
		prism(void);
		void input(float, float, float);
		void printvolume();
		void printsurface();
		float getvolume();
		float getsurface();
};