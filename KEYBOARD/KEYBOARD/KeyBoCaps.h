#pragma once

#include "KeyBoMain.h"
#include "Resource.h"
// CKeyBoCaps �Ի���

class CKeyBoMain;//���ǰ������

class CKeyBoCaps : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoCaps)



public:
	CKeyBoCaps(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKeyBoCaps();

// �Ի�������
	enum { IDD = IDD_KEYBOARD_CAPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCAPS_CAPS();

};
