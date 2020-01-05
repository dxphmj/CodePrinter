#pragma once
#include"InkAdvanceDlg.h"
#include "InkSetupDlg.h"
#include "InkParDlg.h"
#include "InkPhasingDlg.h"
#include "CodePrinter.h"
#include "ImageButton.h"
#include "ColorButton.h"
#include "NumKey.h"


// CInkSystemDlg 对话框

class CInkSystemDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSystemDlg)

public:
	CInkSystemDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkSystemDlg();

// 对话框数据
	enum { IDD = IDD_INKSYSTEM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void showInkDlg(int ID);
public:
	CInkAdvanceDlg *m_inkAdv;
	CInkSetupDlg *m_setup;
	CInkParDlg *m_par;
	CInkPhasingDlg *m_phas;
	afx_msg void OnBnClickedAdvanceBtn();
	afx_msg void OnBnClickedInkCloseBtn();
	afx_msg void OnBnClickedUsualBtn();
	afx_msg void OnBnClickedSetupBtn();
	afx_msg void OnBnClickedParameterBtn();
	afx_msg void OnBnClickedPhasingBtn();

	afx_msg void OnEnChangePressureEdit();
	//彩色按钮
	CColorButton m_CIB_SpeedMode;     //泵速模式
	CColorButton m_CIB_PressureMode;  //压力模式
	CColorButton m_CIB_BleedValve;    //排气阀
	CColorButton m_CIB_Pump;          //压力泵
	CColorButton m_CIB_WashValve;     //冲洗阀
	CColorButton m_CIB_NozzleValve;   //喷嘴阀
	CColorButton m_CIB_FeedValve;     //供墨阀
	CColorButton m_CIB_SolventValve;  //溶剂阀
	CColorButton m_CIB_ViscoValve;    //粘度阀
	CColorButton m_CIB_FlushValve  ;  //清洗阀

	CImageButton m_returnIB;
	CImageButton m_usualIB;
	CImageButton m_advanceIB;
	CImageButton m_setupIB;
	CImageButton m_parameterIB;
	CImageButton m_phasingIB;
	CImageButton m_okIB;

   
	//变量
	CEdit m_Pressure;         //压力
	   		
	int m_Pumpspeed;  		 //泵速
	int m_InkTemp;           //墨水温度
	int m_PrintheadTemp;	 //喷头温度
	int m_InkLev;            //墨水液位
	int m_SolventLev;        //溶剂液位
	int m_TargetVisco;       //目标粘度
	int m_ActualVisco;       //实际粘度
	int m_HighVol;           //高压
	CString m_Inkflow;        //回收检测

	//CNumKey *pNumKey;        //数字键盘

	afx_msg void OnBnClickedSpeedModeBtn();
	afx_msg void OnBnClickedPressureModeBtn();
	afx_msg void OnBnClickedPumpBtn();
	afx_msg void OnBnClickedBleedValveBtn();
	afx_msg void OnBnClickedWashValveBtn();
	afx_msg void OnBnClickedNozzleValveBtn();
	afx_msg void OnBnClickedFeedValveBtn();
	afx_msg void OnBnClickedSolventValveBtn();
	afx_msg void OnBnClickedViscoValveBtn();
	afx_msg void OnBnClickedFlushValveBtn();

	afx_msg void OnBnClickedInkOkBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
