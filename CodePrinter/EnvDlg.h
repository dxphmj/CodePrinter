#pragma once
#include "afxwin.h"
#include "ImageButton.h"
//#include "ModuleMain.h"

// CEnvDlg 对话框

class CEnvDlg : public CDialog
{
	DECLARE_DYNAMIC(CEnvDlg)

public:
	CEnvDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEnvDlg();
    //ModuleMain envModule;
// 对话框数据
	enum { IDD = IDD_ENV_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeLanguageCombo();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListBox m_langeageList;
	afx_msg void OnBnClickedLanSelButton();
public:
	CImageButton m_ButLanSel;
	void ControlTextChange();
};
