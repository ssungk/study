#include <iostream>
using namespace std;

#include "Polygons.h"
#include "Rectangle.h"
#include "Triangle.h"


int main()
{
	cout << "## 도형의 넓이와 둘레 구하기 ##" << endl;

	Triangle t(5,12);
	t.calcArea();
	t.calcPerimeter();

	Rectangle rect(10,20);
	rect.calcArea();
	rect.calcPerimeter();

	cout << endl << "[직각삼각형]" << endl;
	t.printArea();
	t.printPerimeter();

	cout << endl << "[직사각형]" << endl;
	rect.printArea();
	rect.printPerimeter();
	
	
	return 0;
}