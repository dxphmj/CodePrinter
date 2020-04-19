// ClientSocket.h: interface for the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSOCKET_H__2E836D50_8979_42C9_9E9D_9F3DAE358C4F__INCLUDED_)
#define AFX_CLIENTSOCKET_H__2E836D50_8979_42C9_9E9D_9F3DAE358C4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "UserInfo.h"

class CCodePrinterDlg;


class CClientSocket : public CObject  
{
public:
	CClientSocket(CCodePrinterDlg *pServDlg, SOCKET s, WSAEVENT hEvent);
	virtual ~CClientSocket();

public:
	void intTobyte(BYTE* outbyte);
	vector<CString> Split(CString source, CString division);	//�ָ�cstring
	//BOOL 	Send(const u_short type, const CString &strData);	//��������
	BOOL 	Send(const u_short type,const BYTE* sendData, int sentLen);	//��������
	BOOL	Recv(void);											//��������
	//void	SaveUserInfo(const CUserInfo &userInfo);			//�����û���Ϣ
	static DWORD WINAPI SendThread(void *pParam);//�����̺߳���
	HANDLE			m_hThreadSend;	//�����߳̾��
public:
	SOCKET		m_s;		//�׽���
	WSAEVENT	m_hEvent;	//�¼�������
	//CUserInfo	m_UserInfo;	//�û���Ϣ
	bool            m_clientLive;               //�Ƿ����
	string			lab_name;
private:
	CClientSocket();
private:
	CCodePrinterDlg	*m_pServDlg;//CServerDlgָ��
};

#endif // !defined(AFX_CLIENTSOCKET_H__2E836D50_8979_42C9_9E9D_9F3DAE358C4F__INCLUDED_)
