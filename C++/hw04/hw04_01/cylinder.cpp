#include "cylinder.h"

cylinder::cylinder(void)
{
}

cylinder::cylinder(float radius, float height)
{
	m_radius = radius;
	m_height = height;
}

void cylinder::input()
{
	float radius;
	float height;
		
	for(;;)
	{
		cout << "\ncylinder의 정보 입력" << endl;
		cout << "반지름 입력 : ";
		cin >> radius;
		cout << "높이 입력 : ";
		cin >> height;
		cout << endl;

		if(radius > 0 && height > 0)
		{
			break;
		}
		cout << "반지름 또는 높이를 0의 이상의 값으로 입력해주세요";
	}
	
	m_radius = radius;
	m_height = height;
	return;
}

void cylinder::printvolume()
{

	cout << "3.14159  * " << m_radius << " * " << m_radius << " * " << m_height;
	return;
}

void cylinder::printsurface()
{
	cout << "(2 * 3.14159 * " << m_radius << " * " << m_radius << ") + (2 * 3.14159 * " << m_radius << " * " << m_height << ")";
	return;
}

double cylinder::getvolume()
{
	return (3.14159 * m_radius * m_radius * m_height);
}

double cylinder::getsurface()
{
	return ((2 * 3.14159 * m_radius * m_radius) + (2 * 3.14159 * m_radius * m_height));
}