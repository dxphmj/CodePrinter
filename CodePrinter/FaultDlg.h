#pragma once


// CFaultDlg �Ի���

class CFaultDlg : public CDialog
{
	DECLARE_DYNAMIC(CFaultDlg)

public:
	CFaultDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFaultDlg();

// �Ի�������
	enum { IDD = IDD_FAULT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	//err���
	void getAllErrorFile();
	afx_msg void OnBnClickedButton4();
};
