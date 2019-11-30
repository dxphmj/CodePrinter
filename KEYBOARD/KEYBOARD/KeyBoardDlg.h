// KeyBoardDlg.h : 头文件
//
#pragma once
#include "KeyBoMain.h"

#include "Resource.h"
// CKeyBoardDlg 对话框
class CKeyBoardDlg : public CDialog
{

private:
	CKeyBoMain *pMain;
// 构造
public:
	CKeyBoardDlg(CWnd* pParent = NULL);	// 标准构造函数
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


public:
	 void setEditText(CString &str);
};

