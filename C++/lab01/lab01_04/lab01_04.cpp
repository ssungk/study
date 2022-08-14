#include <iostream>
#include <iomanip>
using namespace std;

int* topgrade (int*,int*,int*);

int main()
{
	int grade1;
	int grade2;
	int grade3;

	int* pgrade1;
	int* pgrade2;
	int* pgrade3;

	cin >> grade1;
	cin >> grade2;
	cin >> grade3;
	
	pgrade1 = &grade1;
	pgrade2 = &grade2;
	pgrade3 = &grade3;
		
	int* top;
	top = topgrade(pgrade1, pgrade2, pgrade3);
  
	cout << "value : grade1 = " << setw(10) << grade1 << " *pgrade1 = " << setw(10) << *pgrade1 << " *&grade1 = " << setw(10) << *&grade1 <<endl;
	cout << "addr  : &grade1 = " << setw(10) << &grade1 << " pgrade1 = " << setw(10) << pgrade1 << " &pgrade1 = " << setw(10) << &pgrade1 <<endl;
	cout << "value : grade2 = " << setw(10) << grade2 << " *pgrade2 = " << setw(10) << *pgrade2 << " *&grade2 = " << setw(10) << *&grade2 <<endl;
	cout << "addr  : &grade2 = " << setw(10) << &grade2 << " pgrade2 = " << setw(10) << pgrade2 << " &pgrade2 = " << setw(10) << &pgrade2 <<endl;
	cout << "value : grade3 = " << setw(10) << grade3 << " *pgrade3 = " << setw(10) << *pgrade3 << " *&grade3 = " << setw(10) << *&grade3 <<endl;
	cout << "addr  : &grade3 = " << setw(10) << &grade3 << " pgrade3 = " << setw(10) << pgrade3 << " &pgrade3 = " << setw(10) << &pgrade3 <<endl;

	cout << "top = " << *top << "(addr : " << top << ")" <<endl;

	return 0;
}
int* topgrade (int* px, int* py, int* pz)
{
	int* t;
	t = (*px > *py ? px : py);
	t = (*t > *pz ? t : pz);
	
	return t;
}