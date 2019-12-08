#pragma once
#include "UserOpenDlg.h"
#include "UserNewDlg.h"
#include "UserDeleteDlg.h"
#include "UserFreshDlg.h"
#include "UserDlg.h"

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
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedNewBtn();
	afx_msg void OnBnClickedDeleteBtn();
	afx_msg void OnBnClickedUserFreshBtn();
	afx_msg void OnBnClickedCloseUserBtn();
	void showUserDlg(int ID);
public:
	CUserOpenDlg *pUserOpen;
	CUserNewDlg *pUserNew;
	CUserDeleteDlg *pUserDelete;
	CUserFreshDlg *pUserFresh;
	CUserDlg *pUser;
};
