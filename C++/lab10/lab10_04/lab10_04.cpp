#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

class Member
{
public:
	Member(string l, string f) : last(l), first(f){}
	void print() const
	{
		cout.setf(ios::left);
		cout << setw(15) << first << " "<< last <<endl;
	}
private:
	string first, last;
	friend bool operator < (const Member& m1, const Member& m2)
	{
		return (m1.last < m2.last) ? true : false;
	}
	friend bool operator == (const Member& m1, const Member& m2)
	{
		return (m1.last == m2.last) ? true : false;
	}
};

	int main ()
{
	typedef Member M;
	typedef set<M> S;
	M m("Frost","Robert");
	S s;
	s.insert(m);
	s.insert(M("Smith","John"));
	s.insert(M("Amstrong","Bill"));
	s.insert(M("Bain","Linda"));
	s.insert(M("Amstrong","Bill")); //두 번째 입력과 동일
	/* 기존에 존재하는 값들과 비교하여, 동일한 값이 이미 존재
	할 경우 값을 추가하지 않는다. 이 동작은 operator ==를
	통해 이루어진다. */
	S::iterator it = s.begin();
	while ( it != s.end() )
		(it++)->print();
	it = s.find(m);
	if ( it == s.end() )
		cout << "element not found" << endl;
	else
	{
		cout << "element is found : ";
		(*it).print();
	}
	return 0;
}