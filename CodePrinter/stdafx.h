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
/*Ӧ�ó�����*/
#include "Resource.h"

#include  <afxtempl.h> 
#include "winsock2.h"
#pragma comment(lib, "ws2.lib")
//#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF", "adoEOF") 

#define		SERVERPORT			8899						//�������˿�
#define		THREAD_SLEEP_TIME	100							//�߳�˯��ʱ��
#define		HEADERLEN			(sizeof(PACKETHDR))			//��ͷ����
#define		WM_USER_ADDWORD		(WM_USER + 100)				//��ӵ���

//���ݰ�ͷ����
#define		ETOC				0							//Ӣ�뺺
#define		CTOE				1							//����Ӣ
typedef struct _packethdr
{
	u_short	type;	//����
	u_short	len;	//���ݰ�����(����)
}PACKETHDR, *PPACKETHDR;

class CCodePrinterDlg;
typedef struct _threadparam
{
	HWND		hServHwnd;	//�����ھ��
	CCodePrinterDlg *pServView;	//������ָ��
}THREADPARAM, *PTHREADPARAM;

class CClientSocket;
typedef struct __threadparamC
{
	CClientSocket *pClient;
}THECLIENT,*PTHECLIENT;