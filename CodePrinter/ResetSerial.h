#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "NumKey.h"


// CResetSerial �Ի���

class CResetSerial : public CDialog
{
	DECLARE_DYNAMIC(CResetSerial)

public:
	CResetSerial(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CResetSerial();

// �Ի�������
	enum { IDD = IDD_RESET_SERIAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedResetSerialReturnBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_returnIB;
};
