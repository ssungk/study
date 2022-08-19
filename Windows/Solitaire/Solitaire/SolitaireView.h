
// SolitaireView.h : CSolitaireView Ŭ������ �������̽�
#pragma once


class CSolitaireView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSolitaireView();
	DECLARE_DYNCREATE(CSolitaireView)

// Ư���Դϴ�.
public:
	CSolitaireDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CSolitaireView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);						// Draw�� �������� �����ϱ����� ���ϰ��� true�� ����
	afx_msg void OnMenuPyramtest();
//	afx_msg void OnMenuShuffle();
	afx_msg void OnMenuOption();
	afx_msg void OnMenuPyrambase();
	afx_msg void OnUpdateMenuPyrambase(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenuPyramtest(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // SolitaireView.cpp�� ����� ����
inline CSolitaireDoc* CSolitaireView::GetDocument() const
   { return reinterpret_cast<CSolitaireDoc*>(m_pDocument); }
#endif

