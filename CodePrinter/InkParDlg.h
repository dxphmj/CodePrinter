#pragma once


// CInkParDlg �Ի���

class CInkParDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkParDlg)

public:
	CInkParDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkParDlg();

// �Ի�������
	enum { IDD = IDD_INK_PAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
