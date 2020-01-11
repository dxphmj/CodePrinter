#pragma once
#include "ConfigPrintModeDlg.h"
#include "ConfigOutSetDlg.h"
#include "afxwin.h"
#include "ImageButton.h"
#include "NumKey.h"
// CConfigurationDlg 对话框

class CConfigurationDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigurationDlg)

public:
	CConfigurationDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigurationDlg();

// 对话框数据
	enum { IDD = IDD_CONFIGURATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

    //喷印界面的几个按钮界面接口
	CConfigPrintModeDlg *m_ConfigPM;
	CConfigOutSetDlg *m_ConfigOS;

	afx_msg void OnBnClickedConfiCloseBtn();
	void showConfigDlg(int ID);
	afx_msg void OnBnClickedPrintSetBtn();
	afx_msg void OnBnClickedOutSetBtn();

	int m_height;
	CComboBox m_reverse;
	CComboBox m_inverse;
	float m_dotPitch;
	int m_delay;
	int m_repeatDis;
	CComboBox m_speedWay;
	int m_speed;

	int m_nPcfPic;
	HBITMAP   m_HBitmap[8]; 
	CString pcfNameDlg;
 
	afx_msg void OnBnClickedSavePcf();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void pcf_diagram_select();


	CImageButton m_returnIB;
	CImageButton m_printSetIB;
	CImageButton m_outSetIB;
	CImageButton m_configOpenIB;
	CImageButton m_configSaveIB;
	CImageButton m_configOkIB;
 
	afx_msg void OnBnClickedConfiOpenBtn();
	afx_msg void OnBnClickedConfiSaveBtn();
	afx_msg void OnCbnSelchangeInverseCombo();

	afx_msg void OnEnSetfocusSpeedEdit();
	CEdit m_edit_speed;
	CNumKey *pNumKey;
	CEdit m_edit_delay;
	afx_msg void OnEnSetfocusDelayEdit();
	afx_msg void OnCbnSelchangeReverseCombo();
	afx_msg void OnPaint();
	afx_msg void OnEnChangeDelayEdit();

	CEdit m_edit_height;
	afx_msg void OnEnSetfocusHeightEdit();
	CEdit m_edit_repeatDis;
	afx_msg void OnEnSetfocusRepeatDisEdit();
	CEdit m_edit_dotPitch;
	afx_msg void OnEnSetfocusDotPitchEdit();
};
