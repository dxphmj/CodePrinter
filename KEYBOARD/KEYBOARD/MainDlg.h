#pragma once
#ifdef KEYBOARD_EXPORTS
#define MESSAGEEDIT_API  _declspec(dllexport)
#else
#define MESSAGEEDIT_API  _declspec(dllimport)
#endif

// CMainDlg �Ի���

class MESSAGEEDIT_API CMainDlg : public CDialog
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDlg();

// �Ի�������
	enum { IDD = 4000 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
