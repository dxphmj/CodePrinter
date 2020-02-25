// ClientContext.h: interface for the CClientContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTCONTEXT_H__DE6218FD_8A39_46C1_A9D2_EB6BC7082509__INCLUDED_)
#define AFX_CLIENTCONTEXT_H__DE6218FD_8A39_46C1_A9D2_EB6BC7082509__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "CodePrinterDlg.h"
class CCodePrinterDlg;

struct strSendData
{
	double m_dTemp;
	int m_nSpeedTheory;
	//double m_dSpeedReal;
	int    m_nFrictionSensor;
	int    m_nStrainSensor;
};


class CClientContext :public CObject
{
public:
	CClientContext(SOCKET s, CCodePrinterDlg* pServView);
	virtual ~CClientContext();
	enum state
	{
		LOGIN,	//登录状态
		DOING,	//答卷状态
		DONE,	//交卷
		DISCON,	//掉线状态
		UNKNOWN	//未知状态
	};

public:
	BOOL		AsyncSendPaper(void);					//发送试卷
	BOOL		AsyncSendStudentName(void);				//发送学生姓名
	BOOL		AsyncSendFailLoginMsg(void);			//考生验证失败
	void		OnSendCompleted(DWORD dwIOSize);		//发送数据完毕	

	BOOL		AsyncRecvHead( void );					//接收包头
	BOOL		AsyncRecvBody(int nLen);				//接收包体
	void		OnRecvHeadCompleted( DWORD dwIOSize );	//接收包头完毕
	void		OnRecvBodyCompleted( DWORD dwIOSize );	//接收包体完毕
	BOOL		AsyncRecvIOOK(void);					//客户端退出
	
	void		SaveDisConnectState(void);				//保存断开状态
	BOOL        AsyncSendSensorInfo( void );

public:
	IO_OPERATION_DATA	m_iIO;			//读扩展重叠结构数据结构
	IO_OPERATION_DATA	m_oIO;			//写扩展重叠结构数据结构
	state				m_eState;		//考生状态
	CTime				m_time;			//心跳时间
	BOOL				m_bPulse;		//心跳包
	UINT				m_nStdSN;		//学号
	strSendData         m_strSendData;

protected:
	SOCKET				m_s;			//套接字
	CCodePrinterDlg			*m_pServerView;	//主窗口指针
	CString				m_strName;		//考生姓名
	int					m_nGrade;		//成绩
};

#endif // !defined(AFX_CLIENTCONTEXT_H__DE6218FD_8A39_46C1_A9D2_EB6BC7082509__INCLUDED_)
