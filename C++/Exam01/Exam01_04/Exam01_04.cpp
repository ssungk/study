#include <iostream>
#include "Employee.h";
using namespace std;

int main()
{
	/* �� ���� ���(employee) �ν��Ͻ��� ������ */
	Employee emp1, emp2; 

	/* ������ �ν��Ͻ��� ��� ����(�̸�, ���, ���޿���)�� �Է��Ͽ� �ʱ�ȭ�� */
	emp1.initialize("���缮", 33170, 5000000);
	emp2.initialize("�ڸ��", 31092, 1000000);

	/* ù��° ����� ������ ����� */
	cout << "[ù° ��� ����]" << endl;
	emp1.show_data();	

	/* �ι�° ����� ������ ����� */
	cout << "[��° ��� ����]" << endl;
	emp2.show_data();	

	return 0;
}