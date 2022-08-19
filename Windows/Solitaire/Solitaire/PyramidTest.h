#include "DlgSetOption.h"
#include "Card.h"
#include "CardGame.h"
#include "PyramidStorage.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>
#pragma once
//�Ƕ�̵� ī������� �׽�Ʈ Ŭ������ �߻�Ŭ������ CCardGameŬ������ ��ӹ޴´�.
class CPyramidTest : public CCardGame
{
public:
	CPyramidTest(void);				    	//�⺻������
	~CPyramidTest(void);			       	//�Ҹ���
private:
	CList<CCard,CCard&> m_List1;			//ī�带 �����ص� ����Ʈ1
	CList<CCard,CCard&> m_List2;			//ī�带 �����ص� ����Ʈ2
	CList<CCard,CCard&> m_CompleteList;		//���� 13�� �Ǽ� �ϼ��� ī�带 �����ص� ����Ʈ
	CList<CCard,CCard&> m_TempList;			//���õ� ī�带 �ӽ������ص� ����Ʈ
	CList<CCard,CCard&> m_AniList;			//�ִϸ��̼� ���� ī�� ������ ����Ʈ
	CPyramidStorage m_PyrmidStorage;		//�Ƕ�̵��� ī�� ����� ó���� ����� �Ƕ�̵彺�丮�� ��ü		
	bool m_ChoiceList1;						//����Ʈ1�� ���É���� üũ�ص� bool����
	bool m_ChoiceList2;						//����Ʈ2�� ���É���� üũ�ص� bool����
	bool m_IsDraw;							//�ִϸ��̼��� �������� üũ�� bool����
	int m_ReDeal;							//ī���� ȸ������ ī��Ʈ�� int ����
	int m_score;                            //����ڰ� ���� ������ ������ int ����
	int m_shuffle;                          //ī�� ���� ���� Ƚ��
	int m_background;				    	//��� ��Ʈ�� ���̵�
public:
	virtual void NewGame(void);				//������ �Լ�		(�θ𿡼� ���������Լ��̹Ƿ� �ݵ�� ������)
	virtual void MouseClick(CPoint point);	//���콺Ŭ�� �Լ�	(�θ𿡼� ���������Լ��̹Ƿ� �ݵ�� ������)
	virtual void MouseMove(CPoint point);	//���콺�̵� �Լ�	(�θ𿡼� ���������Լ��̹Ƿ� �ݵ�� ������)
	virtual void Draw(CDC* pDC);			//Draw �Լ�			(�θ𿡼� ���������Լ��̹Ƿ� �ݵ�� ������)
	bool IsClickList1(CPoint point);		//����Ʈ1�� Ŭ�� �糪 ��ȯ�ϴ� �Լ�
	bool IsClickList2(CPoint point);		//����Ʈ2�� Ŭ�� �糪 ��ȯ�ϴ� �Լ�
	void DrawDoubleBuffering(CDC *pDC);		//������۸��� ó���� �� ī�带 �׸��� �Լ�
	void Serialize(CArchive& ar);           //�Ƕ�̵� ������ �����͸� �����ϰ� �ҷ����� �Լ�
	void CardShuffle(CDC *pDC, CCard card);            //ī�� ���� �ִϸ��̼�
	void Animation(CDC* pDC);
	void SetOption();                      //���� �ɼ� ���� �Լ�
};

