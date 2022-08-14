#include <iostream>
using namespace std;
#include "Shape.h"

int main()
{
	Shape* shapePtr;
	Triangle* triPtr ;
	Rectangle* recPtr;
	Circle* cirPtr;
	Cone* conPtr;
	Cube* cubPtr;
	Shphere* shpPtr;

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
		int factor;
		cout << "Ȯ���� ���� �Է��Ͻÿ� : ";
		cin >> factor;
		Shape* shapePtr2 = shapePtr->dup(factor);
		shapePtr->calculate();
		shapePtr2->calculate();
		cout << "���� ����" << endl;
		shapePtr->print();
		cout << factor << "�� Ȯ���� ����" << endl;
	//	shapePtr2->print();
		shapePtr2->getShapeType();
		switch(shapePtr2->getShapeType())
		{
		case TRIANGLE:
			triPtr = dynamic_cast<Triangle*>(shapePtr2);
			triPtr->print();
			break;
		case RECTANGLE:
			recPtr = dynamic_cast<Rectangle*>(shapePtr2);
			recPtr->print();
			break;
		case CIRCLE:
			cirPtr = dynamic_cast<Circle*>(shapePtr2);
			cirPtr->print();
			break;
		case CONE:
			conPtr = dynamic_cast<Cone*>(shapePtr2);
			conPtr->print();
			break;
		case CUBE:
			cubPtr = dynamic_cast<Cube*>(shapePtr2);
			cubPtr->print();
			break;
		case SHPHERE:
			shpPtr = dynamic_cast<Shphere*>(shapePtr2);
			shpPtr->print();
			break;
		}
		cout << endl;
	}	
	
	return 0;
}