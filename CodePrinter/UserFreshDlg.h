#pragma once


// CUserFreshDlg 对话框

class CUserFreshDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserFreshDlg)

public:
	CUserFreshDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserFreshDlg();

// 对话框数据
	enum { IDD = IDD_USER_FRESH_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
