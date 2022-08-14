#include <iostream>
using namespace std;

#include "Calculator.h"

/* 기본생성자로써 멤버 변수들을 초기화함 */
Calculator::Calculator(void)
{
	/* 시험 문제로써 이 부분을 작성함 */

	m_num1 = 0.0;
	m_num2 = 0.0;
	m_result = 0.0;
}

/* 덧셈 연산을 위한 메소드 */
void Calculator::add (float num1, float num2)
{
	/* 시험 문제로써 이 부분을 작성함 */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 + num2;	
}

/* 뺄셈 연산을 위한 메소드 */
void Calculator::substract (float num1, float num2)
{
	/* 시험 문제로써 이 부분을 작성함 */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 - num2;	
}

/* 곱셈 연산을 위한 메소드 */
void Calculator::multiply (float num1, float num2)
{
	/* 시험 문제로써 이 부분을 작성함 */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 * num2;	
}

/* 나눗셈 연산을 위한 메소드 */
void Calculator::divide (float num1, float num2)
{
	/* 시험 문제로써 이 부분을 작성함 */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 / num2;	
}

/* 입력된 연산기호가 적절한지(+, -, *, /) 검출 */
bool Calculator::operValidator(char oper)
{	
	/* 시험 문제로써 이 부분을 작성함 */

	if( (oper == '+') || (oper == '-') || (oper == '*') || (oper == '/') )
	{
		return true;
	}
	else
	{
		cout << "ERROR! 연산 기호가 잘못 입력되었습니다!" << endl;
		return false;
	}
}

/* 입력된 수가 나누기 연산에 적합한지(0으로 나누기 불가) 검출 */
bool Calculator::divValidator(float num2, char oper)
{
	/* 시험 문제로써 이 부분을 작성함 */
	
	m_num2 = num2;
	if( (oper == '/') && (m_num2 == 0) )
	{
		cout << "ERROR! 0으로 나누는 연산은 불가능합니다!" << endl ; 
		return false;
	}
	else
	{
		return true;
	}	
}

/* 연산자를 비교하여 연산자에 해당하는 메소드를 호출하여 연산결과값 출력 */
void Calculator::operation(float num1, float num2, char oper)
{
	/* 시험 문제로써 이 부분을 작성함 */

	switch(oper)
	{
	case '+':
		add(num1, num2);		
		break;
	case '-':
		substract(num1, num2);
		break;
	case '*':
		multiply(num1, num2);
		break;
	case '/':
		divide(num1, num2);
		break;
	default:
		break;
	}
}

void Calculator::printResult(void)
{
	cout << m_result << endl;
}