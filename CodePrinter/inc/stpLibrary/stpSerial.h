/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpSerail.cpp
*	文件标识: 
*	摘要：
*		此类的主要功能有:
*		 1.可以发送和接收完整的一帧报文（0203的转义控制协议）。自动存在转义处理和CRC报文的处理。这些报文是串口通信层
*		   的CRC报文，不是应用层的报文。并可以控制CRC的高字节在前或者是低字节在前。
*		 2.可以自由的控制波特率、数据位、停止位、校验位等参数
*		 3.使用仿真测试平台函数库中的底层函数，需配合仿真测试平台函数库使用，是仿真测试平台函数库中的一部分。
*		 4.可以设置自动记录串口信息的功能。
*		 5.可以设置是按正向传输（从缓冲区低地址开始传输）还是按照反向传输。
*	当前版本：1.0
*	作 者：王伟
*	完成日期：2009-5-24
*
*	取代版本：CSerailEx V0.5
*	作 者：王伟
*	完成日期：2008-12-31
*/


#ifndef _FILE_STP_SERIAL_H__
#define _FILE_STP_SERIAL_H__


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "process.h"
#include "stpDefine.h"

//串口接收缓冲区上限
#define STP_SERAIL_MAX_SIZE_RCV_BUFF					16384		/*16K BYTES*/

//组帧所需内容
#define STP_SERAIL_FRAME_HEAD						(BYTE)0x02		/*帧头*/   
#define STP_SERAIL_FRAME_TAIL						(BYTE)0x03		/*帧尾*/    
#define STP_SERAIL_FRAME_KEY_WORD					(BYTE)0x10		/*转义字符1*/  
#define STP_SERAIL_FRAME_KEY_OFFSET					(BYTE)0x80		/*转义字符2*/  

//错误码

//无效值
#define INVALID_COM									-1				/*无效串口端口*/			

/*
函数原型:UINT __stdcall stpTP_SerialRcv(LPVOID IN pParam)
参数说明:
	LPVOID IN pParam						要开启线程的串口类的指针，即当前类的指针，此函数对外不可见。
											使用时需要进行强制转换
使用到的全局变量：
功能描述:
	接收处理的功能，根据类的设置对接收到的串口数据进行解析，可以进行的解析有CRC16或CRC32，帧头帧尾
	处理（选出完整的一帧进行输出）以及字符转义处理等。输出形式为函数指针
返回值:
	线程正常结束返回0，异常退出返回错误码
*/
UINT __stdcall stpTP_SerialRcv(LPVOID IN pParam);

class AFX_EXT_CLASS CStpSerial
{

public:

	/*
	函数原型:CSerialEx(int IN nCycleLen = 200)
	参数说明:
		int IN nCycleLen			串口接收线程的轮询周期
	使用到的全局变量：
	功能描述:
		构造函数，可初始化轮询周期
	返回值:
		无
	*/
	CStpSerial(int IN nCycleLen = 200);//默认周期长度200ms


	/*
	函数原型:~CSerialEx(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		析构函数。目前无用
	返回值:
		无
	*/
	~CStpSerial(void);

