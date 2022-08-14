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
	cout << "���� : " << m_area << " / �ѷ� : " << m_perimter << endl;
}

void ThreeDimResult::print()
{
	cout << "���� : " << m_volume << " / �ѳ��� : " << m_area << endl;
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
		cout << "�ﰢ�� ";
		break;
	case RECTANGLE:
		cout << "�簢�� ";
		break;
	case CIRCLE:
		cout << "�� ";
		break;
	}
	tdr.print();
//	cout << "���� : " << tdr.m_area << " / �ѷ� : " << tdr.m_perimter << endl;
}

ThreeDimensinal::ThreeDimensinal()
{
}
void ThreeDimensinal::print()
{
	switch(shapeType)
	{
	case CONE:
		cout << "���� ";
		break;
	case CUBE:
		cout << "������ü ";
		break;
	case SHPHERE:
		cout << "�� ";
		break;
	}
	tdr.print();
//	cout << "���� : " << tdr.m_volume << " / �ѳ��� : " << tdr.m_area << endl;
}


Triangle::Triangle()
{
	shapeType = TRIANGLE;
}
void Triangle::inputVal()
{
	cout << "�ﰢ���� �غ�<Width> : ";
	cin >> width;
	cout << "�ﰢ���� ����<Height> : ";
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
	cout << "�簢���� �غ�<Width> : ";
	cin >> width;
	cout << "�簢���� ����<Geight> : ";
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
	cout << "���� ������<Radius> : ";
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
	cout << "������<Radius> : ";
	cin >> radius;
	cout << "����<Height> : ";
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
	cout << "�Ѻ��� ����<Side> : ";
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
	cout << "������<Radius> : ";
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