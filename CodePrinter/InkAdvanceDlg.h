#pragma once
#include "ColorButton.h"

// CInkAdvanceDlg 对话框

class CInkAdvanceDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkAdvanceDlg)

public:
	CInkAdvanceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkAdvanceDlg();

// 对话框数据
	enum { IDD = IDD_INK_ADVANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
//彩色按钮
	afx_msg void OnBnClickedInkflowOffBtn();
	afx_msg void OnBnClickedCloseInklineBtn();
	afx_msg void OnBnClickedAddSolventBtn();
	afx_msg void OnBnClickedHighVoltageBtn();
	afx_msg void OnBnClickedBetectViscoBtn();
	afx_msg void OnBnClickedWashNozzleBtn();
	afx_msg void OnBnClickedSuckNozzleBtn();
	afx_msg void OnBnClickedAdjustInklineBtn();
	afx_msg void OnBnClickedInkCirBtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	
	CColorButton m_CIB_InkCir;         //墨路循环
	CColorButton m_CIB_InkflowOff;     //关回收检测
	CColorButton m_CIB_AdjustInkline;  //墨线校准
	CColorButton m_CIB_AddSolvent;     //添加溶剂
	CColorButton m_CIB_SuckNozzle;     //反吸喷嘴
	CColorButton m_CIB_HighVoltage;    //高压开关
	CColorButton m_CIB_WashNozzle;     //冲洗喷嘴
	CColorButton m_CIB_CloseInkline;   //关闭墨线
	CColorButton m_CIB_BetectVisco;    //检测粘度
};