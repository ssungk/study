
// SolitaireDoc.h : CSolitaireDoc 클래스의 인터페이스
//
#include "Pyramid.h"
#include "PyramidTest.h"
#pragma once
using namespace std;

struct Rank{

	int score;
	CString name;
	int rank;
};

class CSolitaireDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CSolitaireDoc();
	DECLARE_DYNCREATE(CSolitaireDoc)

// 특성입니다.
public:
	int gameType; //게임 타입 시연용 게임과 기본 게임을 구분
	CCardGame* m_Game;
	Rank ranking[10];//랭킹 데이터를 저장
// 작업입니다.
public:
	void testGame();//시연용 게임 
	void baseGame();//기본 게임 
// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CSolitaireDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
