#include "StdAfx.h"
#include "Card.h"


CCard::CCard(void)
{
	//�⺻ �����ڴ� 0���� �ʱ�ȭ
	m_CardNum = 0;
	m_Num = 0;
}


CCard::~CCard(void)
{
}


CCard::CCard(int CardNum, int Num)
{
	//ī���ȣ�� ī���� ���� �Ķ���ͷ� �޴� ������
	m_CardNum = CardNum;
	m_Num = Num;
}

//ī���� �����͸� �����ϰ� �ҷ����� �Լ�
void CCard::Serialize(CArchive& ar)  
{
	if (ar.IsStoring())//���� �ڵ�
	{
		ar<<m_CardNum<<m_Num;
	}
	else//�ε� �ڵ�
	{
		ar>>m_CardNum>>m_Num;
	}
}