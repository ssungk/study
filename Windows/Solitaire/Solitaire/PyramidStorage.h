#pragma once
#include "Card.h"
#include "afx.h"
class CPyramidStorage :	public CObject
{
protected:
	CCard** m_pointer;				//피라미드모양 배열을 동적으로 만들기위한 CCard** 변수
	int row,col;					//현재 저장된 위치를 파악하기위한 변수
public:
	CPyramidStorage(void);										//기본생성자
	virtual ~CPyramidStorage(void);								//소멸자
	void Push(CCard card);										//삽입함수
	void Draw(CDC* pDC,CList<CCard,CCard&>& List);				//Draw함수
	void MouseClick(CPoint point,CList<CCard,CCard&>& List);	//마우스클릭처리 함수
	void RemoveChoiceCard(CList<CCard,CCard&>& List);			//선택된카드를 제거하는 함수
	void RemoveAll();											//피라미드스토리지를 비우는 함수
	void Serialize(CArchive& ar);                               //피라미드의 데이터를 저장하고 불러오는 함수
};