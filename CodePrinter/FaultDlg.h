#pragma once
#include <string>
#include <vector>
#include "ImageButton.h"
using namespace std;
// CFaultDlg 对话框

class CFaultDlg : public CDialog
{
	DECLARE_DYNAMIC(CFaultDlg)

public:
	CFaultDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFaultDlg();

// 对话框数据
	enum { IDD = IDD_FAULT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedFaultCloseBtn();
	CListBox m_faultList;

	void get_save_error();
	void get_error_name();
	void openfailurefile(string filePathName);
	string Errorlog_name;
	vector<string> strErrorFileNameArr;
	int intErrorFileNameArr;
	int nowErrDay;
	CString m_strPreOperation;
	afx_msg void OnBnClickedDeleteBtn();
	afx_msg void OnBnClickedBeforeBtn();
	afx_msg void OnBnClickedNextBtn();
	//err相关
	void getAllErrorFile();
	afx_msg void OnBnClickedRefreshBtn();
	afx_msg void OnBnClickedLHistoryBtn();
	afx_msg void OnBnClickedRHistoryBtn();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	CImageButton m_pReturn;
	CImageButton m_LHistory;
	CImageButton m_RHistory;
	CImageButton m_refresh;
	CImageButton m_delete;
	CImageButton m_next;
	CImageButton m_before;
};
