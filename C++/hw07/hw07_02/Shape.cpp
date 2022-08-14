#include <iostream>
using namespace std;
#include "Shape.h"
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
Shape * Shape::dup(int factor)
{
	return new Shape();
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
	cout << "���� : " << m_area << " / �ѷ� : " << m_perimter << endl;
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
	cout << "���� : " << m_area << " / �ѳ��� : " << m_perimter << endl;
}


Triangle::Triangle()
{
	shapeType = TRIANGLE;
}
void Triangle::inputVal()
{
	cout << "�ﰢ���� �غ�<Width> : ";
	cin >> width;
	cout << "�ﰢ���� ����<Geight> : ";
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
	cout << "�簢���� �غ�<Width> : ";
	cin >> width;
	cout << "�簢���� ����<Geight> : ";
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
	cout << "���� ������<Radius> : ";
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
	cout << "������<Radius> : ";
	cin >> radius;
	cout << "����<Height> : ";
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
	cout << "�Ѻ��� ����<Side> : ";
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
	cout << "������<Radius> : ";
	cin >> radius;
	
}
void Shphere::calculate()
{
	m_area = (4 * PI * radius * radius * radius) / 3;
	m_perimter = 4 * PI * radius * radius;
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