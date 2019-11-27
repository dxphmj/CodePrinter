#pragma once
#include "afxwin.h"
#include "ClassMessage.h"
using namespace MyNameSpace;
// CLabelDlg �Ի���

class CLabelDlg : public CDialog
{
	DECLARE_DYNAMIC(CLabelDlg)
public:
	int matrix;
	int pixel;
	ClassMessage myclassMessage;
	bool isFrame;

public:
	CLabelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLabelDlg();

// �Ի�������
	enum { IDD = IDD_LABEL_DIALOG };

	bool m_bDesign;	
    CStatic m_designArea;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox ComboMatrix;
	CComboBox pixelComboBox;
    

	afx_msg void OnBnClickedInputButton();
	
	afx_msg void OnPaint();
	afx_msg void OnCbnSelchangeComboMatrix();
	
	afx_msg void OnCbnSelchangeCombo2();

};
