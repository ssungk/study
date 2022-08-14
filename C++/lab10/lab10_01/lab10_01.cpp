#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>


class Member
{
public:
	Member(string f, string l) :
	first_n(f), last_n(l) {}
	void print()
	{
		cout << last_n << " " << first_n << endl;
	}
private:
	string last_n, first_n;
	friend bool operator < (Member& m1,	Member& m2)
	{
		return m1.last_n < m2.last_n;
	}
	friend bool operator == (Member& m1, Member& m2)
	{
		return m1.last_n == m2.last_n;
	}
};

int main ()
{
	list<Member> li1;
	li1.push_back(Member("Linda","Smith"));
	li1.push_back(Member("Robert","Frost"));
	li1.push_back(Member("Alex","Amstrong"));
	list<Member> li2;
	li2.push_back(Member("Linda","Smith"));
	li2.push_back(Member("John","Wood"));
	li2.push_back(Member("Alex","Amstrong"));
	li1.sort();
	li2.sort();
	li1.merge(li2);
	cout << "li1 after sorting and mergin"<< endl;
	list<Member>::iterator it = li1.begin();
	while ( it != li1.end() ) (it++)->print();
	li1.unique();
	cout << "After li1.unique()" << endl;
	it = li1.begin();
	while ( it != li1.end() ) (it++)->print();

	return 0;
}