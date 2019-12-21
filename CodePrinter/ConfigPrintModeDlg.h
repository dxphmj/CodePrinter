#pragma once
#include "afxwin.h"


// CConfigPrintModeDlg 对话框

class CConfigPrintModeDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigPrintModeDlg)

public:
	CConfigPrintModeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigPrintModeDlg();

// 对话框数据
	enum { IDD = IDD_CONFIG_PRINT_MODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfigCloseBtn();
	CListBox m_printModeList;//喷印模式
	CListBox m_workListList;//工作列表
	CListBox m_virtualPrintList;//虚拟打印
	int m_reapeatCount;//重复次数
};
