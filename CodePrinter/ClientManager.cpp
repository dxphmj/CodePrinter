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
 * �õ��ͻ��˹������ָ��
 */
CClientManager * CClientManager::GetClientManager( void )
{
	return (m_pClientMgr == NULL)? m_pClientMgr = new CClientManager:m_pClientMgr;
}
/* 
 * ���ӿͻ���
 */
void CClientManager::AddClient( CClientContext *pClient )
{
	
	m_clientList.AddTail(pClient);
}

/* 
 * ɾ���ͻ���
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
 * ɾ�����пͻ���
 */
void CClientManager::DeleteAllClient( void )
{
	m_cs.Lock();
	//ɾ���ͻ�������
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
 * �ͷ��ڴ�
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
 * I/O����
 */
void CClientManager::ProcessIO( CClientContext* pClient, 
							   LPOVERLAPPED pOverlapped, DWORD dwIOSize)
{
	//��ȡ��չ�ص��ṹָ��
	PIO_OPERATION_DATA pIO = CONTAINING_RECORD(pOverlapped,	
												IO_OPERATION_DATA,
												overlapped);
	if (NULL != pIO)
	{
		switch(pIO->type)//�ص���������
		{
		case IOReadHead://����ͷ
			{
				pClient->OnRecvHeadCompleted(dwIOSize);
				break;				
			}
		case IOReadBody://������
			{
				pClient->OnRecvBodyCompleted(dwIOSize);
				DeleteClient(pClient);
				break;				
			}			
		case IOWriteInfo://���ʹ�������Ϣ
			{
				pClient->OnSendCompleted(dwIOSize);
				break;
			}		
		case IOWriteUnLogin://������֤ʧ��
			{
				DeleteClient(pClient);
				break;
			}
		case IOWriteSTNAME://���Ϳ�������
			{
				pClient->AsyncSendPaper();
				break;
			}
		case IOWritePAPER://�����Ծ�
			{
				pClient->OnSendCompleted(dwIOSize);
				break;
			}
		case IOEXIT://�ͻ����˳�
			{
				DeleteClient(pClient);
				break;
			}
		default:break;
		}		
	}
}