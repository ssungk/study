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