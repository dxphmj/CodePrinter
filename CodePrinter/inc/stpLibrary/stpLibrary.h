/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpLibrary.h
*	文件标识: 这是CBTC仿真测试平台中封装的公用函数库中头文件的管理文件。
*	摘要：
*		此文件实现的主要功能有:
*		 1.包含目前函数库中的所有头文件
*		 2.根据需求链接不同的库文件(通过宏来控制)
*	当前版本：0.0.0.20090518
*	作 者：王伟
*	完成日期：2009年5月18日
*
*	取代版本：
*	作 者：
*	完成日期：
*/

#ifndef _FILE_STP_LIBRARY_H /*stpLibrary.h*/
#define _FILE_STP_LIBRARY_H

#include "stpDefine.h"
#include "stpCRC.h"//CRC16和CRC32的函数
#include "stpQueue.h"//队列的函数
#include "stpTypeChange.h"//类型转换的函数
#include "stpTrace.h"//文件记录的函数

#ifdef _STP_FUNC_LIBRARY

#pragma comment(lib, "stpFuncLibrary.lib")//链接共用函数的动态库

#define CRC16			stpCrc16			//16位Crc函数名称的重定义
#define CRC32			stpCrc32			//32位Crc函数名称的重定义

#define fTRACE			stpTrace			//把信息TRACE到文件里的函数的重定义

#endif	//#ifdef _STP_FUNC_LIBRARY



#ifdef _STP_SERIAL_LIBRARY			//串口动态链接库

#include "stpSerial.h"						//串口链接库的头文件
#if !defined(_STP_FUNC_LIBRARY) 			//之前如果没有链接公用函数动态库，那么直接自动链接该库
#pragma comment(lib, "stpFuncLibrary.lib")//链接共用函数的动态库
#endif
#pragma comment(lib, "stpSerialLibrary.lib")//链接串口动态链接库

#endif//#ifdef _STP_SERIAL_LIBRARY


#ifdef _STP_UDP_SOCKET_LIBRARY			//UDPSocket动态链接库

#include "stpUDPSocket.h"						//UDPSocket链接库的头文件
#if !defined(_STP_FUNC_LIBRARY) && !defined(_STP_SERIAL_LIBRARY)			//之前如果没有链接公用函数动态库，那么直接自动链接该库
#pragma comment(lib, "stpFuncLibrary.lib")//链接共用函数的动态库
#endif
//#pragma comment(lib, "ws2_32.lib")//自动链接Socket库
#pragma comment(lib, "Ws2.lib")//自动链接Socket库
#pragma comment(lib, "stpUDPSocketLibrary.lib")//链接UDPSocket动态链接库

#endif//#ifdef _STP_UDP_SOCKET_LIBRARY

#ifdef _STP_EXCEL_LIBRARY			//Excel动态链接库

#include "stpExcel.h"						//Excel链接库的头文件
//之前如果没有链接公用函数动态库，那么直接自动链接该库
#if !defined(_STP_FUNC_LIBRARY) && !defined(_STP_SERIAL_LIBRARY) && !defined(_STP_UDP_SOCKET_LIBRARY)
#pragma comment(lib, "stpFuncLibrary.lib")//链接共用函数的动态库
#endif
#pragma comment(lib, "stpExcelLibrary.lib")//链接Excel动态链接库

#endif//#ifdef _STP_EXCEL_LIBRARY


#ifdef _STP_DRAW_TRAIN_LIBRARY					//画小车类动态库的头文件	

#include "stpDrawTrain.h"
#pragma comment(lib, "stpDrawTrainLibrary.lib")//链接画小车类的动态库

#endif	//#ifdef _STP_DRAW_TRAIN_LIBRARY



#endif