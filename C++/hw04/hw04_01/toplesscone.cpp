#include "cone.h"
#include "toplesscone.h"

toplesscone::toplesscone(void)
{
}

toplesscone::toplesscone(cone& conelarge,cone& conehide)
{
	this->m_conelarge = conelarge;
	this->m_conehide = conehide;
}
void toplesscone::input()
{
	float height;
	float radius;
	float hheight;

	for(;;)
	{
		cout << "\ntoplesscone�� ���� �Է�" << endl;
		cout << "cone ���� �Է� : ";
		cin >> height;
		cout << "cone ������ �Է� : ";
		cin >> radius;
		cout << "hide cone ���� �Է�: ";
		cin >> hheight;
		cout << endl;

		if(height > 0 && radius > 0 && hheight > 0 && height > hheight)
		{
			break;
		}
		cout << "���� �Ǵ� �������� 0�� �̻��� ������ �Է����ְų� \ncone�� ���̸� hidecone�� ���̺��� ũ�� ���ּ���";
	}
	
	cone conelarge(radius, height);
	cone conehide(radius * hheight / height, hheight);

	this->m_conelarge = conelarge;
	this->m_conehide = conehide;
	return;
}

void toplesscone::printvolume()
{
	m_conelarge.printvolume();
	cout << " - ";
	m_conehide.printvolume();
	return;
}

void toplesscone::printsurface()
{
	m_conelarge.printsurface();
	cout << " - ";
	m_conehide.printsurface();
	return;
}

double toplesscone::getvolume()
{
	return (m_conelarge.getvolume() - m_conehide.getvolume());
}

double toplesscone::getsurface()
{
	return (m_conelarge.getsurface() - m_conehide.getsurface());
}