#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "NumKey.h"

// CConfigPrintModeDlg �Ի���

class CConfigPrintModeDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigPrintModeDlg)

public:
	CConfigPrintModeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigPrintModeDlg();

// �Ի�������
	enum { IDD = IDD_CONFIG_PRINT_MODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfigCloseBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
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
};
