#pragma once


// CUserFreshDlg �Ի���

class CUserFreshDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserFreshDlg)

public:
	CUserFreshDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserFreshDlg();

// �Ի�������
	enum { IDD = IDD_USER_FRESH_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
