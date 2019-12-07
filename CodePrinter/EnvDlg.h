#pragma once
#include "afxwin.h"
#include "ModuleMain.h"

// CEnvDlg 对话框

class CEnvDlg : public CDialog
{
	DECLARE_DYNAMIC(CEnvDlg)

public:
	CEnvDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEnvDlg();
    ModuleMain envModule;
// 对话框数据
	enum { IDD = IDD_ENV_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_LanguageComboBox;
	afx_msg void OnCbnSelchangeLanguageCombo();
};
