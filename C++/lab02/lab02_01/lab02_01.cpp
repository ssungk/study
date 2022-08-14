#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ary[5] = {10, 20, 30, 40, 50}; // �迭�� ����� �ʱ�ȭ
	cout << setw(15) << "Print Element";

	for( int i=0; i<5; i++ )
	{
	cout << setw(10) << ary[i]; // �迭�� ���� ���(�迭 ÷�� ������)
	}
	cout << endl;

	cout << setw(15) << "Address of Element";
	for( int i=0; i<5; i++ )
	{
	cout << setw(10) << &ary[i] ; // �迭�� ���� �ּ� ���(�迭 ÷�� ������, �ּ� ������)
	}
	cout << endl;

	cout << setw(15) << "Size of Memory";
	for( int i=0; i<5; i++ )
	{
		cout << setw(10) << sizeof(ary[i]); // �迭 �� ������ �޸� ������ ���(sizeof() �Լ�
	}
	cout << endl;

	char *answer = "�ּ� ������ ũ��� 4�̰� �ּҿ��� ���ݶ��� 4�� �����ϴ�.";
	cout << answer << endl;
	return 0;
}