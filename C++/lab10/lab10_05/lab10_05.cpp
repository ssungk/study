#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void main( )
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	for(int i = 0 ; i < v.size() ; i++)
		cout << v[i] << " ";
	cout << endl;
	sort(v.begin(), v.end());
	for(int i = 0 ; i < v.size() ; i++)
		cout << v[i] << " ";
	cout << endl;
}
