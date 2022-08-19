
// SolitaireDoc.h : CSolitaireDoc Ŭ������ �������̽�
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
protected: // serialization������ ��������ϴ�.
	CSolitaireDoc();
	DECLARE_DYNCREATE(CSolitaireDoc)

// Ư���Դϴ�.
public:
	int gameType; //���� Ÿ�� �ÿ��� ���Ӱ� �⺻ ������ ����
	CCardGame* m_Game;
	Rank ranking[10];//��ŷ �����͸� ����
// �۾��Դϴ�.
public:
	void testGame();//�ÿ��� ���� 
	void baseGame();//�⺻ ���� 
// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CSolitaireDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
