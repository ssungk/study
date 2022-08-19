
// SolitaireView.cpp : CSolitaireView Ŭ������ ����
//
#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CSolitaireView ����/�Ҹ�

CSolitaireView::CSolitaireView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	
}

CSolitaireView::~CSolitaireView()
{
}

BOOL CSolitaireView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSolitaireView �׸���

void CSolitaireView::OnDraw(CDC* pDC)
{
	CSolitaireDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	pDoc->m_Game->Draw(pDC);
	
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSolitaireView �μ�


void CSolitaireView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSolitaireView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSolitaireView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSolitaireView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CSolitaireView ����

#ifdef _DEBUG
void CSolitaireView::AssertValid() const
{
	CView::AssertValid();
}

void CSolitaireView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSolitaireDoc* CSolitaireView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSolitaireDoc)));
	return (CSolitaireDoc*)m_pDocument;
}
#endif //_DEBUG


// CSolitaireView �޽��� ó����


void CSolitaireView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CSolitaireDoc* pDoc = GetDocument();
	//pDoc->m_Pyramid.NewGame();
	pDoc->m_Game->MouseClick(point);
	Invalidate(false);

	CView::OnLButtonDown(nFlags, point);
}

BOOL CSolitaireView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
//	//MessageBox(NULL,_T("Solitaire"),_T("�޷�"));	//���� �޼��� ���
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
