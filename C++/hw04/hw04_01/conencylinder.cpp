#include "cylinder.h"
#include "cone.h"
#include "conencylinder.h"

conencylinder::conencylinder(void)
{
}

void conencylinder::input()
{
	float height;
	float radius;
	float cheight;

	
	
	for(;;)
	{
		cout << "\ncone & cylinder의 정보 입력" << endl;
		cout << "cone 높이 입력 : ";
		cin >> height;
		cout << "cone 반지름 입력 : ";
		cin >> radius;
		cout << "cylinder 높이 입력 : ";
		cin >> cheight;
		cout << endl;

		if(radius > 0 && height > 0)
		{
			break;
		}
		cout << "반지름 또는 높이를 0의 이상의 값으로 입력해주세요";
	}


	cone cone1(radius,height);
	cylinder cylinder1(radius,cheight);

	
	m_cone = cone1;
	m_cylinder = cylinder1;
	return;
}

void conencylinder::printvolume()
{
	m_cone.printvolume();
	cout << " + ";
	m_cylinder.printvolume();
	return;
}

void conencylinder::printsurface()
{
	m_cone.printsurface();
	cout << " + ";
	m_cylinder.printsurface();
	return;
}

double conencylinder::getvolume()
{
	return (m_cone.getvolume() + m_cylinder.getvolume());
}

double conencylinder::getsurface()
{
	return (m_cone.getsurface() + m_cylinder.getsurface());
}