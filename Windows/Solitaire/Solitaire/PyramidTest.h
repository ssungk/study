#include "DlgSetOption.h"
#include "Card.h"
#include "CardGame.h"
#include "PyramidStorage.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>
#pragma once
//피라미드 카드게임의 테스트 클래스로 추상클래스인 CCardGame클래스를 상속받는다.
class CPyramidTest : public CCardGame
{
public:
	CPyramidTest(void);				    	//기본생성자
	~CPyramidTest(void);			       	//소멸자
private:
	CList<CCard,CCard&> m_List1;			//카드를 저장해둘 리스트1
	CList<CCard,CCard&> m_List2;			//카드를 저장해둘 리스트2
	CList<CCard,CCard&> m_CompleteList;		//합이 13이 되서 완성된 카드를 저장해둘 리스트
	CList<CCard,CCard&> m_TempList;			//선택된 카드를 임시저장해둘 리스트
	CList<CCard,CCard&> m_AniList;			//애니메이션 위해 카드 저장할 리스트
	CPyramidStorage m_PyrmidStorage;		//피라미드모양 카드 저장과 처리를 담당할 피라미드스토리지 객체		
	bool m_ChoiceList1;						//리스트1이 선택됬는지 체크해둘 bool변수
	bool m_ChoiceList2;						//리스트2이 선택됬는지 체크해둘 bool변수
	bool m_IsDraw;							//애니메이션이 출력됬었는지 체크할 bool변수
	int m_ReDeal;							//카드패 회전수를 카운트할 int 변수
	int m_score;                            //사용자가 얻은 점수를 관리할 int 변수
	int m_shuffle;                          //카드 셔플 가능 횟수
	int m_background;				    	//배경 비트맵 아이디
public:
	virtual void NewGame(void);				//새게임 함수		(부모에서 순수가상함수이므로 반드시 재정의)
	virtual void MouseClick(CPoint point);	//마우스클릭 함수	(부모에서 순수가상함수이므로 반드시 재정의)
	virtual void MouseMove(CPoint point);	//마우스이동 함수	(부모에서 순수가상함수이므로 반드시 재정의)
	virtual void Draw(CDC* pDC);			//Draw 함수			(부모에서 순수가상함수이므로 반드시 재정의)
	bool IsClickList1(CPoint point);		//리스트1이 클릭 됬나 반환하는 함수
	bool IsClickList2(CPoint point);		//리스트2가 클릭 됬나 반환하는 함수
	void DrawDoubleBuffering(CDC *pDC);		//더블버퍼링을 처리할 때 카드를 그리는 함수
	void Serialize(CArchive& ar);           //피라미드 게임의 데이터를 저장하고 불러오는 함수
	void CardShuffle(CDC *pDC, CCard card);            //카드 셔플 애니메이션
	void Animation(CDC* pDC);
	void SetOption();                      //게임 옵션 설정 함수
};

