#pragma once


// CBarCodeDlg �Ի���

class CBarCodeDlg : public CDialog
{
	DECLARE_DYNAMIC(CBarCodeDlg)

public:
	CBarCodeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBarCodeDlg();

// �Ի�������
	enum { IDD = IDD_BARCODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBarcodeCloseBtn();
};
