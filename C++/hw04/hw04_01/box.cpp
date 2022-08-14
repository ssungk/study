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
		cout << "\nbox�� ���� �Է�" << endl;
		cout << "�ʺ� �Է� : ";
		cin >> width;
		cout << "���� �Է� : ";
		cin >> height;
		cout << "���� �Է� : ";
		cin >> length;
		cout << endl;
		
		if(width > 0 && height > 0 && length > 0)
		{
			break;
		}
		cout << "�ʺ� �Ǵ� ���� �Ǵ� ���̸� 0�� �̻��� ������ �Է����ּ���";
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