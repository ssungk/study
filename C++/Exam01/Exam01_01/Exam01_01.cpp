#include <iostream>
using namespace std;

int CountSetDifference(int a[],int b[],int a_size,int b_size);

int main()
{
	int alen,blen;
	int i,j;
	cout << "���� 1�� ������ ������ �Է��ϼ���. :";
	cin >> alen;
	cout << "���� 2�� ������ ������ �Է��ϼ���. :";
	cin >> blen;
	cout << endl;
	cout << "���� 1�� ���Ҹ� �Է��ϼ���. :";
	int* a=new int [alen];
	int* b=new int [blen];

	for(i=0; i<alen; i++)
	{
		cin>>a[i];
	}

	cout << "���� 2�� ���Ҹ� �Է��ϼ���. :";
	for(i=0; i<blen; i++)
	{
		cin>>b[i];
	}

	cout << endl << "������ ������ ���� :";
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