#include "Polygons.h"
#include <iostream>
using namespace std;

Polygons::Polygons()
{
	area = 0;
	perimeter = 0;
}

void Polygons::printArea()
{
	cout << "도형의 넓이는 " << area << "입니다." << endl;
}

void Polygons::printPerimeter()
{
	cout << "도형의 둘레는 " << perimeter << "입니다." << endl;
}