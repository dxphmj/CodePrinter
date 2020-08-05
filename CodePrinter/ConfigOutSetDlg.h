#pragma once
#include "ImageButton.h"
#include "NumKey.h"
#include "CustomStatic.h"
// CConfigOutSet 对话框

class CConfigOutSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigOutSetDlg)

public:
	CConfigOutSetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigOutSetDlg();

// 对话框数据
	enum { IDD = IDD_CONFIG_OUTSET_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedConfigOsreturnBtn();
	CListBox m_encodeSign;
	CListBox m_printDire;
	CListBox m_productDete;
	CListBox m_activeLev;
	CComboBox m_FreqMulti;
	CEdit  m_impulse;//ImpulsesRoration编码器1转脉冲数
	CEdit m_length;//Cirumference同步轮周长
	CEdit m_currentLevel;
	CEdit m_triggerLen;

	CImageButton m_outSetReturn;
	CImageButton m_outSetOk;

	CString m_currentLevelStr;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	afx_msg void OnEnSetfocusImpulseEdit();
	afx_msg void OnEnSetfocusTriggerLenEdit();
	afx_msg void OnEnSetfocusLengthEdit();

	CNumKey *pNumKey;
	afx_msg void OnBnClickedOutsetOkBtn();
	CCustomStatic m_outsetPrintDir;
	CCustomStatic m_outsetEncodeSign;
	CCustomStatic m_outsetPreqmulti;
	CCustomStatic m_outsetImpulse;
	CCustomStatic m_outsetLength;
	CCustomStatic m_outsetProduct;
	CCustomStatic m_outsetActiveLev;
	CCustomStatic m_outsetCurLev;
	CCustomStatic m_outsetTrigger;
	int m_intImpulse;
	int m_intLength;
	int m_intTriggerLen;
};
