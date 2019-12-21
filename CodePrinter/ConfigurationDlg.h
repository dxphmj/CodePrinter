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

	int m_height;//高度
	CComboBox m_reverse;//翻转
	CComboBox m_inverse;//颠倒
	int m_dotPitch;//列距
	int m_delay;//延时
	int m_repeatDis;//重复距离
	CComboBox m_speedMode;//速度模式
	int m_speed;//速度
};
