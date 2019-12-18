#pragma once
#include"InkAdvanceDlg.h"
#include "InkSetupDlg.h"
#include "InkParDlg.h"
#include "InkPhasingDlg.h"
#include "CodePrinter.h"
#define TIMER1 1

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
	//��Ӷ�ʱ��
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
	int m_Pressure;   		 //ѹ��
	int m_Pumpspeed;  		 //����
	int m_InkTemp;           //īˮ�¶�
	int m_PrintheadTemp;	 //��ͷ�¶�
	int m_InkLev;            //īˮҺλ
	int m_SolventLev;        //�ܼ�Һλ
	int m_TargetVisco;       //Ŀ��ճ��
	int m_ActualVisco;       //ʵ��ճ��
	int m_HighVol;           //��ѹ
	CString m_Inkflow;        //���ռ��
	afx_msg void OnTimer(UINT_PTR nIDEvent);
=======
>>>>>>> 8182bf51fb697132e6c544b13cb48cb51f1aa2a6
	afx_msg void OnBnClickedSpeedModeBtn();
};
