#pragma once
#include "afx.h"
//CObject�� �θ�� ���� �߻� Ŭ���� CCardGame
class CCardGame : public CObject
{
public:
	CCardGame(void);							//�⺻������
	virtual ~CCardGame(void);					//�Ҹ���
	virtual void NewGame(void) = 0;				//������ �Լ�(���������Լ�)
	virtual void MouseClick(CPoint point) = 0;	//���콺Ŭ�� �Լ�(���������Լ�)
	virtual void MouseMove(CPoint point) = 0;	//���콺�̵� �Լ�(���������Լ�)
	virtual void Serialize(CArchive& ar) = 0;   //���� ���� �Լ�(���������Լ�)
	virtual void Draw(CDC* pDC) = 0;			//Draw �Լ�(���������Լ�)
	virtual void Animation(CDC* pDC) = 0;       //Animation �Լ�(���������Լ�)
	virtual void SetOption() = 0;              //���� �ɼ� ���� �Լ� (���� �����Լ�)
};

