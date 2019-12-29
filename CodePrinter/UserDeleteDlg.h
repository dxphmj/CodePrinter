#pragma once


// CUserDeleteDlg 对话框

class CUserDeleteDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDeleteDlg)

public:
	CUserDeleteDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserDeleteDlg();

// 对话框数据
	enum { IDD = IDD_USER_DELETE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonOk();
};
