#pragma once


// CConfigPrintModeDlg �Ի���

class CConfigPrintModeDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigPrintModeDlg)

public:
	CConfigPrintModeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigPrintModeDlg();

// �Ի�������
	enum { IDD = IDD_CONFIG_PRINT_MODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfigCloseBtn();
};