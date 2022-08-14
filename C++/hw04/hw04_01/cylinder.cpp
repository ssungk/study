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
		cout << "\ncylinder�� ���� �Է�" << endl;
		cout << "������ �Է� : ";
		cin >> radius;
		cout << "���� �Է� : ";
		cin >> height;
		cout << endl;

		if(radius > 0 && height > 0)
		{
			break;
		}
		cout << "������ �Ǵ� ���̸� 0�� �̻��� ������ �Է����ּ���";
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