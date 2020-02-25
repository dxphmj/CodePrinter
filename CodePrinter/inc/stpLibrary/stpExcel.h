/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpUDPSocket.h
*	文件标识: 仿真测试平台函数库中实现Excel文件读写的类的头文件
*	摘要：
*		此类的主要功能有:
*		 1.封装了Excel9的部分操作函数，使打开Excel、读取Excel、关闭Excel、保存Excel文件变的容易
*		 2.封装了关闭程序打开的Excel进程的功能，但是此功能存在小漏洞，即无法识别哪个EXCEL进程是由程序打开的。这里的处理方式是
*		   打开EXCEL进程前不允许有已经存在的EXCEL，之后程序在关闭EXCEL时会关闭所有EXCEL进程。这里的缺陷是如果在程序打开EXCEL与
*		   关闭EXCEL间用户用自行创建了一个EXCEL进程。那么会导致程序关闭EXCEL进程时错误的关闭用户打开的EXCEL进程。
*		 3.封装了通过一个已有EXCEL文件为模版创建一个EXCEL文件的功能。
*		 4.可以操作指定的Sheet中的内容，这是CSV格式的文件所不能处理的。
*		 5.对单元格的读写操作封装了多种接口，便于用户操作。
*	当前版本：1.0
*	作 者：王伟
*	完成日期：2009-6-20
*
*	取代版本：
*	作 者：
*	完成日期：
*/
//////////////////////////////////////////////////////////////////////

#ifndef _FILE_STP_EXCEL_H__
#define _FILE_STP_EXCEL_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//----------------------包含头文件-----------------------------------------
#include "stpDefine.h"
#include "excel9.h"


//----------------------宏定义-----------------------------------------
//错误码定义
#define STP_EXCEL_ERR_SUCCESS						0				//成功
#define STP_EXCEL_ERR_EXCEL_UNKNOWN					0xFFFF0100		//未知错误
#define STP_EXCEL_ERR_INVALID_FILE_NAME				0xFFFF0101		//无效文件名
#define STP_EXCEL_ERR_INVALID_SHEET_NAME			0xFFFF0102		//无效表单名
#define STP_EXCEL_ERR_FILE_CLOSED					0xFFFF0103		//文件未打开
#define STP_EXCEL_ERR_SHEET_CLOSED					0xFFFF0104		//表单未打开
#define STP_EXCEL_ERR_EXCEL_MISSED					0xFFFF0105		//未安装EXCEL程序
#define STP_EXCEL_ERR_CANNOT_OPEN_TWO_EXCEL_APP		0xFFFF0106		//无法同时打开两个Excel进程
#define STP_EXCEL_ERR_CELL_ABNORMAL					0xFFFF0107		//单元格异常

//Excel读写操作类的说明
class AFX_EXT_CLASS CstpExcel  
{
public:
	/*
	CstpExcel(CHAR IN szAppCaption[] = NULL)
	参数说明:
		CHAR IN szAppCaption					应用程序名称，用于对外弹出消息时的窗体名称说明
	使用到的全局变量：
	功能描述:构造函数,初始化动态库。
	返回值:无
	*/
	CstpExcel(CHAR IN szAppCaption[] = NULL);

	/*
	函数原型:virtual ~CstpExcel(void)
	参数说明:
	使用到的全局变量：
	功能描述:析构函数,进行必要的空间释放工作
	返回值:无
	*/
	virtual ~CstpExcel(void);

	/*
	函数原型:void SetNoMessage(BOOL IN boYes = TRUE)
	参数说明:
		BOOL IN boYes						设置不弹出任何消息
	使用到的全局变量：
	功能描述:
		设置禁用弹出消息功能。如果为TRUE，则禁用弹出消息，否则允许弹出消息
	返回值:
		无
	*/
	void SetNoMessage(BOOL IN boYes = TRUE);

	/*
	函数原型:DWORD OpenFile(const CHAR IN szFileName[], const CHAR IN szSheetName[] = NULL)
	参数说明:
		const CHAR IN szFileName[]				Excel文件的文件名，包含路径
		const CHAR IN szSheetName[]				Excel文件中要打开的表单名，如果填NULL，默认为空
	使用到的全局变量：
	功能描述:通过输入包含路径的文件名，打开指定文件。然后打开指定（未指定的话则默认打开文件名）的表单，以便后续的读写单元格
	返回值:
		成功返回0(SHEET已经打开)，失败返回错误码。
	*/
	DWORD OpenFile(const CHAR IN szFileName[], const CHAR IN szSheetName[] = NULL);

