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
		cout << "\nsphere�� ���� �Է�" << endl;
		cout << "������ �Է� : ";
		cin >> radius;
		cout << endl;
		
		if(radius > 0)
		{
			break;
		}
		cout << "�������� 0�� �̻��� ������ �Է����ּ���";
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