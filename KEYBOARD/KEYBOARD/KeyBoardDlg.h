// KeyBoardDlg.h : ͷ�ļ�
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
// CKeyBoardDlg �Ի���
class CKeyBoardDlg : public CDialog
{

public:
	CKeyBoMain *m_pMain;
	CKeyBoLan *m_pLan;
	CKeyBoSym *m_pSym;
	CKeyBoCaps *m_pCaps;
	
// ����
public:
	CKeyBoardDlg(CString strIn,CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
	enum { IDD = IDD_KEYBOARD_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	vector<CString>splitOut;
	enum LanTypeEnum{ Chinese = 0,Japanese=1,Korean=2,Chinese_others=3,
					  Others=4,Arabic=5,Farsi=6,English=7,
					  Czech=8,Dutch=9,German=10,Finnish=11,
					  Hindi=12,Hungarian=13,Italian=14,Portuguese=15,
					  Russian=16,Spanish=17,Swedish=18,
					  Thai=19,Turkish=20,Japanese_others = 21,Korean_others = 22};
	int LanType;
	int LanTurn;
public:
	 void setEditText(CString &str);//�������༭���ı�
	 void setEditText_Font(CString &str);
	 void getEditText();//��ȡ���༭���ı�
	 void btnHide();//Font��ť����
	 void btnShow();//Font��ť��ʾ
	 void CreateChineseMapLan();
	 void Language();//���պ�
	 void FontSelect();//Font��ť�ı���ȡ
	 vector<CString> split(CString str);//�ַ����ָ�

public:
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnClose();
	afx_msg void OnBnClickedMainFont1();
	afx_msg void OnEnChangeEditZrh();
	afx_msg void OnBnClickedMainLeftpage();
	afx_msg void OnBnClickedMainRightpage();
	afx_msg void OnEnSetfocusEditInput();
	afx_msg void OnEnSetfocusEditZrh();
};

