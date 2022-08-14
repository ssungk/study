#include <math.h>
#include "prism.h"

prism::prism(void)
{
}

void prism::input(float base, float height, float length)
{
	m_base = base;
	m_height = height;
	m_length = length;
	return;
}

void prism::printvolume()
{
	cout << "0.5 * " << m_base << " * " << m_height << " * " << m_length;
	return;
}

void prism::printsurface()
{
	cout << m_base << " * " << m_height << " + " << m_base << " * " << m_length << " + " <<	m_height << " * " << m_length << " + " << m_length << " * (" << m_base << " * " << m_base << " + " << m_height << " * " << m_height << ")^(-2)";
	return;
}

float prism::getvolume()
{
	return ((m_base * m_height * m_length)/2);
}

float prism::getsurface()
{
	return (m_base*m_height+m_base*m_length+m_height*m_length+m_length*sqrt(m_base*m_base+m_height*m_height));
}