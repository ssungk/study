class Employee
{

/* ��� ������ ������ */
private:		
	char* empName;		// ����� �̸��� �ޱ� ���� ����
	int empNumber;		// ����� ��ȣ�� �ޱ� ���� ����
	int empSalary;		// ����� �� �޿����� �ޱ� ���� ����

/* ��� �޼ҵ带 ������ */
public:
	void initialize(char* name, int number, int salary);	// ��� ������ �ʱ�ȭ �ϴ� �޼ҵ�
	void show_data();										// ��� ������ ����ϴ� �޼ҵ�
	void copy_name(char* name, int name_space);				// ��� �̸��� �Է¹޾� name ������ �ִ� �޼ҵ�

};