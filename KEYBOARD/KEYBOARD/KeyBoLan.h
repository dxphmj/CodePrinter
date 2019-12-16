#pragma once
#include "KeyBoMain.h"

#include "Resource.h"
// CKeyBoLan �Ի���
class CKeyBoMain;//���ǰ������

class CKeyBoLan : public CDialog
{
	DECLARE_DYNAMIC(CKeyBoLan)


public:
	CKeyBoLan(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKeyBoLan();

// �Ի�������
	enum { IDD = IDD_KEYBOARD_LAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLanEsc();
	afx_msg void OnBnClickedLanChinese();
	afx_msg void OnBnClickedLanArabic();
	afx_msg void OnBnClickedLanGerman();
	afx_msg void OnBnClickedLanKorean();
	afx_msg void OnBnClickedLanEnglish();
};
