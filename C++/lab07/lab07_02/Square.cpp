#include "Polygons.h"
#include "Square.h"
#include <iostream>
using namespace std;

Square::Square() : side(0) 
{
}

Square::Square(int a) : side(a)
{
}

void Square::calcArea()
{
	area = side * side;
}

void Square::calcPerimeter()
{
	perimeter = 4 * (side);
}