#pragma once


// CInkPhasingDlg �Ի���

class CInkPhasingDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkPhasingDlg)

public:
	CInkPhasingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkPhasingDlg();

// �Ի�������
	enum { IDD = IDD_INK_PHASING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
