#pragma once
#include "afx.h"
//CObject를 부모로 갖는 추상 클래스 CCardGame
class CCardGame : public CObject
{
public:
	CCardGame(void);							//기본생성자
	virtual ~CCardGame(void);					//소멸자
	virtual void NewGame(void) = 0;				//새게임 함수(순수가상함수)
	virtual void MouseClick(CPoint point) = 0;	//마우스클릭 함수(순수가상함수)
	virtual void MouseMove(CPoint point) = 0;	//마우스이동 함수(순수가상함수)
	virtual void Serialize(CArchive& ar) = 0;   //게임 저장 함수(순수가상함수)
	virtual void Draw(CDC* pDC) = 0;			//Draw 함수(순수가상함수)
	virtual void Animation(CDC* pDC) = 0;       //Animation 함수(순수가상함수)
	virtual void SetOption() = 0;              //게임 옵션 설정 함수 (순수 가상함수)
};

