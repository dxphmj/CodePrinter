#pragma once
#include "ImageButton.h"

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

public:

	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonOk();


public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnBnClickedButtonCloseDel();

public:
	CImageButton m_pReturn;
	CImageButton m_pbtnOK;
	virtual BOOL OnInitDialog();
};
