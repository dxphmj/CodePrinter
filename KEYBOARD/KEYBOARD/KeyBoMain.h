#pragma once

#include "KeyBoCaps.h"
#include "KeyBoLan.h"
#include "KeyBoSym.h"

#include "Resource.h"
// CKeyBoMain �Ի���

class CKeyBoLan;//���ǰ������
class CKeyBoCaps;//���ǰ������
class CKeyBoSym;//���ǰ������

class CKeyBoMain : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoMain)

public:
	CKeyBoMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKeyBoMain();

// �Ի�������
	enum { IDD = IDD_KEYBOARD_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedMainCaps();
	afx_msg void OnBnClickedMainSym();
	afx_msg void OnBnClickedMainLan();
	afx_msg void OnBnClickedMainP();
	afx_msg void OnBnClickedMainY();
	afx_msg void OnBnClickedMainA();
	afx_msg void OnBnClickedMainN();
	afx_msg void OnBnClickedMainI();
	afx_msg void OnBnClickedMainEnter();
	afx_msg void OnBnClickedMainBackspace();
	afx_msg void OnBnClickedMainLeft();
	afx_msg void OnBnClickedMainRight();
	afx_msg void OnBnClickedMainDel();
public:
	void InitBtnText(int inputlanguage);
};
