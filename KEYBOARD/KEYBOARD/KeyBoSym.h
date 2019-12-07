#pragma once

#include "KeyBoMain.h"
// CKeyBoSym 对话框

#include "Resource.h"
class CKeyBoMain;//类的前置声明
class CKeyBoSym : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoSym)


public:
	CKeyBoSym(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CKeyBoSym();

// 对话框数据
	enum { IDD = IDD_KEYBOARD_SYM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSymAlphbet();
};
