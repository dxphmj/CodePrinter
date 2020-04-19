// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")

// ע�� - ���ֵ����ΪĿ��� Windows CE OS �汾�Ĺ����Բ���ǿ
#define WINVER _WIN32_WCE

//#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _STP_FUNC_LIBRARY		//Ҫʹ�ù��ú�����
#define _STP_UDP_SOCKET_LIBRARY		//Ҫʹ��UDPͨ�ź�����

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// �� Windows ͷ���ų�����ʹ�õ�����
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯��������ʽ��
#ifdef _CE_DCOM
#define _ATL_APARTMENT_THREADED
#endif

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <ceconfig.h>
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#define SHELL_AYGSHELL
#endif

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �����ؼ���֧��
#endif


#include <afxdisp.h>        // MFC �Զ�����

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC �׽�����չ
#include <afxmt.h>

#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#ifndef _DEVICE_RESOLUTION_AWARE
#define _DEVICE_RESOLUTION_AWARE
#endif
#endif

#ifdef _DEVICE_RESOLUTION_AWARE
#include "DeviceResolutionAware.h"
#endif


#if (_WIN32_WCE < 0x500) && ( defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP) )
	#pragma comment(lib, "ccrtrtti.lib")
	#ifdef _X86_	
		#if defined(_DEBUG)
			#pragma comment(lib, "libcmtx86d.lib")
		#else
			#pragma comment(lib, "libcmtx86.lib")
		#endif
	#endif
#endif

#include <altcecrt.h>



/////////////////////////////////////
//�ó�������
//header
#include <WINSOCK2.H>
#include <afxmt.h>
#pragma comment(lib, "ws2.lib")

//����
//#define		SERVMESSAGE			200							//��������Ϣ
//#define		USERINFOR			201							//�û���Ϣ
//���ݰ����Ͷ���
#define		CONTROL_CE				1					//����
#define		PRINT_CE				2					//��ӡ�����·�
#define		PRINTGET_CE				3					//��ӡ�ֽڴ���
#define		COLLECT_CE				4					//�ɼ�����
#define		COUNTER_CE				5					//������
#define		LAB_NAME				6					//lab��
#define		OTHER_CE				10					//����

//�Զ�����Ϣ
#define WM_USER_ACCEPT		(WM_USER + 200)//FD_ACCEPT
#define WM_USER_READ		(WM_USER + 201)//FD_READ
#define WM_USER_CLOSE		(WM_USER + 202)//FD_CLOSE


//MACRO
#define		SERVERPORT			8899						//�������˿�
#define		MAX_NUM_EVENTS		WSA_MAXIMUM_WAIT_EVENTS		//����¼���������
#define		SERVER_WAIT_TIMEOUT	100							//˯��ʱ��

//�ṹ��С
#define		CLIENTPACKETLEN		(sizeof(CLINETPACKET))		//�ͻ������ݰ�����
#define		PACKETHDRLEN		(sizeof(PACKETHDR))			//��ͷ����

//��������ͻ��˷������ݰ�ͷ
typedef struct _packethdr
{
	u_short	type;	//����
	u_short	len;	//���ݰ�����(����)
}PACKETHDR, *PPACKETHDR;

//�̺߳�������
typedef struct _threadparam
{
	HWND	hServHwnd;		//�����ھ��
	BOOL	*pRunning;		//�߳�����״̬
	WORD	*pTotalEvent;	//�¼���������
	WSAEVENT*pArrEvent;		//�¼���������
	SOCKET	*pArrSocket;	//�׽��־������
	HANDLE	hEventExit;		//�߳��˳��¼����
}THREADPARAM, *PTHREADPARAM;

class CClientSocket;
typedef struct __threadparamC
{
	CClientSocket *pClient;
}THECLIENT,*PTHECLIENT;