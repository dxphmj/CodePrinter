#pragma once


// CInkParDlg 对话框

class CInkParDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkParDlg)

public:
	CInkParDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkParDlg();

// 对话框数据
	enum { IDD = IDD_INK_PAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
