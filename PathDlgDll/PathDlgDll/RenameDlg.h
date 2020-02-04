#pragma once
#include "afxwin.h"
#include "ImageButton.h"

// CRenameDlg �Ի���

class CRenameDlg : public CDialog
{
	DECLARE_DYNAMIC(CRenameDlg)

public:
	CRenameDlg(CString renameSTR,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRenameDlg();
	COLORREF m_BKcolor;
	CBrush m_DlgBrush;
// �Ի�������
	enum { IDD = IDD_DIALOG_RENAMEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CImageButton m_OKBUT;
	CImageButton m_CLOBUT;
	CString m_RenameSTR;
protected:
	virtual void OnOK();
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
