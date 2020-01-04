#pragma once
#include"InkAdvanceDlg.h"
#include "InkSetupDlg.h"
#include "InkParDlg.h"
#include "InkPhasingDlg.h"
#include "CodePrinter.h"
#include "ImageButton.h"
#include "ColorButton.h"
#include "NumKey.h"


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

	afx_msg void OnEnChangePressureEdit();
	//��ɫ��ť
	CColorButton m_CIB_SpeedMode;     //����ģʽ
	CColorButton m_CIB_PressureMode;  //ѹ��ģʽ
	CColorButton m_CIB_BleedValve;    //������
	CColorButton m_CIB_Pump;          //ѹ����
	CColorButton m_CIB_WashValve;     //��ϴ��
	CColorButton m_CIB_NozzleValve;   //���췧
	CColorButton m_CIB_FeedValve;     //��ī��
	CColorButton m_CIB_SolventValve;  //�ܼ���
	CColorButton m_CIB_ViscoValve;    //ճ�ȷ�
	CColorButton m_CIB_FlushValve  ;  //��ϴ��

	CImageButton m_returnIB;
	CImageButton m_usualIB;
	CImageButton m_advanceIB;
	CImageButton m_setupIB;
	CImageButton m_parameterIB;
	CImageButton m_phasingIB;
	CImageButton m_okIB;

   
	//����
	CEdit m_Pressure;         //ѹ��
	   		
	int m_Pumpspeed;  		 //����
	int m_InkTemp;           //īˮ�¶�
	int m_PrintheadTemp;	 //��ͷ�¶�
	int m_InkLev;            //īˮҺλ
	int m_SolventLev;        //�ܼ�Һλ
	int m_TargetVisco;       //Ŀ��ճ��
	int m_ActualVisco;       //ʵ��ճ��
	int m_HighVol;           //��ѹ
	CString m_Inkflow;        //���ռ��

	//CNumKey *pNumKey;        //���ּ���

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
