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
	s.insert(M("Amstrong","Bill")); //�� ��° �Է°� ����
	/* ������ �����ϴ� ����� ���Ͽ�, ������ ���� �̹� ����
	�� ��� ���� �߰����� �ʴ´�. �� ������ operator ==��
	���� �̷������. */
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