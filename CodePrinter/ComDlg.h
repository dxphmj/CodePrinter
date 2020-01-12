#pragma once
#include "afxwin.h"
#include "CustomStatic.h"


// CComDlg 对话框

class CComDlg : public CDialog
{
	DECLARE_DYNAMIC(CComDlg)

public:
	CComDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CComDlg();

// 对话框数据
	enum { IDD = IDD_COM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox m_com1BaudRate;
	CListBox m_com2Baudrate;
	CListBox m_com1Parity;
	CListBox m_com2Parity;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CCustomStatic m_staticCOM1Baut;
};
