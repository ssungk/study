#include <iostream>
using namespace std;
#include "Clss_def.h"

int main()
{
	Shape* shapePtr;
	int input;

	while(1)
	{
		cout << "1. �����ﰢ��(Triangle)" << endl
			<< "2. �簢��(Rectangle)" << endl
			<< "3. ��(Circle)" << endl
			<< "4. ����(Cone)" << endl
			<< "5. ������ü(Cube)" << endl
			<< "6. ��(Shphere)" << endl
			<< "0. ����(Exit)" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> input;

		switch(input)
		{
		case 1:
			shapePtr = new Triangle();
			break;
		case 2:
			shapePtr = new Rectangle();
			break;
		case 3:
			shapePtr = new Circle();
			break;
		case 4:
			shapePtr = new Cone();
			break;
		case 5:
			shapePtr = new Cube();
			break;
		case 6:
			shapePtr = new Shphere();
			break;
		case 0:
			cout << "���α׷��� ���� �˴ϴ�!" << endl;
			return 0;	
		}
		
		shapePtr->inputVal();
		shapePtr->calculate();
		shapePtr->print();
	}	
	
	return 0;
}