#pragma once
#include "afxwin.h"


// CLabelDlg �Ի���

class CLabelDlg : public CDialog
{
	DECLARE_DYNAMIC(CLabelDlg)

public:
	CLabelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLabelDlg();

// �Ի�������
	enum { IDD = IDD_LABEL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox ComboMatrix;
	afx_msg void OnBnClickedInputButton();
};
