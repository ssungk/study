#include <iostream> 
#include <new>
using namespace std ;
int main()
{
	cout << "Demonstrate memory allocation failure\n" ;
	try
	{ 
		for( int count = 0 ; ; count++ )
		{
			double * Arr = new double[1024*1024*10] ;
			cout << "count "<< count << "Memory allocated successfully\n" ;
		}
	} 
	catch( exception & err )
	{
		cout << "** Enter 100 : Program out of memory\n **" << err.what() << endl ;
	} 
	cout << "End of exceptions tests\n" ; 
	return 0 ;
}