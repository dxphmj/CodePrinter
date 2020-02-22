/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpUDPSocket.h
*	文件标识: 仿真测试平台函数库中实现UDP通信的类
*	摘要：
*		此类的主要功能有:
*		 1.可以实现UDP数据的单播发送与单播接收。
*		 2.可以实现UDP数据的组播发送与组播接收。
*		 3.使用仿真测试平台函数库中的底层函数，需配合仿真测试平台函数库使用，是仿真测试平台函数库中的一部分。
*	当前版本：1.0
*	作 者：王伟
*	完成日期：2009-6-13
*
*	取代版本：Comm_V_2.h
*	作 者：王伟
*	完成日期：2008-12-31
*/
//////////////////////////////////////////////////////////////////////

#ifndef _FILE_STP_UDP_SOCKET_H__
#define _FILE_STP_UDP_SOCKET_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//----------------------包含头文件-----------------------------------------
#include "winsock2.h"
#include "ws2tcpip.h"
#include "stpDefine.h"
//----------------------宏定义-----------------------------------------
//错误码定义
#define STP_ERR_SOCK_SUCCESS						0				//成功
#define STP_ERR_SOCK_PORT_BUSY						0xFFFF0000		//端口被占用					
#define STP_ERR_SOCK_BIND_FAILED					0xFFFF0001		//绑定失败
#define STP_ERR_SOCK_JOIN_GROUP_FAILED				0xFFFF0002		//加入多播组失败
#define STP_ERR_SOCK_CHANGE_OPTION_FAILED			0xFFFF0003		//修改Socket功能失败
#define STP_ERR_SOCK_CREATE_FAILED					0xFFFF0004		//Socket创建失败					
#define STP_ERR_SOCK_TRY_REOPEN						0xFFFF0005		//尝试重新打开一个Socket，在使用时必须先关闭才能再打开					
#define STP_ERR_SOCK_CLOSED							0xFFFF0006		//Socket尚未开启，如果需要使用多播组，首先打开Socket			
#define STP_ERR_SOCK_INVALID_GROUP					0xFFFF0007		//无效多播组
#define STP_ERR_SOCK_ALREADY_IN_GROUP				0xFFFF0008		//已经加入多播组

#define STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET		40				//Socket所能加入的多播组的个数

#define STP_UDP_SOCKETMAX_MAX_SIZE_RCV_BUFF			1500			//1500字节，最大只接收一个MTU

//#define JOINGROUP_WSAJoinLeaf										//设定使用多播组的方式

//UDP通信类的声明
class AFX_EXT_CLASS CstpUDPSocket  
{
public:

	/*
	函数原型CstpUDPSocket(int IN nCycleLen = 200)
	参数说明:
		int IN nCycleLen			网络接收线程的轮询周期
	使用到的全局变量：
	功能描述:构造函数,初始化动态库。
	返回值:无
	*/
	CstpUDPSocket(int IN nCycleLen = 200);//构造函数	目前没用

	/*
	函数原型:virtual ~CstpUDPSocket(void)
	参数说明:
	使用到的全局变量：
	功能描述:析构函数,释放动态库。进行必要的空间释放工作
	返回值:无
	*/
	virtual ~CstpUDPSocket(void);//析构函数	目前没用

