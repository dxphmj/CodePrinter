#pragma once
#include "afxwin.h"


// CInkSetupDlg �Ի���

class CInkSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSetupDlg)

public:
	CInkSetupDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkSetupDlg();

// �Ի�������
	enum { IDD = IDD_INK_SETUP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nextService;
	int m_inkLifeTime;
	CListBox m_sizeList;
	CListBox m_modulFreList;
	CListBox m_inkTypeList;
	CListBox m_peltierList;
	CListBox m_sleepList;
	virtual BOOL OnInitDialog();
};
