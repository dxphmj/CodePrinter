#pragma once


// CInkPhasingDlg 对话框

class CInkPhasingDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkPhasingDlg)

public:
	CInkPhasingDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkPhasingDlg();

// 对话框数据
	enum { IDD = IDD_INK_PHASING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
