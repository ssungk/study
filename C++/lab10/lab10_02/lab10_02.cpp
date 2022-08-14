#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Member
{

public:
	Member(string t, double d) : name(t), sal(d)
	{
	}
	void print()
	{
		cout << name << " "<< sal <<endl;
	}
private:
	string name;
	double sal;
};

int main()
{
	vector<Member> v;
	int i;
	v.push_back(Member("Linda", 75000));
	v.push_back(Member("Robert", 60000));
	vector<Member>::iterator it = v.begin();
	cout << "Entire vector(using iterator):" <<endl; // Iterator�� �̿��Ͽ� ��ü ���� ���
	while(it != v.end())
		(it++)->print();
	cout <<endl;
	cout << "Entire vector(random access):" << endl; // ���� ������ ���� vector ��ü ���� ���
	for(i=0; i<v.size(); i++)
	v[i].print(); cout << endl;
	cout << "Return from front()" <<endl;
	v.front().print();
	return 0;
}