	/*
	函数原型:DWORD OpenFileEx(const CHAR IN szFileCaption[], const CHAR IN szSheetName[] = NULL)
	参数说明:
		const CHAR IN szFileCaption[]			Excel文件的文件名，不包含路径
		const CHAR IN szSheetName[]				Excel文件中要打开的表单名，如果填NULL，默认为空
	使用到的全局变量：
	功能描述:
		通过输入不包含路径的文件名，在经过查询本程序的路径获得当前路径后，拼接成完整路径，打开指定文件。
		然后打开指定（未指定的话则默认打开文件名）的表单，以便后续的读写单元格
	返回值:
		成功返回0(SHEET已经打开)，失败返回错误码。
	*/
	DWORD OpenFileEx(const CHAR IN szFileCaption[], const CHAR IN szSheetName[] = NULL);

	/*
	函数原型:DWORD CreateFileIndirect(const CHAR IN szNewFileName[], const CHAR IN szSrcFileName[])
	参数说明:
		const CHAR IN szNewFileName[]			新文件名
		const CHAR IN szSheetName[]				源文件名
	使用到的全局变量：
	功能描述:
		通过指定的szSrcFileName，创建格式为源文件格式的szNewFileName新文件。此函数不负责打开文件。
		并且在创建时，要求不能Excel类不能打开任何已有文件。
		此函数在导出Excel文件时非常有用。
	返回值:
		创建成功返回0，失败返回错误码。
	*/
	DWORD CreateFileIndirect(const CHAR IN szNewFileName[], const CHAR IN szSrcFileName[]);

	/*
	函数原型:DWORD ChangeSheet(const CHAR IN szNewSheetName[])
	参数说明:
		const CHAR IN szNewSheetName[]				要打开的新的Sheet名	
	使用到的全局变量：
	功能描述:
		通过输入新的表单名，关闭原有表单，同时打开新的表单。如果打开失败，也不会重新开启原有表单。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD ChangeSheet(const CHAR IN szNewSheetName[]);

	/*
	函数原型:BOOL IsFileOpen(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		返回Excel文件是否已打开。此类只允许同时打开一个文件，不允许同时打开多个文件。
	返回值:
		已打开返回TRUE，否则返回FALSE。
	*/
	BOOL IsFileOpen(void);

	/*
	函数原型:BOOL IsSheetOpen(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		返回表单是否已打开。此类只允许同时打开一个表单，不允许同时打开多个表单。另外，读写单元格必须针对特定的表单，
		当表单未打开时，无法读写单元格。
	返回值:
		已打开返回TRUE，否则返回FALSE。
	*/
	BOOL IsSheetOpen(void);

	/*
	函数原型:void CloseFile(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		关闭文件。释放必要的资源，以及关闭已经开启的Excel文件。
	返回值:
		无
	*/
	void CloseFile(void);

	/*
	函数原型:void SaveFile(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		保存文件。把已经写入的数据保存到文件中。
	返回值:
		无
	*/
	void SaveFile(void);

