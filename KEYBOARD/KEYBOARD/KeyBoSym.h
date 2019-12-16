#pragma once

#include "KeyBoMain.h"
// CKeyBoSym �Ի���

#include "Resource.h"
class CKeyBoMain;//���ǰ������
class CKeyBoSym : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoSym)


public:
	CKeyBoSym(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKeyBoSym();

// �Ի�������
	enum { IDD = IDD_KEYBOARD_SYM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
};
