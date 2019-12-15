#pragma once


// CInkSetupDlg 对话框

class CInkSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSetupDlg)

public:
	CInkSetupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkSetupDlg();

// 对话框数据
	enum { IDD = IDD_INK_SETUP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
