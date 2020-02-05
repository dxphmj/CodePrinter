// IOVsd.cpp: implementation of the CIOVsd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CodePrinter.h"
#include "IOVsd.h"
#include "MyLogCpp.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//extern CMyLogCpp g_log;//��־��¼��--by kun.zhu 20180619
CIOVsd::CIOVsd()
{
   //m_hRevTime = NULL;
   m_pSerialPort = NULL;
   m_iCommunicationStatus = VSD_CLOSE;

   m_nComIndx=0;
   m_nCurrent = 0;
   m_nDataLen = 0;
   m_nRecvSize =256;
}

CIOVsd::~CIOVsd()
{
	DWORD dwExitCode = 0;
	//if (m_pThreadRecv)
	//{
	//	if (m_pThreadRecv->m_hThread)
	//	{
	//		::SetThreadPriority(m_pThreadRecv->m_hThread, THREAD_PRIORITY_TIME_CRITICAL);//��ʱ�������ȼ����ؼ���
	//		GetExitCodeThread(m_pThreadRecv->m_hThread,&dwExitCode);
	//		if (dwExitCode == STILL_ACTIVE)
	//		{
	//			TerminateThread(m_pThreadRecv->m_hThread, 0);//ֱ����ֹ�̣߳����ᳫ����ģʽ�����߳���û�п������ڴ�
	//		}
	//		delete m_pThreadRecv;
	//		m_pThreadRecv = NULL;
	//	}
	//}
	if(m_pSerialPort)
	{
		m_pSerialPort->Close();
		delete m_pSerialPort;
		m_pSerialPort = NULL;
	}
	//CloseHandle(m_hRevTime);
}

BOOL CIOVsd::OpenComm(MyDcb dcb)//��ʼ������
{
	BOOL bRet = FALSE;
	//����Ѿ��򿪣����ش���
	if(GetCommunicationStatus() == VSD_OPEN)
		return FALSE;
	if (m_pSerialPort)
	{
		m_pSerialPort->Close();
		delete m_pSerialPort;
		m_pSerialPort = NULL;
	}
	
	m_pSerialPort = new CSTPSerialPort;
	TSTPSPInfo strPSPInfo;
	memset(&strPSPInfo,0,sizeof(TSTPSPInfo));
	strPSPInfo.nBaudRate = dcb.BaudRate;
	strPSPInfo.nPortNo   = dcb.nComPort;
	strPSPInfo.byDataBit = dcb.ByteSize;
	strPSPInfo.byStopBit = dcb.StopBits;
	strPSPInfo.byParity  = dcb.Parity;
	
	if(m_pSerialPort->Open(&strPSPInfo) == 0)//�ɹ�
	{
		m_iCommunicationStatus = VSD_OPEN;
		//m_pThreadRecv = AfxBeginThread(
		//	ThreadProc_RecvData,
		//	(LPVOID)this,
		//	THREAD_PRIORITY_NORMAL,
		//	0,
		//	CREATE_SUSPENDED
		//	);
		//ASSERT(m_pThreadRecv);
		//m_pThreadRecv->m_bAutoDelete = FALSE;
		//m_pThreadRecv->ResumeThread();
		/* ���г�ʼ�� */
		//InitMutualQueue(&queueSerial, SERIAL_QUEUE_SIZE);
		return TRUE;
	}
	else
	{
		m_pSerialPort->Close();
		delete m_pSerialPort;
		m_pSerialPort = NULL;
		m_iCommunicationStatus = VSD_CLOSE;
		return FALSE;
	}
	return bRet;
	
}
//��������
//UINT  CIOVsd::ThreadProc_RecvData(LPVOID pParam)
//{
//	CIOVsd* pTemp = (CIOVsd*)pParam;
//	if (!pTemp)
//		return 0;
//	
//	BYTE byBuffer[2048] = {0};
//	const DWORD dwLen = 2048;
//	UINT32 nDataLen = 0;
//	
//	pTemp->m_hRevTime = CreateWaitableTimer(NULL,FALSE,NULL);
//	LARGE_INTEGER li;
//	const int nTimerUnitsPerSecond = 10000000;
//	li.QuadPart = -(0.0*nTimerUnitsPerSecond);
//	SetWaitableTimer(pTemp->m_hRevTime,&li,50,NULL,NULL,FALSE);
//	
//	while (TRUE)								//while(1)��ά���豸��������,50������һ��
//	{
//		if (WaitForSingleObject(pTemp->m_hRevTime,INFINITE) != WAIT_OBJECT_0)
//		{
//			CloseHandle(pTemp->m_hRevTime);
//			break;
//		}
//		pTemp->Read();
//		
//	}
//	return 1;
//}

