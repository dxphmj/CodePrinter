#pragma once


// CNumKey 对话框

class CNumKey : public CDialog
{
	DECLARE_DYNAMIC(CNumKey)

public:
	CNumKey(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNumKey();

// 对话框数据
	enum { IDD = IDD_DIALOG_NUMKEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
