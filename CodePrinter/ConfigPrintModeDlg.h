#pragma once
#include "afxwin.h"


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
	CListBox m_printModeList;//��ӡģʽ
	CListBox m_workListList;//�����б�
	CListBox m_virtualPrintList;//�����ӡ
	int m_reapeatCount;//�ظ�����
};
