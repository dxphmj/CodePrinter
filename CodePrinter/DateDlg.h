#pragma once


// CDateDlg 对话框

class CDateDlg : public CDialog
{
	DECLARE_DYNAMIC(CDateDlg)

public:
	CDateDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDateDlg();

// 对话框数据
	enum { IDD = IDD_DATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDateCloseBtn();
};
