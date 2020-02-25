/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpUDPSocket.h
*	�ļ���ʶ: �������ƽ̨��������ʵ��UDPͨ�ŵ���
*	ժҪ��
*		�������Ҫ������:
*		 1.����ʵ��UDP���ݵĵ��������뵥�����ա�
*		 2.����ʵ��UDP���ݵ��鲥�������鲥���ա�
*		 3.ʹ�÷������ƽ̨�������еĵײ㺯��������Ϸ������ƽ̨������ʹ�ã��Ƿ������ƽ̨�������е�һ���֡�
*	��ǰ�汾��1.0
*	�� �ߣ���ΰ
*	������ڣ�2009-6-13
*
*	ȡ���汾��Comm_V_2.h
*	�� �ߣ���ΰ
*	������ڣ�2008-12-31
*/
//////////////////////////////////////////////////////////////////////

#ifndef _FILE_STP_UDP_SOCKET_H__
#define _FILE_STP_UDP_SOCKET_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//----------------------����ͷ�ļ�-----------------------------------------
#include "winsock2.h"
#include "ws2tcpip.h"
#include "stpDefine.h"
//----------------------�궨��-----------------------------------------
//�����붨��
#define STP_ERR_SOCK_SUCCESS						0				//�ɹ�
#define STP_ERR_SOCK_PORT_BUSY						0xFFFF0000		//�˿ڱ�ռ��					
#define STP_ERR_SOCK_BIND_FAILED					0xFFFF0001		//��ʧ��
#define STP_ERR_SOCK_JOIN_GROUP_FAILED				0xFFFF0002		//����ಥ��ʧ��
#define STP_ERR_SOCK_CHANGE_OPTION_FAILED			0xFFFF0003		//�޸�Socket����ʧ��
#define STP_ERR_SOCK_CREATE_FAILED					0xFFFF0004		//Socket����ʧ��					
#define STP_ERR_SOCK_TRY_REOPEN						0xFFFF0005		//�������´�һ��Socket����ʹ��ʱ�����ȹرղ����ٴ�					
#define STP_ERR_SOCK_CLOSED							0xFFFF0006		//Socket��δ�����������Ҫʹ�öಥ�飬���ȴ�Socket			
#define STP_ERR_SOCK_INVALID_GROUP					0xFFFF0007		//��Ч�ಥ��
#define STP_ERR_SOCK_ALREADY_IN_GROUP				0xFFFF0008		//�Ѿ�����ಥ��

#define STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET		40				//Socket���ܼ���Ķಥ��ĸ���

#define STP_UDP_SOCKETMAX_MAX_SIZE_RCV_BUFF			1500			//1500�ֽڣ����ֻ����һ��MTU

//#define JOINGROUP_WSAJoinLeaf										//�趨ʹ�öಥ��ķ�ʽ

//UDPͨ���������
class AFX_EXT_CLASS CstpUDPSocket  
{
public:

	/*
	����ԭ��CstpUDPSocket(int IN nCycleLen = 200)
	����˵��:
		int IN nCycleLen			��������̵߳���ѯ����
	ʹ�õ���ȫ�ֱ�����
	��������:���캯��,��ʼ����̬�⡣
	����ֵ:��
	*/
	CstpUDPSocket(int IN nCycleLen = 200);//���캯��	Ŀǰû��

	/*
	����ԭ��:virtual ~CstpUDPSocket(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:��������,�ͷŶ�̬�⡣���б�Ҫ�Ŀռ��ͷŹ���
	����ֵ:��
	*/
	virtual ~CstpUDPSocket(void);//��������	Ŀǰû��

