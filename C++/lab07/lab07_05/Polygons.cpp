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
	cout << "������ ���̴� " << area << "�Դϴ�." << endl;
}

void Polygons::printPerimeter()
{
	cout << "������ �ѷ��� " << perimeter << "�Դϴ�." << endl;
}