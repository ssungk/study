#include <iostream>
using namespace std;

struct sBox
{
	int key;
	int age;
	float salary;
};

template <class TYPE, class KEY>
int search (TYPE arr[], KEY key, int size)
{
	int index = 0;
	while ( index < size )
	{
		if ( key != arr[index].key )
			index++;
		else
			return index;
	}
	return -1;
}
void main()
{
	sBox arr[3] = { {5, 32, 3.23f}, {2, 48, 5.18f}, {7, 60, 6.01f} };
	cout << "Key : " << arr[search(arr,2,sizeof(arr)/sizeof(arr[0]))].key << endl;
	cout << "age : " << arr[search(arr,2,sizeof(arr)/sizeof(arr[0]))].age << endl;
	cout << "Salary : " << arr[search(arr,2,sizeof(arr)/sizeof(arr[0]))].salary << endl;
	cout << "found at loaction : " << search(arr,2,sizeof(arr)/sizeof(arr[0])) << endl;
	//(�ڵ� �ۼ�) �׽�Ʈ ���α׷�
}