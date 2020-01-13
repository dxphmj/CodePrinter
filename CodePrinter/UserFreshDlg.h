#pragma once
#include "ImageButton.h"
#include "CustomStatic.h"

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
public:

	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonOk();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	CImageButton m_pReturn;
	CImageButton m_pbtnOK;
	virtual BOOL OnInitDialog();
	CCustomStatic m_freshUserNameStatic;
	CCustomStatic m_freshPasswordStatic;

	CListBox m_userNameList;
	CEdit m_passwordEdit;
};
