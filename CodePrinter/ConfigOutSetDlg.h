#pragma once
#include "ImageButton.h"
#include "NumKey.h"
// CConfigOutSet �Ի���

class CConfigOutSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigOutSetDlg)

public:
	CConfigOutSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigOutSetDlg();

// �Ի�������
	enum { IDD = IDD_CONFIG_OUTSET_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedConfigOsreturnBtn();
	CListBox m_encodeSign;
	CListBox m_printDire;
	CListBox m_productDete;
	CListBox m_activeLev;
	CComboBox m_FreqMulti;
	CEdit  m_impulse;
	CEdit m_length;
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
};
