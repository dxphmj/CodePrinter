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
	enum Symbol{ Group1 = 0,Group2,Group3,Group4};
	int SymbolGroup;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSymAlphbet();
	afx_msg void OnBnClickedSymBackspace();
	afx_msg void OnBnClickedSymSpace();
	afx_msg void OnBnClickedSymPgDn();
	afx_msg void OnBnClickedSymPgUp();
	afx_msg void OnBnClickedSymDel();
	afx_msg void OnBnClickedSymEnter();
	afx_msg void OnBnClickedSymRight();
	afx_msg void OnBnClickedSymLeft();

	afx_msg void OnBnClickedSym_1_1();
	afx_msg void OnBnClickedSym_1_2();
	afx_msg void OnBnClickedSym_1_3();
	afx_msg void OnBnClickedSym_1_4();
	afx_msg void OnBnClickedSym_1_5();
	afx_msg void OnBnClickedSym_1_6();
	afx_msg void OnBnClickedSym_1_7();
	afx_msg void OnBnClickedSym_1_8();
	afx_msg void OnBnClickedSym_1_9();
	afx_msg void OnBnClickedSym_1_10();
	afx_msg void OnBnClickedSym_1_11();

	afx_msg void OnBnClickedSym_2_1();
	afx_msg void OnBnClickedSym_2_2();
	afx_msg void OnBnClickedSym_2_3();
	afx_msg void OnBnClickedSym_2_4();
	afx_msg void OnBnClickedSym_2_5();
	afx_msg void OnBnClickedSym_2_6();
	afx_msg void OnBnClickedSym_2_7();
	afx_msg void OnBnClickedSym_2_8();
	afx_msg void OnBnClickedSym_2_9();
	afx_msg void OnBnClickedSym_2_10();
	afx_msg void OnBnClickedSym_2_11();

	afx_msg void OnBnClickedSym_3_1();
	afx_msg void OnBnClickedSym_3_2();
	afx_msg void OnBnClickedSym_3_3();
	afx_msg void OnBnClickedSym_3_4();
	afx_msg void OnBnClickedSym_3_5();
	afx_msg void OnBnClickedSym_3_6();
	afx_msg void OnBnClickedSym_3_7();
	afx_msg void OnBnClickedSym_3_8();
	afx_msg void OnBnClickedSym_3_9();
	afx_msg void OnBnClickedSym_3_10();
	afx_msg void OnBnClickedSym_3_11();

	afx_msg void OnBnClickedSym_4_1();
	afx_msg void OnBnClickedSym_4_2();
	afx_msg void OnBnClickedSym_4_3();
	afx_msg void OnBnClickedSym_4_4();
	afx_msg void OnBnClickedSym_4_5();
	afx_msg void OnBnClickedSym_4_6();
	afx_msg void OnBnClickedSym_4_7();
	afx_msg void OnBnClickedSym_4_8();
	afx_msg void OnBnClickedSym_4_9();
	afx_msg void OnBnClickedSym_4_10();
	afx_msg void OnBnClickedSym_4_11();
};
