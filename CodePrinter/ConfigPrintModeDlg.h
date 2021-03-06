#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "NumKey.h"
#include "CustomStatic.h"

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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLbnSelchangePrintModeList();

	CListBox m_printMode;
	CListBox m_workList;
	int m_repeatCount;
	CListBox m_virtualPrint;
	virtual BOOL OnInitDialog();

	CImageButton m_returnIB;
	CImageButton m_okIB;
	CEdit m_edit_repeatCount;
	afx_msg void OnEnSetfocusReapeatCountEdit();

	CNumKey *pNumKey;
	afx_msg void OnBnClickedConfigOkBtn();
	CCustomStatic m_printModeStatic;
	CCustomStatic m_workListStatic;
	CCustomStatic m_reapeatCountStatic;
	CCustomStatic m_virtualPrintStatic;
};
