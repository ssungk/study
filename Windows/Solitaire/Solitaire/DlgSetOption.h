#include"resource.h"
#pragma once
#include "afxwin.h"


// CDlgSetOption dialog

class CDlgSetOption : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetOption)

public:
	CDlgSetOption(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSetOption();

// Dialog Data
	enum { IDD = IDD_DLG_OPTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_shuffle;                           //카드 셔플 횟수
	int m_back;								 //배경 비트맵 아이디
	CEdit m_editShuffle;					 //카드 셔플 횟수를 입력 받는 에디트 박스
	CButton m_radioBase;					 //배경 종류
	CButton m_radioWater;
	CButton m_radioOil;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadioBase();
	afx_msg void OnBnClickedRadioWater();
	afx_msg void OnBnClickedRadioOil();
	virtual BOOL OnInitDialog();
};
