#pragma once


// CInkAdvanceDlg 对话框

class CInkAdvanceDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkAdvanceDlg)

public:
	CInkAdvanceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkAdvanceDlg();

// 对话框数据
	enum { IDD = IDD_INK_ADVANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInkflowOffBtn();
	afx_msg void OnBnClickedCloseInklineBtn();
	afx_msg void OnBnClickedAddSolventBtn();
	afx_msg void OnBnClickedHighVoltageBtn();
	afx_msg void OnBnClickedBetectViscoBtn();
	afx_msg void OnBnClickedWashNozzleBtn();
	afx_msg void OnBnClickedSuckNozzleBtn();
	afx_msg void OnBnClickedAdjustInklineBtn();
	afx_msg void OnBnClickedInkCirBtn();
};
