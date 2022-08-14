#include <iostream>
#include <iomanip>

using namespace std;

int*** buildTable();
void filltable(int***);
void processtable(int***);
void sorttable(int***);

int rowminimum(int*);
int smaller(int, int);
int rowmaximum(int*);
int larger(int, int);
float rowaverage(int*);

int main()
{
	int*** grade = buildTable();

	filltable(grade);

	processtable(grade);

	sorttable(grade);

	return 0;
}

int*** buildTable()
{
	int*** grade = new int** [2];

	
	
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

		toeicgrade[i] = new int [toeicnum+2];
		toeicgrade[i][0] = toeicnum+1;
		toeicgrade[i][1] = i+1;
	}

	toeicgrade[i] = NULL;

	int** statisticsgrade = new int* [studentnum+1];
	
	for(i=0;i < studentnum;i++)
	{
	statisticsgrade[i] = new int [4];
	statisticsgrade[i][0] = i+1;
	}
	grade[0]=toeicgrade;
	grade[1]=statisticsgrade;
	
	cout << endl;

	return grade;
}

void filltable (int*** grade)
{
	int j = 0;
	cout << "각 시험의 점수를 입력해주세요 " << endl;

	for(;grade[0][j] != NULL;j++)
	{
		cout << j+1 <<"번째 학생의 점수를 입력해주세요(" << grade[0][j][0]-1 << "번 응시) : ";

		int k;
		for(k=2;k-2 < grade[0][j][0]-1;k++)
		{
			cin >> grade[0][j][k];
		}
	}
	cout << endl;

	return;
}

void processtable(int*** grade)
{
	int row;
	for(row=0;grade[0][row] != NULL;row++)
	{
		grade[1][row][1] = rowminimum(grade[0][row]);
		grade[1][row][2] = rowmaximum(grade[0][row]);
		grade[1][row][3] = rowaverage(grade[0][row]);
	}	
			
	cout <<  setw(8) << "toeicGrade출력"<< endl;
	cout << setw(8) << "배열길이";
	cout << setw(8) << "학생ID";
	cout << setw(8) << "점수"<< endl;
		
	int i;
	for(i=0;*(*(grade)+i) != NULL;i++)
	{
		for(int j=0; j <= **(*(grade)+i); j++ )
		{
		cout << setw(8) << *(*(*(grade)+i)+j);
		}
		cout << endl;
	}	
	cout << endl;
	cout << setw(8) << "statisticsGrade 출력"<< endl;
	cout << setw(8) << "학생ID";
	cout << setw(8) << "최저점";
	cout << setw(8) << "최고점";
	cout << setw(8) << "평균" << endl;

	for(i=0;*(*(grade)+i) != NULL;i++)
	{
		cout << setw(8) << *(*(*(grade+1)+i)+0);
		cout << setw(8) << *(*(*(grade+1)+i)+1);
		cout << setw(8) << *(*(*(grade+1)+i)+2);
		cout << setw(8) << *(*(*(grade+1)+i)+3);
		cout << endl;
	}	

	return;
}

int rowminimum(int* rowptr)
{
	int rowmin =INT_MAX;
	for(int column=1;column <= *(rowptr)-1;column++)
	{
		rowmin = smaller(rowmin, rowptr[column+1]);
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
	for(int column=1;column <= *(rowptr)-1;column++)
	{
		rowmax = larger(rowmax, rowptr[column+1]);
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
	for(int column=1;column <= *rowptr-1;column++)
	{
		total = *(rowptr + (column+1)) + total;
	}
	float rowave;
	rowave = total/ ((*rowptr)-1);
	return rowave;
}



void sorttable(int*** grade)
{
	int k;
	int j;
	int* temp;
	for(k=0;*(*(grade)+k) != NULL;k++)
	{
		for(j=0;*(*(grade)+j) != NULL;j++)
		{
			if(grade[1][k][3] > grade[1][j][3])
			{
				temp = grade[1][k];
				grade[1][k] = grade[1][j];
				grade[1][j] = temp;
			}

		}
	}
	
	cout << endl;
	cout << setw(8) << "정렬 후 statisticsGrade 출력"<< endl;
	cout << setw(8) << "학생ID";
	cout << setw(8) << "최저점";
	cout << setw(8) << "최고점";
	cout << setw(8) << "평균" << endl;

	int i;
	for(i=0;*(*(grade)+i) != NULL;i++)
	{
		cout << setw(8) << *(*(*(grade+1)+i)+0);
		cout << setw(8) << *(*(*(grade+1)+i)+1);
		cout << setw(8) << *(*(*(grade+1)+i)+2);
		cout << setw(8) << *(*(*(grade+1)+i)+3);
		cout << endl;
	}
	return;
}