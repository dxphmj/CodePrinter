#pragma once


// CInkAdvanceDlg �Ի���

class CInkAdvanceDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkAdvanceDlg)

public:
	CInkAdvanceDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkAdvanceDlg();

// �Ի�������
	enum { IDD = IDD_INK_ADVANCE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
