#include <iostream>
using namespace std;

#include "Calculator.h"

int main()
{
	float inputNum1 = 0.0;
	float inputNum2 = 0.0;
	char inputOper = '0';
	Calculator cal;

	cout << "$$ 누구나 만드는 계산기 프로그램(종료: 0을 입력) $$" << endl;	

	while(1)
	{
		cout << endl << "연산 기호를 입력하세요(+,-,*,/,O) : ";
		cin >> inputOper;

		/* 연산 기호로 0을 넣으면 종료하는 코드 추가 */
		if( inputOper == '0') break;

		/* 연산 기호가 제대로 입력되었는지 검출 */
		if( cal.operValidator(inputOper) == true )
		{
			/* 제대로 입력되었을 시 계속 진행 */
			cout << "첫번째 수를 입력하세요 : ";
			cin >> inputNum1;
			cout << "두번째 수를 입력하세요 : ";
			cin >> inputNum2;				
			
			/* 나누기 연산이 가능한지 검출 */
			if( cal.divValidator(inputNum2, inputOper) == true )
			{
				/* 나누기 연산이 가능한 경우라면 주어진 연산을 수행 */
				cout << "계산결과 : ";

				/* 연산을 수행하는 메소드 호출 */
				cal.operation(inputNum1, inputNum2, inputOper);

				/* 연산 결과를 출력하는 메소드 호출 */
				cal.printResult();
			}
		
			/* 입력값과 기호가 부적절 하면 다시 입력 받음 */
			else
			{ 
				// 아무 작업도 하지 않음
			}			
		}		
		/* 입력값과 기호가 부적절 하면 다시 입력 받음 */
		else
		{ 
			// 아무 작업도 하지 않음
		}	
	};
	
	return 0;
};