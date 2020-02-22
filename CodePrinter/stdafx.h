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
#include <math.h>
#include "./inc/stpLibrary/stpLibrary.h"			//包含头文件并使用动态链接库
//#pragma comment( lib, "Ws2.lib" )

#include "vector"

using namespace std;

#define		PAPER_BUFFER_SIZE	(1024*10)					//试题缓冲区1024*10
#define		ANSWER_BUFFER_SIZE	(50)						//答案缓冲区
#define		HEADELEN			(sizeof(HDR))				//包头长度
#define		OVERLAPPEDPLUSLEN	(sizeof(IO_OPERATION_DATA))	//扩展重叠结构长度
#define		SERVERPORT			5561						//服务器端口
#define		BUFFER_SIZE			(128)						//接收数据缓冲区64


//最大子线程数量
#define		MAX_SUBTHREAD_SIZE	(15)							//最多子线程数量 

//学号长度
#define		SNLEN				4							//学号长度

//I/O操作类型
#define		IOReadHead			10							//接收包头  //01 03 低字节在前，高字节在后
#define		IOReadBody			11							//接收包体
#define		IOWriteInfo			12							//接收包体
#define		IOWriteUnLogin		13							//验证失败
#define		IOWriteSTNAME		14							//发送姓名
#define		IOWritePAPER		15							//发送试卷
#define		IOEXIT				16							//客户端退出



//包类型
#define		Command03			03							//03指令
#define		Command04			04							//04指令
#define		STNAME				102							//学生姓名	|服务器
#define		PAPER				103							//试卷		|
//包头
typedef struct _header
{
	BYTE		usHead[6];	//地址
	BYTE		usAdress;	//地址
	BYTE		usCommandType;	//命令类型
}HDR, *PHDER;

//考生信息
typedef struct _studentinfo
{
	CString	strSN;		//学号S:student N:Number
	CString	strName;	//姓名
	CString	strState;	//状态
	u_short usGrade;	//分数
}STUDENTINFO, *PSTUDENTINFO;

// I/O 操作数据结构
typedef	struct _io_operation_data 
{
	OVERLAPPED	overlapped;					//重叠结构
	char		recvBuf[BUFFER_SIZE];		//接收数据缓冲区
	HDR			hdr;						//包头
	byte		type;						//操作类型
}IO_OPERATION_DATA, *PIO_OPERATION_DATA;