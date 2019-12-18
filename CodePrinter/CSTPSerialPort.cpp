/**********************************************************************************************
*@FileName:CSTPSerialPort.cpp
*@Author:chengyuanjun
*@Date:2013-06-12 09:55:08
*@Copyright: 2012-2014 TCT Incorporated 
*@Desp:本文件实现了对串口的基本管理
*@Revision:
*@Date		@Author			@Content
*	
***********************************************************************************************/

/*****************************************************************
*@Head Files Of Lib---系统头文件
*****************************************************************/
#include "StdAfx.h"

/*****************************************************************
*@Head Files Of User---用户自定义头文件
*****************************************************************/
#include "CSTPSerialPort.h"


/*****************************************************************
*@Global Var---全局变量定义
*****************************************************************/


/*****************************************************************
*@Macro Definition---宏定义
*****************************************************************/


/*****************************************************************
*@Struct Definition---结构体定义
*****************************************************************/

/*****************************************************************
*@Function Definition---静态成员函数定义
*****************************************************************/


/*****************************************************************
*@Function Definition---成员函数定义
*****************************************************************/

//==============================================================================================
//函 数 名:CSTPSerialPort
//函数参数:无
//返 回 值:无
//功能描述:构造函数
//==============================================================================================
CSTPSerialPort::CSTPSerialPort()
{
	m_bOpenFlag = FALSE;
	memset(&m_stPortInfo, 0x00, sizeof(TSTPSPInfo));
	
	return;
}
//==============================================================================================
//函 数 名:~CSTPSerialPort
//函数参数:无
//返 回 值:无
//功能描述:析构函数
//==============================================================================================
CSTPSerialPort::~CSTPSerialPort()
{
	if (m_bOpenFlag)
	{
		Close();
		m_bOpenFlag = FALSE;
	}
	
	return;
}
//==============================================================================================
//函 数 名:Open
//函数参数:nPortNo:端口号;nBaudRate:波特率;byDataBit:数据位;byStopBit:停止位;byParity:校验类型
//返 回 值:0:成功;其他值:失败
//功能描述:打开串口
//==============================================================================================
int CSTPSerialPort::Open(UINT32 nPortNo, UINT32 nBaudRate, BYTE byDataBit, BYTE byStopBit, BYTE byParity)
{
	CHAR szPort[16];
	DCB dcb;	//设备控制块

	//------------------------------------------------------------
    //检查串口是否已经打开
	if (m_bOpenFlag) 
	{
		return 0;
	}

	//------------------------------------------------------------
	//保存串口参数
	m_stPortInfo.nPortNo = nPortNo;
	m_stPortInfo.nBaudRate = nBaudRate;
	m_stPortInfo.byDataBit = byDataBit;
	m_stPortInfo.byStopBit = byStopBit;
	m_stPortInfo.byParity = byParity;
	
	//------------------------------------------------------------
	//对串口名称进行格式化
	memset(szPort, 0x00, sizeof(szPort));
//	wsprintf(szPort, "\\\\.\\COM%d", nPortNo);
	sprintf(szPort, "COM%d:", nPortNo);//////////////gai
	
	//------------------------------------------------------------
	//打开指定串口

	USES_CONVERSION;  
    
	m_hCOM = CreateFile(A2W(szPort),								/*串口名称*/
							GENERIC_READ | GENERIC_WRITE,	/*对该串口拥有读写权限*/
							0,								/*串口打开成功后，二次打开会失败*/
							NULL,							/*安全属性*/
							OPEN_EXISTING,					/*串口属已存在设备*/
							//FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //////////gai
							0,
							NULL);
	if (INVALID_HANDLE_VALUE == m_hCOM)
	{ 
		return -1;
	}
		
	//------------------------------------------------------------
	//串口超时参数设置
	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;	//两字符之间最大的延迟
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = 0;
	SetCommTimeouts(m_hCOM, &CommTimeOuts);
	
	//------------------------------------------------------------
	//串口配置
	dcb.DCBlength = sizeof(DCB);
	GetCommState(m_hCOM, &dcb);//获取串行口的当前配置
	dcb.BaudRate = nBaudRate;
	dcb.ByteSize = byDataBit;	//数据位
	dcb.StopBits = byStopBit;	//停止位
	dcb.Parity = byParity;		//校验位
	dcb.fParity = 1;
	
	//对配置进行修改，并且指定发送和接收缓冲区的大小，如果失败则关闭串口
	if(!SetCommState(m_hCOM, &dcb) )    //   || !SetupComm(m_hCOM, 10, 10)   设置缓存区失败
	{
		CloseHandle(m_hCOM);
		return -1;
	}
	
	//------------------------------------------------------------
	//串口读写事件
	memset(&m_OverlappedRead, 0, sizeof(OVERLAPPED));
	memset(&m_OverlappedWrite, 0, sizeof(OVERLAPPED));	
	m_OverlappedRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (m_OverlappedRead.hEvent == NULL)
	{
		CloseHandle(m_hCOM);
		return -1;
	}
	m_OverlappedWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (m_OverlappedWrite.hEvent == NULL)
	{
		CloseHandle(m_hCOM);
		CloseHandle(m_OverlappedRead.hEvent);
		return -1;
	}

	PurgeComm(m_hCOM, PURGE_RXCLEAR);
	PurgeComm(m_hCOM, PURGE_TXCLEAR);
	m_bOpenFlag = TRUE;//串口已打开

	return 0;
}
//==============================================================================================
//函 数 名:Open
//函数参数:pSPInfo:指向串口信息的结构体指针
//返 回 值:0:成功;其他值:失败
//功能描述:打开串口
//==============================================================================================
int CSTPSerialPort::Open(TSTPSPInfo* pSPInfo)
{
	if (pSPInfo)
	{
		return Open(pSPInfo->nPortNo, pSPInfo->nBaudRate, pSPInfo->byDataBit, pSPInfo->byStopBit, pSPInfo->byParity);
	}

	return -1;
}
//==============================================================================================
//函 数 名:Close
//函数参数:无
//返 回 值:预留:默认返回0
//功能描述:关闭串口
//==============================================================================================
int CSTPSerialPort::Close()
{	
	if (!IsOpened())
	{
		return 0;
	}
	
	if(NULL != m_OverlappedRead.hEvent) 
	{
		CloseHandle(m_OverlappedRead.hEvent);
	}
	
	if(NULL != m_OverlappedWrite.hEvent)
	{ 
		CloseHandle(m_OverlappedWrite.hEvent);
	}
	
	CloseHandle(m_hCOM);

	m_bOpenFlag = FALSE;

	return 0;
}
//==============================================================================================
//函 数 名:Send
//函数参数:pSendBuf:指向发送数据的结构体的指针;nToSndLen:发送数据的长度;pSendLen:实际发送的数据的长度
//返 回 值:
//功能描述:发送数据
//==============================================================================================
int CSTPSerialPort::Send(BYTE* pSendBuf, UINT32 nToSndLen, UINT32* pSendLen)
{
	BOOL bReturnValue = FALSE;
	DWORD dwBytesWritten = 0;
	DWORD dwTimeOut = (DWORD)(((nToSndLen * 8) * 1.0 ) / (m_stPortInfo.nBaudRate * 1.0) * 1000 * 3);

	//------------------------------------------------------------
	//检查要发送的数据是否有效
	if (pSendBuf == NULL || nToSndLen <= 0)
	{
		return -1;
	}

	//------------------------------------------------------------
	//检查串口是否已经打开
	if (!m_bOpenFlag)
	{
		return -1;
	}

	//------------------------------------------------------------
	/*
	*WriteFile resets the event specified by the hEvent member of the OVERLAPPED structure 
	*to a nonsignaled state when it begins the I/O operation
	*The event specified in the OVERLAPPED structure is set to the signaled state upon completion of the write operation.
	*/
	//串口发送数据的处理
	bReturnValue = WriteFile(m_hCOM, (LPSTR)pSendBuf, nToSndLen, &dwBytesWritten, &m_OverlappedWrite);
	if (bReturnValue)
	{
		if (pSendLen)
		{
			*pSendLen = dwBytesWritten;//已将长度为nSndLen的数据发送成功
		}
		return 0;
	}
	else
	{/*指定长度的数据未发送完*/
		
		if((GetLastError() == ERROR_IO_PENDING))
		{	
			/* //后期完善
			BOOL bResult = FALSE;
			while (!(bResult = GetOverlappedResult(m_hCOM, &m_OverlappedWrite, &dwBytesWritten, FALSE)))
			{
				if (GetLastError() == ERROR_IO_INCOMPLETE)
				{
					m_OverlappedWrite.Offset += dwBytesWritten;
				}
				else
				{
					if (WaitForSingleObject(m_hCOM, dwTimeOut))
					{
						if (GetLastError() != ERROR_IO_INCOMPLETE)
						{
							PurgeComm(m_hCOM, PURGE_RXCLEAR);	//清空接收缓冲区
							PurgeComm(m_hCOM, PURGE_TXCLEAR);	//情况发送缓冲区
							return -1;//发生其他错误
						}
					}
				}
			}
			if (bResult)
			{
				if (pSendLen)
				{
					*pSendLen = nToSndLen;//已将长度为nSndLen的数据发送成功
				}
				return 0;//发送成功
			}
			*/
		}
		else
		{
			PurgeComm(m_hCOM, PURGE_RXCLEAR);	//清空接收缓冲区
			PurgeComm(m_hCOM, PURGE_TXCLEAR);	//情况发送缓冲区
			return -1;//发生其他错误
		}
	}
	
	return 0;
}
//==============================================================================================
//函 数 名:Receive
//函数参数:pRecvBuf:接收数据的缓冲区的指针;nRecvSize:缓冲区的大小;pRecvLen:指向实际接收数据的指针
//返 回 值:0:成功;其他值:失败
//功能描述:接收数据
//==============================================================================================
int CSTPSerialPort::Receive(BYTE* pRecvBuf, UINT32 nRecvSize, UINT32* pRecvLen)
{	
	DWORD dwErrFlags = 0;
	COMSTAT stComStat;
	DWORD dwBytesToRead = 0;	//期望从串口读到的字节数
	DWORD dwBytesRead = 0;		//实际从串口读到的字节数
	BOOL bReturnValue = FALSE;
    *pRecvLen = 0;
	//------------------------------------------------------------
	//检查输入参数
	if (pRecvBuf == NULL || nRecvSize <= 0)
	{
		return -1;
	}
	
	//------------------------------------------------------------
	//判断串口是否已经打开
	if (m_hCOM == INVALID_HANDLE_VALUE || !m_bOpenFlag)
	{
		return -1;
	}
	
	//------------------------------------------------------------
	//从串口中读取数据
    //memset(pRecvBuf,'\0',(BYTE)nRecvSize*sizeof(BYTE));//清空数组

	memset(&stComStat, 0x00, sizeof(stComStat));
	BOOL bTest = ClearCommError(m_hCOM, &dwErrFlags, &stComStat);
	if (stComStat.cbInQue > 0)
	{
		dwBytesToRead = (stComStat.cbInQue > nRecvSize) ? nRecvSize : stComStat.cbInQue;
		bReturnValue = ReadFile(m_hCOM, pRecvBuf,  dwBytesToRead, &dwBytesRead, &m_OverlappedRead);
		if (!bReturnValue)
		{/*没有获取到队列中的所有数据*/
			if (GetLastError() == ERROR_IO_PENDING)
			{/*串口正在进行重叠操作*/
				WaitForSingleObject(m_OverlappedRead.hEvent, 1000);//直至读操作完成或延时达到1s(当读操作完成的时候,m_OverlappedRead.hEvent会被置为有信号态)
				if (pRecvLen)
				{
					*pRecvLen = dwBytesRead;
				}
			}
			else
			{
				PurgeComm(m_hCOM, PURGE_RXCLEAR);	//清空接收缓冲区
				PurgeComm(m_hCOM, PURGE_TXCLEAR);	//情况发送缓冲区
				return -1;							//发生其他错误
			}
		}
		else
		{
			if (pRecvLen)
			{
				*pRecvLen = dwBytesRead;
			}
		}
	}
	//else///增加返回0长度
	//{
	//	*pRecvLen = 0;
	//}

	return 0;
}
//==============================================================================================
//函 数 名:IsOpened
//函数参数:无
//返 回 值:无
//功能描述:判断串口是否打开
//==============================================================================================
BOOL CSTPSerialPort::IsOpened()
{
	return m_bOpenFlag;
}
//==============================================================================================
//函 数 名:GetPortInfo
//函数参数:pInfo:指向串口信息的结构体指针
//返 回 值:无
//功能描述:获取串口的基本信息
//==============================================================================================
void CSTPSerialPort::GetPortInfo(TSTPSPInfo* pInfo)
{
	if (pInfo)
	{
		memcpy(pInfo, &m_stPortInfo, sizeof(TSTPSPInfo));
	}
	
	return;
}