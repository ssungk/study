
// SolitaireDoc.cpp : CSolitaireDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Solitaire.h"
#endif

#include "SolitaireDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSolitaireDoc

IMPLEMENT_DYNCREATE(CSolitaireDoc, CDocument)

BEGIN_MESSAGE_MAP(CSolitaireDoc, CDocument)
END_MESSAGE_MAP()


// CSolitaireDoc ����/�Ҹ�

CSolitaireDoc::CSolitaireDoc()
{
	gameType=0;
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	m_Game = new CPyramid;
}

void CSolitaireDoc::testGame()//�ÿ��� ����
{
	if(gameType==0)
	{
		gameType=1;
		delete m_Game;
		m_Game = new CPyramidTest;
		OnNewDocument();
	}
}

void CSolitaireDoc::baseGame()//�⺻ ����
{
	if(gameType==1)
	{
		gameType=0;
		delete m_Game;
		m_Game = new CPyramid;
		OnNewDocument();
	}
}

CSolitaireDoc::~CSolitaireDoc()
{
}

BOOL CSolitaireDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_Game->NewGame();
	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CSolitaireDoc serialization

void CSolitaireDoc::Serialize(CArchive& ar)
{
	m_Game->Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CSolitaireDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CSolitaireDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSolitaireDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSolitaireDoc ����

#ifdef _DEBUG
void CSolitaireDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSolitaireDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSolitaireDoc ���
