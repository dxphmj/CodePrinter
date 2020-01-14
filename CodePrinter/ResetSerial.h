#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "NumKey.h"


// CResetSerial 对话框

class CResetSerial : public CDialog
{
	DECLARE_DYNAMIC(CResetSerial)

public:
	CResetSerial(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CResetSerial();

// 对话框数据
	enum { IDD = IDD_RESET_SERIAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedResetSerialReturnBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
};
