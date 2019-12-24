#pragma once
#include "ColorButton.h"

// CInkAdvanceDlg �Ի���

class CInkAdvanceDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkAdvanceDlg)

public:
	CInkAdvanceDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkAdvanceDlg();

// �Ի�������
	enum { IDD = IDD_INK_ADVANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
//��ɫ��ť
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

	
	CColorButton m_CIB_InkCir;         //ī·ѭ��
	CColorButton m_CIB_InkflowOff;     //�ػ��ռ��
	CColorButton m_CIB_AdjustInkline;  //ī��У׼
	CColorButton m_CIB_AddSolvent;     //����ܼ�
	CColorButton m_CIB_SuckNozzle;     //��������
	CColorButton m_CIB_HighVoltage;    //��ѹ����
	CColorButton m_CIB_WashNozzle;     //��ϴ����
	CColorButton m_CIB_CloseInkline;   //�ر�ī��
	CColorButton m_CIB_BetectVisco;    //���ճ��
};