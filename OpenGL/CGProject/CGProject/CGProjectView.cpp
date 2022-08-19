
// CGProjectView.cpp : CCGProjectView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CGProject.h"
#endif

#include "CGProjectDoc.h"
#include "CGProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCGProjectView

IMPLEMENT_DYNCREATE(CCGProjectView, CView)

BEGIN_MESSAGE_MAP(CCGProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCGProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CCGProjectView 생성/소멸

CCGProjectView::CCGProjectView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCGProjectView::~CCGProjectView()
{
}

BOOL CCGProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCGProjectView 그리기

void CCGProjectView::OnDraw(CDC* /*pDC*/)
{
	CCGProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDoc->m_iGL.Display(NULL);
}


// CCGProjectView 인쇄


void CCGProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCGProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCGProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCGProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CCGProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCGProjectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCGProjectView 진단

#ifdef _DEBUG
void CCGProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CCGProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGProjectDoc* CCGProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGProjectDoc)));
	return (CCGProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CCGProjectView 메시지 처리기


void CCGProjectView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CCGProjectDoc* pDoc = GetDocument();
	pDoc->m_iGL.SetProjectView(cx, cy);
}


void CCGProjectView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	CCGProjectDoc* pDoc = GetDocument();
	pDoc->m_iGL.Release();
}


int CCGProjectView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1,1000,NULL);

	CCGProjectDoc* pDoc = GetDocument();

	return pDoc->m_iGL.Initialize(new CClientDC(this));
}


BOOL CCGProjectView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	//return CView::OnEraseBkgnd(pDC);
	return false;
}


void CCGProjectView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CCGProjectDoc* pDoc = GetDocument();
	pDoc->m_iGL.OnKeyDown(nChar,nRepCnt,nFlags);
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CCGProjectView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if(nIDEvent==1)
	{
		CCGProjectDoc* pDoc = GetDocument();
		pDoc->m_iGL.Timer();
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}
