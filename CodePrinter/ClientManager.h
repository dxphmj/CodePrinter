// ClientManager.h: interface for the CClientManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTMANAGER_H__688E1208_4C99_4411_938C_D8B547910E87__INCLUDED_)
#define AFX_CLIENTMANAGER_H__688E1208_4C99_4411_938C_D8B547910E87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CClientContext;

class CClientManager : public CObject  
{
public:
	virtual ~CClientManager();
public:
	static CClientManager *GetClientManager(void);	//�õ�����ͻ��˶���ָ��
	static void ReleaseManager(void);				//�ͷŹ���ͻ��˶���ռ����Դ

	void	ProcessIO(CClientContext* pClient,		//I/O����
			LPOVERLAPPED pOverlapped, DWORD dwIOSize);
	void	AddClient(CClientContext *pClient);		//���ӿͻ���
	void	DeleteClient(CClientContext *pClient);	//ɾ���ͻ���
	void	DeleteAllClient(void);					//ɾ�����пͻ���

	
public:
	CObList		m_clientList;						//����ͻ�������
private:
	CClientManager();
	CClientManager(const CClientManager& other);
	CClientManager& operator = (CClientManager &other);
	static CClientManager *m_pClientMgr;
	CCriticalSection m_cs;							//�����ͻ����������
};

#endif // !defined(AFX_CLIENTMANAGER_H__688E1208_4C99_4411_938C_D8B547910E87__INCLUDED_)
