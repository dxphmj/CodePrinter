// CodePrinterDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "FaultDlg.h"
#include "SystemDlg.h"
#include "UserDlg.h"
#include "ConfigurationDlg.h"
#include "FileManaDlg.h"
#include "InkSystemDlg.h"
#include "PictureStatic.h"


#include "OnOffDlg.h"
#define TIMER1 1

// CCodePrinterDlg 对话框
class CCodePrinterDlg : public CDialog
{
// 构造
public:
	CCodePrinterDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CODEPRINTER_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


public:
    CPictureStatic m_PicHead;

public:
    void UpdateValve(); //更新各种阀的信息
    void GetFaultInfo(); //获得各种故障信息

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLabelButton();
	afx_msg void OnBnClickedFaultButton();
	afx_msg void OnBnClickedSystemButton();
	afx_msg void OnBnClickedUserButton();
	afx_msg void OnBnClickedConfigurationButton();
	afx_msg void OnBnClickedFilemanaButton();
	afx_msg void OnBnClickedInkButton();
	afx_msg void OnBnClickedOnoroffButton();
	afx_msg void OnBnClickedStartprintButton();
	afx_msg void OnBnClickedPauseprintButton();
	CImageButton m_ButFault;
	CImageButton m_ButSystem;
	CImageButton m_ButUser;
	CImageButton m_ButLabel;
	CImageButton m_ButConfig;
	CImageButton m_ButFileMana;
	CImageButton m_ButInk;
	CImageButton m_ButOnOrOff;
	CImageButton m_StartPrint;
	CImageButton m_PausePrint;

	CStatic m_LogoPicBox;

	CSystemDlg *m_System;
	CUserDlg *m_User;
	CLabelDlg *m_Label;
	CConfigurationDlg *m_Confi;
	CFileManaDlg *m_FileMan;
	CInkSystemDlg *m_Ink;
	CFaultDlg *m_Fault;
	COnOffDlg *m_OnOff;

public:
	void showDlg(int ID);

public:

	afx_msg void OnTimer(UINT_PTR nIDEvent); //定时器
 
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  

};
