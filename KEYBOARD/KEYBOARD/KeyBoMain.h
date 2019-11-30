#pragma once

#include "KeyBoCaps.h"
#include "KeyBoLan.h"
#include "KeyBoSym.h"

#include "Resource.h"
// CKeyBoMain 对话框

class CKeyBoLan;//类的前置声明
class CKeyBoCaps;//类的前置声明
class CKeyBoSym;//类的前置声明

class CKeyBoMain : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoMain)

private:
	CKeyBoLan *pLan;
	CKeyBoCaps *pCaps;
	CKeyBoSym *pSym;


public:
	CKeyBoMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CKeyBoMain();

// 对话框数据
	enum { IDD = IDD_KEYBOARD_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedMainCaps();
	afx_msg void OnBnClickedMainSym();
	afx_msg void OnBnClickedMainLan();
	afx_msg void OnBnClickedMainP();
	afx_msg void OnBnClickedMainY();
	afx_msg void OnBnClickedMainEnter();
};
