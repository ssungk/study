#include <iostream>
using namespace std;

int main()
{
	int nCount = 5;

	int ** pp;
	int row, col;

	pp = new int *[nCount];

	for( row = 0 ; row < nCount ; row++ )
	{
		*(pp+row) = new int[nCount - row]; // notice: *(pp+row) <==> pp[row]
	}

	for( row = 0 ; row < nCount ; row++ )
	{
		for( col = 0 ; col < nCount - row ; col++ )
		{
			*(*(pp+row) + col) = col; 
			// notice: *(*(pp+row) + col) <==> *(pp[row] + col) <==> (pp[row])[col] <==> pp[row][col]
		}
	}

	for( row = 0 ; row < nCount ; row++ )
	{
		for( col = 0 ; col < nCount - row ; col++ )
		{
			cout << pp[row][col] << " " ;
		}
		cout << endl ;
	}

	return 0 ;
}