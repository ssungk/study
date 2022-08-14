#include <iostream>
using namespace std;

#include "set.h"

set::set()
{
	pset = NULL;
	ncount = 0;
}
set::set(set& s)
{
	pset=new int [s.ncount];

	int i;
	for(i=0;i<s.ncount;i++)
	{
		pset[i]=s.pset[i];
	}
	ncount = s.ncount;
}
set::~set()
{
	delete[] pset;
}

bool set::add(int num)
{
	if(ismember(num))
	{
		return false;
	}
	ncount++;
	int* temp;
	temp = new int [ncount];
	int i;
	for(i=0;i<ncount-1;i++)
	{
		temp[i]=pset[i];
	}
	temp[i]=num;

	delete[] pset;
	pset = new int [ncount];
	pset = temp;

	return true;
}

bool set::remove(int num)
{
	if(ismember(num))
	{
		ncount--;
		int* temp;
		temp = new int [ncount];
		int i;
		for(i=0;i<ncount;i++) 
		{
			if(pset[i]==num)
			{
				break;
			}
			temp[i]=pset[i];
		}

		for(;i<ncount;i++)
		{
			temp[i]=pset[i+1];
		}
			
		delete[] pset;
		pset = new int [ncount];
		pset = temp;
				
		return true;
	}
	return false;
}

void set::print()
{
	int i;
	for(i=0;i<ncount;i++)
	{
		cout << pset[i] << " ";
	}
}

bool set::ismember(int num)
{
	int i;
	for(i=0;i<ncount;i++)
	{
		if(pset[i] == num)
		{
			return true;
		}
	}
	return false;
}

set set::operator = (const set& s)
{
	pset=new int [s.ncount];

	int i;
	for(i=0;i<s.ncount;i++)
	{
		pset[i]=s.pset[i];
	}
	ncount = s.ncount;
	return *this;
}

set set::operator + (const set& s)
{
	set temp(*this);
	int i;
	for(i=0;i < s.ncount;i++)
	{
		if(!temp.ismember(s.pset[i]))
		{
			temp.add(s.pset[i]);
		}
	}
	return set(temp);
}

set set::operator - (const set& s)
{
	set temp(*this);
	int i;
	for(i=0;i < s.ncount;i++)
	{
		if(temp.ismember(s.pset[i]))
		{
			temp.remove(s.pset[i]);
		}
	}
		
	return set(temp);
}

set set::operator * (const set& s)
{
	set temp;
	int i;
	for(i=0;i < s.ncount;i++)
	{
		if(ismember(s.pset[i]))
		{
			temp.add(s.pset[i]);
		}
	}
		
	return set(temp);
}

void operator += (set& a, set& s)
{
	int i;
	for(i=0;i < s.ncount;i++)
	{
		if(!a.ismember(s.pset[i]))
		{
			a.add(s.pset[i]);
		}
	}
	return;
}

void operator -= (set& a, set& s)
{
	int i;
	for(i=0;i < s.ncount;i++)
	{
		if(a.ismember(s.pset[i]))
		{
			a.remove(s.pset[i]);
		}
	}
	return;
}

void operator *= (set& a, set& s)
{
	set temp;
	int i;
	for(i=0;i < s.ncount;i++)
	{
		if(a.ismember(s.pset[i]))
		{
			temp.add(s.pset[i]);
		}
	}
	a = set(temp);
	return;
}

void evendelete(set& s)
{
	int i;
	int j;
	for(j=0;j<s.ncount;j++)
	{
		for(i=0;i<=100;i=i+2)
		{
			if(s.pset[i]==i);
			{
				s.remove(i);
			}
		}
	}
}

int set::getcount()
{
	return this->ncount;
}