	/*
	函数原型:DWORD Write(int IN nRow, int IN nCol, int IN nValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		int IN nValue						单元格的值(int型)
	使用到的全局变量：
	功能描述:
		向第nRow行第nCol列的单元格写入值为nValue的int型整数
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Write(int IN nRow, int IN nCol, int IN nValue);

	/*
	函数原型:DWORD Write(int IN nRow, int IN nCol, DWORD IN dwValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		DWORD IN dwValue					单元格的值(int型)
	使用到的全局变量：
	功能描述:
		向第nRow行第nCol列的单元格写入值为dwValue的DWORD型整数
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Write(int IN nRow, int IN nCol, DWORD IN dwValue);

	/*
	函数原型:DWORD Write(int IN nRow, int IN nCol, double IN dfValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		double IN dfValue					单元格的值(double型)
	使用到的全局变量：
	功能描述:
		向第nRow行第nCol列的单元格写入值为dfValue的double型浮点数
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Write(int IN nRow, int IN nCol, double IN dfValue);

	/*
	函数原型:DWORD Write(int IN nRow, int IN nCol, CString IN strValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		CString IN strValue					单元格的值(CString型字符串)
	使用到的全局变量：
	功能描述:
		向第nRow行第nCol列的单元格写入值为strValue的CString型字符串
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Write(int IN nRow, int IN nCol, CString IN strValue);

	/*
	函数原型:DWORD Write(int IN nRow, int IN nCol, const CHAR IN szValue[])
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		const CHAR IN szValue[]				单元格的值(const CHAR型字符串)
	使用到的全局变量：
	功能描述:
		向第nRow行第nCol列的单元格写入值为szValue的const CHAR型字符串
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Write(int IN nRow, int IN nCol, const CHAR IN szValue[]);

	/*
	函数原型:DWORD Write(int IN nRow, int IN nCol, const BYTE IN pbValue[], int IN nLen)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		const BYTE IN pbValue[]				要存储在单元格中的原始值(const BYTE型数组)，写入时写成十六进制的字符串
		int IN nLen							数组有效内容大小						
	使用到的全局变量：
	功能描述:
		向第nRow行第nCol列的单元格写入长度为nLen的pbValue数组的十六进制形式，以空格为分隔符
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD WriteHex(int IN nRow, int IN nCol, const BYTE IN pbValue[], int IN nLen);

	/*
	函数原型:DWORD Read(int IN nRow, int IN nCol, int OUT *pnValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		int IN *pnValue						单元格的值(int型指针)
	使用到的全局变量：
	功能描述:
		读取第nRow行第nCol列的单元格存储的int型整数的值，存储在pnValue中。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Read(int IN nRow, int IN nCol, int OUT *pnValue);

	/*
	函数原型:DWORD Read(int IN nRow, int IN nCol, DWORD OUT *pdwValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		DWORD OUT *pdwValue					单元格的值(DWORD型指针)
	使用到的全局变量：
	功能描述:
		读取第nRow行第nCol列的单元格存储的DWORD型整数的值，存储在pdwValue中。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Read(int IN nRow, int IN nCol, DWORD OUT *pdwValue);

	/*
	函数原型:DWORD Read(int IN nRow, int IN nCol, double OUT *pdfValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		double OUT *pdfValue				单元格的值(double型指针)
	使用到的全局变量：
	功能描述:
		读取第nRow行第nCol列的单元格存储的double型浮点数的值，存储在pdfValue中。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Read(int IN nRow, int IN nCol, double OUT *pdfValue);

	/*
	函数原型:DWORD Read(int IN nRow, int IN nCol, CString OUT *pstrValue)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		CString OUT *pstrValue				单元格的值(double型指针)
	使用到的全局变量：
	功能描述:
		读取第nRow行第nCol列的单元格存储的CString型字符串的值，存储在pstrValue中。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Read(int IN nRow, int IN nCol, CString OUT *pstrValue);

	/*
	函数原型:DWORD Read(int IN nRow, int IN nCol, CHAR OUT szValue[])
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		CHAR OUT szValue[]					单元格的值(CHAR型指针)
	使用到的全局变量：
	功能描述:
		读取第nRow行第nCol列的单元格存储的CHAR型字符串的值，存储在szValue中。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD Read(int IN nRow, int IN nCol, CHAR OUT szValue[]);

	/*
	函数原型:DWORD Read(int IN nRow, int IN nCol, BYTE OUT pbValue[], int IN *pnLen)
	参数说明:
		int IN nRow							单元格行号
		int IN nCol							单元格列号
		BYTE OUT pbValue[]					单元格的值(以十六进制文本形式存储的，转换成字节形式后的值)
		int OUT *pnLen						字节形式的值的长度
	使用到的全局变量：
	功能描述:
		读取第nRow行第nCol列的单元格存储的CHAR型字符串的值，然后转换成该十六进制文本形式对应的字节形式，并存储内容于
		pbValue，长度于pnLen。
	返回值:
		成功返回0，失败返回错误码。
	*/
	DWORD ReadHex(int IN nRow, int IN nCol, BYTE OUT pbValue[], int OUT *pnLen);

	/*
	函数原型:int GetValidRowCount(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		读取已经打开的当前Sheet中的有效行数。
	返回值:
		成功返回有效的行数，失败返回-1。
	*/
	int GetValidRowCount(void);

	/*
	函数原型:int GetValidColumnCount(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		读取已经打开的当前Sheet中的有效列数。
	返回值:
		成功返回有效的列数，失败返回-1。
	*/
	int GetValidColumnCount(void);

	BOOL m_boNoMessage;//禁用弹出消息
private:
	/*
	函数原型:BOOL IsExcelAppExist(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		判断是否有Excel程序在运行。如果存在，那么返回TRUE，否则返回失败。
	返回值:
		如果存在，那么返回TRUE，否则返回FALSE。
	*/
	BOOL CstpExcel::IsExcelAppExist(void);

	/*
	函数原型:void CloseAllExistExcelApp(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		关闭所有已经存在的ExcelApp.
	返回值:
		无
	*/
	void CloseAllExistExcelApp(void);

	CHAR m_szAppCaption[MAX_PATH];//应用程序的名称

	CHAR m_szFileName[MAX_PATH];//文件名（含路径）
	CHAR m_szSheetName[MAX_PATH];//表单名
	BOOL m_boIsFileOpened;//文件是否被打开
	BOOL m_boIsSheetOpened;//表单是否被打开

	//Excel读写用参数
	_Application  m_ExcelApp;//进程实体
	Workbooks m_wbsMyBooks;//工作薄集实体
	_Workbook m_wbMyBook;//工作薄实体
	Worksheets m_wssMysheets;//表单集实体
	_Worksheet m_wsMysheet;//表单实体
	Range m_rgMyRge;//单元格实体
};

#endif // !defined(AFX_STPEXCEL_H__F4914924_7E51_4764_AC20_0F6C35EA10F0__INCLUDED_)
