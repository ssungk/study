enum SHAPES{TRIANGLE = 1, RECTANGLE, CIRCLE, CONE, CUBE, SHPHERE};
typedef float INPUT;
typedef double RESULT;

class Shape
{
protected:
	SHAPES shapeType;
public:
	Shape();
	const static double PI;
	virtual void inputVal();
	virtual void calculate();
	virtual void print();
	virtual Shape * dup(int factor);
};

class TwoDimensinal : public Shape
{
protected:
	RESULT m_area;
	RESULT m_perimter;
public:
	TwoDimensinal();
	virtual void print();

};

class ThreeDimensinal : public Shape
{
protected:
	RESULT m_area;
	RESULT m_perimter;
public:
	ThreeDimensinal();
	virtual void print();

};

class Triangle : public TwoDimensinal
{
private:
	INPUT width;
	INPUT height;
public:
	Triangle();
	Triangle(Triangle& t);
	virtual void inputVal();
	virtual void calculate();
	virtual Shape * dup(int factor);
};

class Rectangle : public TwoDimensinal
{
private:
	INPUT width;
	INPUT height;
public:
	Rectangle();
	Rectangle(Rectangle& r);
	virtual void inputVal();
	virtual void calculate();
	virtual Shape * dup(int factor);
};

class Circle : public TwoDimensinal
{
private:
	INPUT radius;
public:
	Circle();
	Circle(Circle& c);
	virtual void inputVal();
	virtual void calculate();
	virtual Shape * dup(int factor);
};

class Cone : public ThreeDimensinal
{
private:
	INPUT radius;
	INPUT height;
public:
	Cone();
	Cone(Cone& c);
	virtual void inputVal();
	virtual void calculate();
	virtual Shape * dup(int factor);
};

class Cube : public ThreeDimensinal
{
private:
	INPUT side;
public:
	Cube();
	Cube(Cube& c);
	virtual void inputVal();
	virtual void calculate();
	virtual Shape * dup(int factor);
};

class Shphere : public ThreeDimensinal
{
private:
	INPUT radius;
public:
	Shphere();
	Shphere(Shphere& s);
	virtual void inputVal();
	virtual void calculate();
	virtual Shape * dup(int factor);
};