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
		cout << "\ntoplesscone의 정보 입력" << endl;
		cout << "cone 높이 입력 : ";
		cin >> height;
		cout << "cone 반지름 입력 : ";
		cin >> radius;
		cout << "hide cone 높이 입력: ";
		cin >> hheight;
		cout << endl;

		if(height > 0 && radius > 0 && hheight > 0 && height > hheight)
		{
			break;
		}
		cout << "높이 또는 반지름을 0의 이상의 값으로 입력해주거나 \ncone의 높이를 hidecone의 높이보다 크게 해주세요";
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