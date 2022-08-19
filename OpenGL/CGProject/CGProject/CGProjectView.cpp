
// CGProjectView.cpp : CCGProjectView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CCGProjectView ����/�Ҹ�

CCGProjectView::CCGProjectView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCGProjectView::~CCGProjectView()
{
}

BOOL CCGProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCGProjectView �׸���

void CCGProjectView::OnDraw(CDC* /*pDC*/)
{
	CCGProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDoc->m_iGL.Display(NULL);
}


// CCGProjectView �μ�


void CCGProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCGProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCGProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCGProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CCGProjectView ����

#ifdef _DEBUG
void CCGProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CCGProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGProjectDoc* CCGProjectView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGProjectDoc)));
	return (CCGProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CCGProjectView �޽��� ó����


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
