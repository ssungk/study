#include<iostream>
using namespace std;

#include "box.h"
#include "cylinder.h"
#include "prism.h"

int main()
{
	float width;
	float heigth;
	float length;
	float radius;
	float base;

	int i;
	int j;

	for(;;)
	{
		cout << "메뉴 항목을 골라주세요" << endl;
		cout << "1.box" << endl << "2.cylinder" << endl << "3.prism" << endl << "4.exit" << endl;
		cout << "메뉴 항목 : ";
		cin >> i;
		
		if(i == 1)
		{
			cout << "\nbox의 정보 입력" << endl;
			cout << "너비 입력 : ";
			cin >> width;
			cout << "높이 입력 : ";
			cin >> heigth;
			cout << "길이 입력 : ";
			cin >> length;
			cout << endl;

			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				box box;
				box.input(width, heigth, length);
				box.printvolume();
				cout << " = " << box.getvolume() << endl;
			}
			if(j == 2)
			{
				box box;
				box.input(width, heigth, length);
				box.printsurface();
				cout << " = " << box.getsurface() << endl;
			}
			if(j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 2)
		{
			cout << "\ncylinder의 정보 입력" << endl;
			cout << "반지름 입력 : ";
			cin >> radius;
			cout << "높이 입력 : ";
			cin >> heigth;
			cout << endl;

			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				cylinder cylinder;
				cylinder.input(radius, heigth);
				cylinder.printvolume();
				cout << " = " << cylinder.getvolume() << endl;
			}
			if(j == 2)
			{
				cylinder cylinder;
				cylinder.input(radius, heigth);
				cylinder.printsurface();
				cout << " = " << cylinder.getsurface() << endl;
			}
			if(j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}

		if(i == 3)
		{
			cout << "\nprism의 정보 입력" << endl;
			cout << "밑변 입력 : ";
			cin >> base;
			cout << "높이 입력 : ";
			cin >> heigth;
			cout << "길이 입력 : ";
			cin >> length;
			cout << endl;

			cout << "메뉴 항목을 골라주세요" << endl;
			cout << "1.부피" << endl << "2.겉넓이" << endl;
			cout << "메뉴 항목 : ";
			cin >> j;

			if(j == 1)
			{
				prism prism;
				prism.input(base, heigth, length);
				prism.printvolume();
				cout << " = " << prism.getvolume() << endl;
			}
			if(j == 2)
			{
				prism prism;
				prism.input(base, heigth, length);
				prism.printsurface();
				cout << " = " << prism.getsurface() << endl;
			}
			if(j > 2)
			{
				cout << "\n올바른 메뉴를 입력해주세요" << endl;
			}
		}
		
		if(i == 4)
		{
			cout << "\n감사합니다.\n\n";
			break;
		}

		cout << endl;

		if(i > 4)
		{
			cout << "올바른 메뉴를 입력해주세요" << endl;
		}	
	}
	return 0;
}