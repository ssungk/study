#include <iostream>
using namespace std;

#include "Polygons.h"
#include "Rectangle.h"
#include "Triangle.h"


int main()
{
	cout << "## ������ ���̿� �ѷ� ���ϱ� ##" << endl;

	Triangle t(5,12);
	t.calcArea();
	t.calcPerimeter();

	Rectangle rect(10,20);
	rect.calcArea();
	rect.calcPerimeter();

	cout << endl << "[�����ﰢ��]" << endl;
	t.printArea();
	t.printPerimeter();

	cout << endl << "[���簢��]" << endl;
	rect.printArea();
	rect.printPerimeter();
	
	
	return 0;
}