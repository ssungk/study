#include <iostream>
#include <iomanip>
using namespace std;

void multiply (int* pAry, int size);

void checkSize(int* pAry, int Ary[], int size);

int main()
{
	int Ary [5] = {10, 20, 30, 40,50};
	int* pAry = Ary;
	int arySize = sizeof(Ary)/sizeof(Ary[0]);

	multiply (Ary, arySize);

	int j;
	for(j=0;j<arySize;j++)
	{
		cout << setw(4) << Ary[j] <<" ";
	}

	cout << endl;

	checkSize(pAry, Ary, arySize);
	cout << setw(35) << "main() : sizeof(�迭�� Ary) = "<< sizeof(Ary) << endl;

	char* answer = "main �Լ������� Ary�� �迭 ��ü���� �迭�� ũ�� 20�̰� checkSize Ary�� Ary�� �ּҰ��� �޾ƿ°��̹Ƿ� ũ��� 4";
	cout << answer << endl;

	return 0;
}

void multiply (int* pAry, int size)
{
	int *pLast = pAry + size -1;
	for (int* pWalk = pAry; pWalk <= pLast; pWalk++)
		*pWalk = *pWalk * 2;
	return;
}

void checkSize(int* pAry, int* Ary, int size)
{
	cout << "checkSize() : sizeof(������ pAry) = " << sizeof(pAry) << endl;
	cout << "checkSize() : sizeof(�迭�� Ary) = " << sizeof(Ary) << endl;
	return;
}