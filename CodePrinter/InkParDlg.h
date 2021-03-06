#pragma once
#include "afxwin.h"
#include "NumKey.h"
#include "CustomStatic.h"

// CInkParDlg 对话框

class CInkParDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkParDlg)

public:
	CInkParDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkParDlg();

// 对话框数据
	enum { IDD = IDD_INK_PAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_parPressure;
	int m_parPumpSpeed;
	int m_inkFlowLev;
	int m_inkAddLev;
	int m_inkEmptyLev;
	int m_printheadTemp;
	int m_viscoDevia;
	int m_solventFlowLev;
	int m_solAddLev;
	int m_solEmptyLev;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);


	virtual BOOL OnInitDialog();
	afx_msg void OnEnSetfocusParPressureEdit();
	afx_msg void OnEnSetfocusPrintheadTempEdit();
	afx_msg void OnPaint();
	afx_msg void OnEnSetfocusParPumpSpeedEdit();
	afx_msg void OnEnSetfocusViscoDeviaEdit();
	afx_msg void OnEnSetfocusInkFlowLevEdit();
	afx_msg void OnEnSetfocusSolventFlowLevEdit();
	afx_msg void OnEnSetfocusInkAddLevEdit();
	afx_msg void OnEnSetfocusSolAddLevEdit();
	afx_msg void OnEnSetfocusInkEmptyLevEdit();
	afx_msg void OnEnSetfocusSolEmptyLevEdit();
	CEdit m_edit_parPressure;
	CEdit m_edit_parPumpSpeed;
	CEdit m_medit_viscoDevia;
	CEdit m_edit_inkFlowLev;
	CEdit m_edit_solventFlowLev;
	CEdit m_edit_inkAddLev;
	CEdit m_edit_solAddLev;
	CEdit m_edit_inkEmptyLev;
	CEdit m_edit_solEmptyLev;
	CEdit m_edit_printheadTemp;

	CCustomStatic m_parPressureStatic;
	CCustomStatic m_parPumpSpeedStatic;
	CCustomStatic m_viscoDeviaStatic;
	CCustomStatic m_inkFlowLevStatic;
	CCustomStatic m_solventFlowLevStatic;
	CCustomStatic m_inkAddLevStatic;
	CCustomStatic m_solAddLevStatic;
	CCustomStatic m_inkEmptyLevStatic;
	CCustomStatic m_solEmptyLevStatic;
	CCustomStatic m_printheadTempStatic;
};
