#pragma once


// CUserDlg �Ի���

class CUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDlg)

public:
	CUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserDlg();

// �Ի�������
	enum { IDD = IDD_USER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
