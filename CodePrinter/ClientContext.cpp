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
	//CancelIo((HANDLE)m_s);  //找不到
	closesocket(m_s);
	m_pServerView = NULL;
}
/*
 * 发送试卷
 */
BOOL CClientContext::AsyncSendPaper( void )
{
	/*
	DWORD	flags = 0;			//标志
	DWORD	sendBytes =0;		//发送字节数
	

	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWritePAPER;	//操作类型

	WSABUF wsaBuf[2];
	m_oIO.hdr.ustype = PAPER;						//试卷类型
	m_oIO.hdr.usLen = 0;//m_pServerView->m_usPaperLen;	//试卷长度

	wsaBuf[0].buf = (char*)&m_oIO.hdr;				//发送包头
	wsaBuf[0].len = HEADELEN;

	wsaBuf[1].buf = 0;//m_pServerView->m_cPaper;		//试卷
	wsaBuf[1].len = 0;//m_pServerView->m_usPaperLen;	//长度
	//发送数据
	if (WSASend(m_s, 
				wsaBuf,
				2, 
				&sendBytes, 
				flags,
				&m_oIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//成功发起重叠操作
		{
			return FALSE;
		}
	}	
	*/
	return TRUE;
}


/*
 * 接收数据
 */
BOOL CClientContext::AsyncRecvHead( void )
{
	DWORD	flags = 0;		//标志
	DWORD	recvBytes =0;	//发送字节数

	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	m_iIO.type = IOReadHead;//操作类型

	WSABUF wsaBuf;
	wsaBuf.buf = (char*)&m_iIO.hdr;	//接收包头
	wsaBuf.len = HEADELEN;			//长度
	
	//读取数据
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
 * 接收包头完毕处理
 */
void CClientContext::OnRecvHeadCompleted( DWORD dwIOSize )
{
	if (Command03 == m_iIO.hdr.usCommandType)	//处理 03指令
	{	
	//	m_bPulse = TRUE;					//接收到心跳包
	//	m_time = CTime::GetCurrentTime();	//时间
		AsyncRecvBody(4);					//继续接收包头
		
	}
	else if (Command04 == m_iIO.hdr.usCommandType)	//接收包体
	{
		;//AsyncRecvBody(m_iIO.hdr.usLen);
	}
}



/*
 * 发送数据完毕处理
 */
void CClientContext::OnSendCompleted( DWORD dwIOSize )
{
	//
}
/*
 * 发送验证学号失败信息
 */
BOOL CClientContext::AsyncSendFailLoginMsg( void )
{
	/*
	DWORD	flags = 0;			//标志
	DWORD	sendBytes =0;		//发送字节数
	

	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWriteUnLogin;		//操作类型

	WSABUF wsaBuf;
	m_oIO.hdr.ustype = STNAME;			//数据包类型
	m_oIO.hdr.usLen = 0;				//试卷长度0

	wsaBuf.buf = (char*)&m_oIO.hdr;		//发送包头
	wsaBuf.len = HEADELEN;

	//发送数据
	if (WSASend(m_s, 
				&wsaBuf,
				1, 
				&sendBytes, 
				flags,
				&m_oIO.overlapped,
				NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//成功发起重叠操作
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
DWORD	flags = 0;			//标志
DWORD	sendBytes = 0;		//发送字节数

ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
m_oIO.type = IOWriteInfo;					//操作类型

WSABUF wsaBuf[1];
//m_oIO.hdr.ustype = STNAME;					//包类型
//	m_oIO.hdr.usLen = 7;	//数据长度	
//发送 


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



//发送数据
if (WSASend(m_s, 
wsaBuf,
1, 
&sendBytes, 
flags,
&m_oIO.overlapped,
NULL) == SOCKET_ERROR)
{
if(ERROR_IO_PENDING != WSAGetLastError())//成功发起重叠操作
{
return FALSE;
}
}	
return TRUE;
}

*/

/*
 * 发送传感器等数据
 */
BOOL CClientContext::AsyncSendSensorInfo( void )
{
	DWORD	flags = 0;			//标志
	DWORD	sendBytes = 0;		//发送字节数
	
	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWriteInfo;					//操作类型
	
	WSABUF wsaBuf[1];	

	BYTE  bySendBuffer[17] = {0};
	bySendBuffer[0] = 0x00;
	bySendBuffer[1] = 0x00;
	bySendBuffer[2] = 0x00;
	bySendBuffer[3] = 0x00;
	bySendBuffer[4] = 0x00; //bySendBuffer[4]与 bySendBuffer[5]表示后面的字节数
	bySendBuffer[5] = 0x0B;

	bySendBuffer[6] = 0x01;
	bySendBuffer[7] = 0x03;
	bySendBuffer[8] = 0x08; //有效字节个数

	 
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

	//发送数据
	if (WSASend(m_s, 
		wsaBuf,
		1, 
		&sendBytes, 
		flags,
		&m_oIO.overlapped,
		NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//成功发起重叠操作
		{
			return FALSE;
		}
	}	
	return TRUE;
}

/*
 * 发送考生姓名
 */
BOOL CClientContext::AsyncSendStudentName( void )
{
	/*
	DWORD	flags = 0;			//标志
	DWORD	sendBytes =0;		//发送字节数
	
	ZeroMemory(&m_oIO, OVERLAPPEDPLUSLEN);
	m_oIO.type = IOWriteSTNAME;					//操作类型
	
	WSABUF wsaBuf[2];
	m_oIO.hdr.ustype = STNAME;					//包类型
	m_oIO.hdr.usLen = m_strName.GetLength();	//数据长度	
	//发送包头
	wsaBuf[0].buf = (char*)&m_oIO.hdr;				
	wsaBuf[0].len = HEADELEN;
	//包体
	wsaBuf[1].buf = (char*)(LPCSTR)m_strName;	//姓名		
	wsaBuf[1].len = m_strName.GetLength();		//长度
	
	//发送数据
	if (WSASend(m_s, 
		wsaBuf,
		2, 
		&sendBytes, 
		flags,
		&m_oIO.overlapped,
		NULL) == SOCKET_ERROR)
	{
		if(ERROR_IO_PENDING != WSAGetLastError())//成功发起重叠操作
		{
			return FALSE;
		}
	}
	*/
	return TRUE;
}



/*
 * 退出
 */
BOOL CClientContext::AsyncRecvIOOK(void) 
{
	DWORD	flags = 0;		//标志
	DWORD	recvBytes =0;	//发送字节数

	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	m_iIO.type = IOEXIT;				//读取数据

	WSABUF wsaBuf;
	wsaBuf.buf = (char*)&m_iIO.hdr;	//接收包头
	wsaBuf.len = HEADELEN;

	//读取数据
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
 * 接收包体
 */
BOOL CClientContext::AsyncRecvBody(int nLen )
{
	DWORD	flags = 0;			//标志
	DWORD	recvBytes =0;		//发送字节数
	
	ZeroMemory(&m_iIO, OVERLAPPEDPLUSLEN);
	m_iIO.type = IOReadBody;	//操作类型
	
	WSABUF wsaBuf;	
	wsaBuf.buf = m_iIO.recvBuf;	//接收包体
	wsaBuf.len = nLen;			//缓冲区长度

	//读取数据
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
 * 接收包体完成
 */
void CClientContext::OnRecvBodyCompleted( DWORD dwIOSize )
{
	//直接发送温度等信息给Scada系统
	AsyncSendSensorInfo();	 
}

void CClientContext::SaveDisConnectState( void )
{
	//m_pServerView->UpdateStudentState(m_nStdSN, DISCON);
}