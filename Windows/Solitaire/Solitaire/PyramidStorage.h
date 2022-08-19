#pragma once
#include "Card.h"
#include "afx.h"
class CPyramidStorage :	public CObject
{
protected:
	CCard** m_pointer;				//�Ƕ�̵��� �迭�� �������� ��������� CCard** ����
	int row,col;					//���� ����� ��ġ�� �ľ��ϱ����� ����
public:
	CPyramidStorage(void);										//�⺻������
	virtual ~CPyramidStorage(void);								//�Ҹ���
	void Push(CCard card);										//�����Լ�
	void Draw(CDC* pDC,CList<CCard,CCard&>& List);				//Draw�Լ�
	void MouseClick(CPoint point,CList<CCard,CCard&>& List);	//���콺Ŭ��ó�� �Լ�
	void RemoveChoiceCard(CList<CCard,CCard&>& List);			//���õ�ī�带 �����ϴ� �Լ�
	void RemoveAll();											//�Ƕ�̵彺�丮���� ���� �Լ�
	void Serialize(CArchive& ar);                               //�Ƕ�̵��� �����͸� �����ϰ� �ҷ����� �Լ�
};