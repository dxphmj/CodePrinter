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
	afx_msg void OnBnClickedButtonKey7();
public:
	int m_curNum;
	int m_EditId;
	bool isShow;
	void setEditNum( CString Numstr );
	void getNumFromEdit( int num,int ID );
	afx_msg void OnBnClickedButtonKeyEsc();
	afx_msg void OnBnClickedButtonKey8();
};
