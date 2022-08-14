#include <iostream>
#include <iomanip>

using namespace std;

int** buildTable();
void filltable(int**);
void processtable(int**);

int rowminimum(int*);
int smaller(int, int);
int rowmaximum(int*);
int larger(int, int);
float rowaverage(int*);

int main()
{
	int** toeicgrade = buildTable();

	filltable(toeicgrade);
	processtable(toeicgrade);

	return 0;
}

int** buildTable()
{

	int studentnum;
	cout << "학생의 수를 입력하세요 ";
	cin >> studentnum;
	cout << endl;
		
	int** toeicgrade = new int* [studentnum + 1];

	int i;
	for (i=0;i < studentnum;i++)
	{
		int toeicnum;
		cout << i+1 << "번째 학생의 토익응시 횟수 : ";
		cin >> toeicnum;

		toeicgrade[i] = new int [toeicnum+5];
		toeicgrade[i][0] = toeicnum+4;
		toeicgrade[i][1] = i+1;
	}

	toeicgrade[i] = NULL;

	cout << endl;

	return toeicgrade;
}

void filltable (int** toeicgrade)
{
	int j = 0;
	cout << "각 시험의 점수를 입력해주세요 " << endl;

	for(;toeicgrade[j] != NULL;j++)
	{
		cout << j+1 <<"번째 학생의 점수를 입력해주세요(" << toeicgrade[j][0]-4 << "번 응시) : ";

		int k;
		for(k=5;k-5 < toeicgrade[j][0]-4;k++)
		{
			cin >> toeicgrade[j][k];
		}
	}
	cout << endl;

	return;
}

void processtable(int** toeicgrade)
{
	
	int row = 0;
	
	for(;toeicgrade[row] != NULL;row++)
	{
		toeicgrade[row][2] = rowminimum(toeicgrade[row]);
		toeicgrade[row][3] = rowmaximum(toeicgrade[row]);
		toeicgrade[row][4] = (float)rowaverage(toeicgrade[row]);
	}	
	
	cout << setw(8) << "배열길이";
	cout << setw(8) << "학생ID";
	cout << setw(8) << "최저점";
	cout << setw(8) << "최고점";
	cout << setw(8) << "평균";
	cout << setw(8) << "점수"<< endl;
	
	int i;

	for(i=0;*(toeicgrade+i) != NULL;i++)
	{
		for(int j=0; j <= **(toeicgrade+i); j++ )
		{
		cout << setw(8) << *(*(toeicgrade+i)+j);
		}
		cout << endl;
	}	
	return;
}

int rowminimum(int* rowptr)
{
	int rowmin =INT_MAX;
	for(int column=1;column <= *(rowptr)-4;column++)
	{
		rowmin = smaller(rowmin, rowptr[column+4]);
	}
	return rowmin;
}

int smaller(int f, int s)
{
	return(f < s ? f:s);
}

int rowmaximum(int* rowptr)
{
	int rowmax =INT_MIN;
	for(int column=1;column <= *(rowptr)-4;column++)
	{
		rowmax = larger(rowmax, rowptr[column+4]);
	}
	return rowmax;
}

int larger(int f, int s)
{
	return(f > s ? f:s);
}

float rowaverage(int* rowptr)
{
	float total = 0;
	for(int column=1;column <= *rowptr-4;column++)
	{
		total = *(rowptr + (column+4)) + total;
	}
	float rowave;
	rowave = total/ (*rowptr-4);

	return rowave;
}