#pragma once
#include"InkAdvanceDlg.h"
#include "InkSetupDlg.h"
#include "InkParDlg.h"
#include "InkPhasingDlg.h"
#include "CodePrinter.h"
#define TIMER1 1

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
	//添加定时器
//	afx_msg void OnTimer(UINT nIDEvent);
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
<<<<<<< HEAD
	afx_msg void OnEnChangePressureEdit();
	int m_Pressure;   		 //压力
	int m_Pumpspeed;  		 //泵速
	int m_InkTemp;           //墨水温度
	int m_PrintheadTemp;	 //喷头温度
	int m_InkLev;            //墨水液位
	int m_SolventLev;        //溶剂液位
	int m_TargetVisco;       //目标粘度
	int m_ActualVisco;       //实际粘度
	int m_HighVol;           //高压
	CString m_Inkflow;        //回收检测
	afx_msg void OnTimer(UINT_PTR nIDEvent);
=======
>>>>>>> 8182bf51fb697132e6c544b13cb48cb51f1aa2a6
	afx_msg void OnBnClickedSpeedModeBtn();
};
