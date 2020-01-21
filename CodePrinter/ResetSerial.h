#pragma once

#include "afxwin.h"
#include "ImageButton.h"
#include "CustomStatic.h"

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

	CImageButton ResetBtn1;
	CImageButton ResetBtn2;
	CImageButton ResetBtn3;
	CImageButton ResetBtn4;
	CImageButton allResetBtn;
	CImageButton resetSerialReturnBtn;
	CCustomStatic m_serialStatic1;
	CCustomStatic m_serialStatic2;
	CCustomStatic m_serialStatic3;
	CCustomStatic m_serialStatic4;
	CCustomStatic m_serial1_quad1_static;
	CCustomStatic m_serial1_quad2_static;
	CCustomStatic m_serial2_quad1_static;
	CCustomStatic m_serial2_quad2_static;
	CCustomStatic m_serial3_quad1_static;
	CCustomStatic m_serial3_quad2_static;
	CCustomStatic m_serial4_quad1_static;
	CCustomStatic m_serial4_quad2_static;
	CCustomStatic m_serial1_cur_static;
	CCustomStatic m_serial2_cur_static;
	CCustomStatic m_serial3_cur_static;
	CCustomStatic m_serial4_cur_static;
};
