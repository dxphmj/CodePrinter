#pragma once


// CNumKey �Ի���

class CNumKey : public CDialog
{
	DECLARE_DYNAMIC(CNumKey)

public:
	CNumKey(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNumKey();

// �Ի�������
	enum { IDD = IDD_DIALOG_NUMKEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void setEditNum( CString Numstr );
	void getNumFromEdit( CEdit *pEdit );
	int m_EditId;
	CEdit *m_edit;
	bool isShow;
	
public:

	afx_msg void OnBnClickedButtonKeyEsc();
	afx_msg void OnBnClickedButtonKeyDel();
	afx_msg void OnBnClickedButtonKeyOk();
	afx_msg void OnBnClickedButtonKeyLeft();
	afx_msg void OnBnClickedButtonKeyRight();

	afx_msg void OnBnClickedButtonKey9();
	afx_msg void OnBnClickedButtonKey8();
	afx_msg void OnBnClickedButtonKey7();
	afx_msg void OnBnClickedButtonKey6();
	afx_msg void OnBnClickedButtonKey5();
	afx_msg void OnBnClickedButtonKey4();
	afx_msg void OnBnClickedButtonKey3();
	afx_msg void OnBnClickedButtonKey2();
	afx_msg void OnBnClickedButtonKey1();
	afx_msg void OnBnClickedButtonKey0();
	afx_msg void OnBnClickedButtonKeyDoc();
};