int CIOVsd::Read()
{
	m_pSerialPort->Receive(m_pRecvBuf,m_nRecvSize,&m_nDataLen);

	//if(nDataLen > 7)
	//{
	//	m_cRecieveInfo = "";

	//	// for(int i = 0; i < nDataLen; i++)
	//	//   TRACE("%d ",pRecvBuf[i]); 
	//	unsigned short crc = CRC16(pRecvBuf,6);
	//	unsigned short crcRecv = (pRecvBuf[6] << 8) + pRecvBuf[7];
	//	if(pRecvBuf[0] == 0x01 && pRecvBuf[1] == 0x03 && crc == crcRecv)
	//	{

	//		for(int i = 0; i < nDataLen; i++)
	//		{
	//			CString strTmp;
	//			strTmp.Format("%02X ",pRecvBuf[i]);
	//			m_cRecieveInfo += strTmp;
	//		}
	//	}
	//}
	return m_nDataLen;

}
INT CIOVsd::GetCommunicationStatus()
{
	if (!m_pSerialPort)
	{
		return m_iCommunicationStatus;
	}
	if (m_pSerialPort->IsOpened())
	{
		m_iCommunicationStatus = VSD_OPEN;
	}
	else
	{
		m_iCommunicationStatus = VSD_CLOSE;
	}
	return m_iCommunicationStatus;
}

BOOL CIOVsd::Send(LPTSTR lpszSendString, INT nszSendStringLen)
{
	//�ô��ڷ�������
    BOOL bRet = FALSE;
	UINT32 iSendLen = 0;
	if (m_pSerialPort)
		m_pSerialPort->Send((BYTE *)lpszSendString,nszSendStringLen,&iSendLen);

	BYTE bySendBuffer[1024] = {0};
	memcpy(bySendBuffer,lpszSendString,nszSendStringLen);
// 	CString csMsg = _T("");
// 	csMsg.Format("COM:%d--TX:PacketType:%d--Len:%d ",m_nComIndx,bySendBuffer[1],nszSendStringLen);
//	g_log.logFormat("COM:%d--���ٶȼ�D0:0x%x--D1:0x%x--D2:0x%x\n",m_nComIndx,bySendBuffer[2],
//		             bySendBuffer[3],bySendBuffer[4]);

	if(iSendLen == nszSendStringLen || iSendLen == _tcslen(lpszSendString))
	{
		bRet = TRUE;
	}	
	else
	{
		bRet = FALSE;
	}
	
	return bRet;
}

//���ô��ں�
void CIOVsd::SetComIndx(int nComIndx)
{
	m_nComIndx = nComIndx;
}
unsigned short CIOVsd::CRC16(unsigned char *puchMsg,unsigned short usDataLen)
{
	unsigned char uchCRCHi = 0xFF ; /* high byte of CRC initialized */
	unsigned char uchCRCLo = 0xFF ; /* low byte of CRC initialized */
	unsigned uIndex ; /* will index into CRC lookup table */
	while (usDataLen--) /* pass through message buffer */
	{
		uIndex = uchCRCHi ^ *puchMsg++ ; /* calculate the CRC */
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
		uchCRCLo = auchCRCLo[uIndex] ;
	}
	return (uchCRCHi << 8 | uchCRCLo) ;
}

void CIOVsd::ClearInOutBuf()
{
	PurgeComm(m_pSerialPort->GetHandle(), PURGE_RXCLEAR);	//��ս��ջ�����
	PurgeComm(m_pSerialPort->GetHandle(), PURGE_TXCLEAR);	//������ͻ�����
}