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
		//CString	strUserInfo;			//�û���Ϣ
		//int	nTotalLen = 0;				//�Ѿ���ȡ�ַ�����
		//int	nDataLen = packetHdr.len;	//���ݳ���
		//int	nReadLen = 0;				//ÿ�ζ�ȡ�ַ����� 
		//while ( nTotalLen != nDataLen )
		//{		
		//	char cRecv;								//�����ַ�
		//	nReadLen = recv(m_s, &cRecv, 1,0);		//ÿ�ν���һ���ַ�
		//	if (SOCKET_ERROR == nReadLen)			//�������
		//	{
		//		if (WSAEWOULDBLOCK == WSAGetLastError())
		//		{
		//			continue;
		//		}
		//		AfxMessageBox(_T("��ȡ�ͻ�������ʧ�ܣ�"));
		//		reVal = FALSE;
		//	}else if (0 == nReadLen)
		//	{
		//		AfxMessageBox(_T("�ͻ��˹ر������ӣ�"));
		//		reVal = FALSE;
		//	}else if (nReadLen > 0)
		//	{
		//		if ('<' == cRecv)			//��ʼ�ַ�
		//		{				
		//			strUserInfo.Empty();
		//			
		//		}else if ('>' == cRecv)		//�����ַ�
		//		{					
		//			break;
		//		}else
		//		{
		//			strUserInfo += cRecv;	//����ַ�
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
			//str.Format(_T(��%d��), i);
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