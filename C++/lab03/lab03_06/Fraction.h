#include <iostream>
using namespace std;

class SmartPhone
{
	private:
		char m_strName[20];
		int m_nMemorySize;
	public:
		SmartPhone(void);
		SmartPhone(char* strName,int nMemorySize);
		void change(int nMemorySize);
		void changeOSName(char* strName);
		void store(char* strName,int nMemorySize);
		void print () const;
};



/*- ������ :
20����Ʈ ũ���� �ü�� �̸�
��ġ�� ǥ���� �޸� ũ��

- ������ (public) :
��쿡 ���� �����͸� �ʱ�ȭ �ϴ� �����ڸ� �� �� �ۼ� 
�⺻ ������ : �ü�� �̸��� ��� ����Ʈ�� �޸��� ũ�⸦ 0���� �ʱ�ȭ
�ü�� �̸��� �޸��� ũ�⸦ �Ű������� �Է� �޾� ��� ������ ����

- �޼ҵ�(public) :
�޸� ũ�⸦ �����ϴ� �޼ҵ� changeMemSize()
�ü�� �̸��� �����ϴ� �޼ҵ� changeOSName()
SmartPhone ������ ����ϴ� �޼ҵ� print()

�޼ҵ�(private) :
20����Ʈ ũ���� �ü�� �̸� ��� ����Ʈ�� 0���� �ʱ�ȭ �ϴ� �޼ҵ�
�Է� ���� �ü�� �̸��� ��� ������ ����.


private:
		int m_nNumerator;// ����
		int m_nDenominator;// �и�
	public:
		CFraction ( void );
		CFraction (int nNumer);
		CFraction (int nNumer,int nDenom);
		CFraction (const CFraction&fr);
		~CFraction(void);
		void store(int nNumer,int nDenom);
		void print () const;

*/