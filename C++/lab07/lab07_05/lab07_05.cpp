#include <iostream>
using namespace std;
#include "Polygons.h"
#include "Rectangle.h"
#include "Square.h"

int main()
{
	cout << "## ������ ���̿� �ѷ� ���ϱ� ##" << endl;

	Square sqr(5);
	sqr.calcArea();
	sqr.calcPerimeter();

	Rectangle rect(10,20);
	rect.calcArea();
	rect.calcPerimeter();

	cout << endl << "[���簢��]" << endl;
	sqr.printArea();
	sqr.printPerimeter();

	cout << endl << "[���簢��]" << endl;
	rect.printArea();
	rect.printPerimeter();

	return 0;
}