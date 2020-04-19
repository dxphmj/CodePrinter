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
	vector<CString> Split(CString source, CString division);	//分割cstring
	//BOOL 	Send(const u_short type, const CString &strData);	//发送数据
	BOOL 	Send(const u_short type,const BYTE* sendData, int sentLen);	//发送数据
	BOOL	Recv(void);											//接收数据
	//void	SaveUserInfo(const CUserInfo &userInfo);			//保存用户信息
	static DWORD WINAPI SendThread(void *pParam);//发送线程函数
	HANDLE			m_hThreadSend;	//服务线程句柄
public:
	SOCKET		m_s;		//套接字
	WSAEVENT	m_hEvent;	//事件对象句柄
	//CUserInfo	m_UserInfo;	//用户信息
	bool            m_clientLive;               //是否活着
	string			lab_name;
private:
	CClientSocket();
private:
	CCodePrinterDlg	*m_pServDlg;//CServerDlg指针
};

#endif // !defined(AFX_CLIENTSOCKET_H__2E836D50_8979_42C9_9E9D_9F3DAE358C4F__INCLUDED_)
