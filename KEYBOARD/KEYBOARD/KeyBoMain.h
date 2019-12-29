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
	afx_msg void OnBnClickedMainEsc();
	
	afx_msg void OnBnClickedMainQ();
	afx_msg void OnBnClickedMainW();
	afx_msg void OnBnClickedMainE();
	afx_msg void OnBnClickedMainR();
	afx_msg void OnBnClickedMainT();
	afx_msg void OnBnClickedMainY();
	afx_msg void OnBnClickedMainU();
	afx_msg void OnBnClickedMainI();
	afx_msg void OnBnClickedMainO();
	afx_msg void OnBnClickedMainP();
	afx_msg void OnBnClickedMainA();
	afx_msg void OnBnClickedMainS();
	afx_msg void OnBnClickedMainD();
	afx_msg void OnBnClickedMainF();
	afx_msg void OnBnClickedMainG();
	afx_msg void OnBnClickedMainH();
	afx_msg void OnBnClickedMainJ();
	afx_msg void OnBnClickedMainK();
	afx_msg void OnBnClickedMainL();
	afx_msg void OnBnClickedMainZ();
	afx_msg void OnBnClickedMainX();
	afx_msg void OnBnClickedMainC();
	afx_msg void OnBnClickedMainV();
	afx_msg void OnBnClickedMainB();
	afx_msg void OnBnClickedMainN();
	afx_msg void OnBnClickedMainM();

	afx_msg void OnBnClickedMain_SYM_1();
	afx_msg void OnBnClickedMain_SYM_2();
	afx_msg void OnBnClickedMain_SYM_3();
	afx_msg void OnBnClickedMain_SYM_4();
	afx_msg void OnBnClickedMain_SYM_5();
	afx_msg void OnBnClickedMain_SYM_6();
	afx_msg void OnBnClickedMain_SYM_7();
	afx_msg void OnBnClickedMain_SYM_8();
	afx_msg void OnBnClickedMain_SYM_9();
	afx_msg void OnBnClickedMain_SYM_10();
	afx_msg void OnBnClickedMain_SYM_11();

	afx_msg void OnBnClickedMain_1();
	afx_msg void OnBnClickedMain_2();
	afx_msg void OnBnClickedMain_3();
	afx_msg void OnBnClickedMain_4();
	afx_msg void OnBnClickedMain_5();
	afx_msg void OnBnClickedMain_6();
	afx_msg void OnBnClickedMain_7();
	afx_msg void OnBnClickedMain_8();
	afx_msg void OnBnClickedMain_9();
	afx_msg void OnBnClickedMain_0();
public:
	bool Upper;
public:
	void btnTextSel(int inputlanguage);
	void btnTextUpper();

	void LanArabic1();
	void LanArabic2();
	void LanArabic3();
	void LanArabic4();

	void LanEnglish();
	void LanKorean();
	void LanGerman();
	void LanCzech();
	void LanDutch();
	void LanFinnish();
	void LanHindi();
	void LanHungarian();
	void LanItalian();
	void LanPortuguese();
	void LanRussian();
	void LanSpanish();
	void LanSwedish();
	void LanThai();
	void LanTurkish();
};
