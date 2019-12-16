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
	afx_msg void OnBnClickedMainEnter();
	afx_msg void OnBnClickedMainBackspace();
	afx_msg void OnBnClickedMainLeft();
	afx_msg void OnBnClickedMainRight();
	afx_msg void OnBnClickedMainDel();
	afx_msg void OnBnClickedMainSpace();
	afx_msg void OnBnClickedMainPgDn();
	afx_msg void OnBnClickedMainPgUp();
	afx_msg void OnBnClickedMainNS();
	afx_msg void OnBnClickedMainP();
	afx_msg void OnBnClickedMainY();
	afx_msg void OnBnClickedMainA();
	afx_msg void OnBnClickedMainN();
	afx_msg void OnBnClickedMainI();
public:
	bool Upper;
public:
	void btnTextSel(int inputlanguage);
	void btnTextUpper();

	//void LanEnglish();
	//void LanArabic();
	//void LanFarsi();
	//void LanKorean();
	//void LanGerman();
	//void LanCzech();
	//void LanDutch();
	//void LanFinnish();
	//void LanHindi();
	//void LanHungarian();
	//void LanItalian();
	//void LanPortuguese();
	//void LanRussian();
	//void LanSpanish();
	//void LanSwedish();
	//void LanThai();
	//void LanTurkish();
};