	/*
	����ԭ��:DWORD StartSocket(DWORD IN dwIP, WORD IN wPort)
	����˵��:
		DWORD IN dwIP									����IP��ַ��˫�ֽ�����
		WORD IN wPort									��SocketҪʹ�õı��ض˿�
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ���������ֽ�������IP��ַ�Ͷ˿�����������Socket���ܣ����󶨶˿�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD StartSocket(DWORD IN dwIP, WORD IN wPort);

	/*
	����ԭ��:DWORD StartSocket(const CHAR IN szIP[], int IN nPort)
	����˵��:
		const CHAR IN szIP[]									����IP��ַ���ַ�����������
		int IN nPort									��SocketҪʹ�õı��ض˿�
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ���������ַ���������IP��ַ����ʮ���������Ķ˿ڣ�����Socket���ܣ����󶨶˿�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD StartSocket(const CHAR IN szIP[], int IN nPort);

	/*
	����ԭ��:DWORD StartSocket(sockaddr_in IN *pstLocalSocketAddr)
	����˵��:
		sockaddr_in IN *pstLocalSocketAddr				����Socket��ַ��ʹ�ýṹ���������ýṹ��ָ�봫��
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ������ṹ��������Socket��ַ������Socket���ܣ����󶨶˿�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD StartSocket(sockaddr_in IN *pstLocalSocketAddr);

	/*
	����ԭ��:DWORD StartSocketEx(DWORD IN dwIP, WORD IN wPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL)
	����˵��:
		DWORD IN dwIP									����IP��ַ��˫�ֽ�����
		WORD IN wPort									��SocketҪʹ�õı��ض˿�
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID)
														UDPSocket���մ���Ļص������ĺ���ָ�룬
														���е�һ��������Ҫ���յ����ݵ����ݻ��������ڶ��������ǽ��յ������ݵĳ���
														������������������Դ��Socket��ַ�����ĸ������Ǵ��ݳ����Ķ��������Ĭ��Ϊ�������
		HWND IN hwnd									������������ͨ���������ڵĴ���
		LPVOID IN pParam = NULL							Ԥ������
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ���������ֽ�������IP��ַ�Ͷ˿�����������Socket���ܣ����󶨶˿ڣ��������Զ��������ݵ��̡߳�
			���ݴ�����Ҫʹ��pFuncRcvCallback�Ļص�����
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD StartSocketEx(DWORD IN dwIP, WORD IN wPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL);

	/*
	����ԭ��:DWORD StartSocketEx(const CHAR IN szIP[], int IN nPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL)
	����˵��:
		const CHAR IN szIP[]									����IP��ַ���ַ�����������
		int IN nPort									��SocketҪʹ�õı��ض˿�
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID)
														UDPSocket���մ���Ļص������ĺ���ָ�룬
														���е�һ��������Ҫ���յ����ݵ����ݻ��������ڶ��������ǽ��յ������ݵĳ���
														������������������Դ��Socket��ַ�����ĸ������Ǵ��ݳ����Ķ��������Ĭ��Ϊ�������
		HWND IN hwnd									������������ͨ���������ڵĴ���
		LPVOID IN pParam = NULL							Ԥ������
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ���������ַ���������IP��ַ����ʮ���������Ķ˿ڣ�����Socket���ܣ����󶨶˿ڣ��������Զ��������ݵ��̡߳�
			���ݴ�����Ҫʹ��pFuncRcvCallback�Ļص�����
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD StartSocketEx(const CHAR IN szIP[], int IN nPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL);

	/*
	����ԭ��:DWORD StartSocketEx(sockaddr_in IN *pstLocalSocketAddr, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL)
	����˵��:
		sockaddr_in IN *pstLocalSocketAddr				����Socket��ַ��ʹ�ýṹ���������ýṹ��ָ�봫��
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID)
														UDPSocket���մ���Ļص������ĺ���ָ�룬
														���е�һ��������Ҫ���յ����ݵ����ݻ��������ڶ��������ǽ��յ������ݵĳ���
														������������������Դ��Socket��ַ�����ĸ������Ǵ��ݳ����Ķ��������Ĭ��Ϊ�������
		HWND IN hwnd									������������ͨ���������ڵĴ���
		LPVOID IN pParam = NULL							Ԥ������
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ������ṹ��������Socket��ַ������Socket���ܣ����󶨶˿ڣ��������Զ��������ݵ��̡߳�
			���ݴ�����Ҫʹ��pFuncRcvCallback�Ļص�����
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD StartSocketEx(sockaddr_in IN *pstLocalSocketAddr, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL);

	/*
	����ԭ��:DWORD JoinGroup(const CHAR IN szIP[])
	����˵��:
		const CHAR IN szIP[]							Ҫ����Ķಥ���ַ
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ���������ֽ������Ķಥ���ַ������ָ���ಥ��
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD JoinGroup(const CHAR IN szIP[]);

	/*
	����ԭ��:DWORD QuitGroup(const CHAR IN szIP[])
	����˵��:
		const CHAR IN szIP[]							Ҫ�˳��Ķಥ���ַ
	ʹ�õ���ȫ�ֱ�����
		��
	��������:ͨ���������ֽ������Ķಥ���ַ���˳�ָ���ಥ��
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش�����
	*/
	DWORD QuitGroup(const CHAR IN szIP[]);

	/*
	����ԭ��:void QuitAllGroup(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
		��
	��������:�˳��Ѽ�������жಥ��
	����ֵ:
	*/
	void QuitAllGroup(void);

