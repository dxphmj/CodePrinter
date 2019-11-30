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

private:
	CKeyBoLan *pLan;
	CKeyBoCaps *pCaps;
	CKeyBoSym *pSym;


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
	afx_msg void OnBnClickedMainEnter();
};
