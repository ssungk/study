#include <iostream>
using namespace std;
#include "Clss_def.h"
#include <math.h>

const double Shape::PI = 3.141592; 

Shape::Shape()
{
}
void Shape::inputVal()
{
}
void Shape::calculate()
{
}
void Shape::print()
{
}

TwoDimensinal::TwoDimensinal()
{
}
void TwoDimensinal::print()
{
	switch(shapeType)
	{
	case TRIANGLE:
		cout << "삼각형 ";
		break;
	case RECTANGLE:
		cout << "사각형 ";
		break;
	case CIRCLE:
		cout << "원 ";
		break;
	}

cout << "넓이 : " << m_area << " / 둘레 : " << m_perimter << endl;
}

ThreeDimensinal::ThreeDimensinal()
{
}
void ThreeDimensinal::print()
{
	switch(shapeType)
	{
	case CONE:
		cout << "원뿔 ";
		break;
	case CUBE:
		cout << "정육면체 ";
		break;
	case SHPHERE:
		cout << "구 ";
		break;
	}
	cout << "부피 : " << m_area << " / 겉넓이 : " << m_perimter << endl;
}


Triangle::Triangle()
{
	shapeType = TRIANGLE;
}
void Triangle::inputVal()
{
	cout << "삼각형의 밑변<Width> : ";
	cin >> width;
	cout << "삼각형의 높이<Geight> : ";
	cin >> height;

}
void Triangle::calculate()
{
	m_area = (width * height)/2;
	m_perimter = width + height + sqrt( width*width + height*height );
}

Rectangle::Rectangle()
{
	shapeType = RECTANGLE;
}
void Rectangle::inputVal()
{
	cout << "사각형의 밑변<Width> : ";
	cin >> width;
	cout << "사각형의 높이<Geight> : ";
	cin >> height;
	
}
void Rectangle::calculate()
{
	m_area = (width * height);
	m_perimter = 2 * (width + height);
}

Circle::Circle()
{
	shapeType = CIRCLE;
}
void Circle::inputVal()
{
	cout << "원의 반지름<Radius> : ";
	cin >> radius;
	
}
void Circle::calculate()
{
	m_area = PI * radius * radius;
	m_perimter = 2 * PI * radius;
}

Cone::Cone()
{
	shapeType = CONE;
}
void Cone::inputVal()
{
	cout << "반지름<Radius> : ";
	cin >> radius;
	cout << "높이<Height> : ";
	cin >> height;
	
}
void Cone::calculate()
{
	m_area = (height * PI * radius * radius) / 3;
	m_perimter = PI * radius * sqrt(radius * radius + height * height) + PI * radius * radius;
}

Cube::Cube()
{
	shapeType = CUBE;
}
void Cube::inputVal()
{
	cout << "한변의 길이<Side> : ";
	cin >> side;
	
}
void Cube::calculate()
{
	m_area = side * side * side;
	m_perimter = side * side * 6;
}

Shphere::Shphere()
{
	shapeType = SHPHERE;
}
void Shphere::inputVal()
{
	cout << "반지름<Radius> : ";
	cin >> radius;
	
}
void Shphere::calculate()
{
	m_area = (4 * PI * radius * radius * radius) / 3;
	m_perimter = 4 * PI * radius * radius;
}