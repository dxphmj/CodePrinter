// KeyBoardDlg.h : ͷ�ļ�
//
#pragma once
#include "KeyBoMain.h"

#include "Resource.h"
// CKeyBoardDlg �Ի���
class CKeyBoardDlg : public CDialog
{

private:
	CKeyBoMain *pMain;
// ����
public:
	CKeyBoardDlg(CString strIn,CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
	enum { IDD = IDD_KEYBOARD_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnBnClickedButton1();

public:
	CString m_strRet;
    CString m_strOld;
public:
	 void setEditText(CString &str);
	 void getEditText();
	 afx_msg void OnClose();
};

