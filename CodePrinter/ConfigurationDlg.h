#pragma once
#include "ConfigPrintModeDlg.h"
#include "ConfigOutSetDlg.h"
#include "afxwin.h"
#include "ImageButton.h"

// CConfigurationDlg �Ի���

class CConfigurationDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigurationDlg)

public:
	CConfigurationDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigurationDlg();

// �Ի�������
	enum { IDD = IDD_CONFIGURATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

    //��ӡ����ļ�����ť����ӿ�
	CConfigPrintModeDlg*  m_ConfigPrintModeDlg;
	CConfigPrintModeDlg *m_ConfigPM;
	CConfigOutSetDlg *m_ConfigOS;

	afx_msg void OnBnClickedConfiCloseBtn();
	void showConfigDlg(int ID);
	afx_msg void OnBnClickedPrintSetBtn();
	afx_msg void OnBnClickedOutSetBtn();

	int m_height;
	CComboBox m_reverse;
	CComboBox m_inverse;
	float m_dotPitch;
	int m_delay;
	int m_repeatDis;
	CComboBox m_speedWay;
	int m_speed;
 
	afx_msg void OnBnClickedSavePcf();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CImageButton m_returnIB;
	CImageButton m_printSetIB;
	CImageButton m_outSetIB;
	CImageButton m_configOpenIB;
	CImageButton m_configSaveIB;
	CImageButton m_configOkIB;
 
	afx_msg void OnBnClickedConfiOpenBtn();
	afx_msg void OnBnClickedConfiSaveBtn();
};
