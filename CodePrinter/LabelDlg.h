#pragma once
#include "afxwin.h"


// CLabelDlg 对话框

class CLabelDlg : public CDialog
{
	DECLARE_DYNAMIC(CLabelDlg)

public:
	CLabelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLabelDlg();

// 对话框数据
	enum { IDD = IDD_LABEL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox ComboMatrix;
	afx_msg void OnBnClickedInputButton();
};
