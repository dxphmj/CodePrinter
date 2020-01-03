#pragma once
#include "afxwin.h"
#include "ImageButton.h"


// CInkPhasingDlg 对话框

class CInkPhasingDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkPhasingDlg)

public:
	CInkPhasingDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkPhasingDlg();

// 对话框数据
	enum { IDD = IDD_INK_PHASING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int m_fixed;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnBnClickedPhasingAddBtn();
	afx_msg void OnBnClickedPashingCutBtn();
	afx_msg void OnBnClickedSetAdjustSmallBtn();
	afx_msg void OnBnClickedSetAdjustBigBtn();
	afx_msg void OnBnClickedAutoSetBtn();

	CImageButton m_PhaMvAuto;
	CImageButton m_PhaMvStep10;
	CImageButton m_PhaMvStep1;
	CImageButton m_PhaMvAdd;
	CImageButton m_PhaMvSub;
	virtual BOOL OnInitDialog();
	CStatic m_PicPhaAngle;

	CBitmap m_AngleBitmap[36];  // CBitmap对象，用于加载位图  
	HBITMAP m_AnglehBmp[36];
};
