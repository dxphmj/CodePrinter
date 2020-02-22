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
#include <math.h>
#include "./inc/stpLibrary/stpLibrary.h"			//����ͷ�ļ���ʹ�ö�̬���ӿ�
//#pragma comment( lib, "Ws2.lib" )

#include "vector"

using namespace std;

#define		PAPER_BUFFER_SIZE	(1024*10)					//���⻺����1024*10
#define		ANSWER_BUFFER_SIZE	(50)						//�𰸻�����
#define		HEADELEN			(sizeof(HDR))				//��ͷ����
#define		OVERLAPPEDPLUSLEN	(sizeof(IO_OPERATION_DATA))	//��չ�ص��ṹ����
#define		SERVERPORT			5561						//�������˿�
#define		BUFFER_SIZE			(128)						//�������ݻ�����64


//������߳�����
#define		MAX_SUBTHREAD_SIZE	(15)							//������߳����� 

//ѧ�ų���
#define		SNLEN				4							//ѧ�ų���

//I/O��������
#define		IOReadHead			10							//���հ�ͷ  //01 03 ���ֽ���ǰ�����ֽ��ں�
#define		IOReadBody			11							//���հ���
#define		IOWriteInfo			12							//���հ���
#define		IOWriteUnLogin		13							//��֤ʧ��
#define		IOWriteSTNAME		14							//��������
#define		IOWritePAPER		15							//�����Ծ�
#define		IOEXIT				16							//�ͻ����˳�



//������
#define		Command03			03							//03ָ��
#define		Command04			04							//04ָ��
#define		STNAME				102							//ѧ������	|������
#define		PAPER				103							//�Ծ�		|
//��ͷ
typedef struct _header
{
	BYTE		usHead[6];	//��ַ
	BYTE		usAdress;	//��ַ
	BYTE		usCommandType;	//��������
}HDR, *PHDER;

//������Ϣ
typedef struct _studentinfo
{
	CString	strSN;		//ѧ��S:student N:Number
	CString	strName;	//����
	CString	strState;	//״̬
	u_short usGrade;	//����
}STUDENTINFO, *PSTUDENTINFO;

// I/O �������ݽṹ
typedef	struct _io_operation_data 
{
	OVERLAPPED	overlapped;					//�ص��ṹ
	char		recvBuf[BUFFER_SIZE];		//�������ݻ�����
	HDR			hdr;						//��ͷ
	byte		type;						//��������
}IO_OPERATION_DATA, *PIO_OPERATION_DATA;