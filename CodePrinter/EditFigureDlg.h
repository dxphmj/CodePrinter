#pragma once

#include "ImageButton.h"
#include "afxwin.h"
// CEditFigureDlg 对话框

class CEditFigureDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditFigureDlg)

public:
	CEditFigureDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditFigureDlg();

// 对话框数据
	enum { IDD = IDD_EDITFIGURE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEditfigCloseBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
	CImageButton m_okIB;
	CComboBox m_FontBox;
	CComboBox m_FormatBox;
	void RefreshSerial();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnCbnSelchangeFormatCombo();
	afx_msg void OnBnClickedEditfigureOkBtn();
	CComboBox m_countBox;
};
