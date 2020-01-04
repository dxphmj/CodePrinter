#pragma once


// CVersion 对话框

class CVersion : public CDialog
{
	DECLARE_DYNAMIC(CVersion)

public:
	CVersion(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVersion();

// 对话框数据
	enum { IDD = IDD_VERSION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedMainboardSoftwareTypeStatic();
	afx_msg void OnStnClickedSystemSoftwareUpdateTimeStatic();
};
