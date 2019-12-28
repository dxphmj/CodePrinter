#pragma once
#include "afxwin.h"


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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
