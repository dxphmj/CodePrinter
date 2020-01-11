#pragma once
#include "afxwin.h"
#include "ImageButton.h"

// CNewDlg 对话框

class CNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CNewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewDlg();
	COLORREF m_BKcolor;
	CBrush m_DlgBrush;
// 对话框数据
	enum { IDD = IDD_NEWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();

	CImageButton m_OKBUT;
	CImageButton m_CLOBUT;
	CString m_nameSTR;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
