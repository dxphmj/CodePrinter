#pragma once
#include "ImageButton.h"
#include "CustomStatic.h"
#include "afxwin.h"

// CDateDlg 对话框

class CDateDlg : public CDialog
{
	DECLARE_DYNAMIC(CDateDlg)

public:
	CDateDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDateDlg();
	void ChangeTime();
// 对话框数据
	enum { IDD = IDD_DATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CImageButton m_returnIB;
	CImageButton m_okIB;
	CImageButton m_freshIB;
	CImageButton m_dateAddBtn;
	CEdit m_skewValue;
	CCustomStatic m_previewStatic;
 	CCustomStatic m_formatStatic;
	CCustomStatic m_fontStatic;
	CCustomStatic m_skewStatic;
	CCustomStatic m_skewVauleStatic;
	CCustomStatic m_skewUnitStatic;

	CListBox m_formatList;
	CListBox m_skewUnitList;
	CComboBox m_dateFontCombo;
	CComboBox m_dateSkewCombo;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedDateCloseBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedDateAddBtn();
	afx_msg void OnBnClickedDateRefreshBtn();
	afx_msg void OnLbnSelchangeSkewUnitList();
	afx_msg void OnBnClickedDateOkBtn();
	afx_msg void OnCbnSelchangeDateSkewCombo();

	bool isDynamicUse_dateDlg;
};
