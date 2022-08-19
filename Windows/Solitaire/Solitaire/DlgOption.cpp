// DlgOption.cpp : implementation file
//

#include "stdafx.h"
#include "Solitaire.h"
#include "DlgOption.h"
#include "afxdialogex.h"


// CDlgOption dialog

IMPLEMENT_DYNAMIC(CDlgOption, CDialogEx)

CDlgOption::CDlgOption(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgOption::IDD, pParent)
{
	m_shuffle=2;
	m_back=IDB_BITMAPBack;
}

CDlgOption::~CDlgOption()
{
}

void CDlgOption::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SHUFFLE, m_editShuffle);
	DDX_Control(pDX, IDC_RADIO_BASE, m_radioBase);
	DDX_Control(pDX, IDC_RADIO_WATER, m_radioWater);
	DDX_Control(pDX, IDC_RADIO_OIL, m_radioOil);
}
/*
BOOL CDlgOption::OnInitDialog()
{
	return TRUE;
}*/

BEGIN_MESSAGE_MAP(CDlgOption, CDialogEx)
END_MESSAGE_MAP()


// CDlgOption message handlers
