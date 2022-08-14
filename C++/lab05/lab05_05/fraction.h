#include <iostream>
using namespace std;

class fraction
{
private:
	int numerator;
	int denominator;
	int GreatestComDiv(int,int);	
	static int naddopcount;
	static int nsubstractcount;
public:
	fraction (void); 
	fraction (int nNumer); 
	fraction (int nNumer, int nDenom); 
	~fraction();
	void store (int nNumer, int nDenom);
	void print ();
	void printThisValue(void);
	void printThisValueWithArgument(const fraction &dummyFr);
	friend void store(int nNumer,int nDenom,fraction &fr);
	friend void print(const fraction& fr);
	fraction operator = (const fraction& fr);
	fraction operator + (const fraction& fr);
	fraction operator - (const fraction& fr);
	fraction operator * (const fraction& fr);
	fraction operator / (const fraction& fr);
	fraction operator ++();
	fraction operator ++ (int);
	void add(fraction& fr);
	void substract(fraction& fr);
	static void printstatic();
};