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
		cout << "1. 직각삼각형(Triangle)" << endl
			<< "2. 사각형(Rectangle)" << endl
			<< "3. 원(Circle)" << endl
			<< "4. 원뿔(Cone)" << endl
			<< "5. 정육면체(Cube)" << endl
			<< "6. 구(Shphere)" << endl
			<< "0. 종료(Exit)" << endl;
		cout << "도형을 선택하세요 : ";
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
			cout << "프로그램이 종료 됩니다!" << endl;
			return 0;	
		}
		
		shapePtr->inputVal();
		int factor;
		cout << "확대할 값을 입력하시오 : ";
		cin >> factor;
		Shape* shapePtr2 = shapePtr->dup(factor);
		shapePtr->calculate();
		shapePtr2->calculate();
		cout << "원래 도형" << endl;
		shapePtr->print();
		cout << factor << "배 확대한 도형" << endl;
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