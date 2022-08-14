#include "cylinder.h"

cylinder::cylinder(void)
{
}

void cylinder::input(float radius, float height)
{
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

float cylinder::getvolume()
{
	return (3.14159 * m_radius * m_radius * m_height);
}

float cylinder::getsurface()
{
	return ((2 * 3.14159 * m_radius * m_radius) + (2 * 3.14159 * m_radius * m_height));
}