#pragma once


// COnOffDlg �Ի���

class COnOffDlg : public CDialog
{
	DECLARE_DYNAMIC(COnOffDlg)

public:
	COnOffDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COnOffDlg();

// �Ի�������
	enum { IDD = IDD_ONOFF_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSequenceButton();
	afx_msg void OnBnClickedFastButton();
	afx_msg void OnBnClickedReturnBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
