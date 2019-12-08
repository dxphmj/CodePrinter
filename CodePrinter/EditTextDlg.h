#pragma once


// CEditTextDlg 对话框

class CEditTextDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditTextDlg)

public:
	CEditTextDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditTextDlg();

// 对话框数据
	enum { IDD = IDD_EDITTEXT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEdittextCloseBtn();
};
