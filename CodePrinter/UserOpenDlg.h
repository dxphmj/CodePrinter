#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CustomStatic.h"

// CUserOpenDlg 对话框

class CUserOpenDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserOpenDlg)

public:
	CUserOpenDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserOpenDlg();

// 对话框数据
	enum { IDD = IDD_USER_OPEN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_notGranted;
	CListBox m_granted;
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedRightMoveBtn();
	afx_msg void OnBnClickedLeftMoveBtn();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonOk();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

public:
	CImageButton m_pReturn;
	CImageButton m_pbtnOK;
	CImageButton m_pRight_move;
	CImageButton m_pLeft_move;

	CCustomStatic m_openUserNameStatic;
	CCustomStatic m_openUnauthorizedStatic;
	CCustomStatic m_openPasswordStatic;
	CCustomStatic m_openAuthorizedStatic;

	CEdit m_open_nameEdit;
	CEdit m_open_passwordEdit;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