	/*
	函数原型:DWORD StartSocket(DWORD IN dwIP, WORD IN wPort)
	参数说明:
		DWORD IN dwIP									本地IP地址，双字节描述
		WORD IN wPort									本Socket要使用的本地端口
	使用到的全局变量：
		无
	功能描述:通过输入用字节描述的IP地址和端口描述，开启Socket功能，并绑定端口
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD StartSocket(DWORD IN dwIP, WORD IN wPort);

	/*
	函数原型:DWORD StartSocket(const CHAR IN szIP[], int IN nPort)
	参数说明:
		const CHAR IN szIP[]									本地IP地址，字符串描述描述
		int IN nPort									本Socket要使用的本地端口
	使用到的全局变量：
		无
	功能描述:通过输入用字符串描述的IP地址和用十进制描述的端口，开启Socket功能，并绑定端口
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD StartSocket(const CHAR IN szIP[], int IN nPort);

	/*
	函数原型:DWORD StartSocket(sockaddr_in IN *pstLocalSocketAddr)
	参数说明:
		sockaddr_in IN *pstLocalSocketAddr				本地Socket地址，使用结构体描述，用结构体指针传递
	使用到的全局变量：
		无
	功能描述:通过输入结构体描述的Socket地址，开启Socket功能，并绑定端口
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD StartSocket(sockaddr_in IN *pstLocalSocketAddr);

	/*
	函数原型:DWORD StartSocketEx(DWORD IN dwIP, WORD IN wPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL)
	参数说明:
		DWORD IN dwIP									本地IP地址，双字节描述
		WORD IN wPort									本Socket要使用的本地端口
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID)
														UDPSocket接收处理的回调函数的函数指针，
														其中第一个参数是要接收到数据的数据缓冲区，第二个参数是接收到的数据的长度
														第三个参数是数据来源的Socket地址，第四个参数是传递出来的额外参数，默认为句柄参数
		HWND IN hwnd									窗体句柄参数，通信类所基于的窗口
		LPVOID IN pParam = NULL							预留参数
	使用到的全局变量：
		无
	功能描述:通过输入用字节描述的IP地址和端口描述，开启Socket功能，并绑定端口，并启动自动接收数据的线程。
			数据处理需要使用pFuncRcvCallback的回调函数
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD StartSocketEx(DWORD IN dwIP, WORD IN wPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL);

	/*
	函数原型:DWORD StartSocketEx(const CHAR IN szIP[], int IN nPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL)
	参数说明:
		const CHAR IN szIP[]									本地IP地址，字符串描述描述
		int IN nPort									本Socket要使用的本地端口
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID)
														UDPSocket接收处理的回调函数的函数指针，
														其中第一个参数是要接收到数据的数据缓冲区，第二个参数是接收到的数据的长度
														第三个参数是数据来源的Socket地址，第四个参数是传递出来的额外参数，默认为句柄参数
		HWND IN hwnd									窗体句柄参数，通信类所基于的窗口
		LPVOID IN pParam = NULL							预留参数
	使用到的全局变量：
		无
	功能描述:通过输入用字符串描述的IP地址和用十进制描述的端口，开启Socket功能，并绑定端口，并启动自动接收数据的线程。
			数据处理需要使用pFuncRcvCallback的回调函数
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD StartSocketEx(const CHAR IN szIP[], int IN nPort, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL);

	/*
	函数原型:DWORD StartSocketEx(sockaddr_in IN *pstLocalSocketAddr, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL)
	参数说明:
		sockaddr_in IN *pstLocalSocketAddr				本地Socket地址，使用结构体描述，用结构体指针传递
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID)
														UDPSocket接收处理的回调函数的函数指针，
														其中第一个参数是要接收到数据的数据缓冲区，第二个参数是接收到的数据的长度
														第三个参数是数据来源的Socket地址，第四个参数是传递出来的额外参数，默认为句柄参数
		HWND IN hwnd									窗体句柄参数，通信类所基于的窗口
		LPVOID IN pParam = NULL							预留参数
	使用到的全局变量：
		无
	功能描述:通过输入结构体描述的Socket地址，开启Socket功能，并绑定端口，并启动自动接收数据的线程。
			数据处理需要使用pFuncRcvCallback的回调函数
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD StartSocketEx(sockaddr_in IN *pstLocalSocketAddr, 
		DWORD (*pFuncRcvCallback)(CHAR*, int, sockaddr_in*, LPVOID),
		HWND IN hwnd, LPVOID IN pParam = NULL);

	/*
	函数原型:DWORD JoinGroup(const CHAR IN szIP[])
	参数说明:
		const CHAR IN szIP[]							要加入的多播组地址
	使用到的全局变量：
		无
	功能描述:通过输入用字节描述的多播组地址，加入指定多播组
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD JoinGroup(const CHAR IN szIP[]);

	/*
	函数原型:DWORD QuitGroup(const CHAR IN szIP[])
	参数说明:
		const CHAR IN szIP[]							要退出的多播组地址
	使用到的全局变量：
		无
	功能描述:通过输入用字节描述的多播组地址，退出指定多播组
	返回值:
		成功返回0，失败返回错误码
	*/
	DWORD QuitGroup(const CHAR IN szIP[]);

