#include <iostream>
#include <math.h>
using namespace std;

// �Ҽ� �׽�Ʈ
int main()
{
	bool isPrime = true;
	for(int i=2; i<50; i++)
	{
		for(int j=2; j<sqrt((double)i)+1; j++)
		{
			if( i == 2 & j == 2)
				continue;
			if( i % j == 0 )
			{
				isPrime = false;
				break;
			}
		}
		if(isPrime == true)
			cout << i << "�� �Ҽ��Դϴ�." <<endl;
		else
			cout << i << "�� �Ҽ��� �ƴմϴ�." <<endl;

		isPrime= true;
	}
	
	return 0;

}