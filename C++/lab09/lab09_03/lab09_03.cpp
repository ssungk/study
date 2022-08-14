#define MAX(x, y) (((x) > (y))? (x) : (y)) //매크로 함수
#include <iostream>
using namespace std;


template <class TYPE>
TYPE MAX_TPL(TYPE x,TYPE y)
{
	return ((x) > (y))? (x) : (y);
}
//(코드작성) 매크로 함수MAX와 동일한 동작을 수행하는 템플릿 함수MAX_TPL을 작성하시오.
void main()
{
	cout << "Begin macro tests\n";
	cout << "Test1 : " << MAX(1,4) << endl;
	cout << "Test2 : " << MAX('A', 'B') << endl;
	cout << "Test3 : " << MAX(4, 'C' ) << endl;
	cout << "End of macro tests\n";
	cout << "Begin Template tests\n";
	cout << "Test4 : " << MAX_TPL(1,4) << endl;
	cout << "Test5 : " << MAX_TPL('A', 'B') << endl;
//	cout << "Test6 : " << MAX_TPL(4, 'C' ) << endl; /*에러문을 확인하고 그 이유를 생각해보시오*/
	cout << "Test3과 Test6의 예를 통해 매크로 함수가 가지는 문제점을 설명하시오" << endl;
	cout << "매크로 함수는 숫자와 문자의 서로 다름이 고려하지 못하고 template를 쓰면 둘이 다른걸 고려해주어 에러가 납니다." << endl;
	cout << "End of Template tests\n";
}