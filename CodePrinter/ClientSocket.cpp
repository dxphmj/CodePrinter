// ClientSocket.cpp: implementation of the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CodePrinter.h"
#include "ClientSocket.h"
#include "CodePrinterDlg.h"
#include <algorithm>
#include <fstream>
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
			//CString str ;
			//for (int i=0;i<nReadLen;i++)
			//{
			//	CString temp;
			//	temp.Format(_T("%d"),mybyte[i]);
			//	str=str+temp;
			//}
			switch(mybyte[0])
			{
			case 0:
				m_pServDlg->m_OnOff->OnBnClickedSequenceButton();
				break;
			case 1:
				m_pServDlg->m_OnOff->OnBnClickedFastButton();
				break;
			case 2:
				m_pServDlg->OnBnClickedStartprintButton();
				break;
			case 4:
				m_pServDlg->OnBnClickedPauseprintButton();
				break;
			default:
				break;
			}
			
		}
		else if(packetHdr.type == PRINT_CE)
		{
			const int bufferSize = 1024;
			char buffer[bufferSize] = {0};
			int readLen = 0;
			string desFileName = "Storage Card\\User\\Label\\"+lab_name;
			ofstream desFile;
			desFile.open(desFileName.c_str(), ios::binary|ios::app);
			if (!desFile)
			{
				return FALSE;
			}

			readLen = recv(m_s,buffer,packetHdr.len, 0);
			if (SOCKET_ERROR == readLen)
			{
				if (WSAEWOULDBLOCK == WSAGetLastError())
				{
					return TRUE;
				}
				return FALSE;
			}
			else
			{
				desFile.write(buffer, readLen);
			}

			desFile.close();
			theApp.m_MessageEdit.ReadObjectsFromXml(const_cast<char*>(desFileName.c_str()));
			m_pServDlg->m_Label->OnBnClickedDownloadButton();
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
		else if(packetHdr.type == LAB_NAME)
		{
			char *mybyte=new char[packetHdr.len];
			int nReadLen = recv(m_s, mybyte, packetHdr.len,0);
			if (SOCKET_ERROR == nReadLen)
			{
				if (WSAEWOULDBLOCK == WSAGetLastError())
				{
					return TRUE;
				}
				return FALSE;
			}
			CString tempCstr=theApp.myModuleMain.Utf8ToUnicode_CSTR(mybyte);
			lab_name=theApp.myModuleMain.CString2string(tempCstr);
			string desFileName = "Storage Card\\User\\Label\\"+lab_name;
			ofstream desFile;
			desFile.open(desFileName.c_str(), ios::binary|ios::trunc);
			desFile.close();
			delete []mybyte;
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
	int printTimes = 0;
	while (pClientS->m_clientLive)
	{
		if (theApp.sendCodeque.size()>0)//有打印数据
		{
			vector<BYTE> tempVec;
			theApp.boSendCodeLock.Lock();
			tempVec=theApp.sendCodeque.front();
			theApp.sendCodeque.pop();
			theApp.boSendCodeLock.Unlock();
			BYTE* tempByte=new BYTE[tempVec.size()];

			copy(tempVec.begin(), tempVec.end(), tempByte);
			pClientS->Send(PRINTGET_CE,tempByte,tempVec.size());
			printTimes++;
			Sleep(10);
			if (printTimes>10)
			{
				pClientS->Send(COLLECT_CE,theApp.bytStatus,37);
				printTimes=0;
				Sleep(10);
				if (theApp.sendCounter.size()>0)
				{
					BYTE* intByte=new BYTE[theApp.sendCounter.size()*4];
					pClientS->intTobyte(intByte);
					pClientS->Send(COUNTER_CE,intByte,theApp.sendCounter.size()*4);
					Sleep(10);
				}
			}
			continue;
		}
		else
		{
			printTimes=0;
			//test
			BYTE testbyte[37];
			for (int i=0;i<37;i++)
			{
				int m_nTemp = rand() % 100;
				testbyte[i]=m_nTemp;
			}
			pClientS->Send(COLLECT_CE,testbyte,37);
			Sleep(1000);
			if (theApp.sendCounter.size()>0)
			{
				BYTE* intByte=new BYTE[theApp.sendCounter.size()*4];
				pClientS->intTobyte(intByte);
				pClientS->Send(COUNTER_CE,intByte,theApp.sendCounter.size()*4);
				Sleep(10);
			}
			//实际用
			//pClientS->Send(COLLECT_CE,theApp.bytStatus,37);
			//if (theApp.m_MessagePrint.boDynamic)
			//{
			//	Sleep(100);
			//}
			//else
			//{
			//	Sleep(1000);
			//}
			
		}

	}
	return 0;
}

void CClientSocket::intTobyte(BYTE* outbyte)
{
	for (int i=0;i<theApp.sendCounter.size();i++)
	{
		outbyte[4*i] = (byte)(theApp.sendCounter[i]);
		outbyte[4*i+1] = (byte)(theApp.sendCounter[i] >> 8);
		outbyte[4*i+2] = (byte)(theApp.sendCounter[i] >> 16);
		outbyte[4*i+3] = (byte)(theApp.sendCounter[i] >> 24);
	}
	
}

vector<CString> CClientSocket::Split(CString source, CString division)
{
	//dest.RemoveAll();
	vector<CString> rtVec;
	int pos = 0;
	int pre_pos = 0;
	while( -1 != pos ){
		pre_pos = pos;
		pos = source.Find(division,(pos+1));
		rtVec.push_back(source.Mid(pre_pos,(pos-pre_pos)));
	}
	return rtVec;
}