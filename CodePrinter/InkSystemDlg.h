#pragma once


// CInkSystemDlg �Ի���

class CInkSystemDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSystemDlg)

public:
	CInkSystemDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkSystemDlg();

// �Ի�������
	enum { IDD = IDD_INKSYSTEM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
