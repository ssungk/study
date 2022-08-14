#include "box.h"

box::box(void)
{
}

void box::input()
{
	float width;
	float height;
	float length;
	
	for(;;)
	{
		cout << "\nbox의 정보 입력" << endl;
		cout << "너비 입력 : ";
		cin >> width;
		cout << "높이 입력 : ";
		cin >> height;
		cout << "길이 입력 : ";
		cin >> length;
		cout << endl;
		
		if(width > 0 && height > 0 && length > 0)
		{
			break;
		}
		cout << "너비 또는 높이 또는 길이를 0의 이상의 값으로 입력해주세요";
	}

	m_width = width;
	m_height = height;
	m_length = length;
	return;
}

void box::printvolume()
{
	cout << m_width << " * " << m_height << " * " << m_length;
	return;
}

void box::printsurface()
{
	cout << "2 * (" << m_width << " * " << m_height << " + " << m_length << " * " << m_width << " + " << m_height << " * " << m_length << ")";
	return;
}

float box::getvolume()
{
	return (m_width * m_height * m_length);
}

float box::getsurface()
{
	return (2 * (m_width * m_height + m_length * m_width + m_height * m_length));
}