	/*
	函数原型:Open(IN HWND hwnd, IN DWORD (*pFuncRcvCallback)(BYTE*, int, LPVOID), LPVOID IN pParam,
					   IN int nPort, IN int nBaud, IN int nData, IN int nParity, IN int nStop)
	参数说明:
		hwnd				当前窗体的句柄，用于必要的消息传递。
		pFuncRcvCallback	接收处理函数的函数指针，当此函数为NULL时，不开启处理时钟。
							pFuncRcvCallback的参数有三个，第一个BYTE*是接收到的完整一帧的缓冲区地址，第二个int是接收到的完整一帧的
							报文长度，第三个LPVOID是下面传递进来pParam
		pParam				要传递到串口接收线程里的参数，将来作为pFuncRcvCallback中的输出参数
		nPort				端口号
		nBaud			    发送速率
		nData				数据位		  1-5 = 4-9
		nParity				奇偶校验位	  0-4=None,Odd,Even,Mark,Space
		nStop				停止位		  0,1,2 = 1, 1.5, 2
	使用到的全局变量：
	功能描述:
		打开指定的串口设备，并进行必要的初始化工作。
		如果pFuncRcvCallback为NULL的话，那么不会启用线程接收函数，用户如果要接收串口数据时，需开启时钟或线程周期性调用接收函数ReadData。
		如果pFuncRcvCallback不为NULL的话，那么此类会自动开启一个线程接收函数。此时用户接收数据由pFuncRcvCallback完成，每收到一帧
		完整的数据，此函数即会被调用一次。完整一帧的判断标准是始于02终于03且中间无转移字符10。此时用户无需调用ReadData（即ReadData无效）。
	返回值:成功返回1，失败返回0
	*/
	BOOL Open(IN HWND hwnd, IN DWORD (*pFuncRcvCallback)(BYTE*, int, LPVOID), LPVOID IN pParam = NULL,
			   IN int nPort = 1, IN int nBaud = 9600, IN int nData = 4, IN int nParity = 0, IN int nStop = 0);

	/*
	函数原型:Close( void )
	参数说明:
		无
	使用到的全局变量：
	功能描述:关闭串口设备
	返回值:成功返回1
	*/
	BOOL Close(void);

	/*
	函数原型:int ReadDataWaiting(void)
	参数说明:
		无
	使用到的全局变量：
	功能描述:
		获取数据接收缓冲区中的接收数据的长度。非阻塞函数。
	返回值:
		返回接收到数据的长度。-1表示接收时出现错误。
	*/
	int ReadDataWaiting(void);

	/*
	函数原型:DWORD ReadData(BYTE OUT *pbBuffer, DWORD IN dwLimit)
	参数说明:
		OUT void *pbBuffer				接收数据缓冲区
		IN DWORD dwLimit			    接收数据的长度，一般填充接收数据缓冲区的长度
	使用到的全局变量：
	功能描述:读取串口接收到的信息
	返回值:dwBytesRead 返回串口读到的数据量，失败返回0
	*/
	DWORD ReadData(BYTE OUT *pbBuffer, DWORD IN dwLimit);

	/*
	函数原型:DWORD SendData(const BYTE IN *pbBuffer, int IN nSize)
	参数说明:
		IN const char *pbBuffer					发送数据缓冲区
		IN int nSize			                发送数据的长度
	使用到的全局变量：
	功能描述:串口发送数据
	返回值:返回串口发送的数据量，失败返回0
	*/
	DWORD SendData(const BYTE IN *pbBuffer, int IN nSize);

 	/*
	函数原型:BOOL IsOpened(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		用于判断串口是否已经打开。
	返回值:返回串口发送的数据量，失败返回0
	*/
    BOOL IsOpened(void);

 	/*
	函数原型:BOOL GetPortIndex(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		用于获取当前串口的端口号
	返回值:
		当前串口的端口号。无效或未打开时返回-1.
	*/
    int GetPortIndex(void);

 	/*
	函数原型:void SetCycleLen(int IN nCycleLen)
	参数说明:
		int IN nCycleLen	要设定的周期长度
	使用到的全局变量：
	功能描述:
		用于设定串口采集数据的轮询周期
	返回值:
	*/
    void SetCycleLen(int IN nCycleLen);

