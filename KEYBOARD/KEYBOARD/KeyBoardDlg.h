// KeyBoardDlg.h : 头文件
//
#pragma once
#include "KeyBoMain.h"
#include "KeyBoCaps.h"
#include "KeyBoLan.h"
#include "KeyBoSym.h"
#include <Map>
#include <vector>

#include "Resource.h"
#include "afxwin.h"

using namespace std;
// CKeyBoardDlg 对话框
class CKeyBoardDlg : public CDialog
{

public:
	CKeyBoMain *m_pMain;
	CKeyBoLan *m_pLan;
	CKeyBoSym *m_pSym;
	CKeyBoCaps *m_pCaps;
	
// 构造
public:
	CKeyBoardDlg(CString strIn,CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
	enum { IDD = IDD_KEYBOARD_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:

public:
	CString m_strRet;
    CString m_strOld;
	CEdit m_zrh_edit;
	CEdit m_edit_input;
	int j1,i1;
	map< CString,CString >ChineseLanMap;
	map< CString,CString >JapaneseLanMap;
	map< CString,CString >KoreanLanMap;
	vector<CString>splitOut;
	enum LanTypeEnum{ Chinese = 0,Japanese=1,Korean=2,Chinese_others=3,
					  Others=4,Arabic=5,Farsi=6,English=7,
					  Czech=8,Dutch=9,German=10,Finnish=11,
					  Hindi=12,Hungarian=13,Italian=14,Portuguese=15,
					  Russian=16,Spanish=17,Swedish=18,
					  Thai=19,Turkish=20,Japanese_others = 21,Korean_others = 22,Symbol = 23};
	int LantypeReverse;//语言与符号转换
	int LanType;//当前语言种类
	int LanTurn;//英语与其他语言转换
public:
	 void setEditText(CString &str);//设置主编辑框文本
	 void setEditText_Font(CString &str);
	 void getEditText();//获取主编辑框文本
	 void btnHide();//Font按钮隐藏
	 void btnShow();//Font按钮显示
	 void CreateChineseMapLan();
	 void CreateJapaneseMapLan();
	 void CreateKoreanMapLan();
	 void Language();//中日韩
	 void FontSelect();//Font按钮文本获取
	 void FontNull();//Font文本清空
	 vector<CString> split(CString str);//字符串分割
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnClose();
	afx_msg void OnEnChangeEditZrh();
	afx_msg void OnBnClickedMainLeftpage();
	afx_msg void OnBnClickedMainRightpage();
	afx_msg void OnEnSetfocusEditInput();
	afx_msg void OnEnSetfocusEditZrh();

	afx_msg void OnBnClickedMainFont1();
	afx_msg void OnBnClickedMainFont2();
	afx_msg void OnBnClickedMainFont3();
	afx_msg void OnBnClickedMainFont4();
	afx_msg void OnBnClickedMainFont5();
	afx_msg void OnBnClickedMainFont6();
	afx_msg void OnBnClickedMainFont7();
	afx_msg void OnBnClickedMainFont8();
	afx_msg void OnBnClickedMainFont9();
	afx_msg void OnBnClickedMainFont10();
	afx_msg void OnBnClickedMainFont11();
	afx_msg void OnBnClickedMainFont12();
	afx_msg void OnBnClickedMainFont13();
	afx_msg void OnBnClickedMainFont14();
	afx_msg void OnBnClickedMainFont15();

public:
	COLORREF m_BKcolor;
	CBrush m_DlgBrush;
};

