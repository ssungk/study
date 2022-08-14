#include <math.h>
#include "prism.h"

prism::prism(void)
{
}

void prism::input()
{
	float base;
	float height;
	float length;

	for(;;)
	{
		cout << "\nprism의 정보 입력" << endl;
		cout << "밑변 입력 : ";
		cin >> base;
		cout << "높이 입력 : ";
		cin >> height;
		cout << "길이 입력 : ";
		cin >> length;
		cout << endl;

		if(base > 0 && height >0 && length > 0)
		{
			break;
		}
		cout << "밑변 또는 높이 또는 길이를 0의 이상의 값으로 입력해주세요";
	}
	
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