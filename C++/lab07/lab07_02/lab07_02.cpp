#include <iostream>
using namespace std;

#include "Polygons.h"
#include "Rectangle.h"
#include "Square.h"

int main()
{
	cout << "## 도형의 넓이와 둘레 구하기 ##" << endl;

	Square sqr(5);
	sqr.calcArea();
	sqr.calcPerimeter();

	Rectangle rect(10,20);
	rect.calcArea();
	rect.calcPerimeter();

	cout << endl << "[정사각형]" << endl;
	sqr.printArea();
	sqr.printPerimeter();

	cout << endl << "[직사각형]" << endl;
	rect.printArea();
	rect.printPerimeter();

	cout << "private으로 선언하면 상속을 받아오지 못하기 떄문에 쓰면 안된다" << endl;
	cout << "또 public으로 선언하면 상속 받을떄 area와 perimeter가 public이 되서 마음대로 수정할수 있기때문에 안된다." << endl;

	return 0;
}