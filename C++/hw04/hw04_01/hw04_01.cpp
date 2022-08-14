#include<iostream>
using namespace std;

#include "box.h"
#include "cylinder.h"
#include "prism.h"
#include "cone.h"
#include "sphere.h"
#include "conencylinder.h"
#include "toplesscone.h"

void maketoplesscone(toplesscone &topless)
{
	float height;
	float radius;
	float hheight;
	float hradius;
	
	for(;;)
	{
		cout << "\nlarge cone의 정보 입력" << endl;
		cout << "cone 높이 입력 : ";
		cin >> height;
		cout << "cone 반지름 입력 : ";
		cin >> radius;
		cout << "\nhide cone의 정보 입력" << endl;
		cout << "hide cone 높이 입력: ";
		cin >> hheight;
		cout << "hide cone 반지름 입력: ";
		cin >> hradius;
		cout << endl;

		if(hradius != (radius * hheight / height))
		{
			cout << "올바른 반지름 : " << radius * hheight / height << endl;
			hradius = (radius * hheight / height);
		}
		
		if(height > 0 && radius > 0 && hheight > 0 && hradius > 0 && height > hheight)
		{
			break;
		}
		cout << "높이 또는 반지름을 0의 이상의 값으로 입력해주세요" << endl;
		cout << "또는 large cone높이를 hide cone 보다 크게 입력해주세요";
	}

	cone conelarge(radius, height);
	cone conehide(hradius, hheight);

	topless.m_conelarge = conelarge;
	topless.m_conehide = conehide;


}



int main()
{
	float width=0;
	float height=0;
	float length=0;
	float radius=0;
	float base=0;
	float cheight=0;
	float hheight=0;


	int i;
	int j;

	for(;;)
	{
		cout << "메뉴 항목을 골라주세요" << endl;
		cout << "0.exit" << endl <<"1.box" << endl << "2.cylinder" << endl << "3.prism" << endl << "4.cone" << endl << "5.sphere" << endl << "6.cone & cylinder" << endl << "7.toplesscone" << endl << "8.make toplesscone" << endl;
		cout << "메뉴 항목 : ";
		cin >> i;
		
		if(i == 0)
		{
			cout << "\n감사합니다.\n\n";
			break;
		}

		if(i == 1)
		{
			box box;
			box.input();
			
			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				box.printvolume();
				cout << " = " << box.getvolume() << endl;
			}
			if(j == 2)
			{
				box.printsurface();
				cout << " = " << box.getsurface() << endl;
			}
			if(j > 2 || j < 0)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 2)
		{
			cylinder cylinder;
			cylinder.input();
			
			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				cylinder.printvolume();
				cout << " = " << cylinder.getvolume() << endl;
			}
			if(j == 2)
			{
				cylinder.printsurface();
				cout << " = " << cylinder.getsurface() << endl;
			}
			if(j > 2 || j < 0)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 3)
		{
			prism prism;
			prism.input();
			
			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				prism.printvolume();
				cout << " = " << prism.getvolume() << endl;
			}
			if(j == 2)
			{
				prism.printsurface();
				cout << " = " << prism.getsurface() << endl;
			}
			if(j > 2 || j < 0)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}
		
		if(i == 4)
		{
			cone cone;
			cone.input();
			
			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				cone.printvolume();
				cout << " = " << cone.getvolume() << endl;
			}
			if(j == 2)
			{
				cone.printsurface();
				cout << " = " << cone.getsurface() << endl;
			}
			if(j< 0 || j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 5)
		{
			sphere sphere;
			sphere.input();

			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{				
				sphere.printvolume();
				cout << " = " << sphere.getvolume() << endl;
			}
			if(j == 2)
			{
				sphere.printsurface();
				cout << " = " << sphere.getsurface() << endl;
			}
			if(j< 0 || j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}
				
		if(i == 6)
		{
			conencylinder conencylinder;
			conencylinder.input();

			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;
			
			if(j == 1)
			{
				conencylinder.printvolume();
				cout << " = " << conencylinder.getvolume() << endl;
			}
			if(j == 2)
			{
				conencylinder.printsurface();
				cout << " = " << conencylinder.getsurface() << endl;
			}
			if(j< 0 || j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 7)
		{
			toplesscone toplesscone;
			toplesscone.input();
			
			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;
			
			if(j == 1)
			{
				toplesscone.printvolume();
				cout << " = " << toplesscone.getvolume() << endl;
			}
			if(j == 2)
			{
				toplesscone.printsurface();
				cout << " = " << toplesscone.getsurface() << endl;
			}
			if(j< 0 || j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 8)
		{
			toplesscone topless;
			maketoplesscone(topless);

			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;
			
			if(j == 1)
			{
				topless.printvolume();
				cout << " = " << topless.getvolume() << endl;
			}
			if(j == 2)
			{
				topless.printsurface();
				cout << " = " << topless.getsurface() << endl;
			}
			if(j< 0 || j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}
		
		cout << endl;

		if(i < 0 || i > 8)
		{
			cout << "올바른 메뉴를 입력해주세요" << endl;
		}	
	}
	return 0;
}

