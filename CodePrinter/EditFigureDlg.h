#pragma once

#include "ImageButton.h"
#include "afxwin.h"
#include "CustomStatic.h"
// CEditFigureDlg �Ի���

class CEditFigureDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditFigureDlg)

public:
	CEditFigureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditFigureDlg();

// �Ի�������
	enum { IDD = IDD_EDITFIGURE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	CCustomStatic m_previewStatic;
	CCustomStatic m_firstQuartileStatic;
	CCustomStatic m_fourQuartileStatic;
	CCustomStatic m_startStatic;
	CCustomStatic m_stepSizeStatic;
	CCustomStatic m_repeatCountStatic;
	CCustomStatic m_bitStatic;
	CCustomStatic m_counterStatic;
	CCustomStatic m_fontStatic;
	CCustomStatic m_formatStatic;
};
