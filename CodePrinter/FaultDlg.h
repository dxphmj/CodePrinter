#pragma once
#include <string>
#include <vector>
#include "ImageButton.h"
#include "afxwin.h"
#include "CustomStatic.h"
using namespace std;
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
	int intErrorFileNameArr;
	int nowErrDay;
	CString m_strPreOperation;
	afx_msg void OnBnClickedDeleteBtn();
	afx_msg void OnBnClickedBeforeBtn();
	afx_msg void OnBnClickedNextBtn();
	//err���
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
//������Ϣ��־λ
public:
	bool m_staInkTemSenFauLas;//īˮ�¶ȴ�����
	bool m_staPriHeaTemFauLas;//��ͷ�¶ȴ�����
	bool m_staBumSpeOveFauLas;//�ó��ٱ���
	bool m_staPreOveFauLas;   //��ѹ����
	bool m_staVisAbnFauLas;   //ճ���쳣
	bool m_staVisSenFauLas;   //ճ�ȼƹ���
	bool m_staInkFloFauLas;   //���չ���
	bool m_staFanFauLas;      //���ȹ���
	bool m_staChaFauLas;      //������
	bool m_staPhaFauLas;      //��λ����
	bool m_staHigVolFauLas;   //��ѹ����
	string m_staSolLevFauLas; //�ܼ�Һλ״̬
	string m_staInkLevFauLas; //īˮҺλ״̬
	bool m_staProSenFasLas;   //���۹��� 
	bool m_staAutModFauLas;   //�Զ�����ʧ��
	bool m_staValFauLas;      //������
	bool m_staLinFasLas;      //����������
	bool m_staPriHeaHotFauLas;//���¹���
	
	//CStatic m_ErrorTrans;
public:
	vector<CString> split(CString str ,CString segStr);//�ַ����ָ�
public:
	CCustomStatic m_ErrorTransStatic;
};
