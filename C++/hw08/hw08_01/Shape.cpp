#include <iostream>
using namespace std;
#include "Shape.h"
#include <math.h>

const double Shape::PI = 3.141592; 

Shape::Shape()
{
}
SHAPES Shape::getShapeType()
{
	return shapeType;
}

void TwoDimResult::print()
{
	cout << "넓이 : " << m_area << " / 둘레 : " << m_perimter << endl;
}

void ThreeDimResult::print()
{
	cout << "부피 : " << m_volume << " / 겉넓이 : " << m_area << endl;
}
void TwoDimResult::set(float a,float b)
{	
	 m_area = a;
	 m_perimter = b;
}

void ThreeDimResult::set(float a,float b)
{	
	m_volume = a;
	m_area = b;
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
	tdr.print();
//	cout << "넓이 : " << tdr.m_area << " / 둘레 : " << tdr.m_perimter << endl;
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
	tdr.print();
//	cout << "부피 : " << tdr.m_volume << " / 겉넓이 : " << tdr.m_area << endl;
}


Triangle::Triangle()
{
	shapeType = TRIANGLE;
}
void Triangle::inputVal()
{
	cout << "삼각형의 밑변<Width> : ";
	cin >> width;
	cout << "삼각형의 높이<Height> : ";
	cin >> height;
}
void Triangle::calculate()
{
	tdr.set((width * height)/2,width + height + sqrt( width*width + height*height ));
//	tdr.m_area = (width * height)/2;
//	tdr.m_perimter = width + height + sqrt( width*width + height*height );
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
	tdr.set(width * height,2 * (width + height));
//	tdr.m_area = (width * height);
//	tdr.m_perimter = 2 * (width + height);
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
	tdr.set(PI * radius * radius,2 * PI * radius);
//	tdr.m_area = PI * radius * radius;
//	tdr.m_perimter = 2 * PI * radius;
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
	tdr.set((height * PI * radius * radius) / 3, PI * radius * sqrt(radius * radius + height * height) + PI * radius * radius);
//	tdr.m_volume = (height * PI * radius * radius) / 3;
//	tdr.m_area = PI * radius * sqrt(radius * radius + height * height) + PI * radius * radius;
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
	tdr.set(side * side * side, side * side * 6);
//	tdr.m_volume = side * side * side;
//	tdr.m_area = side * side * 6;
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
	tdr.set((4 * PI * radius * radius * radius) / 3,4 * PI * radius * radius);
//	tdr.m_volume = (4 * PI * radius * radius * radius) / 3;
//	tdr.m_area = 4 * PI * radius * radius;
}

Triangle::Triangle(Triangle& t)
{
	width = t.width;
	height = t.height;
	shapeType = t.shapeType;
}

Shape * Triangle::dup(int factor)
{
	Triangle temp;
	temp.width = factor * width;
	temp.height = factor * height;

	return new Triangle(temp);
}

Rectangle::Rectangle(Rectangle& r)
{
	width = r.width;
	height = r.height;
	shapeType = r.shapeType;
}

Shape * Rectangle::dup(int factor)
{
	Rectangle temp;
	temp.width = factor * width;
	temp.height = factor * height;

	return new Rectangle(temp);
}

Circle::Circle(Circle& c)
{
	radius = c.radius;
	shapeType = c.shapeType;
}

Shape * Circle::dup(int factor)
{
	Circle temp;
	temp.radius = factor * radius;

	return new Circle(temp);
}

Cone::Cone(Cone& c)
{
	radius = c.radius;
	height = c.height;
	shapeType = c.shapeType;
}

Shape * Cone::dup(int factor)
{
	Cone temp;
	temp.radius = factor * radius;
	temp.height = factor * height;

	return new Cone(temp);
}

Cube::Cube(Cube& c)
{
	side = c.side;
	shapeType = c.shapeType;
}

Shape * Cube::dup(int factor)
{
	Cube temp;
	temp.side = factor * side;

	return new Cube(temp);
}

Shphere::Shphere(Shphere& s)
{
	radius = s.radius;
	shapeType = s.shapeType;
}

Shape * Shphere::dup(int factor)
{
	Shphere temp;
	temp.radius = factor * radius;

	return new Shphere(temp);
}