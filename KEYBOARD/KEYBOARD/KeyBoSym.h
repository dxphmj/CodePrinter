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
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSymAlphbet();
};
