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
		LOGIN,	//��¼״̬
		DOING,	//���״̬
		DONE,	//����
		DISCON,	//����״̬
		UNKNOWN	//δ֪״̬
	};

public:
	BOOL		AsyncSendPaper(void);					//�����Ծ�
	BOOL		AsyncSendStudentName(void);				//����ѧ������
	BOOL		AsyncSendFailLoginMsg(void);			//������֤ʧ��
	void		OnSendCompleted(DWORD dwIOSize);		//�����������	

	BOOL		AsyncRecvHead( void );					//���հ�ͷ
	BOOL		AsyncRecvBody(int nLen);				//���հ���
	void		OnRecvHeadCompleted( DWORD dwIOSize );	//���հ�ͷ���
	void		OnRecvBodyCompleted( DWORD dwIOSize );	//���հ������
	BOOL		AsyncRecvIOOK(void);					//�ͻ����˳�
	
	void		SaveDisConnectState(void);				//����Ͽ�״̬
	BOOL        AsyncSendSensorInfo( void );

public:
	IO_OPERATION_DATA	m_iIO;			//����չ�ص��ṹ���ݽṹ
	IO_OPERATION_DATA	m_oIO;			//д��չ�ص��ṹ���ݽṹ
	state				m_eState;		//����״̬
	CTime				m_time;			//����ʱ��
	BOOL				m_bPulse;		//������
	UINT				m_nStdSN;		//ѧ��
	strSendData         m_strSendData;

protected:
	SOCKET				m_s;			//�׽���
	CCodePrinterDlg			*m_pServerView;	//������ָ��
	CString				m_strName;		//��������
	int					m_nGrade;		//�ɼ�
};

#endif // !defined(AFX_CLIENTCONTEXT_H__DE6218FD_8A39_46C1_A9D2_EB6BC7082509__INCLUDED_)
