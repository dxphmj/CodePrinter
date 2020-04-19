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
	closesocket(m_s);					//�ر��׽���
	WSAEventSelect(m_s, m_hEvent, 0);	//ȡ�������¼�
	WSACloseEvent(m_hEvent);			//�ͷ��¼�����
}

/*
 * ��������
 */
BOOL CClientSocket::Recv( void )
{
	int reVal;							//����ֵ
	WSAEventSelect(m_s, m_hEvent, 0);	//ȡ�������¼�

	//��ȡ���ݰ���ĳ���
	PACKETHDR packetHdr;			
	reVal = recv(m_s, (char*)&packetHdr, PACKETHDRLEN, 0);
	
	if ( 0 == reVal)
	{
		return FALSE;
	}else if (SOCKET_ERROR == reVal)//�������
	{
		int nErrCode = WSAGetLastError();
		if (WSAEWOULDBLOCK == nErrCode)
		{
			return TRUE;
		}
		AfxMessageBox(_T("�����û��б����"));
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

		//ע�������¼�
		WSAEventSelect(m_s, m_hEvent, FD_READ|FD_CLOSE);

		//test
		//Send(SERVMESSAGE,_T("�Ҽ�"));
		//�����û��б�
		//return (m_pServDlg->UpdateUserList(strUserInfo, this));
	}
	
	return TRUE;
}

/*
 * ��������
 */
BOOL CClientSocket::Send(const u_short type,const BYTE* sendData, int sentLen)
{
	//ASSERT(sentLen==0);
	DWORD	dwNumberOfBytesSent;	//���������ֽ��� 
	DWORD	dwFlags = 0;			//��־
	int			nErrCode;				//����ֵ	
	PACKETHDR	packetHdr;				//�����ͷ

	packetHdr.type = type;				//����
	packetHdr.len = sentLen;//���ݳ���
	WSABUF wsaSendBuf[2];
	wsaSendBuf[0].buf = (char*)&packetHdr;	//��ͷ������
	wsaSendBuf[0].len = 4;		//��ͷ����������
	//byte testss=1;

	wsaSendBuf[1].buf = (CHAR*)sendData;	//����
	wsaSendBuf[1].len = sentLen;		//���ݳ���

	nErrCode = WSASend(m_s,							//��������
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
			AfxMessageBox(_T("WSASend��������ʧ�ܣ�"));
			return FALSE;
		}
	}
	//���Ͱ�ͷ
	//nErrCode = send(m_s, (char*)&packetHdr, PACKETHDRLEN, 0);
	//if (SOCKET_ERROR == nErrCode)
	//{
	//	AfxMessageBox(_T("�����û��б����"));
	//	return FALSE;
	//}
	////���Ͱ���
	//nErrCode = send(m_s, (char*)sendData, packetHdr.len, 0);
	//if (SOCKET_ERROR == nErrCode)
	//{
	//	AfxMessageBox(_T("�����û��б����"));
	//	return FALSE;
	//}
	return TRUE;	
}



DWORD WINAPI CClientSocket::SendThread( void *pParam )
{
	PTHECLIENT	pThreadParam = (PTHECLIENT)pParam;
	CClientSocket		*pClientS = pThreadParam->pClient;	//CClientSocket��ָ��
	int printTimes = 0;
	while (pClientS->m_clientLive)
	{
		if (theApp.sendCodeque.size()>0)//�д�ӡ����
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
			//ʵ����
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