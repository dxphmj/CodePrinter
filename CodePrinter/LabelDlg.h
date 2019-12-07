#pragma once
#include "afxwin.h"
#include "ClassMessage.h"
#include "ModuleMain.h"
using namespace MyNameSpace;
// CLabelDlg 对话框

class CLabelDlg : public CDialog
{
	DECLARE_DYNAMIC(CLabelDlg)
public:
	int matrix;
	int pixel;
	ClassMessage myclassMessage;
	ModuleMain labModule;
	bool isFrame;
	void getMessageDot();

public:
	CLabelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLabelDlg();

// 对话框数据
	enum { IDD = IDD_LABEL_DIALOG };

	bool m_bDesign;	
    CStatic m_designArea;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox ComboMatrix;
	CComboBox pixelComboBox;
    

	afx_msg void OnBnClickedInputButton();
	
	afx_msg void OnPaint();
	afx_msg void OnCbnSelchangeComboMatrix();
	
	afx_msg void OnCbnSelchangeCombo2();

	afx_msg void OnBnClickedUshiftButton();
	afx_msg void OnBnClickedLselectButton();
	afx_msg void OnBnClickedRselectButton();
	afx_msg void OnBnClickedDshiftButton();
	afx_msg void OnBnClickedLshiftButton();
	afx_msg void OnBnClickedRshiftButton();
	afx_msg void OnBnClickedLqshiftButton();
	afx_msg void OnBnClickedRqshiftButton();
	afx_msg void OnBnClickedSaveButton();
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedRepeatButton();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedDownloadButton();
};
