#pragma once


// CEditTextDlg �Ի���

class CEditTextDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditTextDlg)

public:
	CEditTextDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditTextDlg();

// �Ի�������
	enum { IDD = IDD_EDITTEXT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEdittextCloseBtn();
};
