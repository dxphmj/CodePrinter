#pragma once


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
	CComboBox FreqMulti;
	CEdit  m_impulse;
	CEdit m_length;
	CEdit m_currentLev;
	CEdit m_triggerLen;
};
