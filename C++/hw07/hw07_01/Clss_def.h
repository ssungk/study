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
	virtual void inputVal();
	virtual void calculate();
};

class Rectangle : public TwoDimensinal
{
private:
	INPUT width;
	INPUT height;
public:
	Rectangle();
	virtual void inputVal();
	virtual void calculate();
};

class Circle : public TwoDimensinal
{
private:
	INPUT radius;
public:
	Circle();
	virtual void inputVal();
	virtual void calculate();
};

class Cone : public ThreeDimensinal
{
private:
	INPUT radius;
	INPUT height;
public:
	Cone();
	virtual void inputVal();
	virtual void calculate();
};

class Cube : public ThreeDimensinal
{
private:
	INPUT side;
public:
	Cube();
	virtual void inputVal();
	virtual void calculate();
};

class Shphere : public ThreeDimensinal
{
private:
	INPUT radius;
public:
	Shphere();
	virtual void inputVal();
	virtual void calculate();
};