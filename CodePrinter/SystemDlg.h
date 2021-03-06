#pragma once
#include "SystemDlg.h"
#include "EnvDlg.h"
#include "ComDlg.h"
#include "Version.h"
#include "ImageButton.h"
#include "CustomStatic.h"

// CSystemDlg 对话框

class CSystemDlg : public CDialog
{
	DECLARE_DYNAMIC(CSystemDlg)

public:
	CSystemDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSystemDlg();

// 对话框数据
	enum { IDD = IDD_SYSTEM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEvnBtn();
	afx_msg void OnBnClickedComBtn();
	afx_msg void OnBnClickedVersionBtn();
	afx_msg void OnBnClickedNetBtn();
	afx_msg void OnBnClickedSystemCloseBtn();
	void showSystemDlg(int ID);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

public:
	CEnvDlg *pEvn;
	CComDlg *pCom;
	CVersion *pVersion;
	CImageButton m_freshUp;
	CImageButton m_freshDown;
	CImageButton m_sysReturn;
	CImageButton m_sysOk;
	CImageButton m_dhcp;

	CImageButton m_ButNet;
	CImageButton m_ButSerial;
	CImageButton m_ButEnv;
	CImageButton m_ButCustom;
	CImageButton m_ButVersion;

	CCustomStatic m_serverIpStatic;
	CCustomStatic m_serverPortStatic;
	CCustomStatic m_validEquipStatic;
	CCustomStatic m_netNameStatic;
	CCustomStatic m_localIpStatic;
	CCustomStatic m_localPortStatic;
	CCustomStatic m_subNetMaskStatic;
	CCustomStatic m_gatewayStatic;
	CCustomStatic m_DHCPStatic;
};
