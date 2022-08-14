#include <iostream> 
#include <exception> 
using namespace std; 
void myunexpected ()
{ 
	cerr << "myunexpected called\n";
	throw 0; 
	// throws int (in exception-specification)
} 
void myunexpected2 () 
{
	cerr << "myunexpected2 called\n";
	exit(100); 
	// exit the program 
}
void myfunction ()throw (int) 
{ 
	throw 'x';// throws char (not in exception-specification)
} 
int main (void)
{ 
	// 주의: MSVC는 C++의 exception specification을 표준대로 구현하지 않아 textbook의 설명대로 동작하지 않음
	set_unexpected( myunexpected ); // &myunexpected can also be used instead of myunexpected
	try 
	{ 
		myfunction();
	} 
	catch (int)
	{ 
		cerr << "caught int\n";
	} 
	catch (...) 
	{ 
		cerr << "caught other exception (non-compliant compiler?)\n";
	}
	unexpected_handler oldHand = set_unexpected( myunexpected2 ); // &myunexpected can also be used 
	cout << "oldHand: " << oldHand << " myunexpected: " << myunexpected << " &myunexpected: " << &myunexpected << endl;
	return 0;
}