#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	int norigarr[50];
	int* ptagarr[50];
	
	srand(time(NULL));

	int q;

	for(q=0;q<50;q++)
	{
		ptagarr[q] = &norigarr[q];
	}

	int i;
	int j;
	
	
	for(i=0;i<50;i++)
	{
		norigarr[i]=(rand()%100+1);
			for(j=0;j<i;j++)
		{
			if(norigarr[j]==norigarr[i])
			{
				i--;
				break;
			}
		}
	}

	int z;
	
	for(z=0;z<50;z++)
	{
		cout << "["<< z << "]" << "(norigarr[" << z << "] 주소, " << norigarr[z] << ")" << endl;
	}

	int* temp;

	for(i=0;i<50;i++)
	{
		for(j=i;j<50;j++)
		{
			 if(*ptagarr[i] > *ptagarr[j])
			 {
				 temp = ptagarr[i];
				 ptagarr[i] = ptagarr[j];
				 ptagarr[j] = temp;
			 }
		}
	}

	for(z=0;z<50;z++)
	{
		cout << "["<< z << "]" << "(ptagarr[" << z << "] 값, " << *ptagarr[z] << ")" << endl;
	}

	
	int s;
	int f;
	int r;
	int k;
	

	cout << "1~100사이의 숫자 입력(0입력시 종료)" << endl; 
		
	for(;;)
	{
		cin >> s;

		if( s == 0 )
			break ;
		
		for(f=0,r=49,k=0;;k++)
		{
						
			if( s == *ptagarr[(f+r)/2])
			{
				cout << "값 존재 " << endl;
				cout << "ptagarr[" << (f+r)/2 << "] : " << *ptagarr[(f+r)/2] << endl;
				cout << "norigarr[" << (ptagarr[(f+r)/2] - &norigarr[0]) <<"] : " << *ptagarr[(f+r)/2] << endl;

				break;
			}
			if( *ptagarr[(f+r)/2] < s )
			{
				f = ((f+r)/2)+1;
			}
			else
			{
				r = ((f+r)/2)-1;
			}
			if(k>=5)
			{
				cout << "값 없음" << endl;
				break;
			}

						
		}
				
	}
	return 0;
}