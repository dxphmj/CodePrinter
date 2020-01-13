#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CustomStatic.h"

// CInkSetupDlg 对话框

class CInkSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkSetupDlg)

public:
	CInkSetupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInkSetupDlg();

// 对话框数据
	enum { IDD = IDD_INK_SETUP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nextService;
	int m_inkLifeTime;
	CListBox m_sizeList;
	CListBox m_modulFreList;
	CListBox m_inkTypeList;
	CListBox m_peltierList;
	CListBox m_sleepList;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CImageButton m_solventCalibIB;
	CImageButton m_inkCalibIB;

	CEdit m_nextSer;
	CEdit m_inkLifeT;

	afx_msg void OnStnClickedInkSetupInktypeStatic();

	CCustomStatic m_setupSizeStatic;
	CCustomStatic m_setupRateStatic;
	CCustomStatic m_setupInkTypeStatic;
	CCustomStatic m_setupConStatic;
	CCustomStatic m_setupSleepModeStatic;
	CCustomStatic m_setupTimeResetStatic;
	CCustomStatic m_setupNextTimeStatic;
	CCustomStatic m_setupLastTimeStatic;
	CCustomStatic m_setupSolLevStatic;
	CCustomStatic m_setupInkLevStatic;
};
