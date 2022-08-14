#include <iostream>
using namespace std;
#include "Clss_def.h"

int main()
{
	Shape* shapePtr;
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
		shapePtr->calculate();
		shapePtr->print();
	}	
	
	return 0;
}