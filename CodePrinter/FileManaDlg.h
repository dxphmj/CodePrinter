#pragma once


// CFileManaDlg 对话框

class CFileManaDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileManaDlg)

public:
	CFileManaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFileManaDlg();

// 对话框数据
	enum { IDD = IDD_FILEMANA_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedFilemanaCloseBtn();
};
