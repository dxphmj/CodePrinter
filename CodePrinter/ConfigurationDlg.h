#pragma once
#include "ConfigPrintModeDlg.h"
#include "ConfigOutSetDlg.h"
// CConfigurationDlg �Ի���

class CConfigurationDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigurationDlg)

public:
	CConfigurationDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigurationDlg();

// �Ի�������
	enum { IDD = IDD_CONFIGURATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CConfigPrintModeDlg *m_ConfigPM;
	CConfigOutSetDlg *m_ConfigOS;

	afx_msg void OnBnClickedConfiCloseBtn();
	void showConfigDlg(int ID);
	afx_msg void OnBnClickedPrintSetBtn();
	afx_msg void OnBnClickedOutSetBtn();
};
