#pragma once
#include <string>
#include <vector>
#include "ImageButton.h"
#include "afxwin.h"
#include "CustomStatic.h"
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
	afx_msg void OnLbnSelchangeFaultList();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	CImageButton m_pReturn;
	CImageButton m_LHistory;
	CImageButton m_RHistory;
	CImageButton m_refresh;
	CImageButton m_delete;
	CImageButton m_next;
	CImageButton m_before;
//故障信息标志位
public:
	bool m_staInkTemSenFauLas;//墨水温度传感器
	bool m_staPriHeaTemFauLas;//喷头温度传感器
	bool m_staBumSpeOveFauLas;//泵超速保护
	bool m_staPreOveFauLas;   //过压保护
	bool m_staVisAbnFauLas;   //粘度异常
	bool m_staVisSenFauLas;   //粘度计故障
	bool m_staInkFloFauLas;   //回收故障
	bool m_staFanFauLas;      //风扇故障
	bool m_staChaFauLas;      //充电故障
	bool m_staPhaFauLas;      //相位故障
	bool m_staHigVolFauLas;   //高压故障
	string m_staSolLevFauLas; //溶剂液位状态
	string m_staInkLevFauLas; //墨水液位状态
	bool m_staProSenFasLas;   //电眼过快 
	bool m_staAutModFauLas;   //自动分裂失败
	bool m_staValFauLas;      //阀故障
	bool m_staLinFasLas;      //编码器过快
	bool m_staPriHeaHotFauLas;//恒温故障
	
	//CStatic m_ErrorTrans;
public:
	vector<CString> split(CString str ,CString segStr);//字符串分割
public:
	CCustomStatic m_ErrorTransStatic;
};
