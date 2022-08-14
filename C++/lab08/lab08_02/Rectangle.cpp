#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : sideA(0) , sideB(0)
{
}

Rectangle::Rectangle(int a,int b) : sideA(a) , sideB(b)
{
}

void Rectangle::calcArea()
{
	area = sideA * sideB;
}

void Rectangle::calcPerimeter()
{
	perimeter = 2 * (sideA + sideB);
}

void Rectangle::printArea()
{
	cout << "사각형의 넓이는 " << area << "입니다." << endl;
}

void Rectangle::printPerimeter()
{
	cout << "사각형의 둘레는 " << perimeter << "입니다." << endl;
}