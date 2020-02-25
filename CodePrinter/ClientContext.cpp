// ClientContext.cpp: implementation of the CClientContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "CodePrinterDlg.h"
#include "ClientContext.h"
#include "IOVsd.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
 
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientContext::CClientContext(SOCKET s, CCodePrinterDlg* pServView)
:m_s(s),
m_eState(CClientContext::UNKNOWN),
m_pServerView(pServView),
m_nGrade(-1),
m_bPulse(FALSE)

{
	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);

}

CClientContext::~CClientContext()
{
	//CancelIo((HANDLE)m_s);  //�Ҳ���
	closesocket(m_s);
	m_pServerView = NULL;
}
/*
 * �����Ծ�
 */
BOOL CClientContext::AsyncSendPaper( void )
{
	/*
	DWORD	flags = 0;			//��־
	DWORD	sendBytes =0;		//�����ֽ���
	

	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWritePAPER;	//��������

	WSABUF wsaBuf[2];
	m_oIO.hdr.ustype = PAPER;						//�Ծ�����
	m_oIO.hdr.usLen = 0;//m_pServerView->m_usPaperLen;	//�Ծ���

	wsaBuf[0].buf = (char*)&m_oIO.hdr;				//���Ͱ�ͷ
	wsaBuf[0].len = HEADELEN;

	wsaBuf[1].buf = 0;//m_pServerView->m_cPaper;		//�Ծ�
	wsaBuf[1].len = 0;//m_pServerView->m_usPaperLen;	//����
	//��������
	if (WSASend(m_s, 
				wsaBuf,
				2, 
				&sendBytes, 
				flags,
				&m_oIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//�ɹ������ص�����
		{
			return FALSE;
		}
	}	
	*/
	return TRUE;
}


/*
 * ��������
 */
BOOL CClientContext::AsyncRecvHead( void )
{
	DWORD	flags = 0;		//��־
	DWORD	recvBytes =0;	//�����ֽ���

	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	m_iIO.type = IOReadHead;//��������

	WSABUF wsaBuf;
	wsaBuf.buf = (char*)&m_iIO.hdr;	//���հ�ͷ
	wsaBuf.len = HEADELEN;			//����
	
	//��ȡ����
	if (WSARecv(m_s, 
				&wsaBuf,
				1, 
				&recvBytes, 
				&flags,
				&m_iIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())
		{
			return FALSE;
		}
	}	
	return TRUE;	
}

/*
 * ���հ�ͷ��ϴ���
 */
void CClientContext::OnRecvHeadCompleted( DWORD dwIOSize )
{
	if (Command03 == m_iIO.hdr.usCommandType)	//���� 03ָ��
	{	
	//	m_bPulse = TRUE;					//���յ�������
	//	m_time = CTime::GetCurrentTime();	//ʱ��
		AsyncRecvBody(4);					//�������հ�ͷ
		
	}
	else if (Command04 == m_iIO.hdr.usCommandType)	//���հ���
	{
		;//AsyncRecvBody(m_iIO.hdr.usLen);
	}
}



/*
 * ����������ϴ���
 */
void CClientContext::OnSendCompleted( DWORD dwIOSize )
{
	//
}
/*
 * ������֤ѧ��ʧ����Ϣ
 */
BOOL CClientContext::AsyncSendFailLoginMsg( void )
{
	/*
	DWORD	flags = 0;			//��־
	DWORD	sendBytes =0;		//�����ֽ���
	

	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWriteUnLogin;		//��������

	WSABUF wsaBuf;
	m_oIO.hdr.ustype = STNAME;			//���ݰ�����
	m_oIO.hdr.usLen = 0;				//�Ծ���0

	wsaBuf.buf = (char*)&m_oIO.hdr;		//���Ͱ�ͷ
	wsaBuf.len = HEADELEN;

	//��������
	if (WSASend(m_s, 
				&wsaBuf,
				1, 
				&sendBytes, 
				flags,
				&m_oIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//�ɹ������ص�����
		{
			return FALSE;
		}
	}
	*/
	return TRUE;
}

unsigned short myCRC16(unsigned char *puchMsg,unsigned short usDataLen)
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

/*
BOOL CClientContext::AsyncSendSensorInfo( void )
{
DWORD	flags = 0;			//��־
DWORD	sendBytes = 0;		//�����ֽ���

ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
m_oIO.type = IOWriteInfo;					//��������

WSABUF wsaBuf[1];
//m_oIO.hdr.ustype = STNAME;					//������
//	m_oIO.hdr.usLen = 7;	//���ݳ���	
//���� 


BYTE  bySendBuffer[13] = {0};
bySendBuffer[0] = 0x00;
bySendBuffer[1] = 0x00;
bySendBuffer[2] = 0x00;
bySendBuffer[3] = 0x00;
bySendBuffer[4] = 0x00;
bySendBuffer[5] = 0x06;


bySendBuffer[0] = 0x01;
bySendBuffer[1] = 0x03;
bySendBuffer[2] = 0x04;

bySendBuffer[3] = 0x00;
bySendBuffer[4] = 0x17;

bySendBuffer[5] = 0x00;
bySendBuffer[6] = 0x17;

//unsigned short crc = myCRC16(bySendBuffer,7);

//bySendBuffer[7] = crc >> 8;
//bySendBuffer[8] = crc & 0x00FF;

wsaBuf[0].buf = (char*)bySendBuffer;				
wsaBuf[0].len = 13;



//��������
if (WSASend(m_s, 
wsaBuf,
1, 
&sendBytes, 
flags,
&m_oIO.overlapped,
NULL) == SOCKET_ERROR)
{
if(ERROR_IO_PENDING != WSAGetLastError())//�ɹ������ص�����
{
return FALSE;
}
}	
return TRUE;
}

*/

