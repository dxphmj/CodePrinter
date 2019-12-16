#pragma once

#include "KeyBoMain.h"
#include "Resource.h"
// CKeyBoCaps 对话框

class CKeyBoMain;//类的前置声明

class CKeyBoCaps : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoCaps)



public:
	CKeyBoCaps(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CKeyBoCaps();

// 对话框数据
	enum { IDD = IDD_KEYBOARD_CAPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCAPS_CAPS();

};
