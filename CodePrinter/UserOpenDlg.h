#pragma once


// CUserOpenDlg �Ի���

class CUserOpenDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserOpenDlg)

public:
	CUserOpenDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserOpenDlg();

// �Ի�������
	enum { IDD = IDD_USER_OPEN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
