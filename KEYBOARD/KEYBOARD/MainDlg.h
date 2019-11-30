#pragma once
#ifdef KEYBOARD_EXPORTS
#define MESSAGEEDIT_API  _declspec(dllexport)
#else
#define MESSAGEEDIT_API  _declspec(dllimport)
#endif

// CMainDlg 对话框

class MESSAGEEDIT_API CMainDlg : public CDialog
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDlg();

// 对话框数据
	enum { IDD = 4000 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
