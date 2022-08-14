#include <iostream>
using namespace std;

template <class TYPE>
class smartAry
{
private:
	TYPE* m_ptr; //(�ڵ� �ۼ�) �������� �Ҵ� ���� �迭�� ������ �� �ִ� TYPE�� ������ ����(m_ptr)
	int arySize;//(�ڵ� �ۼ�) �迭 ������(arySize)
public:
	smartAry(int size); //������
	~smartAry(); //�Ҹ���
	TYPE& operator[] (int idx ); //[]������ �����ε�
	int GetSize()
	{
		return (sizeof(m_ptr)/sizeof(m_ptr[0]));//(�ڵ��ۼ�) 
	}//�迭 ���� ��ȯ
};

template <class TYPE>
smartAry<TYPE>::smartAry(int size)
{ 
	arySize = size;
	m_ptr = new TYPE [size];//(�ڵ��ۼ�) size ��ŭ�� TYPE�� ���� �迭 �Ҵ� �� ��� ���� �ʱ�ȭ }
}

template <class TYPE>
smartAry<TYPE>::~smartAry()
{	
	delete[] m_ptr;//(�ڵ� �ۼ�) �Ҹ��� - ��� ������ �Ҵ�� �޸� ����
}

template <class TYPE>
TYPE& smartAry<TYPE>::operator[] (int idx )
{
	return m_ptr[idx];//(�ڵ� �ۼ�) []������ �����ε� - �Ű������� �Է� ���� �ε����� TYPE& ��ȯ
}

void main()
{
	smartAry<int> arr1(4);
	arr1[0] = 1; arr1[1] = 4;
	int i;
	for(i=0;i<4;i++)
	{
		cout << arr1[i] << endl;
	}//(�ڵ� �ۼ�) for���� �̿��� arr1�� ��� �ڵ� �ۼ�
	
	smartAry<double> arr2(4);//(�ڵ� �ۼ�) ���� �Ҵ�� double�� �迭�� �����ϴ� smartAry ��ü(arr2) ����
	arr2[0] = 5.5; arr2[3] = 3.14;
	for(i=0;i<4;i++)
	{
		cout << arr2[i] << endl;
	}//(�ڵ� �ۼ�) for���� �̿��� arr2�� ��� �ڵ� �ۼ�
}