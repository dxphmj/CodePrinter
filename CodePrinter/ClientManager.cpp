// ClientManager.cpp: implementation of the CClientManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "CodePrinterDlg.h"
#include "ClientManager.h"
#include "ClientContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CClientManager * CClientManager::m_pClientMgr = NULL;
CClientManager::CClientManager()
{
	m_pClientMgr = NULL; 
}

CClientManager::~CClientManager()
{
	
}
/* 
 * 得到客户端管理对象指针
 */
CClientManager * CClientManager::GetClientManager( void )
{
	return (m_pClientMgr == NULL)? m_pClientMgr = new CClientManager:m_pClientMgr;
}
/* 
 * 增加客户端
 */
void CClientManager::AddClient( CClientContext *pClient )
{
	
	m_clientList.AddTail(pClient);
}

/* 
 * 删除客户端
 */
void CClientManager::DeleteClient( CClientContext *pClient )
{
	m_cs.Lock();
	POSITION pos1 = NULL;
	POSITION pos2 = NULL;
	for (pos1 = m_clientList.GetHeadPosition(); (pos2 = pos1) != NULL;)
	{
		CClientContext *pClientCText = (CClientContext*)m_clientList.GetNext(pos1);
		if (pClient == pClientCText)
		{
			m_clientList.RemoveAt(pos2);
			delete pClientCText;
			pClientCText = NULL;
		}		
	}
	m_cs.Unlock();
}

/* 
 * 删除所有客户端
 */
void CClientManager::DeleteAllClient( void )
{
	m_cs.Lock();
	//删除客户端链表
	POSITION pos = NULL;
	for (pos = m_clientList.GetHeadPosition(); pos != NULL;)
	{
		CClientContext *pClient = (CClientContext*)m_clientList.GetNext(pos);
		delete pClient;
		pClient = NULL;
	}
	m_clientList.RemoveAll();
	m_cs.Unlock();
}

/* 
 * 释放内存
 */
void CClientManager::ReleaseManager( void )
{
	if (NULL != m_pClientMgr)
	{
		delete m_pClientMgr;
		m_pClientMgr = NULL;
	}
	
}

/* 
 * I/O处理
 */
void CClientManager::ProcessIO( CClientContext* pClient, 
							   LPOVERLAPPED pOverlapped, DWORD dwIOSize)
{
	//获取扩展重叠结构指针
	PIO_OPERATION_DATA pIO = CONTAINING_RECORD(pOverlapped,	
												IO_OPERATION_DATA,
												overlapped);
	if (NULL != pIO)
	{
		switch(pIO->type)//重叠操作类型
		{
		case IOReadHead://读包头
			{
				pClient->OnRecvHeadCompleted(dwIOSize);
				break;				
			}
		case IOReadBody://读包体
			{
				pClient->OnRecvBodyCompleted(dwIOSize);
				DeleteClient(pClient);
				break;				
			}			
		case IOWriteInfo://发送传感器信息
			{
				pClient->OnSendCompleted(dwIOSize);
				break;
			}		
		case IOWriteUnLogin://考生验证失败
			{
				DeleteClient(pClient);
				break;
			}
		case IOWriteSTNAME://发送考生姓名
			{
				pClient->AsyncSendPaper();
				break;
			}
		case IOWritePAPER://发送试卷
			{
				pClient->OnSendCompleted(dwIOSize);
				break;
			}
		case IOEXIT://客户端退出
			{
				DeleteClient(pClient);
				break;
			}
		default:break;
		}		
	}
}