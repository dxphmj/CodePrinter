/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpTypeChange.h
*	文件标识: 这是CBTC仿真测试平台中封装的公用函数库中封装类型转换的代码文件。
*	摘要：
*		此文件实现的主要功能有:
*		 1.把一个DWORD型按低字节在前转换成字节型
*		 2.把一个WORD型按低字节在前转换成字节型
*		 3.把两个BYTE型按低字节在前转换成WORD型
*		 4.把四个BYTE型按低字节在前转换成DWORD型
*		 5.把一个DWORD型按高字节在前转换成字节型
*		 6.把一个WORD型按高字节在前转换成字节型
*		 7.把两个BYTE型按高字节在前转换成WORD型
*		 8.把四个BYTE型按高字节在前转换成DWORD型
*		 9.把一个数组转换成十六进制字符串数组
*		 10.把一个十六进制字符串数组转换成数组
*	当前版本：0.0.0.20090407
*	作 者：王伟
*	完成日期：2009年4月7日
*
*	取代版本：
*	作 者：
*	完成日期：
*/

#ifndef FILE_STP_TYPE_CHANGE_H /* stpQueue.h */
#define FILE_STP_TYPE_CHANGE_H

#include "stpDefine.h"

/*
函数原型:void stpDWord2Byte(DWORD IN dwIn, BYTE OUT pbOut[])
参数说明:
	DWORD IN dwIn						要转换成字节型的DWORD型数值
	BYTE OUT pbOut[]  					存储字节型的地址
功能描述:
	将4个字节的DWord变为高低字节（高位高字节，低位低字节）表示 wIn 为输入 pbOut为输出
返回值:
	无
*/
void stpDWord2Byte(DWORD IN dwIn, BYTE OUT pbOut[]);

/*
函数原型:void stpWord2Byte(WORD IN wIn, BYTE OUT pbOut[])
参数说明:
	WORD IN wIn						要转换成字节型的WORD型数值
	BYTE OUT pbOut[]  					存储字节型的地址
功能描述:
	将2个字节的Word变为高低字节表示 wIn 为输入  pbOut为输出 高8位存入高地址 低8位存入低地址
返回值:
	无
*/
void stpWord2Byte(WORD IN wIn, BYTE OUT pbOut[]);

/*
函数原型:WORD stpByte2Word(const BYTE IN pbIn[])
参数说明:
	const BYTE IN pbIn[]  		要转换为WORD型的BYTE型地址
功能描述:
	将两个字节的Bytes变为Word  低字节在前  高字节在后
返回值:
	返回WORD型的值。假如pbIn是NULL的话直接返回0xcccc
*/
WORD stpByte2Word(const BYTE IN pbIn[]);

/*
函数原型:DWORD stpByte2DWord(const BYTE IN pbIn[])
参数说明:
	const BYTE IN pbIn[]  		要转换为DWORD型的BYTE型地址
功能描述:
	将四个字节的Bytes变为DWord  低字节在前 高字节在后
返回值:
	返回DWORD型的值。假如pbIn是NULL的话直接返回0xcccc
*/
DWORD stpByte2DWord(const BYTE IN pbIn[]);

/*
函数原型:void stpDWord2ByteEx(DWORD IN dwIn, BYTE OUT pbOut[])
参数说明:
	DWORD IN dwIn						要转换成字节型的DWORD型数值
	BYTE OUT pbOut[]  					存储字节型的地址
功能描述:
	将4个字节的DWord变为高低字节（低位高字节，高位低字节）表示 wIn 为输入 pbOut为输出
返回值:
	无
*/
void stpDWord2ByteEx(DWORD IN dwIn, BYTE OUT pbOut[]);

/*
函数原型:void stpWord2ByteEx(WORD IN wIn, BYTE OUT pbOut[])
参数说明:
	WORD IN wIn						要转换成字节型的WORD型数值
	BYTE OUT pbOut[]  					存储字节型的地址
功能描述:
	将2个字节的Word变为高低字节表示 wIn 为输入  pbOut为输出 高8位存入低地址 低8位存入高地址
返回值:
	无
*/
void stpWord2ByteEx(WORD IN wIn, BYTE OUT pbOut[]);

/*
函数原型:WORD stpByte2WordEx(const BYTE IN pbIn[])
参数说明:
	const BYTE IN pbIn[]  		要转换为WORD型的BYTE型地址
功能描述:
	将两个字节的Bytes变为Word  高字节在前  低字节在后
返回值:
	返回WORD型的值。假如pbIn是NULL的话直接返回0xcccc
*/
WORD stpByte2WordEx(const BYTE IN pbIn[]);

/*
函数原型:DWORD stpByte2DWordEx(const BYTE IN pbIn[])
参数说明:
	const BYTE IN pbIn[]  		要转换为DWORD型的BYTE型地址
功能描述:
	将四个字节的Bytes变为DWord  高字节在前 低字节在后
返回值:
	返回DWORD型的值。假如pbIn是NULL的话直接返回0xcccc
*/
DWORD stpByte2DWordEx(const BYTE IN pbIn[]);

/*
函数原型:void stpStrToHex(BYTE IN *pbDest, const BYTE IN *pbSrc, int IN nLen)
参数说明:
	BYTE OUT *pbDest  		输出缓冲区
	BYTE IN *pbSrc			字符串
	int IN nLen				16进制数的字节数(字符串的长度/3)
功能描述:
	将字符串转化为16进制数
返回值:
*/
void stpStrToHex(BYTE OUT *pbDest, const BYTE IN *pbSrc, int IN nLen);

/*
函数原型:void stpHexToStr(BYTE OUT *pbDest, const BYTE IN *pbSrc, int IN nLen)
参数说明:
	BYTE IN *pbDest  		存放目标字符串
	BYTE IN *pbSrc			输入16进制数的起始地址
	int IN nLen				16进制数的字节数
功能描述:
	将16进制数转化为字符串
返回值:
*/
void stpHexToStr(BYTE OUT *pbDest, const BYTE IN *pbSrc, int IN nLen);

#endif