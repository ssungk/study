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
		cout << "\ncone�� ���� �Է�" << endl;
		cout << "���� �Է� : ";
		cin >> height;
		cout << "������ �Է� : ";
		cin >> radius;
		cout << endl;

		if(height > 0 && radius > 0)
		{
			break;
		}
		cout << "���� �Ǵ� �������� 0�� �̻��� ������ �Է����ּ���";
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