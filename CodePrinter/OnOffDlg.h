#pragma once


// COnOffDlg 对话框

class COnOffDlg : public CDialog
{
	DECLARE_DYNAMIC(COnOffDlg)

public:
	COnOffDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COnOffDlg();

// 对话框数据
	enum { IDD = IDD_ONOFF_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSequenceButton();
	afx_msg void OnBnClickedFastButton();
	afx_msg void OnBnClickedReturnBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
