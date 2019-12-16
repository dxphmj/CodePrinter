#pragma once
#include "KeyBoMain.h"

#include "Resource.h"
// CKeyBoLan 对话框
class CKeyBoMain;//类的前置声明

class CKeyBoLan : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoLan)


public:
	CKeyBoLan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CKeyBoLan();

// 对话框数据
	enum { IDD = IDD_KEYBOARD_LAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLanEsc();
	afx_msg void OnBnClickedLanChinese();
	afx_msg void OnBnClickedLanArabic();
	afx_msg void OnBnClickedLanGerman();
	afx_msg void OnBnClickedLanKorean();
	afx_msg void OnBnClickedLanEnglish();
};
