#pragma once
#include "afxwin.h"
#include "ImageButton.h"

// CIsDeletDlg 对话框

class CIsDeletDlg : public CDialog
{
	DECLARE_DYNAMIC(CIsDeletDlg)

public:
	CIsDeletDlg(CString isDetStr,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CIsDeletDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ISDETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CImageButton m_OKBUT;
	CImageButton m_CLOBUT;
	CString m_isDetstr;
};
