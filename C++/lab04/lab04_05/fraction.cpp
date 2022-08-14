#include "Fraction.h"

CFraction::CFraction(void)
{
	m_nNumerator     =0; 
	m_nDenominator   =1; 
}

CFraction::CFraction (int nNumer)
{
	m_nNumerator = nNumer;
	m_nDenominator = 1;
}

CFraction::CFraction (int nNumer, int nDenom)
{
	if(nDenom==0)
	{
		cout << "can not divide by 0" << endl;
		exit(100);
	}
		
	int gcd = GreatestComDiv(nNumer,nDenom);
	nNumer = nNumer / gcd;
	nDenom = nDenom / gcd;

	if(nDenom < 0)
	{
		nDenom = -nDenom;
		nNumer = -nNumer;
	}

	m_nNumerator = nNumer;
	m_nDenominator = nDenom;
}

void CFraction::store (int nNumer, int nDenom)
{
	if(nDenom==0)
	{
		cout << "can not divide by 0" << endl;
		exit(100);
	}

	int gcd = GreatestComDiv(nNumer,nDenom);
	nNumer = nNumer / gcd;
	nDenom = nDenom / gcd;

	if(nDenom < 0)
	{
		nDenom = -nDenom;
		nNumer = -nNumer;
	}
		
	m_nNumerator = nNumer;
	m_nDenominator = nDenom;

	return;
}

void CFraction::print () const
{
	cout << m_nNumerator << "/" << m_nDenominator ;
	return;
}

int  CFraction::GreatestComDiv(int nNumer,int nDenom)
{
	if (nDenom == 0)
	{
		return nNumer;
	}
    return GreatestComDiv(nDenom,nNumer % nDenom);
}

void CFraction::add(const CFraction& fr)
{
	this->m_nNumerator = (this->m_nNumerator)*(fr.m_nDenominator) + (this->m_nDenominator)*(fr.m_nNumerator);
	this->m_nDenominator = (this->m_nDenominator)*(fr.m_nDenominator);

	
	int gcd = GreatestComDiv(this->m_nNumerator,this->m_nDenominator);
	this->m_nNumerator = this->m_nNumerator / gcd;
	this->m_nDenominator = this->m_nDenominator / gcd;

	if(this->m_nDenominator < 0)
	{
		this->m_nDenominator = -this->m_nDenominator;
		this->m_nNumerator = -this->m_nNumerator;
	}

	
}
void CFraction::subtract(const CFraction& fr)
{
	this->m_nNumerator = (this->m_nNumerator)*(fr.m_nDenominator) - (this->m_nDenominator)*(fr.m_nNumerator);
	this->m_nDenominator = (this->m_nDenominator)*(fr.m_nDenominator);

	int gcd = GreatestComDiv(this->m_nNumerator,this->m_nDenominator);
	this->m_nNumerator = this->m_nNumerator / gcd;
	this->m_nDenominator = this->m_nDenominator / gcd;

	if(this->m_nDenominator < 0)
	{
		this->m_nDenominator = -this->m_nDenominator;
		this->m_nNumerator = -this->m_nNumerator;
	}
}
void CFraction::multiply(const CFraction& fr)
{
	this->m_nNumerator = (this->m_nNumerator)*(fr.m_nNumerator);
	this->m_nDenominator = (this->m_nDenominator)*(fr.m_nDenominator);

	int gcd = GreatestComDiv(this->m_nNumerator,this->m_nDenominator);
	this->m_nNumerator = this->m_nNumerator / gcd;
	this->m_nDenominator = this->m_nDenominator / gcd;

	if(this->m_nDenominator < 0)
	{
		this->m_nDenominator = -this->m_nDenominator;
		this->m_nNumerator = -this->m_nNumerator;
	}
}
void CFraction::divide(const CFraction& fr)
{
	this->m_nNumerator = (this->m_nNumerator)*(fr.m_nDenominator);
	this->m_nDenominator = (this->m_nDenominator)*(fr.m_nNumerator);

	int gcd = GreatestComDiv(this->m_nNumerator,this->m_nDenominator);
	this->m_nNumerator = this->m_nNumerator / gcd;
	this->m_nDenominator = this->m_nDenominator / gcd;

	if(this->m_nDenominator < 0)
	{
		this->m_nDenominator = -this->m_nDenominator;
		this->m_nNumerator = -this->m_nNumerator;
	}
}

CFraction:: ~CFraction(void)
{
}