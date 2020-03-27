// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")

// 注意 - 这个值与作为目标的 Windows CE OS 版本的关联性并不强
#define WINVER _WIN32_WCE

//#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _STP_FUNC_LIBRARY		//要使用共用函数库
#define _STP_UDP_SOCKET_LIBRARY		//要使用UDP通信函数库

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// 从 Windows 头中排除极少使用的资料
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的
#ifdef _CE_DCOM
#define _ATL_APARTMENT_THREADED
#endif

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <ceconfig.h>
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#define SHELL_AYGSHELL
#endif

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC 对 Internet Explorer 4 公共控件的支持
#endif


#include <afxdisp.h>        // MFC 自动化类

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC 套接字扩展
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
/*应用程序定义*/
#include "Resource.h"

#include  <afxtempl.h> 
#include "winsock2.h"
#pragma comment(lib, "ws2.lib")
//#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF", "adoEOF") 

#define		SERVERPORT			8899						//服务器端口
#define		THREAD_SLEEP_TIME	100							//线程睡眠时间
#define		HEADERLEN			(sizeof(PACKETHDR))			//包头长度
#define		WM_USER_ADDWORD		(WM_USER + 100)				//添加单词

//数据包头声明
#define		ETOC				0							//英译汉
#define		CTOE				1							//汉译英
typedef struct _packethdr
{
	u_short	type;	//类型
	u_short	len;	//数据包长度(包体)
}PACKETHDR, *PPACKETHDR;

class CCodePrinterDlg;
typedef struct _threadparam
{
	HWND		hServHwnd;	//主窗口句柄
	CCodePrinterDlg *pServView;	//主窗口指针
}THREADPARAM, *PTHREADPARAM;

class CClientSocket;
typedef struct __threadparamC
{
	CClientSocket *pClient;
}THECLIENT,*PTHECLIENT;