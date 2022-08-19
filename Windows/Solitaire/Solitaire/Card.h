#pragma once
#include "afx.h"
class CCard 
{
public:
	CCard(void);					//�⺻������
	virtual ~CCard(void);			//�Ҹ���
	CCard(int CardNum, int Num);	//ī�������ȣ,ī���� ��(1~13)�� �Ķ���ͷ� �޴� ������
	void Serialize(CArchive& ar);  	//ī���� �����͸� �����ϰ� �ҷ����� �Լ�
public:
	int m_CardNum;					//ī�� ������ȣ
	int m_Num;						//ī���� ��(1~13)
public:
	//find�Լ��� ����ϱ� ���� friend bool operator == ����
	friend bool operator == (const CCard& leftcard, const CCard& rightcard)
	{
		return (leftcard.m_CardNum==rightcard.m_CardNum)&&(leftcard.m_Num==rightcard.m_Num);
	}
	
};
