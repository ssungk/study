
// SolitaireView.cpp : CSolitaireView 클래스의 구현
//
#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Solitaire.h"
#endif

#include "SolitaireDoc.h"
#include "SolitaireView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSolitaireView

IMPLEMENT_DYNCREATE(CSolitaireView, CView)

BEGIN_MESSAGE_MAP(CSolitaireView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSolitaireView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_MENU_PYRAMID_TEST, &CSolitaireView::OnMenuPyramtest)
//	ON_COMMAND(ID_MENU_SHUFFLE, &CSolitaireView::OnMenuShuffle)
ON_COMMAND(ID_MENU_OPTION, &CSolitaireView::OnMenuOption)
ON_COMMAND(ID_MENU_PYRAMID_BASE, &CSolitaireView::OnMenuPyrambase)
ON_UPDATE_COMMAND_UI(ID_MENU_PYRAMID_BASE, &CSolitaireView::OnUpdateMenuPyrambase)
ON_UPDATE_COMMAND_UI(ID_MENU_PYRAMID_TEST, &CSolitaireView::OnUpdateMenuPyramtest)
END_MESSAGE_MAP()

// CSolitaireView 생성/소멸

CSolitaireView::CSolitaireView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CSolitaireView::~CSolitaireView()
{
}

BOOL CSolitaireView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSolitaireView 그리기

void CSolitaireView::OnDraw(CDC* pDC)
{
	CSolitaireDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	pDoc->m_Game->Draw(pDC);
	
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSolitaireView 인쇄


void CSolitaireView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSolitaireView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSolitaireView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSolitaireView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CSolitaireView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSolitaireView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSolitaireView 진단

#ifdef _DEBUG
void CSolitaireView::AssertValid() const
{
	CView::AssertValid();
}

void CSolitaireView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSolitaireDoc* CSolitaireView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSolitaireDoc)));
	return (CSolitaireDoc*)m_pDocument;
}
#endif //_DEBUG


// CSolitaireView 메시지 처리기


void CSolitaireView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CSolitaireDoc* pDoc = GetDocument();
	//pDoc->m_Pyramid.NewGame();
	pDoc->m_Game->MouseClick(point);
	Invalidate(false);

	CView::OnLButtonDown(nFlags, point);
}

BOOL CSolitaireView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}


void CSolitaireView::OnMenuPyramtest()
{
	// TODO: Add your command handler code here
	CSolitaireDoc* pDoc = GetDocument();
	pDoc->testGame();
	Invalidate();
}


//void CSolitaireView::OnMenuShuffle()
//{
//	// TODO: Add your command handler code here
//	//MessageBox(NULL,_T("Solitaire"),_T("메롱"));	//축하 메세지 출력
//	CSolitaireDoc* pDoc = GetDocument();
//}


void CSolitaireView::OnMenuOption()
{
	CSolitaireDoc* pDoc = GetDocument();
	pDoc->m_Game->SetOption();
	Invalidate();
	// TODO: Add your command handler code here
}


void CSolitaireView::OnMenuPyrambase()
{
	CSolitaireDoc* pDoc = GetDocument();
	pDoc->baseGame();
	Invalidate();
	// TODO: Add your command handler code here
}


void CSolitaireView::OnUpdateMenuPyrambase(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CSolitaireDoc* pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->gameType==0);
}


void CSolitaireView::OnUpdateMenuPyramtest(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CSolitaireDoc* pDoc = GetDocument();
	pCmdUI->SetCheck(pDoc->gameType==1);
}
