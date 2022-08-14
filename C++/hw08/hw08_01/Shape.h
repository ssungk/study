enum SHAPES{TRIANGLE = 1, RECTANGLE, CIRCLE, CONE, CUBE, SHPHERE};
typedef float INPUT;
typedef double RESULT;

class Shape
{
protected:
	SHAPES shapeType;
public:
	Shape();
	SHAPES getShapeType();
	const static double PI;
	virtual void inputVal() = 0;
	virtual void calculate() = 0;
	virtual void print() = 0;
	virtual Shape* dup(int factor) = 0;
};

class TwoDimResult
{
private:
	RESULT m_area;
	RESULT m_perimter;
public:
	void set(float a,float b);
	void print();
};

class ThreeDimResult
{
private:
	RESULT m_area;
	RESULT m_volume;
public:
	void set(float a,float b);
	void print();
};

class TwoDimensinal : public Shape
{
protected:
	TwoDimResult tdr;
//	RESULT m_area;
//	RESULT m_perimter;
public:
	TwoDimensinal();
	void print();

};

class ThreeDimensinal : public Shape
{
protected:
	ThreeDimResult tdr;
//	RESULT m_area;
//	RESULT m_perimter;
public:
	ThreeDimensinal();
	void print();

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