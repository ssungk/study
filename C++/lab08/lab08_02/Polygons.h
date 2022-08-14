#ifndef POLYGONS_H
#define POLYGONS_H

class Polygons
{
protected:
	int area;
	int perimeter;
public:
	Polygons();
	virtual void printArea() = 0;
	virtual void printPerimeter() = 0;
};


Polygons::Polygons()
{
}

#endif