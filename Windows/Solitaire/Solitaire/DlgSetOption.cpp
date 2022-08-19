// DlgSetOption.cpp : implementation file
//

#include "stdafx.h"
#include "Solitaire.h"
#include "DlgSetOption.h"
#include "afxdialogex.h"


// CDlgSetOption dialog

IMPLEMENT_DYNAMIC(CDlgSetOption, CDialogEx)

	CDlgSetOption::CDlgSetOption(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSetOption::IDD, pParent)
{
	m_shuffle=2;
	m_back=IDB_BITMAPBack;
}

CDlgSetOption::~CDlgSetOption()
{
}

void CDlgSetOption::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SHUFFLE, m_editShuffle);
	DDX_Control(pDX, IDC_RADIO_BASE, m_radioBase);
	DDX_Control(pDX, IDC_RADIO_WATER, m_radioWater);
	DDX_Control(pDX, IDC_RADIO_OIL, m_radioOil);
}


BEGIN_MESSAGE_MAP(CDlgSetOption, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgSetOption::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_BASE, &CDlgSetOption::OnBnClickedRadioBase)
	ON_BN_CLICKED(IDC_RADIO_WATER, &CDlgSetOption::OnBnClickedRadioWater)
	ON_BN_CLICKED(IDC_RADIO_OIL, &CDlgSetOption::OnBnClickedRadioOil)
END_MESSAGE_MAP()


// CDlgSetOption message handlers


void CDlgSetOption::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	if(m_radioBase.GetCheck())
		m_back=371;
	if(m_radioWater.GetCheck())
		m_back=372;
	if(m_radioOil.GetCheck())
		m_back=373;
	CString str;
	m_editShuffle.GetWindowText(str);
	m_shuffle=_ttoi(str);
}


void CDlgSetOption::OnBnClickedRadioBase()
{
	m_radioBase.SetCheck(1);
	m_radioWater.SetCheck(0);
	m_radioOil.SetCheck(0);
	Invalidate();
	// TODO: Add your control notification handler code here
}


void CDlgSetOption::OnBnClickedRadioWater()
{
	m_radioBase.SetCheck(0);
	m_radioWater.SetCheck(1);
	m_radioOil.SetCheck(0);
	Invalidate();
	// TODO: Add your control notification handler code here
}


void CDlgSetOption::OnBnClickedRadioOil()
{
	m_radioBase.SetCheck(0);
	m_radioWater.SetCheck(0);
	m_radioOil.SetCheck(1);
	Invalidate();
	// TODO: Add your control notification handler code here
}


BOOL CDlgSetOption::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if(m_back==371)//base
	{
		m_radioBase.SetCheck(1);
		m_radioWater.SetCheck(0);
		m_radioOil.SetCheck(0);
	}
	else if(m_back==372)//water
	{
		m_radioBase.SetCheck(0);
		m_radioWater.SetCheck(1);
		m_radioOil.SetCheck(0);
	}
	else if(m_back==373)//oil
	{
		m_radioBase.SetCheck(0);
		m_radioWater.SetCheck(0);
		m_radioOil.SetCheck(1);
	}

	CString str;
	str.Format(_T("%d"),m_shuffle);
	m_editShuffle.SetWindowText(str);

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
