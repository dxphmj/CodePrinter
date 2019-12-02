#pragma once
#include "afxwin.h"
#include "ModuleMain.h"

// CEnvDlg �Ի���

class CEnvDlg : public CDialog
{
	DECLARE_DYNAMIC(CEnvDlg)

public:
	CEnvDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEnvDlg();
    ModuleMain envModule;
// �Ի�������
	enum { IDD = IDD_ENV_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_LanguageComboBox;
	afx_msg void OnCbnSelchangeLanguageCombo();
};