/*
 * ���ʹ�����������
 */
BOOL CClientContext::AsyncSendSensorInfo( void )
{
	DWORD	flags = 0;			//��־
	DWORD	sendBytes = 0;		//�����ֽ���
	
	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWriteInfo;					//��������
	
	WSABUF wsaBuf[1];	

	BYTE  bySendBuffer[17] = {0};
	bySendBuffer[0] = 0x00;
	bySendBuffer[1] = 0x00;
	bySendBuffer[2] = 0x00;
	bySendBuffer[3] = 0x00;
	bySendBuffer[4] = 0x00; //bySendBuffer[4]�� bySendBuffer[5]��ʾ������ֽ���
	bySendBuffer[5] = 0x0B;

	bySendBuffer[6] = 0x01;
	bySendBuffer[7] = 0x03;
	bySendBuffer[8] = 0x08; //��Ч�ֽڸ���

	 
	int nTemp = m_strSendData.m_dTemp*100;
	bySendBuffer[9] = nTemp>>8;
	bySendBuffer[10] = nTemp&0x00FF;

	bySendBuffer[11] = m_strSendData.m_nSpeedTheory>>8;
	bySendBuffer[12] = m_strSendData.m_nSpeedTheory&0x00FF;

	bySendBuffer[13] = m_strSendData.m_nFrictionSensor>>8;
	bySendBuffer[14] = m_strSendData.m_nFrictionSensor&0x00FF;


	bySendBuffer[15] = m_strSendData.m_nStrainSensor>>8;
	bySendBuffer[16] = m_strSendData.m_nStrainSensor&0x00FF;

	wsaBuf[0].buf = (char*)bySendBuffer;				
	wsaBuf[0].len = 17;

	//��������
	if (WSASend(m_s, 
		wsaBuf,
		1, 
		&sendBytes, 
		flags,
		&m_oIO.overlapped,
		NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//�ɹ������ص�����
		{
			return FALSE;
		}
	}	
	return TRUE;
}

/*
 * ���Ϳ�������
 */
BOOL CClientContext::AsyncSendStudentName( void )
{
	/*
	DWORD	flags = 0;			//��־
	DWORD	sendBytes =0;		//�����ֽ���
	
	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWriteSTNAME;					//��������
	
	WSABUF wsaBuf[2];
	m_oIO.hdr.ustype = STNAME;					//������
	m_oIO.hdr.usLen = m_strName.GetLength();	//���ݳ���	
	//���Ͱ�ͷ
	wsaBuf[0].buf = (char*)&m_oIO.hdr;				
	wsaBuf[0].len = HEADELEN;
	//����
	wsaBuf[1].buf = (char*)(LPCSTR)m_strName;	//����		
	wsaBuf[1].len = m_strName.GetLength();		//����
	
	//��������
	if (WSASend(m_s, 
		wsaBuf,
		2, 
		&sendBytes, 
		flags,
		&m_oIO.overlapped,
		NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//�ɹ������ص�����
		{
			return FALSE;
		}
	}
	*/
	return TRUE;
}



/*
 * �˳�
 */
BOOL CClientContext::AsyncRecvIOOK(void) 
{
	DWORD	flags = 0;		//��־
	DWORD	recvBytes =0;	//�����ֽ���

	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	m_iIO.type = IOEXIT;				//��ȡ����

	WSABUF wsaBuf;
	wsaBuf.buf = (char*)&m_iIO.hdr;	//���հ�ͷ
	wsaBuf.len = HEADELEN;

	//��ȡ����
	if (WSARecv(m_s, 
				&wsaBuf,
				1, 
				&recvBytes, 
				&flags,
				&m_iIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())
		{
			return FALSE;
		}
	}	
	return TRUE;	
}

/*
 * ���հ���
 */
BOOL CClientContext::AsyncRecvBody(int nLen )
{
	DWORD	flags = 0;			//��־
	DWORD	recvBytes =0;		//�����ֽ���
	
	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	m_iIO.type = IOReadBody;	//��������
	
	WSABUF wsaBuf;	
	wsaBuf.buf = m_iIO.recvBuf;	//���հ���
	wsaBuf.len = nLen;			//����������

	//��ȡ����
	if (WSARecv(m_s, 
				&wsaBuf,
				1, 
				&recvBytes, 
				&flags,
				&m_iIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())
		{
			return FALSE;
		}
	}	
	return TRUE;	
}

/*
 * ���հ������
 */
void CClientContext::OnRecvBodyCompleted( DWORD dwIOSize )
{
	//ֱ�ӷ����¶ȵ���Ϣ��Scadaϵͳ
	AsyncSendSensorInfo();	 
}

void CClientContext::SaveDisConnectState( void )
{
	//m_pServerView->UpdateStudentState(m_nStdSN, DISCON);
}