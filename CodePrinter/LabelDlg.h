#pragma once
#include "afxwin.h"
#include "ImageButton.h"
//#include "ClassMessage.h"
//#include "ModuleMain.h"
#include "InputDlg.h"
#include "DesignStatic.h"
#include "CustomStatic.h"

// CLabelDlg 对话框

class CLabelDlg : public CDialog
{
	DECLARE_DYNAMIC(CLabelDlg)
public:
	int matrix;
	int pixel;
	
	//ModuleMain labModule;
	bool isFrame;
	void getMessageDot();
	void selectPixel();
	void DownlaodMessage();
	CInputDlg *pInput;

public:
	CLabelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLabelDlg();

// 对话框数据
	enum { IDD = IDD_LABEL_DIALOG };

	bool m_bDesign;	
    CDesignStatic m_designArea;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox ComboMatrix;
	CComboBox pixelComboBox;
	
    CImageButton m_shrink;
	CImageButton m_zoom;
	CImageButton m_notback;
	CImageButton m_addback;
	CImageButton m_close;
	CImageButton m_far;
	CImageButton m_UD_mirror;
	CImageButton m_LR_mirror;
	CImageButton m_L_select;
	CImageButton m_R_select;
	CImageButton m_U_shift;
	CImageButton m_D_shift;
	CImageButton m_L_shift;
	CImageButton m_R_shift;
	CImageButton m_L_Qshift;
	CImageButton m_R_Qshift;
    CImageButton m_download;
	CImageButton m_newlyBuilt;
	CImageButton m_open;
	CImageButton m_save;
	CImageButton m_return;
	CImageButton m_input;
	CImageButton m_repeat;
	CImageButton m_copy;
	CImageButton m_delete;


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
	afx_msg void OnBnClickedLabelCloseBtn();
	void showInputDlg(int ID);

    afx_msg void OnBnClickedZoomButton();

	afx_msg void OnBnClickedClsButton();
	int m_zoomLevel;
	int m_ssValue;
	afx_msg void OnBnClickedShrinkButton();
	
	afx_msg void OnBnClickedCloseUserBtn();
	afx_msg void OnBnClickedFarButton();
	afx_msg void OnBnClickedNozzleValveBtn();
	afx_msg void OnBnClickedAddbackBtn();
	afx_msg void OnBnClickedUdmirrorButton();
	afx_msg void OnBnClickedLrmirrorButton();

	afx_msg void OnStnClickedStaticW();
	void changeDis();


	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnBnClickedCopyButton();

	CStatic m_picBNG;
	CStatic m_picOverturn;

	CBitmap m_PicBitmap[5];  // CBitmap对象，用于加载位图  
	HBITMAP m_PichBmp[5];
	afx_msg void OnBnClickedDeleteButton();
	CCustomStatic m_matrixStatic;
	CCustomStatic m_pixelStatic;
	CCustomStatic m_reversalStatic;
	CCustomStatic m_perversionStatic;
	CComboBox m_reversalCombo;
	CComboBox m_reversionCombo;
	// 白屏滚动条
	
	CScrollBar m_ScrollLab;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
