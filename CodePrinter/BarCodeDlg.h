#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CustomStatic.h"
#include "DesignStatic.h"
#include "MainPicture.h"

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
	void Create2Dcode(int nType);

    int m_nCodeType;

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
	afx_msg void OnEnChangeBarcodeTextEdit();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
	CImageButton m_qrCodeIB;
	CImageButton m_dataMatrixIB;
	CImageButton m_code39IB;
	CImageButton m_code128IB;
	CImageButton m_okIB;
	CImageButton m_L_shiftIB;
	CImageButton m_R_shiftIB;

	afx_msg void OnStnClickedBarcodeSetStatic();

	afx_msg void OnBnClickedCode128Btn();
	afx_msg void OnBnClickedCode39Btn();
	CCustomStatic m_barText;
	CImageButton m_barcodeFigureBtn;
	CImageButton m_barcodeDateBtn;

	afx_msg void OnBnClickedBarcodeFigureBtn();
	afx_msg void OnBnClickedBarcodeDateBtn();
	CStatic m_figureStatic;
	CStatic m_dateStatic;
	CDesignStatic m_barcodeDesignArea;
	//MainPicture m_barcodeDesignArea;
	afx_msg void OnBnClickedBarcodeLButton();
	afx_msg void OnBnClickedBarcodeRButton();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
