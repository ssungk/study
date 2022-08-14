#include <iostream>
#include <math.h>
using namespace std;

// 소수 테스트
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
			cout << i << "는 소수입니다." <<endl;
		else
			cout << i << "는 소수가 아닙니다." <<endl;

		isPrime= true;
	}
	
	return 0;

}