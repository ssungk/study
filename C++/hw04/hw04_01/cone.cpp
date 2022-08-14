#include <math.h>
#include "cone.h"

cone::cone(void)
{
}

cone::cone(float radius, float height)
{
	m_radius = radius;
	m_height = height;
}

void cone::input()
{
	float radius;
	float height;

	for(;;)
	{
		cout << "\ncone의 정보 입력" << endl;
		cout << "높이 입력 : ";
		cin >> height;
		cout << "반지름 입력 : ";
		cin >> radius;
		cout << endl;

		if(height > 0 && radius > 0)
		{
			break;
		}
		cout << "높이 또는 반지름을 0의 이상의 값으로 입력해주세요";
	}
	
	m_radius = radius;
	m_height = height;
	return;
}

void cone::printvolume()
{

	cout << "(3.14159  * " << m_radius << " * " << m_radius << " * " << m_height << ")/3";
	return;
}

void cone::printsurface()
{
	cout << "(3.14159 * " << m_radius << " * (" << m_radius << " * " <<m_radius << " + " << m_height << " * " <<m_height << ")^-2 + (3.14159 * " << m_radius << " * " << m_radius << ")";
	return;
}

double cone::getvolume()
{
	return ((3.14159  * m_radius * m_radius * m_height)/3);
}

double cone::getsurface()
{
	return ((3.14159 * m_radius * sqrt(m_radius*m_radius+m_height*m_height)) + (3.14159 * m_radius * m_radius ));
}