#include <iostream>
using namespace std;

void MaxArray(int **pArr, int row, int col, int *result);

void main()
{
	int ** pArr;
	int row, col;
	int resultArray[3];

	cout << "������� �ϴ� 2���� �迭�� ��� ���� ���� �Է� : ";
	cin >> row >> col;

	pArr = new int*[row]; // ���� ������ŭ �����Ҵ�

	int i, j;
	for(i = 0; i < row; i++)
		pArr[i] = new int[col]; // ������ ���� ������ŭ �����Ҵ�

	for(i = 0; i < row; i++)
	{
		cout << i << "���� �迭 ��� " << col << "���� �Է��Ͻÿ�: ";
		for(j = 0; j < col; j++)
			cin >>  pArr[i][j]; // ����� ��Ҹ� �Է�
	}
	MaxArray(pArr, row, col, resultArray);
	cout <<"\n";
	cout << "2���� �迭�� �ִ밪�� " << resultArray[0] <<endl;
	cout << "�ִ밪�� ��ġ�� " <<resultArray[1] << ", "<< resultArray[2] <<endl;

	// �Ҵ��� ��ŭ �޸�����
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