	/*
	����ԭ��:void SetAutoRecord(BOOL IN boValid = TRUE)
	����˵��:
		BOOL IN boValid					�Ƿ��Զ���¼�շ���Ϣ��TRUEΪ�Զ���¼��FALSEΪ����¼
	ʹ�õ���ȫ�ֱ�����
	��������:
		���������Ƿ��Զ���¼�շ���Ϣ��ȫ�������C:/StpUDPSocketDebug�£��Դ���ʱ��Ϊ�ļ�����
	����ֵ:
	*/
	void SetAutoRecord(BOOL IN boValid = TRUE);

 	/*
	����ԭ��:BOOL IsOpened(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		�����ж������Ƿ��Ѿ��򿪡�
	����ֵ:����Socket��״̬�������������TRUE�����򷵻�FALSE
	*/
    BOOL IsOpened(void);

 	/*
	����ԭ��:void SetCycleLen(int IN nCycleLen)
	����˵��:
		int IN nCycleLen	Ҫ�趨�����ڳ���
	ʹ�õ���ȫ�ֱ�����
	��������:
		�����趨����ɼ����ݵ���ѯ����
	����ֵ:
	*/
    void SetCycleLen(int IN nCycleLen);

	/*
	����ԭ��:DWORD Send(const BYTE IN *pbBuffer, int IN nSize, DWORD IN dwIP, WORD IN wPort)
	����˵��:
		IN const CHAR *pbBuffer					�������ݻ�����
		IN int nSize			                �������ݵĳ���
		DWORD IN dwIP									����IP��ַ��˫�ֽ�����
		WORD IN wPort									��SocketҪʹ�õı��ض˿�
	ʹ�õ���ȫ�ֱ�����
	��������:���緢������
	����ֵ:�������緢�͵���������ʧ�ܷ���0
	*/
	DWORD Send(const BYTE IN *pbBuffer, int IN nSize, DWORD IN dwIP, WORD IN wPort);

	/*
	����ԭ��:DWORD Send(const BYTE IN *pbBuffer, int IN nSize, const CHAR IN szIP[], int IN nPort)
	����˵��:
		IN const CHAR *pbBuffer					�������ݻ�����
		IN int nSize			                �������ݵĳ���
		CHAR IN szIP[]									����IP��ַ���ַ�����������
		int IN nPort									��SocketҪʹ�õı��ض˿�
	ʹ�õ���ȫ�ֱ�����
	��������:���緢������
	����ֵ:�������緢�͵���������ʧ�ܷ���0
	*/
	DWORD Send(const BYTE IN *pbBuffer, int IN nSize, const CHAR IN szIP[], int IN nPort);

	/*
	����ԭ��:DWORD Send(const BYTE IN *pbBuffer, int IN nSize, sockaddr_in IN *pstDestAddr)
	����˵��:
		IN const CHAR *pbBuffer					�������ݻ�����
		IN int nSize			                �������ݵĳ���
		sockaddr_in IN *pstDestAddr				Զ��Socket��ַ��ʹ�ýṹ���������ýṹ��ָ�봫��
	ʹ�õ���ȫ�ֱ�����
	��������:���緢������
	����ֵ:�������緢�͵���������ʧ�ܷ���0
	*/
	DWORD Send(const BYTE IN *pbBuffer, int IN nSize, sockaddr_in IN *pstDestAddr);

 	/*
	����ԭ��:void SetCrcType(stpCrcType IN stType = CrcType_32)
	����˵��:
		stpCrcType IN stType				Ҫ�趨��Crc����
	ʹ�õ���ȫ�ֱ�����
	��������:
		��������Crc�����ͣ�ʹ��16λCRC����32λCRC
	����ֵ:
	*/
    void SetCrcType(stpCrcType IN stType = CrcType_32);

 	/*
	����ԭ��:void SetCrcMode(BOOL IN boCrcValid, BOOL IN boBigEnddian = TRUE)
	����˵��:
		BOOL IN boCrcValid					��Ч��־�����TRUE��ʾCRC��Ч�������ʾCRC��Ч��CRC��Чʱ������֡�ͽ�֡ʱ�Զ�
											ʹ��ѡ����CRC���͡�
		BOOL IN boBigEnddian				�ֽ�˳�����TRUE��ʾ���ֽ���ǰ��FALSE��ʾ���ֽ���ǰ
	ʹ�õ���ȫ�ֱ�����
	��������:
		��������Crc��ģʽ�������Ƿ�����CRC�Լ�CRC�ڴ���ʱ���ֽ�˳��
	����ֵ:
	*/
    void SetCrcMode(BOOL IN boCrcValid, BOOL IN boBigEnddian = TRUE);

