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
	cout << "�����ﰢ���� ���̴� " << area << "�Դϴ�." << endl;
}

void Triangle::printPerimeter()
{
	cout << "�����ﰢ���� �ѷ��� " << perimeter << "�Դϴ�." << endl;
}
