#pragma once


// CInkAdvanceDlg �Ի���

class CInkAdvanceDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkAdvanceDlg)

public:
	CInkAdvanceDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkAdvanceDlg();

// �Ի�������
	enum { IDD = IDD_INK_ADVANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
