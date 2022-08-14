#define MAX(x, y) (((x) > (y))? (x) : (y)) //��ũ�� �Լ�
#include <iostream>
using namespace std;


template <class TYPE>
TYPE MAX_TPL(TYPE x,TYPE y)
{
	return ((x) > (y))? (x) : (y);
}
//(�ڵ��ۼ�) ��ũ�� �Լ�MAX�� ������ ������ �����ϴ� ���ø� �Լ�MAX_TPL�� �ۼ��Ͻÿ�.
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
//	cout << "Test6 : " << MAX_TPL(4, 'C' ) << endl; /*�������� Ȯ���ϰ� �� ������ �����غ��ÿ�*/
	cout << "Test3�� Test6�� ���� ���� ��ũ�� �Լ��� ������ �������� �����Ͻÿ�" << endl;
	cout << "��ũ�� �Լ��� ���ڿ� ������ ���� �ٸ��� ������� ���ϰ� template�� ���� ���� �ٸ��� ������־� ������ ���ϴ�." << endl;
	cout << "End of Template tests\n";
}