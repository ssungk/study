#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int dsize;

	cout << "Enter a size of the array : ";
	cin >> dsize;
	
	int* dary = new int [dsize]; // (�ڵ� �ۼ�) ���� �迭 �Ҵ�
	
	cout << "Enter a number each Element : ";

	int i;
	int j;

	for(i=0;i<dsize;i++)
	{
		cin >> j;
		*(dary+i) = j;
	}// (�ڵ� �ۼ�) �迭 ä���(������ ���� ������ Ȱ��)
	

	for(i=0;i<dsize;i++)
	{
		cout << dary[i] << "  ";
	}// (�ڵ� �ۼ�) �迭 ����ϱ�(�����Ϳ� �迭 ÷�� ������ Ȱ��)

	cout << endl;
	
		
	delete[] dary; // (�ڵ� �ۼ�) ���� �迭 �޸� ����
	
	return 0;
}

