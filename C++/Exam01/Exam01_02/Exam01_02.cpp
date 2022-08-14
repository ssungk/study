#include <iostream>
using namespace std;

int * findMiddle( int * a, int * b, int * c ) ;

int main( void ) 
{
	int * pMiddle ;

	int a = 3 ;
	int b = 5 ; 
	int c = 1 ;

	pMiddle = findMiddle( &a, &b, &c ) ;

	cout << "�� ���� �� �߰� ���� " << *pMiddle << "�Դϴ�." << endl ;

	return 0 ; 
}

int * findMiddle( int * a, int * b, int * c )
{
	int * p = NULL ;
	if( ( *a > *b && *b > *c ) || ( *c > *b && *b > *a ) )
	{
		p = b ;
	}
	else if( ( *b > *a && *a > *c ) || ( *c > *a && *a > *b ) )
	{
		p = a ;
	}
	else
	{
		p = c ;
	}

	return p ;
}