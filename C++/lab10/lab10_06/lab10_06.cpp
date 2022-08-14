#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
void main( )
{
vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
v.push_back(50);
if( binary_search(v.begin(), v.end(), 20) )
cout << "20 있음!" << endl;
else
cout << "20 없음!" << endl;
if( binary_search(v.begin(), v.end(), 15) )
cout << "15 있음!" << endl;
else
cout << "15 없음!" << endl;
}