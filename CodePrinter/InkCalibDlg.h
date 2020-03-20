#pragma once

#include "ImageButton.h"
// CInkCalibDlg �Ի���

class CInkCalibDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkCalibDlg)

public:
	CInkCalibDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkCalibDlg();

// �Ի�������
	enum { IDD = IDD_INK_CALIB_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCalibNext1Btn();
	afx_msg void OnBnClickedCalibNext2Btn();
	afx_msg void OnBnClickedCalibReturnBtn();
	CString LevCal_type;
	virtual BOOL OnInitDialog();
	CImageButton m_CalibNext1IB;
	CImageButton m_CalibNext2IB;
	CImageButton m_CalibReturnIB;
};
