/**********************************************************************************************
*@FileName:CSTPSerialPort.h
*@Author:chengyuanjun
*@Date:2013-06-12 09:55:08
*@Copyright: 2012-2014 TCT Incorporated
*@Desp:本文件实现了对串口的基本管理
*@Revision:
*@Date		@Author			@Content
*	
***********************************************************************************************/

#ifndef __TCT_STP__CSTPSERIALPORT__H__
#define __TCT_STP__CSTPSERIALPORT__H__

/*****************************************************************
*@Head Files Of Lib---系统头文件
*****************************************************************/


/*****************************************************************
*@Head Files Of User---用户自定义头文件
*****************************************************************/


/*****************************************************************
*@Global Var---全局变量声明
*****************************************************************/


/*****************************************************************
*@Macro Definition---宏定义
*****************************************************************/


/*****************************************************************
*@Struct Definition---结构体定义
*****************************************************************/


/*****************************************************************
*@Class Definition---类定义
*****************************************************************/
typedef struct  
{
	UINT32 nPortNo;
	UINT32 nBaudRate; 
	BYTE byDataBit;
	BYTE byStopBit; 
	BYTE byParity;
}TSTPSPInfo;

class CSTPSerialPort
{
	//------------------------------------------------------------
	//CSTPSerialPort的函数成员
	public:
		CSTPSerialPort();
		virtual ~CSTPSerialPort();
		int Open(UINT32 nPortNo, UINT32 nBaudRate, BYTE byDataBit, BYTE byStopBit, BYTE byParity);
		int Open(TSTPSPInfo* pSPInfo);
		int Close();
		int Send(BYTE* pSendBuf, UINT32 nToSndLen, UINT32* pSendLen);
		int Receive(BYTE* pRecvBuf, UINT32 nRecvSize, UINT32* pRecvLen);
		BOOL IsOpened();
		void GetPortInfo(TSTPSPInfo* pInfo);
		HANDLE GetHandle(){return m_hCOM;}
	private:
	protected:
	
	//------------------------------------------------------------
	//CSTPSerialPort的数据成员
	public:
		enum
		{
			NO_PARITY = (BYTE)0,			//1个停止位
			ODD_PARITY = (BYTE)1,			//1个半停止位
			EVEN_PARITY = (BYTE)2,			//2个停止位
		};
		enum
		{
			STOPBIT_ONE = (BYTE)0,			//1个停止位
			STOPBIT_ONE5 = (BYTE)1,			//1个半停止位
			STOPBIT_TWO = (BYTE)2,			//2个停止位
		};
	private:
		BOOL m_bOpenFlag;				//串口是否打开的标志
		HANDLE m_hCOM;					//串口设备的句柄
		OVERLAPPED m_OverlappedRead;
		OVERLAPPED m_OverlappedWrite;
		TSTPSPInfo m_stPortInfo;
};

/**********************************************************************************************
***************************************内联函数************************************************
**********************************************************************************************/


//==============================================================================================
//函 数 名：
//函数参数:
//返 回 值：
//功能描述:
//==============================================================================================


//==============================================================================================
//函 数 名：
//函数参数:
//返 回 值：
//功能描述:
//==============================================================================================

#endif

/*****************************************************************
*@Header Documention---头文件文档说明
*****************************************************************/

