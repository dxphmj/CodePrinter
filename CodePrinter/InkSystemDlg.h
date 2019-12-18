#pragma once
#include"InkAdvanceDlg.h"
#include "InkSetupDlg.h"
#include "InkParDlg.h"
#include "InkPhasingDlg.h"

// CInkSystemDlg �Ի���

class CInkSystemDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSystemDlg)

public:
	CInkSystemDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkSystemDlg();

// �Ի�������
	enum { IDD = IDD_INKSYSTEM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	afx_msg void OnBnClickedSpeedModeBtn();
};
