#pragma once
#include "afxwin.h"


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
	afx_msg void OnBnClickedQrCodeBtn();
	afx_msg void OnBnClickedDataMatrixBtn();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBarcodeOkBtn();
	CComboBox VersionBox;
	afx_msg void OnCbnSelchangeBarcodeVersionCombo();
	CComboBox ErrLevelBox;
	afx_msg void OnCbnSelchangeBarcodeEccLevCombo();
	afx_msg void OnCbnSelchangeBarcodeZoneCombo();
	CComboBox EncodingModeBox;
};
