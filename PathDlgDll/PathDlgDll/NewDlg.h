#pragma once
#include "afxwin.h"
#include "ImageButton.h"

// CNewDlg �Ի���

class CNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CNewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewDlg();
	COLORREF m_BKcolor;
	CBrush m_DlgBrush;
// �Ի�������
	enum { IDD = IDD_NEWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();

	CImageButton m_OKBUT;
	CImageButton m_CLOBUT;
	CString m_nameSTR;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
