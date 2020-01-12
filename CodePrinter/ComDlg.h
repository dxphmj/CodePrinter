#pragma once
#include "afxwin.h"
#include "CustomStatic.h"


// CComDlg �Ի���

class CComDlg : public CDialog
{
	DECLARE_DYNAMIC(CComDlg)

public:
	CComDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CComDlg();

// �Ի�������
	enum { IDD = IDD_COM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox m_com1BaudRate;
	CListBox m_com2Baudrate;
	CListBox m_com1Parity;
	CListBox m_com2Parity;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CCustomStatic m_staticCOM1Baut;
};
