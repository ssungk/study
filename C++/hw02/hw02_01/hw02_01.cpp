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
	cout << "�л��� ���� �Է��ϼ��� ";
	cin >> studentnum;
	cout << endl;
		
	int** toeicgrade = new int* [studentnum + 1];

	int i;
	for (i=0;i < studentnum;i++)
	{
		int toeicnum;
		cout << i+1 << "��° �л��� �������� Ƚ�� : ";
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
	cout << "�� ������ ������ �Է����ּ��� " << endl;

	for(;toeicgrade[j] != NULL;j++)
	{
		cout << j+1 <<"��° �л��� ������ �Է����ּ���(" << toeicgrade[j][0]-4 << "�� ����) : ";

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
	
	cout << setw(8) << "�迭����";
	cout << setw(8) << "�л�ID";
	cout << setw(8) << "������";
	cout << setw(8) << "�ְ���";
	cout << setw(8) << "���";
	cout << setw(8) << "����"<< endl;
	
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