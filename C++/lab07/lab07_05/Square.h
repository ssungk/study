#include "Polygons.h"
class Square : public Polygons
{
private:
	int side;
public:
	Square();
	Square(int a);
	void calcArea();
	void calcPerimeter();
	void printArea();
	void printPerimeter();
};

