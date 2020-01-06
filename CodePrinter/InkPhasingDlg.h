#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "NumKey.h"


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
	void download_inksystem_mv();
	void save_inksystem_mv_to_xml();

public:
	int m_fixed;

	CImageButton m_PhaMvAuto;
	CImageButton m_PhaMvStep10;
	CImageButton m_PhaMvStep1;
	CImageButton m_PhaMvAdd;
	CImageButton m_PhaMvSub;
	CStatic m_PicPhaAngle;

	CBitmap m_AngleBitmap[36];  // CBitmap对象，用于加载位图  
	HBITMAP m_AnglehBmp[36];
	CEdit m_edit_fiexd;
	
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPhasingAddBtn();
	afx_msg void OnBnClickedPashingCutBtn();
	afx_msg void OnBnClickedSetAdjustSmallBtn();
	afx_msg void OnBnClickedSetAdjustBigBtn();
	afx_msg void OnBnClickedAutoSetBtn();
	afx_msg void OnEnSetfocusFixedEdit();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
