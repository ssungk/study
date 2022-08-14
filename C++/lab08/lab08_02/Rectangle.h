#include "Polygons.h"

class Rectangle : public Polygons
{
private:
	int sideA;
	int sideB;
public:
	Rectangle();
	Rectangle(int a,int b);
	void calcArea();
	void calcPerimeter();
	virtual void printArea();
	virtual void printPerimeter();
};