#pragma once
#include "afxwin.h"


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
public:
	CListBox m_notGranted;
	CListBox m_granted;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
