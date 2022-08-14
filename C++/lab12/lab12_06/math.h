#include "Error.h"

double math(char oper, double data1, double data2)
{
	double result;
	switch(oper)
	{
	case '+':
		result = data1 + data2;
		break;
	case '-':
		result = data1 - data2;
		break;
	case '*':
		result = data1 * data2;
		break;
	case '/':
		if(data2 == 0)
			throw DivbyZero();
		if(data2 < 0)
			throw DivbyNeg();
		result = data1 / data2;
		break;
	default:
		throw BadOperator();
			break;
	}
	return result;
}