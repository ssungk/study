#include <iostream>
using namespace std;

int CountSetDifference(int a[],int b[],int a_size,int b_size);

int main()
{
	int alen,blen;
	int i,j;
	cout << "집합 1의 원소의 개수를 입력하세요. :";
	cin >> alen;
	cout << "집합 2의 원소의 개수를 입력하세요. :";
	cin >> blen;
	cout << endl;
	cout << "집합 1의 원소를 입력하세요. :";
	int* a=new int [alen];
	int* b=new int [blen];

	for(i=0; i<alen; i++)
	{
		cin>>a[i];
	}

	cout << "집합 2의 원소를 입력하세요. :";
	for(i=0; i<blen; i++)
	{
		cin>>b[i];
	}

	cout << endl << "차집합 원소의 개수 :";
	cout << CountSetDifference(a,b,alen,blen) << endl;


	delete [] a;
	delete [] b;

	return 0;
}

int CountSetDifference(int a[],int b[],int a_size,int b_size)
{
	int diff= a_size;
	for(int i=0; i<a_size; i++)
	{
		for(int j=0; j<b_size; j++)
		{
			if(a[i]==b[j])
				diff--;	
		}
	
	}
	return diff;
}