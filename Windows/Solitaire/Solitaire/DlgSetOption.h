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
	int m_shuffle;                           //ī�� ���� Ƚ��
	int m_back;								 //��� ��Ʈ�� ���̵�
	CEdit m_editShuffle;					 //ī�� ���� Ƚ���� �Է� �޴� ����Ʈ �ڽ�
	CButton m_radioBase;					 //��� ����
	CButton m_radioWater;
	CButton m_radioOil;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadioBase();
	afx_msg void OnBnClickedRadioWater();
	afx_msg void OnBnClickedRadioOil();
	virtual BOOL OnInitDialog();
};
