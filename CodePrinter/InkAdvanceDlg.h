#pragma once
#include "ImageButton.h"

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

	
	CImageButton m_CIB_InkCir;         //ī·ѭ��
	CImageButton m_CIB_InkflowOff;     //�ػ��ռ��
	CImageButton m_CIB_AdjustInkline;  //ī��У׼
	CImageButton m_CIB_AddSolvent;     //����ܼ�
	CImageButton m_CIB_SuckNozzle;     //��������
	CImageButton m_CIB_HighVoltage;    //��ѹ����
	CImageButton m_CIB_WashNozzle;     //��ϴ����
	CImageButton m_CIB_CloseInkline;   //�ر�ī��
	CImageButton m_CIB_BetectVisco;    //���ճ��
};