	/*
	����ԭ��:BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen)
	����˵��:
		const BYTE IN *pbFrameBuff				Ҫ���CRC��һ֡���ĵ�����
		WORD IN wFrameLen						֡����
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ж����籨�ĵ�CRC�Ƿ���ȷ������CRC�����ͺ�����ģʽ�����жϡ����ĵ�CRC����������������ĸ��ֽڡ�
	����ֵ:
		�������CRC��ȷ����ô����TRUE�����򷵻�FALSE
	*/
    BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen);

	/*
	����ԭ��:void CloseSocket(void)
	����˵��:
		��
	ʹ�õ���ȫ�ֱ�����
	��������:�ر�����Socket���˳��Ѿ�����Ķಥ�飬�˳��Ѿ��������߳�
	����ֵ:��
	*/
	void CloseSocket(void);

	
	sockaddr_in m_stRemoteSocketAddr;//Զ��Socketʹ�õ���SOCKET��ַ�������յ���Ϣ��Զ��Socket��ַ
	sockaddr_in m_stLocalSocketAddr;//��Socket��ʹ�õ���SOCKET��ַ
	SOCKET m_stLocalSocket;//��Socket��ʹ�õ�SOCKET

	BOOL m_boOpened;//����Socket�Ƿ��Ѿ�����������Ѿ���������ô�����ظ�����
	BOOL m_boAutoRecord;//�Զ���¼�ļ�
	int m_nRecordFileIndex;//�Զ���¼�ļ������
	BOOL m_boCrcValid;//Ĭ��CRC��Ч
	stpCrcType m_stCrcType;//Crc���ͣ�16λCrc����32λCRC
	BOOL m_boCrcBigEnddian;//���ֽ���ǰ�Ŀ��Ʊ���	TRUEΪ���ֽ���ǰ��FALSEΪ���ֽ���ǰ

	//�Զ���ȡ����ʱ�߳̿��Ʊ���
	DWORD (*m_pFuncRcvProcess)(CHAR*, int, sockaddr_in*, LPVOID);//UDPSocket���մ���Ļص������ĺ���ָ�룬
													//���е�һ��������Ҫ���յ����ݵ����ݻ��������ڶ��������ǽ��յ������ݵĳ���
													//������������������Դ��Socket��ַ�����ĸ������Ǵ��ݳ����Ķ��������Ĭ��Ϊ�������
	int m_nCycleLen;//��ѯ���ڳ���
	LPVOID m_pParam;//������������ʱҪ���ݳ����Ĳ���
	DWORD m_dwMaxLenOfFrame;//֡��󳤶�
	BOOL m_boTPUDPSocketRcvEnded;//��������߳��˳����Ʊ��������ڰ�ȫ�Ĺض��߳�

private:			//˽�г�Ա����������
	
	SOCKET m_pstMultiSocket[STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET];//�ಥͨ��Socket
#ifdef JOINGROUP_WSAJoinLeaf
	sockaddr_in m_pstMultiSocketAddr[STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET];//�ಥͨ��Socket��ַ
#else
	ip_mreq m_pstMultiSocketAddr[STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET];//�ಥͨ��Socket��ַ
#endif

	/*
	����ԭ��:UINT __stdcall stpTP_UDPSocketRcv(LPVOID IN pParam)
	����˵��:
		LPVOID IN pParam						Ҫ�����̵߳�UDPͨ�����ָ�룬����ǰ���ָ�룬�˺������ⲻ�ɼ���
												ʹ��ʱ��Ҫ����ǿ��ת��
	ʹ�õ���ȫ�ֱ�����
	��������:
		���մ���Ĺ��ܣ�����������öԽ��յ����������ݽ��н�����������Ŀ���Ǵ�ӡ����������ݣ������ʽΪ����ָ��
	����ֵ:
		�߳�������������0���쳣�˳����ش�����
	*/
	static UINT __stdcall stpTP_UDPSocketRcv(LPVOID IN pParam);


	
	//�̲߳���
	HANDLE m_hThreadRcv;//�����߳�
	UINT m_nThreadRcv;//�����߳�

	BYTE m_pbRcvDATA[STP_UDP_SOCKETMAX_MAX_SIZE_RCV_BUFF];//������ջ�����
 	BYTE m_pbRcvString[STP_UDP_SOCKETMAX_MAX_SIZE_RCV_BUFF * 3];//������ջ�����
	DWORD m_dwReceiveNum;//������յ�������
	HWND m_hwnd;//�������Ĵ�����
};

#endif // !defined(AFX_STPUDPSOCKET_H__C47C4BBA_69CD_45DF_BA4D_94E1AAB143CC__INCLUDED_)
