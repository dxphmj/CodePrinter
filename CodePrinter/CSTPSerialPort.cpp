/**********************************************************************************************
*@FileName:CSTPSerialPort.cpp
*@Author:chengyuanjun
*@Date:2013-06-12 09:55:08
*@Copyright: 2012-2014 TCT Incorporated 
*@Desp:���ļ�ʵ���˶Դ��ڵĻ�������
*@Revision:
*@Date		@Author			@Content
*	
***********************************************************************************************/

/*****************************************************************
*@Head Files Of Lib---ϵͳͷ�ļ�
*****************************************************************/
#include "StdAfx.h"

/*****************************************************************
*@Head Files Of User---�û��Զ���ͷ�ļ�
*****************************************************************/
#include "CSTPSerialPort.h"


/*****************************************************************
*@Global Var---ȫ�ֱ�������
*****************************************************************/


/*****************************************************************
*@Macro Definition---�궨��
*****************************************************************/


/*****************************************************************
*@Struct Definition---�ṹ�嶨��
*****************************************************************/

/*****************************************************************
*@Function Definition---��̬��Ա��������
*****************************************************************/


/*****************************************************************
*@Function Definition---��Ա��������
*****************************************************************/

//==============================================================================================
//�� �� ��:CSTPSerialPort
//��������:��
//�� �� ֵ:��
//��������:���캯��
//==============================================================================================
CSTPSerialPort::CSTPSerialPort()
{
	m_bOpenFlag = FALSE;
	memset(&m_stPortInfo, 0x00, sizeof(TSTPSPInfo));
	
	return;
}
//==============================================================================================
//�� �� ��:~CSTPSerialPort
//��������:��
//�� �� ֵ:��
//��������:��������
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
//�� �� ��:Open
//��������:nPortNo:�˿ں�;nBaudRate:������;byDataBit:����λ;byStopBit:ֹͣλ;byParity:У������
//�� �� ֵ:0:�ɹ�;����ֵ:ʧ��
//��������:�򿪴���
//==============================================================================================
int CSTPSerialPort::Open(UINT32 nPortNo, UINT32 nBaudRate, BYTE byDataBit, BYTE byStopBit, BYTE byParity)
{
	CHAR szPort[16];
	DCB dcb;	//�豸���ƿ�

	//------------------------------------------------------------
    //��鴮���Ƿ��Ѿ���
	if (m_bOpenFlag) 
	{
		return 0;
	}

	//------------------------------------------------------------
	//���洮�ڲ���
	m_stPortInfo.nPortNo = nPortNo;
	m_stPortInfo.nBaudRate = nBaudRate;
	m_stPortInfo.byDataBit = byDataBit;
	m_stPortInfo.byStopBit = byStopBit;
	m_stPortInfo.byParity = byParity;
	
	//------------------------------------------------------------
	//�Դ������ƽ��и�ʽ��
	memset(szPort, 0x00, sizeof(szPort));
//	wsprintf(szPort, "\\\\.\\COM%d", nPortNo);
	sprintf(szPort, "COM%d:", nPortNo);//////////////gai
	
	//------------------------------------------------------------
	//��ָ������

	USES_CONVERSION;  
    
	m_hCOM = CreateFile(A2W(szPort),								/*��������*/
							GENERIC_READ | GENERIC_WRITE,	/*�Ըô���ӵ�ж�дȨ��*/
							0,								/*���ڴ򿪳ɹ��󣬶��δ򿪻�ʧ��*/
							NULL,							/*��ȫ����*/
							OPEN_EXISTING,					/*�������Ѵ����豸*/
							//FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //////////gai
							0,
							NULL);
	if (INVALID_HANDLE_VALUE == m_hCOM)
	{ 
		return -1;
	}
		
	//------------------------------------------------------------
	//���ڳ�ʱ��������
	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;	//���ַ�֮�������ӳ�
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = 0;
	SetCommTimeouts(m_hCOM, &CommTimeOuts);
	
	//------------------------------------------------------------
	//��������
	dcb.DCBlength = sizeof(DCB);
	GetCommState(m_hCOM, &dcb);//��ȡ���пڵĵ�ǰ����
	dcb.BaudRate = nBaudRate;
	dcb.ByteSize = byDataBit;	//����λ
	dcb.StopBits = byStopBit;	//ֹͣλ
	dcb.Parity = byParity;		//У��λ
	dcb.fParity = 1;
	
	//�����ý����޸ģ�����ָ�����ͺͽ��ջ������Ĵ�С�����ʧ����رմ���
	if(!SetCommState(m_hCOM, &dcb) )    //   || !SetupComm(m_hCOM, 10, 10)   ���û�����ʧ��
	{
		CloseHandle(m_hCOM);
		return -1;
	}
	
	//------------------------------------------------------------
	//���ڶ�д�¼�
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
	m_bOpenFlag = TRUE;//�����Ѵ�

	return 0;
}
//==============================================================================================
//�� �� ��:Open
//��������:pSPInfo:ָ�򴮿���Ϣ�Ľṹ��ָ��
//�� �� ֵ:0:�ɹ�;����ֵ:ʧ��
//��������:�򿪴���
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
//�� �� ��:Close
//��������:��
//�� �� ֵ:Ԥ��:Ĭ�Ϸ���0
//��������:�رմ���
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
//�� �� ��:Send
//��������:pSendBuf:ָ�������ݵĽṹ���ָ��;nToSndLen:�������ݵĳ���;pSendLen:ʵ�ʷ��͵����ݵĳ���
//�� �� ֵ:
//��������:��������
//==============================================================================================
int CSTPSerialPort::Send(BYTE* pSendBuf, UINT32 nToSndLen, UINT32* pSendLen)
{
	BOOL bReturnValue = FALSE;
	DWORD dwBytesWritten = 0;
	DWORD dwTimeOut = (DWORD)(((nToSndLen * 8) * 1.0 ) / (m_stPortInfo.nBaudRate * 1.0) * 1000 * 3);

	//------------------------------------------------------------
	//���Ҫ���͵������Ƿ���Ч
	if (pSendBuf == NULL || nToSndLen <= 0)
	{
		return -1;
	}

	//------------------------------------------------------------
	//��鴮���Ƿ��Ѿ���
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
	//���ڷ������ݵĴ���
	bReturnValue = WriteFile(m_hCOM, (LPSTR)pSendBuf, nToSndLen, &dwBytesWritten, &m_OverlappedWrite);
	if (bReturnValue)
	{
		if (pSendLen)
		{
			*pSendLen = dwBytesWritten;//�ѽ�����ΪnSndLen�����ݷ��ͳɹ�
		}
		return 0;
	}
	else
	{/*ָ�����ȵ�����δ������*/
		
		if((GetLastError() == ERROR_IO_PENDING))
		{	
			/* //��������
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
							PurgeComm(m_hCOM, PURGE_RXCLEAR);	//��ս��ջ�����
							PurgeComm(m_hCOM, PURGE_TXCLEAR);	//������ͻ�����
							return -1;//������������
						}
					}
				}
			}
			if (bResult)
			{
				if (pSendLen)
				{
					*pSendLen = nToSndLen;//�ѽ�����ΪnSndLen�����ݷ��ͳɹ�
				}
				return 0;//���ͳɹ�
			}
			*/
		}
		else
		{
			PurgeComm(m_hCOM, PURGE_RXCLEAR);	//��ս��ջ�����
			PurgeComm(m_hCOM, PURGE_TXCLEAR);	//������ͻ�����
			return -1;//������������
		}
	}
	
	return 0;
}
//==============================================================================================
//�� �� ��:Receive
//��������:pRecvBuf:�������ݵĻ�������ָ��;nRecvSize:�������Ĵ�С;pRecvLen:ָ��ʵ�ʽ������ݵ�ָ��
//�� �� ֵ:0:�ɹ�;����ֵ:ʧ��
//��������:��������
//==============================================================================================
int CSTPSerialPort::Receive(BYTE* pRecvBuf, UINT32 nRecvSize, UINT32* pRecvLen)
{	
	DWORD dwErrFlags = 0;
	COMSTAT stComStat;
	DWORD dwBytesToRead = 0;	//�����Ӵ��ڶ������ֽ���
	DWORD dwBytesRead = 0;		//ʵ�ʴӴ��ڶ������ֽ���
	BOOL bReturnValue = FALSE;
    *pRecvLen = 0;
	//------------------------------------------------------------
	//����������
	if (pRecvBuf == NULL || nRecvSize <= 0)
	{
		return -1;
	}
	
	//------------------------------------------------------------
	//�жϴ����Ƿ��Ѿ���
	if (m_hCOM == INVALID_HANDLE_VALUE || !m_bOpenFlag)
	{
		return -1;
	}
	
	//------------------------------------------------------------
	//�Ӵ����ж�ȡ����
    //memset(pRecvBuf,'\0',(BYTE)nRecvSize*sizeof(BYTE));//�������

	memset(&stComStat, 0x00, sizeof(stComStat));
	BOOL bTest = ClearCommError(m_hCOM, &dwErrFlags, &stComStat);
	if (stComStat.cbInQue > 0)
	{
		dwBytesToRead = (stComStat.cbInQue > nRecvSize) ? nRecvSize : stComStat.cbInQue;
		bReturnValue = ReadFile(m_hCOM, pRecvBuf,  dwBytesToRead, &dwBytesRead, &m_OverlappedRead);
		if (!bReturnValue)
		{/*û�л�ȡ�������е���������*/
			if (GetLastError() == ERROR_IO_PENDING)
			{/*�������ڽ����ص�����*/
				WaitForSingleObject(m_OverlappedRead.hEvent, 1000);//ֱ����������ɻ���ʱ�ﵽ1s(����������ɵ�ʱ��,m_OverlappedRead.hEvent�ᱻ��Ϊ���ź�̬)
				if (pRecvLen)
				{
					*pRecvLen = dwBytesRead;
				}
			}
			else
			{
				PurgeComm(m_hCOM, PURGE_RXCLEAR);	//��ս��ջ�����
				PurgeComm(m_hCOM, PURGE_TXCLEAR);	//������ͻ�����
				return -1;							//������������
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
	//else///���ӷ���0����
	//{
	//	*pRecvLen = 0;
	//}

	return 0;
}
//==============================================================================================
//�� �� ��:IsOpened
//��������:��
//�� �� ֵ:��
//��������:�жϴ����Ƿ��
//==============================================================================================
BOOL CSTPSerialPort::IsOpened()
{
	return m_bOpenFlag;
}
//==============================================================================================
//�� �� ��:GetPortInfo
//��������:pInfo:ָ�򴮿���Ϣ�Ľṹ��ָ��
//�� �� ֵ:��
//��������:��ȡ���ڵĻ�����Ϣ
//==============================================================================================
void CSTPSerialPort::GetPortInfo(TSTPSPInfo* pInfo)
{
	if (pInfo)
	{
		memcpy(pInfo, &m_stPortInfo, sizeof(TSTPSPInfo));
	}
	
	return;
}