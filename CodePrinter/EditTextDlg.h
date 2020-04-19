#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CustomStatic.h"
#include "Resource.h"

// CEditTextDlg 对话框

class CEditTextDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditTextDlg)

public:
	CEditTextDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditTextDlg();

// 对话框数据
	enum { IDD = IDD_EDITTEXT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEdittextCloseBtn();
	afx_msg void OnEnChangeEdit1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CComboBox fontComboBox;
	afx_msg void OnCbnSelchangeFont();
	afx_msg void OnBnClickedButtonEditok();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
	CImageButton m_okIB;
	CCustomStatic m_textStatic;
	CCustomStatic m_fontStatic;
	CCustomStatic m_dataFieldStatic;
	CEdit m_textEdit;
};
