
// SolitaireView.h : CSolitaireView 클래스의 인터페이스
#pragma once


class CSolitaireView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSolitaireView();
	DECLARE_DYNCREATE(CSolitaireView)

// 특성입니다.
public:
	CSolitaireDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSolitaireView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);						// Draw시 깜빡임을 방지하기위해 리턴값을 true로 고정
	afx_msg void OnMenuPyramtest();
//	afx_msg void OnMenuShuffle();
	afx_msg void OnMenuOption();
	afx_msg void OnMenuPyrambase();
	afx_msg void OnUpdateMenuPyrambase(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenuPyramtest(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // SolitaireView.cpp의 디버그 버전
inline CSolitaireDoc* CSolitaireView::GetDocument() const
   { return reinterpret_cast<CSolitaireDoc*>(m_pDocument); }
#endif