 	/*
	函数原型:void SetCrcType(stpCrcType IN stType = CrcType_16)
	参数说明:
		stpCrcType IN stType				要设定的Crc类型
	使用到的全局变量：
	功能描述:
		用于设置Crc的类型，使用16位CRC还是32位CRC
	返回值:
	*/
    void SetCrcType(stpCrcType IN stType = CrcType_16);

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
	函数原型:void SetTransferMode(BOOL IN boReverseTransfer = FALSE)
	参数说明:
		BOOL IN boReverseTransfer		是否反向传输。如果TRUE，则从缓冲区的最高字节开始传输，否则从缓冲区的最低字节开始传输
	使用到的全局变量：
	功能描述:
		用于设置Crc的模式，包括是否启用CRC以及CRC在传输时的字节顺序。
	返回值:
	*/
    void SetTransferMode(BOOL IN boReverseTransfer = FALSE);

	/*
	函数原型:void SetAutoRecord(BOOL IN boValid = TRUE)
	参数说明:
		BOOL IN boValid					是否自动记录收发信息，TRUE为自动记录，FALSE为不记录
	使用到的全局变量：
	功能描述:
		用于设置是否自动记录收发信息，全部存放在C:/StpSerialDebug下，以创建时间为文件名。
	返回值:
	*/
    void SetAutoRecord(BOOL IN boValid = TRUE);

	/*
	函数原型:BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen)
	参数说明:
		const BYTE IN *pbFrameBuff				要检查CRC的一帧报文的内容
		WORD IN wFrameLen						帧长度
	使用到的全局变量：
	功能描述:
		判读串口报文的CRC是否正确。根据CRC的类型和启用模式进行判断。报文的CRC在最后两个或者是四个字节。
	返回值:
		如果报文CRC正确，那么返回TRUE，否则返回FALSE
	*/
    BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen);

	//线程函数需使用的变量
	DWORD (*m_pFuncRcvProcess)(BYTE*, int, LPVOID);//处理接收数据的函数指针
	BOOL m_boCrcValid;//默认CRC有效
	BOOL m_boReverseTransfer;//传输时是否翻转顺序
	int m_nCycleLen;//轮询周期长度
	BOOL m_boCrcBigEnddian;//高字节在前的控制变量	TRUE为高字节在前，FALSE为低字节在前
	stpCrcType m_stCrcType;//Crc类型，16位Crc或者32位CRC
	BOOL m_boAutoRecord;//自动记录调试信息。即串口的收发信息，全部存放在C:/StpSerialDebug下，以创建时间为文件名
	int m_nRecordFileIndex;//自动记录文件的序号
	LPVOID m_pParam;//串口向外扔数时要传递出来的参数
	DWORD m_dwMaxLenOfFrame;//帧最大长度
	BOOL m_boTPSerialRcvEnded;//串口接收线程退出控制变量，用于安全的关断线程

private:
	/*
	函数原型:WriteCommByte(BYTE bWriteByte)
	参数说明:
		IN  BYTE bWriteByte        要写入串口的数据
	使用到的全局变量：
	功能描述:单字节写入串口
	返回值:成功返回1
	*/
	BOOL WriteCommByte(BYTE bWriteByte);


	/*
	函数原型:
	参数说明:
		IN const BYTE* pbInBuffer        需要组帧的原始数据
		IN int nBufferSize			    原始数据的长度
		OUT BYTE* pbSendBuff             组完帧的数据
		OUT WORD &wSendSize             组完帧的长度
	使用到的全局变量：
	功能描述:对原始数据进行组帧和转义处理
	返回值:无
	*/
	void BuildFrame(const BYTE* pbInBuffer, int nBufferSize, BYTE* pbSendBuff, WORD &wSendSize);

	//线程参数
	HANDLE m_hThreadRcv;//接收线程
	UINT m_nThreadRcv;//接收线程

	//配置参数
	HANDLE m_hIDComDev;
	OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
	BOOL m_boOpened;//串口打开与否的标志
	BYTE m_pbRcvDATA[STP_SERAIL_MAX_SIZE_RCV_BUFF];//串口接收缓冲区
    DWORD m_dwReceiveNum;//串口接收缓冲区
	int m_nPort;//串口端口号
	HWND m_hwnd;//类所属的窗体句柄
};

#endif
