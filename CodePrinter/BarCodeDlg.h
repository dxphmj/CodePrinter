#pragma once


// CBarCodeDlg 对话框

class CBarCodeDlg : public CDialog
{
	DECLARE_DYNAMIC(CBarCodeDlg)

public:
	CBarCodeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBarCodeDlg();

// 对话框数据
	enum { IDD = IDD_BARCODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBarcodeCloseBtn();
};
