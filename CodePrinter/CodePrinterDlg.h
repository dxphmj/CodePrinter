// CodePrinterDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "FaultDlg.h"
#include "SystemDlg.h"
#include "UserDlg.h"
#include "ConfigurationDlg.h"
#include "FileManaDlg.h"
#include "InkSystemDlg.h"
#include "PictureStatic.h"
#include "MainPicture.h"
#include "Resource.h"
#include "OnOffDlg.h"
#include "NumKey.h"
#include "ResetSerial.h"
#include "DealXml.h"

#include "Arabicconjunction.h"

#include "ClientSocket.h"

#define TIMER1 1

// CCodePrinterDlg �Ի���
class CCodePrinterDlg : public CDialog
{
// ����
public:
	CCodePrinterDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CODEPRINTER_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


public:
    CPictureStatic m_PicHead;
	MainPicture m_PictureMain;
	string m_currentDate; //��ǰ����
	string m_currentTime; //��ǰʱ��
public:
    void UpdateValve(); //���¸��ַ�����Ϣ
    void GetFaultInfo(); //��ø��ֹ�����Ϣ
    void UpdatePhase();

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
	afx_msg void OnBnClickedLabelButton();
	afx_msg void OnBnClickedFaultButton();
	afx_msg void OnBnClickedSystemButton();
	afx_msg void OnBnClickedUserButton();
	afx_msg void OnBnClickedConfigurationButton();
	afx_msg void OnBnClickedFilemanaButton();
	afx_msg void OnBnClickedInkButton();
	afx_msg void OnBnClickedOnoroffButton();
	afx_msg void OnBnClickedStartprintButton();
	afx_msg void OnBnClickedPauseprintButton();
	afx_msg void OnBnClickedResetCountBtn();
	afx_msg void OnBnClickedResetSerialBtn();
	CImageButton m_ButFault;
	CImageButton m_ButSystem;
	CImageButton m_ButUser;
	CImageButton m_ButLabel;
	CImageButton m_ButConfig;
	CImageButton m_ButFileMana;
	CImageButton m_ButInk;
	CImageButton m_ButOnOrOff;
	CImageButton m_StartPrint;
	CImageButton m_PausePrint;
	CImageButton m_ButResetCounter;
	CImageButton m_ButResetSerial;

	CSystemDlg *m_System;
	CUserDlg *m_User;
	CLabelDlg *m_Label;
	CConfigurationDlg *m_Confi;
	CFileManaDlg *m_FileMan;
	CInkSystemDlg *m_Ink;
	CFaultDlg *m_Fault;
	CResetSerial *m_resetSerial;

	COnOffDlg *m_OnOff;
	CNumKey *m_pNumKey;


	structMP mainPicStruct;
	
public:
	void showDlg(int ID);
	void OpenNumKeyBoard(CEdit * pWnd,int dlgNum);

public:

	afx_msg void OnTimer(UINT_PTR nIDEvent); //��ʱ��
 
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void ChangeBottonEnable();
public:
	CArabicconjunction *m_cAbrabicconj;
public://����
	afx_msg LRESULT OnSocketAccept(WPARAM wParam, LPARAM lParam);	//FD_ACCEPT�����¼��Զ�����Ϣ
	afx_msg LRESULT OnSocketRead(WPARAM wParam, LPARAM lParam);		//FD_READ�����¼��Զ�����Ϣ
	afx_msg LRESULT OnSocketClose(WPARAM wParam, LPARAM lParam);	//FD_CLOSE�����¼��Զ�����Ϣ

	BOOL	InitSocket(void);								//��ʼ���׽���
	BOOL	BeginListen(void);								//��������ʼ����
	BOOL    StartSocket(void);								//��ʼͨѶ
	static DWORD WINAPI ServiceThread(void *pParam);		//�������̺߳���

	void	ClearSocketAndEventFromArr(const int nIndex);	//ɾ���ͻ����׽���
	void	DeleteClientNode(SOCKET s);						//�ӹ���ͻ�������ɾ���ڵ�
	CClientSocket* FindClientNode(const SOCKET s);			//�ӹ���ͻ��������в��Ҷ�Ӧ��CClientSocketָ��


public:

	SOCKET			m_sListen;						//�����׽���
	WSAEVENT		m_arrEvent[MAX_NUM_EVENTS];		//�׽����¼���������
	SOCKET			m_arrSocket[MAX_NUM_EVENTS];	//�׽�������
	WORD			m_nTotalEvent;					//�����¼�����
	CImageList		*m_pImageList;					//ͼ���б����
	BOOL			m_bRuning;						//����������״̬
	HANDLE			m_hEventExit;					//�������˳��¼�

private:
	//CObList				m_UserList;					//�û�����
	//CCriticalSection	m_csList;					//�ٽ�������
};
