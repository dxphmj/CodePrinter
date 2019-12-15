#pragma once


// CInkAdvanceDlg 对话框

class CInkAdvanceDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkAdvanceDlg)

public:
	CInkAdvanceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkAdvanceDlg();

// 对话框数据
	enum { IDD = IDD_INK_ADVANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
