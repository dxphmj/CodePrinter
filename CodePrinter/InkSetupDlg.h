#pragma once


// CInkSetupDlg �Ի���

class CInkSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSetupDlg)

public:
	CInkSetupDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkSetupDlg();

// �Ի�������
	enum { IDD = IDD_INK_SETUP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
