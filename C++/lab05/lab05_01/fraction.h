class fraction
{
private:
	int numerator;
	int denominator;

public:
	fraction();
	inline void print();
	void store(int a,int b)
	{
		numerator = a;
		denominator = b;
	}
};

fraction::fraction()
{
	numerator=0;
	denominator=0;
}
