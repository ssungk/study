#include <iostream>
#include <iomanip>

using namespace std;

int** buildTable (void);
void fillTable (int** table);
void printTable (int** table);

int main()
{
	int** table = buildTable();

	fillTable (table);
	printTable (table);

	return 0;
}

int** buildTable()
{

	int rowNum =3;

	int** table;
	table = new int* [rowNum + 1];

	int row;
	for (row = 0; row < rowNum; row++)
	{
		int colNum;
		cout << "Size of column in row" << row+1 <<": ";
		cin >> colNum;
		table[row] = new int [colNum+1];
		table[row][0] = colNum;
	}

	table[row] = NULL;
	return table;
}

void fillTable (int** table)
{

	int row = 0;
	cout << " For each row enter a number " << endl;
	while (table[row] != NULL)
	{
		
		cout << " row  "<< row+1 <<"  (" << table[row][0] << " integers) =========> ";
		for (int column = 1; column <= table[row][0]; column++)
			cin >> table[row][column];
		row++;
	}
	return;
}

void printTable(int ** table)
{
	int row = 0;

	cout << "\n Print Array => " << endl;
	while( *(table+row) != NULL )
	{
		for( int column=1; column <= **(table+row); column++ )
			cout << setw(10) << *(*(table+row)+column) ;
		cout << endl;
		row++;
	}	
}