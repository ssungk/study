#include <iostream>
using namespace std;

void MaxArray(int **pArr, int row, int col, int *result);

void main()
{
	int ** pArr;
	int row, col;
	int resultArray[3];

	cout << "만들고자 하는 2차원 배열의 행과 열의 개수 입력 : ";
	cin >> row >> col;

	pArr = new int*[row]; // 행의 갯수만큼 동적할당

	int i, j;
	for(i = 0; i < row; i++)
		pArr[i] = new int[col]; // 각행을 열의 갯수만큼 동적할당

	for(i = 0; i < row; i++)
	{
		cout << i << "행의 배열 요소 " << col << "개를 입력하시오: ";
		for(j = 0; j < col; j++)
			cin >>  pArr[i][j]; // 행렬의 요소를 입력
	}
	MaxArray(pArr, row, col, resultArray);
	cout <<"\n";
	cout << "2차원 배열의 최대값은 " << resultArray[0] <<endl;
	cout << "최대값의 위치는 " <<resultArray[1] << ", "<< resultArray[2] <<endl;

	// 할당한 만큼 메모리해제
	for(i = 0; i < row; i++) 
		delete [] pArr[i];

	delete []pArr; 
}


void MaxArray(int **pArr, int _row, int _col, int *result)
{
	int i,j=0;
	int max=0;
	int row, col = 0;
	for(i=0; i<_row; i++)
	{
		for(j=0; j<_col; j++)
		{
			if(max < pArr[i][j])
			{
				max = pArr[i][j];
				row = i;
				col = j;
			}
		}
	}

	result[0] = max;
	result[1] = row;
	result[2] = col;

	return;
}