#pragma once
#include "afxwin.h"
#include "ImageButton.h"

// CIsDeletDlg �Ի���

class CIsDeletDlg : public CDialog
{
	DECLARE_DYNAMIC(CIsDeletDlg)

public:
	CIsDeletDlg(CString isDetStr,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIsDeletDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ISDETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CImageButton m_OKBUT;
	CImageButton m_CLOBUT;
	CString m_isDetstr;
};
