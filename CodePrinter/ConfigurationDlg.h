#pragma once
#include "ConfigPrintModeDlg.h"
#include "ConfigOutSetDlg.h"
#include "afxwin.h"
// CConfigurationDlg 对话框

class CConfigurationDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigurationDlg)

public:
	CConfigurationDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigurationDlg();

// 对话框数据
	enum { IDD = IDD_CONFIGURATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CConfigPrintModeDlg *m_ConfigPM;
	CConfigOutSetDlg *m_ConfigOS;

	afx_msg void OnBnClickedConfiCloseBtn();
	void showConfigDlg(int ID);
	afx_msg void OnBnClickedPrintSetBtn();
	afx_msg void OnBnClickedOutSetBtn();
    //喷印界面的几个按钮界面接口
	CConfigPrintModeDlg*  m_ConfigPrintModeDlg;
	CConfigOutSetDlg* m_ConfigOutSetDlg;

	int m_height;
	CComboBox m_reverse;
	CComboBox m_inverse;
	float m_dotPitch;
	int m_delay;
	int m_repeatDis;
	CComboBox m_speedWay;
	int m_speed;
};
