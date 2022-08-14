#include "Polygons.h"

class Triangle : public Polygons
{
private:
	int width;
	int height;
public:
	Triangle();
	Triangle(int w,int h);
	void calcArea();
	void calcPerimeter();
	virtual void printArea();
	virtual void printPerimeter();
};


