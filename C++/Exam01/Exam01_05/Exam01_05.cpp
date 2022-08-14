#include <iostream>
using namespace std;

#include "Calculator.h"

int main()
{
	float inputNum1 = 0.0;
	float inputNum2 = 0.0;
	char inputOper = '0';
	Calculator cal;

	cout << "$$ ������ ����� ���� ���α׷�(����: 0�� �Է�) $$" << endl;	

	while(1)
	{
		cout << endl << "���� ��ȣ�� �Է��ϼ���(+,-,*,/,O) : ";
		cin >> inputOper;

		/* ���� ��ȣ�� 0�� ������ �����ϴ� �ڵ� �߰� */
		if( inputOper == '0') break;

		/* ���� ��ȣ�� ����� �ԷµǾ����� ���� */
		if( cal.operValidator(inputOper) == true )
		{
			/* ����� �ԷµǾ��� �� ��� ���� */
			cout << "ù��° ���� �Է��ϼ��� : ";
			cin >> inputNum1;
			cout << "�ι�° ���� �Է��ϼ��� : ";
			cin >> inputNum2;				
			
			/* ������ ������ �������� ���� */
			if( cal.divValidator(inputNum2, inputOper) == true )
			{
				/* ������ ������ ������ ����� �־��� ������ ���� */
				cout << "����� : ";

				/* ������ �����ϴ� �޼ҵ� ȣ�� */
				cal.operation(inputNum1, inputNum2, inputOper);

				/* ���� ����� ����ϴ� �޼ҵ� ȣ�� */
				cal.printResult();
			}
		
			/* �Է°��� ��ȣ�� ������ �ϸ� �ٽ� �Է� ���� */
			else
			{ 
				// �ƹ� �۾��� ���� ����
			}			
		}		
		/* �Է°��� ��ȣ�� ������ �ϸ� �ٽ� �Է� ���� */
		else
		{ 
			// �ƹ� �۾��� ���� ����
		}	
	};
	
	return 0;
};