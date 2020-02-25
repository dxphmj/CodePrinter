/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpTrace.h
*	文件标识: 这是CBTC仿真测试平台中封装的公用函数库中封装文件记录功能的代码文件。
*	摘要：
*		此文件实现的主要功能有:
*		 1.通过1个初始化函数把写文件的相关变量做初始化赋值。
*		 2.stpTrace：把TRACE的内容输出到特定的文件中。
*		 3.通过不同的启动函数，可以设定不同的输出文件。并产生文件的ID。
*		 4.stpTraceEx：把TRACE的文件输出到以ID为编号的文件当中。
*	当前版本：0.0.0.20090519
*	作 者：王伟
*	完成日期：2009年5月19日
*
*	取代版本：
*	作 者：
*	完成日期：
*/

#ifndef FILE_STP_TRACE_H /* stpTrace.h */
#define FILE_STP_TRACE_H

#include "stpDefine.h"


/*----------------宏定义----------------------------------*/
#define ERR_CODE_FLAG								0xff000000	/*错误码的标志。当大于此值时表示必然出现了错误*/
#define ERR_CODE_TRACE_UNKOWN						0xffff0200	/*未知错误*/
#define ERR_CODE_TRACE_BUFF_OVERFLOW				0xffff0201	/*记录文件中缓冲区溢出*/
#define ERR_CODE_TRACE_ILLEGAL_INPUT				0xffff0202	/*非法输入*/
#define ERR_CODE_TRACE_FILE_CLOSED					0xffff0203	/*记录文件未打开*/
#define ERR_CODE_TRACE_FILL_COUNT_OVERFLOW			0xffff0204	/*记录文件不够用*/
#define ERR_CODE_TRACE_CREATE_FILE_FAILURE			0xffff0205	/*创建文件失败*/
#define ERR_CODE_TRACE_INVALID_FORMAT				0xffff0206	/*格式化串无效*/
#define ERR_CODE_TRACE_DISABLE						0xffff02ff	/*记录功能被关闭*/


#define MAX_COUNT_FILE_INDEX						100			/*记录函数可以同时记录文件的上限*/


/*----------------类型定义---------------------------------*/


/*----------------函数声明---------------------------------*/
/*
函数原型:void stpStartTrace(void)
参数说明:
功能描述:
	用于开启文件记录功能。
返回值:
*/
void stpStartTrace(void);

/*
函数原型:void stpEndTrace(void)
参数说明:
功能描述:
	用于关闭文件记录功能。
返回值:
*/
void stpEndTrace(void);

/*
函数原型:void stpInitTrace(BOOL IN boValid)
参数说明:
	BOOL IN boValid					文件记录功能是否有效。
功能描述:
	初始化文件记录。
返回值:
*/
void stpInitTrace(BOOL IN boValid);

/*
函数原型:DWORD __stdcall stpLockTrace(void)
参数说明:
功能描述:
	锁定写文件操作。写文件时有可能存在多线程操作，此时要考虑锁定避免数据紊乱。
	对其锁定后，使用完毕必须进行解锁，否则对其他操作会堵塞
返回值:
	成功返回0，失败返回错误码
*/
DWORD __stdcall stpLockTrace(void);

/*
函数原型:BOOL __stdcall stpUnlockTrace(void)
参数说明:
功能描述:
	解锁写文件操作。写文件时有可能存在多线程操作，此时要考虑锁定避免数据紊乱。
	对其锁定后，使用完毕必须进行解锁，否则对其他操作会堵塞
返回值:
	成功返回成功，否则返回失败
*/
BOOL __stdcall stpUnlockTrace(void);

/*
函数原型:DWORD stpOpenTraceFile(const CHAR* IN szPath, const CHAR* IN szFileName, BOOL IN boIsBinary = FALSE)
参数说明:
	const CHAR* IN szPath			路径名，如果是填NULL，则默认选择当前文件夹
	const CHAR* IN szFileName		文件名，如果是填NULL，则默认以当前时间为文件名。
									时间的格式是"YYYY年mm月DD日HH-MM-SS"
	BOOL IN boIsBinary				是否以二进制方式录入。
功能描述:
	输入不同的路径和文件名获得不同的文件ID。保存此ID用于后续的stpTraceEx。
返回值:
	成功返回0。如果失败，返回错误码。（错误码大于0xff000000）
	当无法创建文件时，返回输入参数不合法（ERR_CODE_TRACE_ILLEGAL_INPUT）。
	当没有空闲的文件空间时，返回记录文件不够用（ERR_CODE_TRACE_FILL_COUNT_OVERFLOW）。
*/
DWORD stpOpenTraceFile(const CHAR* IN szPath, const CHAR* IN szFileName, BOOL IN boIsBinary = FALSE);

/*
函数原型:DWORD stpEndTraceFile(DWORD IN dwTraceIndex)
参数说明:
	DWORD IN dwIndex				TRACE文件的序号，此序号通过stpStartTrace获得
功能描述:
	关闭某个记录文件。
返回值:
*/
void stpCloseTraceFile(DWORD IN dwTraceIndex);

/*
函数原型:DWORD stpEndAllTraceFile(void)
参数说明:
功能描述:
	关闭所有记录文件。
返回值:
*/
void stpCloseAllTraceFile(void);

/*
函数原型:DWORD stpTrace(const CHAR* IN szFormat, ...)
参数说明:
	const CHAR* IN szFormat			格式化串的内容
	...								格式化串中的参数
功能描述:
	把TRACE的结果输出到默认的文件中。默认的文件是指"E:\DebugData"文件夹下以第一次写文件的时间为文件名
	新创建的文件。
返回值:
	返回值为写入到文件中的字节数。如果错误，返回错误码。（错误码大于0xff000000）
	当缓冲区数据超长时，返回缓冲区溢出（ERR_CODE_TRACE_BUFF_OVERFLOW）。
*/
DWORD stpTrace(const CHAR* IN szFormat, ...);

/*
函数原型:DWORD stpTraceEx(DWORD IN dwTraceIndex,const CHAR IN *szFormat, ...)
参数说明:
	DWORD IN dwIndex				TRACE文件的序号，此序号通过stpStartTrace获得
	const CHAR IN *szFormat		格式化串的内容
	...								格式化串中的参数
功能描述:
	通过不同的TRACE序号，以格式化的形式把所有内容输出到特定文件中
返回值:
	返回值为写入到文件中的字节数。如果错误，返回错误码。（错误码大于0xff000000）
	当文件TRACE序号合法时，返回输入参数不合法（ERR_CODE_TRACE_ILLEGAL_INPUT）。
	当文件未打开时，返回文件未打开（ERR_CODE_TRACE_FILE_CLOSED）。
	当缓冲区数据超长时，返回缓冲区溢出（ERR_CODE_TRACE_BUFF_OVERFLOW）。
*/
DWORD stpTraceEx(DWORD IN dwTraceIndex, const CHAR IN *szFormat, ...);

/*
函数原型:void GetCurrentTimeString(CHAR OUT *szTimeString)
参数说明:
	CHAR OUT *szTimeString					形成的当前时间的字符串，格式为“%Y年%B%d_%H_%M_%S”
功能描述:
	获得当前时间的字符串，格式为“%Y年%B%d_%H_%M_%S”
返回值:
*/
void GetCurrentTimeString(CHAR OUT *szTimeString);

#endif