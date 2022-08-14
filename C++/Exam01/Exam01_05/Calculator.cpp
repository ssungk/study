#include <iostream>
using namespace std;

#include "Calculator.h"

/* �⺻�����ڷν� ��� �������� �ʱ�ȭ�� */
Calculator::Calculator(void)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */

	m_num1 = 0.0;
	m_num2 = 0.0;
	m_result = 0.0;
}

/* ���� ������ ���� �޼ҵ� */
void Calculator::add (float num1, float num2)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 + num2;	
}

/* ���� ������ ���� �޼ҵ� */
void Calculator::substract (float num1, float num2)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 - num2;	
}

/* ���� ������ ���� �޼ҵ� */
void Calculator::multiply (float num1, float num2)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 * num2;	
}

/* ������ ������ ���� �޼ҵ� */
void Calculator::divide (float num1, float num2)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */

	m_num1 = num1;
	m_num2 = num2;
	m_result = num1 / num2;	
}

/* �Էµ� �����ȣ�� ��������(+, -, *, /) ���� */
bool Calculator::operValidator(char oper)
{	
	/* ���� �����ν� �� �κ��� �ۼ��� */

	if( (oper == '+') || (oper == '-') || (oper == '*') || (oper == '/') )
	{
		return true;
	}
	else
	{
		cout << "ERROR! ���� ��ȣ�� �߸� �ԷµǾ����ϴ�!" << endl;
		return false;
	}
}

/* �Էµ� ���� ������ ���꿡 ��������(0���� ������ �Ұ�) ���� */
bool Calculator::divValidator(float num2, char oper)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */
	
	m_num2 = num2;
	if( (oper == '/') && (m_num2 == 0) )
	{
		cout << "ERROR! 0���� ������ ������ �Ұ����մϴ�!" << endl ; 
		return false;
	}
	else
	{
		return true;
	}	
}

/* �����ڸ� ���Ͽ� �����ڿ� �ش��ϴ� �޼ҵ带 ȣ���Ͽ� �������� ��� */
void Calculator::operation(float num1, float num2, char oper)
{
	/* ���� �����ν� �� �κ��� �ۼ��� */

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