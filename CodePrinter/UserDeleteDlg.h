#pragma once


// CUserDeleteDlg �Ի���

class CUserDeleteDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDeleteDlg)

public:
	CUserDeleteDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserDeleteDlg();

// �Ի�������
	enum { IDD = IDD_USER_DELETE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
