#include "sphere.h"

sphere::sphere(void)
{
}

sphere::sphere(float radius)
{
	m_radius = radius;
}

void sphere::input()
{
	float radius;
	for(;;)
	{
		cout << "\nsphere의 정보 입력" << endl;
		cout << "반지름 입력 : ";
		cin >> radius;
		cout << endl;
		
		if(radius > 0)
		{
			break;
		}
		cout << "반지름을 0의 이상의 값으로 입력해주세요";
	}
	
	m_radius = radius;
	return;
}

void sphere::printvolume()
{

	cout << "(3.14159  * " << m_radius << " * " << m_radius << " * " << m_radius << ")/6";
	return;
}

void sphere::printsurface()
{
	cout << "4 * 3.14159 * " << m_radius << " * " << m_radius;
	return;
}

float sphere::getvolume()
{
	return ((3.14159 * m_radius * m_radius * m_radius)/6);
}

float sphere::getsurface()
{
	return (4 * 3.14159 * m_radius * m_radius);
}