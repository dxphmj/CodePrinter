// KeyBoardDlg.h : 头文件
//
#pragma once
#include "KeyBoMain.h"
#include "KeyBoCaps.h"
#include "KeyBoLan.h"
#include "KeyBoSym.h"
#include <Map>

#include "Resource.h"
#include "afxwin.h"

using namespace std;
// CKeyBoardDlg 对话框
class CKeyBoardDlg : public CDialog
{

public:
	CKeyBoMain *m_pMain;
	CKeyBoLan *m_pLan;
	CKeyBoSym *m_pSym;
	CKeyBoCaps *m_pCaps;
	
// 构造
public:
	CKeyBoardDlg(CString strIn,CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
	enum { IDD = IDD_KEYBOARD_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
public:
	CString m_strRet;
    CString m_strOld;
	CEdit m_zrh_edit;
	char arr[50];
	int j1,i1;
	map< CString,CString >ChineseLanMap;
	int LanType;
	enum LanTypeEnum{ Chinese = 0,Japanese,Korean };
public:
	 void setEditText(CString &str);
	 void getEditText();
	 void btnHide();
	 void btnShow();
	 void CreateChineseMapLan();
	 void Language();
	 void FontSelect();	 
};

