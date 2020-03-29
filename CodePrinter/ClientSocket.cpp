// ClientSocket.cpp: implementation of the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CodePrinter.h"
#include "ClientSocket.h"
#include "CodePrinterDlg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/*
 * 
 */
CClientSocket::CClientSocket(CCodePrinterDlg *pServDlg, SOCKET s , WSAEVENT hEvent)
{
	m_pServDlg = pServDlg;
	m_s = s;
	m_hEvent = hEvent;
}

/*
 * 
 */
CClientSocket::~CClientSocket()
{
	m_clientLive=false;
	closesocket(m_s);					//关闭套接字
	WSAEventSelect(m_s, m_hEvent, 0);	//取消网络事件
	WSACloseEvent(m_hEvent);			//释放事件对象
}

/*
 * 接收数据
 */
BOOL CClientSocket::Recv( void )
{
	int reVal;							//返回值
	WSAEventSelect(m_s, m_hEvent, 0);	//取消网络事件

	//获取数据包体的长度
	PACKETHDR packetHdr;			
	reVal = recv(m_s, (char*)&packetHdr, PACKETHDRLEN, 0);
	
	if ( 0 == reVal)
	{
		return FALSE;
	}else if (SOCKET_ERROR == reVal)//网络错误
	{
		int nErrCode = WSAGetLastError();
		if (WSAEWOULDBLOCK == nErrCode)
		{
			return TRUE;
		}
		AfxMessageBox(_T("接收用户列表错误！"));
		return FALSE;
	}else
	{
		//CString	strUserInfo;			//用户信息
		//int	nTotalLen = 0;				//已经读取字符数量
		//int	nDataLen = packetHdr.len;	//数据长度
		//int	nReadLen = 0;				//每次读取字符数量 
		//while ( nTotalLen != nDataLen )
		//{		
		//	char cRecv;								//接收字符
		//	nReadLen = recv(m_s, &cRecv, 1,0);		//每次接收一个字符
		//	if (SOCKET_ERROR == nReadLen)			//网络错误
		//	{
		//		if (WSAEWOULDBLOCK == WSAGetLastError())
		//		{
		//			continue;
		//		}
		//		AfxMessageBox(_T("读取客户端数据失败！"));
		//		reVal = FALSE;
		//	}else if (0 == nReadLen)
		//	{
		//		AfxMessageBox(_T("客户端关闭了连接！"));
		//		reVal = FALSE;
		//	}else if (nReadLen > 0)
		//	{
		//		if ('<' == cRecv)			//开始字符
		//		{				
		//			strUserInfo.Empty();
		//			
		//		}else if ('>' == cRecv)		//结束字符
		//		{					
		//			break;
		//		}else
		//		{
		//			strUserInfo += cRecv;	//添加字符
		//		}			
		//		nTotalLen += nReadLen;
		//	}		
		//}
		if (packetHdr.type == CONTROL_CE)
		{
			byte *mybyte=new byte[packetHdr.len];
			int nReadLen = recv(m_s, (char*)mybyte, packetHdr.len,0);
			if (SOCKET_ERROR == nReadLen)
			{
				if (WSAEWOULDBLOCK == WSAGetLastError())
				{
					return TRUE;
				}
				return FALSE;
			}
			CString str ;
			for (int i=0;i<nReadLen;i++)
			{
				CString temp;
				temp.Format(_T("%d"),mybyte[i]);
				str=str+temp;
			}
			//str.Format(_T(“%d”), i);
			//CString temp1,temp2;
			//temp1.Format(_T("%d"),packetHdr.type);
			//temp1.Format(_T("%d"),packetHdr.len);
			//AfxMessageBox(str);
		}
		else if(packetHdr.type == PRINT_CE)
		{

		}
		else if(packetHdr.type == COLLECT_CE)
		{
			byte *mybyte=new byte[packetHdr.len];
			int nReadLen = recv(m_s, (char*)mybyte, packetHdr.len,0);
			if (SOCKET_ERROR == nReadLen)
			{
				if (WSAEWOULDBLOCK == WSAGetLastError())
				{
					return TRUE;
				}
				return FALSE;
			}

			m_clientLive=true;
			PTHECLIENT pParam = new THECLIENT;
			//pParam->hServHwnd = this->GetSafeHwnd();
			pParam->pClient = this;
			DWORD dwThreadId;
			m_hThreadSend = CreateThread(NULL, 0, SendThread, pParam, 0, &dwThreadId);
		}
		else if(packetHdr.type == OTHER_CE)
		{

		}

		//注册网络事件
		WSAEventSelect(m_s, m_hEvent, FD_READ|FD_CLOSE);

		//test
		//Send(SERVMESSAGE,_T("我家"));
		//更新用户列表
		//return (m_pServDlg->UpdateUserList(strUserInfo, this));
	}
	
	return TRUE;
}

