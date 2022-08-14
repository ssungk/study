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
		cout << "�޴� �׸��� ����ּ���" << endl;
		cout << "1.box" << endl << "2.cylinder" << endl << "3.prism" << endl << "4.exit" << endl;
		cout << "�޴� �׸� : ";
		cin >> i;
		
		if(i == 1)
		{
			cout << "\nbox�� ���� �Է�" << endl;
			cout << "�ʺ� �Է� : ";
			cin >> width;
			cout << "���� �Է� : ";
			cin >> heigth;
			cout << "���� �Է� : ";
			cin >> length;
			cout << endl;

			cout << "�޴� �׸��� ����ּ���" << endl;
			cout << "1.����" << endl << "2.�ѳ���" << endl;
			cout << "�޴� �׸� : ";
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
				cout << "\n�ùٸ� �޴��� �Է����ּ���" << endl;
			}
		}

		if(i == 2)
		{
			cout << "\ncylinder�� ���� �Է�" << endl;
			cout << "������ �Է� : ";
			cin >> radius;
			cout << "���� �Է� : ";
			cin >> heigth;
			cout << endl;

			cout << "�޴� �׸��� ����ּ���" << endl;
			cout << "1.����" << endl << "2.�ѳ���" << endl;
			cout << "�޴� �׸� : ";
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
				cout << "\n�ùٸ� �޴��� �Է����ּ���" << endl;
			}
		}

		if(i == 3)
		{
			cout << "\nprism�� ���� �Է�" << endl;
			cout << "�غ� �Է� : ";
			cin >> base;
			cout << "���� �Է� : ";
			cin >> heigth;
			cout << "���� �Է� : ";
			cin >> length;
			cout << endl;

			cout << "�޴� �׸��� ����ּ���" << endl;
			cout << "1.����" << endl << "2.�ѳ���" << endl;
			cout << "�޴� �׸� : ";
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
				cout << "\n�ùٸ� �޴��� �Է����ּ���" << endl;
			}
		}
		
		if(i == 4)
		{
			cout << "\n�����մϴ�.\n\n";
			break;
		}

		cout << endl;

		if(i > 4)
		{
			cout << "�ùٸ� �޴��� �Է����ּ���" << endl;
		}	
	}
	return 0;
}