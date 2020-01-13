#pragma once
#include "ImageButton.h"

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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
	CImageButton m_okIB;
	CImageButton m_freshIB;
	CEdit m_skewValue;
};
