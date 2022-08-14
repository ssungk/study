#include <iostream>
#include <time.h>
using namespace std;

#include "set.h"



int main()
{
	set a;
	a.add(1);
	a.add(2);
	a.add(4);
	a.add(9);
	cout << "A's set : ";
	a.print();
	cout << endl;

	set b;
	b.add(3);
	b.add(2);
	b.add(7);
	b.add(8);
	cout << "B's set : ";
	b.print();
	cout << endl;

	set c;
	c = a + b;
	cout << "A + B : ";
	c.print();
	cout << endl;

	set d;
	d = a - b;
	cout << "A - B : ";
	d.print();
	cout << endl;

	set e;
	e = a * b;
	cout << "A * B : ";
	e.print();
	cout << endl;

	set f(a);
	f += b;
	cout << "A += B : ";
	f.print();
	cout << endl;

	set g(a);
	g -= b;
	cout << "A -= B : ";
	g.print();
	cout << endl;
	
	set h(a);
	h *= b;
	cout << "A *= B : ";
	h.print();
	cout << endl;

	set u;
	int i;
	int j;
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		j = rand()%100+1;
		if(!u.ismember(j))
		{
			u.add(j);
		}
		else
		{
			i--;
		}
	}
	cout << "U's set : ";
	u.print();
	cout << endl;
	
	set t(u);
	evendelete(t);
	cout << "T's set : ";
	t.print();
	cout << endl;

	return 0;
}

