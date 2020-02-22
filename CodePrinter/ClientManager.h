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
	static CClientManager *GetClientManager(void);	//得到管理客户端对象指针
	static void ReleaseManager(void);				//释放管理客户端对象占有资源

	void	ProcessIO(CClientContext* pClient,		//I/O处理
			LPOVERLAPPED pOverlapped, DWORD dwIOSize);
	void	AddClient(CClientContext *pClient);		//增加客户端
	void	DeleteClient(CClientContext *pClient);	//删除客户端
	void	DeleteAllClient(void);					//删除所有客户端

	
public:
	CObList		m_clientList;						//管理客户端链表
private:
	CClientManager();
	CClientManager(const CClientManager& other);
	CClientManager& operator = (CClientManager &other);
	static CClientManager *m_pClientMgr;
	CCriticalSection m_cs;							//保护客户端链表对象
};

#endif // !defined(AFX_CLIENTMANAGER_H__688E1208_4C99_4411_938C_D8B547910E87__INCLUDED_)
