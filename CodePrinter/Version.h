#pragma once


// CVersion �Ի���

class CVersion : public CDialog
{
	DECLARE_DYNAMIC(CVersion)

public:
	CVersion(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVersion();

// �Ի�������
	enum { IDD = IDD_VERSION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedMainboardSoftwareTypeStatic();
	afx_msg void OnStnClickedSystemSoftwareUpdateTimeStatic();
};
