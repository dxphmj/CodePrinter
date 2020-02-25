/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpDefine.h
*	文件标识: 这是CBTC仿真测试平台中封装的公用函数库中封装共用类型和宏定义的头文件。
*	摘要：
*		此文件实现的主要功能有:
*		 1.定义输入输出宏
*		 2.定义错误码的宏
*		 3.定义常用类型
*	当前版本：0.0.0.20090407
*	作 者：王伟
*	完成日期：2009年4月7日
*
*	取代版本：
*	作 者：
*	完成日期：
*/

#ifndef FILE_STP_DEFINE_H /* stpDefine.h */
#define FILE_STP_DEFINE_H

/*常用数值定义*/
#ifndef FALSE
#define FALSE									0				/*失败*/
#endif
#ifndef TRUE
#define TRUE									1				/*成功*/
#endif

#ifndef YES
#define YES										(BYTE)0x55		/*是*/			
#endif
#ifndef NO
#define NO										(BYTE)0xaa		/*否*/			
#endif
#ifndef INVALID
#define INVALID									(BYTE)0xff		/*无效*/			
#endif
#ifndef INITIAL
#define INITIAL									(BYTE)0x00		/*初始化*/			
#endif

/*错误码定义*/
#ifndef ERR_SUCCESS
#define ERR_SUCCESS									0UL			/*错误码中的成功值*/		
#endif

/*LDRA_NOANALYSIS*/
/*NULL的定义*/
#ifndef NULL
#define NULL										0UL			/*NULL值定义*/
#endif
/*LDRA_ANALYSIS*/

/*输入输出类型定义*/
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif


/*常用数据类型定义*/
#if !defined(BYTE)
typedef unsigned char	BYTE;/*单字节类型*/
#endif
#if !defined(WORD)
typedef unsigned short	WORD;/*双字节类型*/
#endif
#if !defined(DWORD)
typedef unsigned long	DWORD;/*四字节类型*/
#endif
#if !defined(CHAR)
typedef char			CHAR;/*单字节类型*/
#endif
#if !defined(SWORD)
typedef signed short	SWORD;/*双字节类型*/
#endif
#if !defined(DSWORD)
typedef signed long		DSWORD;/*四字节类型*/
#endif
#if !defined(BOOL)
typedef int				BOOL;/*布尔类型*/
#endif

//类型定义
typedef enum STP_CRC_TYPE
{
	CrcType_16, CrcType_32
} stpCrcType;//Crc的类型，32位Crc还是16位Crc



#endif