/*
 * 发送数据
 */
BOOL CClientSocket::Send(const u_short type,const BYTE* sendData, int sentLen)
{
	//ASSERT(sentLen==0);
	DWORD	dwNumberOfBytesSent;	//发送数据字节数 
	DWORD	dwFlags = 0;			//标志
	int			nErrCode;				//返回值	
	PACKETHDR	packetHdr;				//定义包头

	packetHdr.type = type;				//类型
	packetHdr.len = sentLen;//数据长度
	WSABUF wsaSendBuf[2];
	wsaSendBuf[0].buf = (char*)&packetHdr;	//包头缓冲区
	wsaSendBuf[0].len = 4;		//包头缓冲区长度
	//byte testss=1;

	wsaSendBuf[1].buf = (CHAR*)sendData;	//包体
	wsaSendBuf[1].len = sentLen;		//数据长度

	nErrCode = WSASend(m_s,							//发送数据
		wsaSendBuf,
		2,
		&dwNumberOfBytesSent,
		dwFlags,
		NULL,
		NULL);
	if (SOCKET_ERROR == nErrCode)
	{
		if (WSA_IO_PENDING == WSAGetLastError())
		{
			return TRUE;
		}else
		{
			AfxMessageBox(_T("WSASend函数调用失败！"));
			return FALSE;
		}
	}
	//发送包头
	//nErrCode = send(m_s, (char*)&packetHdr, PACKETHDRLEN, 0);
	//if (SOCKET_ERROR == nErrCode)
	//{
	//	AfxMessageBox(_T("发送用户列表错误！"));
	//	return FALSE;
	//}
	////发送包体
	//nErrCode = send(m_s, (char*)sendData, packetHdr.len, 0);
	//if (SOCKET_ERROR == nErrCode)
	//{
	//	AfxMessageBox(_T("发送用户列表错误！"));
	//	return FALSE;
	//}
	return TRUE;	
}



DWORD WINAPI CClientSocket::SendThread( void *pParam )
{
	PTHECLIENT	pThreadParam = (PTHECLIENT)pParam;
	CClientSocket		*pClientS = pThreadParam->pClient;	//CClientSocket类指针
	while (pClientS->m_clientLive)
	{
		int printTimes = 0;
		if (theApp.myStatusClass.ctr0X03bit0 == 1 && theApp.myStatusClass.staSysRea == true)
		{
			if (theApp.m_MessagePrint.boDynamic)
			{

			}
			else
			{
				Sleep(100);
				//continue;
			}
		}
		else
		{
			//pClientS->Send(COLLECT_CE,theApp.bytStatus,37);
			//test
			//BYTE* testbyte=new BYTE[37];
			BYTE testbyte[37];
			for (int i=0;i<37;i++)
			{
				int m_nTemp = rand() % 100;
				testbyte[i]=m_nTemp;
			}
			pClientS->Send(COLLECT_CE,testbyte,37);
			//delete []testbyte;
			Sleep(10);
		}

	}
	return 0;
}