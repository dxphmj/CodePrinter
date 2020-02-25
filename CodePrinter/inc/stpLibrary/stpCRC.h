/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpCRC.h
*	文件标识: 这是CBTC仿真测试平台中封装的公用函数库中封装CRC功能的代码文件。
*	摘要：
*		此文件实现的主要功能有:
*		 1.CRC16的功能
*		 2.CRC32的功能
*	当前版本：0.0.0.20090407
*	作 者：王伟
*	完成日期：2009年4月7日
*
*	取代版本：
*	作 者：
*	完成日期：
*/

#ifndef FILE_STP_CRC_H /* stpCRC.h */
#define FILE_STP_CRC_H

#include "stpDefine.h"

/*
函数原型:DWORD stpCrc32(const BYTE IN pbData[], WORD IN wLength)
参数说明:
	BYTE IN pbData[]  				数据指针
	WORD IN wLength					数据缓冲区长度（要计算CRC的缓冲区长度）
功能描述:
	CRC32的函数。注意：计算CRC是从输入数据第一个字节的最高BIT开始的
返回值:
	返回值为32位CRC值，如果输入长度为0或者缓冲区描述为0，那么返回0xcccccccc
*/
DWORD stpCrc32(const BYTE IN pbData[], WORD IN wLength);

/*
函数原型:WORD stpCrc16(const BYTE IN pbData[], WORD IN wLength)
参数说明:
	BYTE IN pbData[]  				数据指针
	WORD IN wLength					数据缓冲区长度（要计算CRC的缓冲区长度）
功能描述:
	CRC16的函数。注意：计算CRC是从输入数据第一个字节的最高BIT开始的
返回值:
	返回值为16位CRC值
*/
WORD stpCrc16(const BYTE IN pbData[], WORD IN wLength);


#endif