	/*
	函数原型:void QuitAllGroup(void)
	参数说明:
	使用到的全局变量：
		无
	功能描述:退出已加入的所有多播组
	返回值:
	*/
	void QuitAllGroup(void);

	/*
	函数原型:void SetAutoRecord(BOOL IN boValid = TRUE)
	参数说明:
		BOOL IN boValid					是否自动记录收发信息，TRUE为自动记录，FALSE为不记录
	使用到的全局变量：
	功能描述:
		用于设置是否自动记录收发信息，全部存放在C:/StpUDPSocketDebug下，以创建时间为文件名。
	返回值:
	*/
	void SetAutoRecord(BOOL IN boValid = TRUE);

 	/*
	函数原型:BOOL IsOpened(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		用于判断网络是否已经打开。
	返回值:返回Socket的状态，如果开启返回TRUE，否则返回FALSE
	*/
    BOOL IsOpened(void);

 	/*
	函数原型:void SetCycleLen(int IN nCycleLen)
	参数说明:
		int IN nCycleLen	要设定的周期长度
	使用到的全局变量：
	功能描述:
		用于设定网络采集数据的轮询周期
	返回值:
	*/
    void SetCycleLen(int IN nCycleLen);

	/*
	函数原型:DWORD Send(const BYTE IN *pbBuffer, int IN nSize, DWORD IN dwIP, WORD IN wPort)
	参数说明:
		IN const CHAR *pbBuffer					发送数据缓冲区
		IN int nSize			                发送数据的长度
		DWORD IN dwIP									本地IP地址，双字节描述
		WORD IN wPort									本Socket要使用的本地端口
	使用到的全局变量：
	功能描述:网络发送数据
	返回值:返回网络发送的数据量，失败返回0
	*/
	DWORD Send(const BYTE IN *pbBuffer, int IN nSize, DWORD IN dwIP, WORD IN wPort);

	/*
	函数原型:DWORD Send(const BYTE IN *pbBuffer, int IN nSize, const CHAR IN szIP[], int IN nPort)
	参数说明:
		IN const CHAR *pbBuffer					发送数据缓冲区
		IN int nSize			                发送数据的长度
		CHAR IN szIP[]									本地IP地址，字符串描述描述
		int IN nPort									本Socket要使用的本地端口
	使用到的全局变量：
	功能描述:网络发送数据
	返回值:返回网络发送的数据量，失败返回0
	*/
	DWORD Send(const BYTE IN *pbBuffer, int IN nSize, const CHAR IN szIP[], int IN nPort);

	/*
	函数原型:DWORD Send(const BYTE IN *pbBuffer, int IN nSize, sockaddr_in IN *pstDestAddr)
	参数说明:
		IN const CHAR *pbBuffer					发送数据缓冲区
		IN int nSize			                发送数据的长度
		sockaddr_in IN *pstDestAddr				远程Socket地址，使用结构体描述，用结构体指针传递
	使用到的全局变量：
	功能描述:网络发送数据
	返回值:返回网络发送的数据量，失败返回0
	*/
	DWORD Send(const BYTE IN *pbBuffer, int IN nSize, sockaddr_in IN *pstDestAddr);

 	/*
	函数原型:void SetCrcType(stpCrcType IN stType = CrcType_32)
	参数说明:
		stpCrcType IN stType				要设定的Crc类型
	使用到的全局变量：
	功能描述:
		用于设置Crc的类型，使用16位CRC还是32位CRC
	返回值:
	*/
    void SetCrcType(stpCrcType IN stType = CrcType_32);

 	/*
	函数原型:void SetCrcMode(BOOL IN boCrcValid, BOOL IN boBigEnddian = TRUE)
	参数说明:
		BOOL IN boCrcValid					有效标志，如果TRUE表示CRC有效，否则表示CRC无效。CRC有效时会在组帧和解帧时自动
											使用选定的CRC类型。
		BOOL IN boBigEnddian				字节顺序，如果TRUE表示高字节在前，FALSE表示低字节在前
	使用到的全局变量：
	功能描述:
		用于设置Crc的模式，包括是否启用CRC以及CRC在传输时的字节顺序。
	返回值:
	*/
    void SetCrcMode(BOOL IN boCrcValid, BOOL IN boBigEnddian = TRUE);

