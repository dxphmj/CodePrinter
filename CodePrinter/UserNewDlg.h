#pragma once
#include "ImageButton.h"

// CUserNewDlg 对话框

class CUserNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserNewDlg)

public:
	CUserNewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserNewDlg();

// 对话框数据
	enum { IDD = IDD_USER_NEW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRightMoveBtn();
	afx_msg void OnBnClickedLeftMoveBtn();
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonClose();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	CImageButton m_pReturn;
	CImageButton m_pbtnOK;
	CImageButton m_pRight_move;
	CImageButton m_pLeft_move;

	
};
