#include <iostream>
using namespace std;


template <class TYPE>
TYPE biggest (TYPE arr[], int arr_size)
{
	TYPE big = arr[0];
	int i;
	for(i=0;i<arr_size;i++)
	{
		if(arr[i]>big)
		{
			big = arr[i];
		}
	}
	return big;//(�ڵ� �ۼ�)�迭�� �迭 ����� �޾� �ִ밪�� ã�� �Լ� �ۼ�
}
void main()
{
	int ary1[4] = {10, 7, 11, 24};
	cout << "Biggest Value is " << biggest(ary1, 4) << endl;
	float ary2[4] = {3.5f, 1.12f, 3.14f, 0.25f};
	cout << "Biggest Value is " << biggest(ary2, 4) << endl;
}