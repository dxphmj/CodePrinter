#pragma once
#include "ImageButton.h"

// CDateDlg �Ի���

class CDateDlg : public CDialog
{
	DECLARE_DYNAMIC(CDateDlg)

public:
	CDateDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDateDlg();

// �Ի�������
	enum { IDD = IDD_DATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDateCloseBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
	CImageButton m_okIB;
	CImageButton m_freshIB;
	CEdit m_skewValue;
};
