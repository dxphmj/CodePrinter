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
//该程序声明
//header
#include <WINSOCK2.H>
#include <afxmt.h>
#pragma comment(lib, "ws2.lib")

//类型
//#define		SERVMESSAGE			200							//服务器消息
//#define		USERINFOR			201							//用户信息
//数据包类型定义
#define		CONTROL_CE				1					//控制
#define		PRINT_CE				2					//打印数据下发
#define		PRINTGET_CE				3					//打印字节传回
#define		COLLECT_CE				4					//采集数据
#define		COUNTER_CE				5					//计数器
#define		LAB_NAME				6					//lab名
#define		OTHER_CE				10					//其他

//自定义消息
#define WM_USER_ACCEPT		(WM_USER + 200)//FD_ACCEPT
#define WM_USER_READ		(WM_USER + 201)//FD_READ
#define WM_USER_CLOSE		(WM_USER + 202)//FD_CLOSE


//MACRO
#define		SERVERPORT			8899						//服务器端口
#define		MAX_NUM_EVENTS		WSA_MAXIMUM_WAIT_EVENTS		//最大事件对象数量
#define		SERVER_WAIT_TIMEOUT	100							//睡眠时间

//结构大小
#define		CLIENTPACKETLEN		(sizeof(CLINETPACKET))		//客户端数据包长度
#define		PACKETHDRLEN		(sizeof(PACKETHDR))			//包头长度

//服务器与客户端发送数据包头
typedef struct _packethdr
{
	u_short	type;	//类型
	u_short	len;	//数据包长度(包体)
}PACKETHDR, *PPACKETHDR;

//线程函数参数
typedef struct _threadparam
{
	HWND	hServHwnd;		//主窗口句柄
	BOOL	*pRunning;		//线程运行状态
	WORD	*pTotalEvent;	//事件对象数量
	WSAEVENT*pArrEvent;		//事件对象数组
	SOCKET	*pArrSocket;	//套接字句柄数组
	HANDLE	hEventExit;		//线程退出事件句柄
}THREADPARAM, *PTHREADPARAM;

class CClientSocket;
typedef struct __threadparamC
{
	CClientSocket *pClient;
}THECLIENT,*PTHECLIENT;