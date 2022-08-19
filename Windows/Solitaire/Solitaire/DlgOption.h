#pragma once
#include "afxwin.h"
#include "resource.h"

// CDlgOption dialog

class CDlgOption : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgOption)

public:
	CDlgOption(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgOption();

// Dialog Data
	enum { IDD = IDD_DLG_OPTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//BOOL CDlgOption::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	int m_shuffle;
	int m_back;
	CEdit m_editShuffle;
	CButton m_radioBase;
	CButton m_radioWater;
	CButton m_radioOil;
};
