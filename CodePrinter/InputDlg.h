#pragma once


// CInputDlg 对话框

class CInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInputDlg();

// 对话框数据
	enum { IDD = IDD_INPUT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEdittextButton();
	afx_msg void OnBnClickedEditfigureButton();
	afx_msg void OnBnClickedEditdateButton();
	afx_msg void OnBnClickedEditpictureButton();
	afx_msg void OnBnClickedBarcodeButton();
};
