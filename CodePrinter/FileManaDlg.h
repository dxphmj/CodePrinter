#pragma once


// CFileManaDlg �Ի���

class CFileManaDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileManaDlg)

public:
	CFileManaDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileManaDlg();

// �Ի�������
	enum { IDD = IDD_FILEMANA_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedFilemanaCloseBtn();
};
