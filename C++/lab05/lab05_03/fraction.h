class fraction
{
private:
	int numerator;
	int denominator;
	int GreatestComDiv(int,int);

public:
	fraction();
	fraction(int n,int d);
	void print();
	fraction operator = (const fraction& fr);
	fraction operator += (const fraction& fr);
	fraction operator ++();
	fraction operator ++ (int);
};