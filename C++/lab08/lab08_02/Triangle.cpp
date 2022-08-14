#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

Triangle::Triangle() : width(0), height(0) 
{
}

Triangle::Triangle(int w,int h) : width(w), height(h) 
{
}

void Triangle::calcArea()
{
	area = (width * height) / 2;
}

void Triangle::calcPerimeter()
{
	perimeter = width + height + sqrt(float(width * width + height * height));
}

void Triangle::printArea()
{
	cout << "직각삼각형의 넓이는 " << area << "입니다." << endl;
}

void Triangle::printPerimeter()
{
	cout << "직각삼각형의 둘레는 " << perimeter << "입니다." << endl;
}
