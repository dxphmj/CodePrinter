/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpQueue.h
*	文件标识: 这是CBTC仿真测试平台中封装的公用函数库中封装静态队列的代码文件。其中队列的一个节点为一个字节
*	摘要：
*		此文件实现的主要功能有:
*		 1.在队列中插入若干个元素
*		 2.在队列中读走若干个元素
*		 3.队列初始化
*		 4.读取队列的内容，但不改变队列的结构
*		 5.读取队列的长度
*		 6.队列元素的销毁
*	当前版本：0.0.0.20090407
*	作 者：王伟
*	完成日期：2009年4月7日
*
*	取代版本：
*	作 者：
*	完成日期：
*/

#ifndef FILE_STP_QUEUE_H /* stpQueue.h */
#define FILE_STP_QUEUE_H

#include "stpDefine.h"

/*----------------宏定义----------------------------------*/
#define ERR_CODE_QUEUE_UNKOWN						0xffff0100	/*未知错误*/
#define ERR_CODE_QUEUE_NOT_ENOUGH_ElEM				0xffff0101	/*队列可用元素数少于要获取的长度数*/
#define ERR_CODE_QUEUE_NOT_ENOUGH_BUFF				0xffff0102	/*队列空闲元素数少于要写入的长度数*/
#define ERR_CODE_QUEUE_ILLEGAL_INPUT				0xffff0111	/*队列函数中输入数据不合法*/


/*----------------类型定义---------------------------------*/
/*以下部分为队列相关的定义*/
typedef   BYTE  QueueElement;/*队列元素声明*/
typedef struct S_stpQueueStruct
{
	DWORD dwIn; /* Queue input/write pointer */
	DWORD dwOut; /* Queue output/read pointer */
	DWORD dwQueueSize;/*队列长度*/
	QueueElement *pValue; /* Queue array */
} stpQueueStruct;

/*----------------函数声明---------------------------------*/

/*
函数原型:DWORD stpQueueInitial(stpQueueStruct IN *pQueue, DWORD IN dwSize)
参数说明:
	stpQueueStruct IN *pQueue  		要初始化的队列
	DWORD IN dwSize					队列大小
功能描述:
	队列初始化函数，用于初始化一个队列，为队列结构体中的pValue分配空间，并将队列的size初始化
返回值:
	成功返回0，失败返回错误码
*/
DWORD stpQueueInitial(stpQueueStruct IN *pQueue, DWORD IN dwSize);

/*
函数原型:DWORD stpQueueInitialEx(stpQueueStruct IN *pQueue, DWORD IN dwSize, QueueElement pQueueElementSpace[])
参数说明:
	stpQueueStruct IN *pQueue  				要初始化的队列
	DWORD IN dwSize							队列大小
	QueueElement IN pQueueElementSpace[]	队列需要的内存空间
功能描述:
	队列初始化函数，用于初始化一个队列，为队列结构体中的pValue分配空间，并将队列的size初始化.
	注意：使用stpQueueInitialEx后不需要使用stpQueueRelease函数。
返回值:
	成功返回0，失败返回错误码
*/
DWORD stpQueueInitialEx(stpQueueStruct IN *pQueue, DWORD IN dwSize, QueueElement IN pQueueElementSpace[]);

/*
函数原型:void stpQueueRelease(stpQueueStruct IN *pQueue)
参数说明:
	stpQueueStruct IN *pQueue  		要释放空间的队列
功能描述:
	队列存储空间释放函数，在不需要某个队列的时候，把队列的元素数组空间释放掉
返回值:
	成功返回0，失败返回错误码
*/
void stpQueueRelease(stpQueueStruct IN *pQueue);

/*
函数原型:DWORD stpQueueScan(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue)
参数说明:
	DWORD IN dwLength				要读出的数据长度
	QueueElement OUT pData[]			读出的数据要存放的数组
	stpQueueStruct IN *pQueue  		要读出数据的队列
功能描述:
	队列扫描函数，可以读出队列中的数据，但是对队列的读写指针都不产生影响，即读到的数据还在队列中
返回值:
	成功返回0，失败返回错误码
		1-	如果队列中的数据不够读就返回0,成功返回1
*/
DWORD stpQueueScan(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue);

/*
函数原型:DWORD stpQueueRead(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue)
参数说明:
	DWORD IN dwLength				要读出的数据长度
	QueueElement OUT pData[]			读出的数据要存放的数组
	stpQueueStruct IN *pQueue  		要读出数据的队列
功能描述:
	读队列函数，可以读出队列中的数据,并存放在一个数组中，数据读出后读指针发生变化，即读出的数据已不存在队列中
返回值:
	成功返回0，失败返回错误码
*/
DWORD stpQueueRead(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue);

/*
函数原型:DWORD stpQueueWrite(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue)
参数说明:
	DWORD IN dwLength				要写入的数据长度
	QueueElement IN pData[]			要写入的数据存放的数组
	stpQueueStruct IN *pQueue  		要写入数据的队列
功能描述:
	写队列函数，将一个数组中的数据写到一个队列中。对一个队列的操作不可以两个任务同时写入
	队列是不可以写满的，如果写不下函数返回错误
返回值:
	成功返回0，失败返回错误码
*/
DWORD stpQueueWrite(DWORD IN dwLength, QueueElement IN pData[], stpQueueStruct IN *pQueue);

/*
函数原型:DWORD stpQueueStatus (stpQueueStruct IN *pQueue)
参数说明:
	stpQueueStruct IN *pQueue  		要读取数据的队列
功能描述:
	读出队列中可用数据长度
返回值:
	返回队列中可用的数据长度，如果队列为空，返回0
*/
DWORD stpQueueStatus(stpQueueStruct IN *pQueue);

/*
函数原型:void stpQueueClear(stpQueueStruct IN *pQueue)
参数说明:
	stpQueueStruct IN *pQueue  		要清空数据的队列
功能描述:
	清空队列中可用数据长度
返回值:
	无
*/
void stpQueueClear(stpQueueStruct IN *pQueue);

/*
函数原型:DWORD stpQueuePointChange(WORD IN wLen, stpQueueStruct IN *pQueue)
参数说明:
	WORD IN wLen					指针的位移大小
	stpQueueStruct IN *pQueue  		要改变读指针的队列
功能描述:
	直接改变读指针。与QueueScan配合使用，两者结合即使QueueRead的功能。此方法会比QueueRead效率高，但是如果存在多个任务同时
	操作一个队列，慎用此函数。因为此函数未作互斥防护。
返回值:
	成功返回0，失败返回错误码
*/
DWORD stpQueuePointChange(WORD IN wLen, stpQueueStruct IN *pQueue);

#endif