	/*
	函数原型:BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen)
	参数说明:
		const BYTE IN *pbFrameBuff				要检查CRC的一帧报文的内容
		WORD IN wFrameLen						帧长度
	使用到的全局变量：
	功能描述:
		判读网络报文的CRC是否正确。根据CRC的类型和启用模式进行判断。报文的CRC在最后两个或者是四个字节。
	返回值:
		如果报文CRC正确，那么返回TRUE，否则返回FALSE
	*/
    BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen);

	/*
	函数原型:void CloseSocket(void)
	参数说明:
		无
	使用到的全局变量：
	功能描述:关闭网络Socket，退出已经加入的多播组，退出已经开启的线程
	返回值:无
	*/
	void CloseSocket(void);

	
	sockaddr_in m_stRemoteSocketAddr;//远程Socket使用到的SOCKET地址，即接收到信息的远端Socket地址
	sockaddr_in m_stLocalSocketAddr;//本Socket类使用到的SOCKET地址
	SOCKET m_stLocalSocket;//本Socket类使用的SOCKET

	BOOL m_boOpened;//本地Socket是否已经开启，如果已经开启了那么无需重复开启
	BOOL m_boAutoRecord;//自动记录文件
	int m_nRecordFileIndex;//自动记录文件的序号
	BOOL m_boCrcValid;//默认CRC有效
	stpCrcType m_stCrcType;//Crc类型，16位Crc或者32位CRC
	BOOL m_boCrcBigEnddian;//高字节在前的控制变量	TRUE为高字节在前，FALSE为低字节在前

	//自动收取数据时线程控制变量
	DWORD (*m_pFuncRcvProcess)(CHAR*, int, sockaddr_in*, LPVOID);//UDPSocket接收处理的回调函数的函数指针，
													//其中第一个参数是要接收到数据的数据缓冲区，第二个参数是接收到的数据的长度
													//第三个参数是数据来源的Socket地址，第四个参数是传递出来的额外参数，默认为句柄参数
	int m_nCycleLen;//轮询周期长度
	LPVOID m_pParam;//网络向外扔数时要传递出来的参数
	DWORD m_dwMaxLenOfFrame;//帧最大长度
	BOOL m_boTPUDPSocketRcvEnded;//网络接收线程退出控制变量，用于安全的关断线程

private:			//私有成员函数及变量
	
	SOCKET m_pstMultiSocket[STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET];//多播通信Socket
#ifdef JOINGROUP_WSAJoinLeaf
	sockaddr_in m_pstMultiSocketAddr[STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET];//多播通信Socket地址
#else
	ip_mreq m_pstMultiSocketAddr[STP_UDP_SOCKET_MAX_COUNT_GROUP_SOCKET];//多播通信Socket地址
#endif

	/*
	函数原型:UINT __stdcall stpTP_UDPSocketRcv(LPVOID IN pParam)
	参数说明:
		LPVOID IN pParam						要开启线程的UDP通信类的指针，即当前类的指针，此函数对外不可见。
												使用时需要进行强制转换
	使用到的全局变量：
	功能描述:
		接收处理的功能，根据类的设置对接收到的网络数据进行解析，解析的目的是打印网络接收数据，输出形式为函数指针
	返回值:
		线程正常结束返回0，异常退出返回错误码
	*/
	static UINT __stdcall stpTP_UDPSocketRcv(LPVOID IN pParam);


	
	//线程参数
	HANDLE m_hThreadRcv;//接收线程
	UINT m_nThreadRcv;//接收线程

	BYTE m_pbRcvDATA[STP_UDP_SOCKETMAX_MAX_SIZE_RCV_BUFF];//网络接收缓冲区
 	BYTE m_pbRcvString[STP_UDP_SOCKETMAX_MAX_SIZE_RCV_BUFF * 3];//网络接收缓冲区
	DWORD m_dwReceiveNum;//网络接收到的数据
	HWND m_hwnd;//类所属的窗体句柄
};

#endif // !defined(AFX_STPUDPSOCKET_H__C47C4BBA_69CD_45DF_BA4D_94E1AAB143CC__INCLUDED_)
