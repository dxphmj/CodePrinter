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

#define ALB_SET_FIRST_LEN   	23
#define ALB_SET_LAST_LEN   		35

#define FIRST        			0
#define LAST           			1
#define MIDDLE         			2
#define ALONE          			3

#define ARBIC_START_ADDR 		(0x621)
#define ARBIC_END_ADDR   		(0x64A)

typedef unsigned short int      uint16_t; 
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
	afx_msg void OnEnChangeEditInput();
public:
	COLORREF m_BKcolor;
	CBrush m_DlgBrush;
////////////阿语连体
public:
	CString disposeinputtext( CString inputtext );//阿拉伯连体
	CString ArabicLan(CString inputstring);
	void W2C(wchar_t w_cn , char c_cn[]);
	CString ConvertWCHARToHex(CString Data, long nDataLength);//CString转16进制
	CString HexStrToCString(CString HexStr);//16进制转CString
};

