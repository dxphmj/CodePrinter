#pragma once


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
};
