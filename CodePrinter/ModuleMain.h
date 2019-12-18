#pragma once
#include <stdio.h>
#include "xml\tinyxml.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

UINT TTLcomLoop(LPVOID pParam);
BYTE* VEC2ARRAY(vector<BYTE> tempVec,int n);
CString GETnBIT_from_bytReadData(int I , int m , int n );
CString GETnBIT_from_bytStatus(int I , int m , int n );
class StatusClass
{
public:
	StatusClass(void){			
		 ctr0X00bit0  = 0 ;//'0关机，1开机
		 ctr0X00bit1  = 0 ;//'0正常，1快速
		 ctr0X00bit2  = 0 ;//'0泵速模式，1压力模式
		 ctr0X00bit3  = 0 ;//'0关泵，1开泵
		 ctr0X00bit5  = 0 ;//'清除下位机故障标志位，0平时，1清除下位机故障

		//'控制0X01
		 ctr0X01bit0  = 0 ;//'0关喷嘴，1开喷嘴
		 ctr0X01bit1  = 0; //'0关供墨阀，1开供墨阀
		 ctr0X01bit2  = 0; //'0关排气阀，1开排气阀
		 ctr0X01bit3  = 0 ;//'0关清洗阀，1开清洗阀
		 ctr0X01bit4  = 0; //'0关溶剂阀，1开溶剂阀
		 ctr0X01bit5  = 0; //'0关粘度阀，1开粘度阀
		 ctr0X01bit6  = 0; //'0关冲洗阀，1开冲洗阀

		//'控制0X02
		 ctr0X02bit0  = 0; //'关回收检测功能，1为关闭检测，0为开启检测
		 ctr0X02bit1  = 0; //'关墨线功能，1为关闭墨线，0为开启墨线
		 ctr0X02bit2  = 0; //'添加溶剂，0关，1开
		 ctr0X02bit3  = 0; //'测试粘度，0关，1开
		 ctr0X02bit4  = 0; //'冲洗喷嘴，0关，1开
		 ctr0X02bit5  = 0; //'反吸喷嘴，0关，1开
		 ctr0X02bit6  = 0; //'墨路校正，0关，1开
		 ctr0X02bit7  = 0; //'墨路循环，0关，1开

		//'控制0X03
		 ctr0X03bit0  = 0; //'开打印功能，1开启
		 ctr0X03bit1  = 0; //'故障重打印（需要重新确认该功能）
		 ctr0X03bit3  = 0; //'高压开关，1为开启
		 ctr0X03bit6  = 0; //'分裂模式，0为手动，1为自动 (下位机默认为1)

		//'其它
		 bytModuStep  = 10; //'固定分裂电压步级
	}
	~StatusClass(){}
	void getstatu();
	void byStatusFromSlaveState();

	void us_button_onoff(HWND hwnd);//墨水普通句柄
	void ad_button_onoff(HWND hwnd);//墨水高级句柄

	void download_inksystem_control00();
	void download_inksystem_control01();
	void download_inksystem_control02();
	void download_inksystem_control03();
public:
	bool staSysRea, staSysBus, staBumMod, staBum, staHarFin, staCleFauFin;
		bool staNozVal, staFeeVal, staBleVal, staFluVal, staSolVal, staVisVal, staWasVal ;
		bool staInkFloSenOff, staCloInkLin, staAddSol, staDetVis, staWasNoz, staSucNoz, staAdjInkLin, staInkCir ;
		bool staInkTemSenFau, staPriHeaTemFau, staBumSpeOveFau, staPreOveFau, staVisAbnFau, staVisSenFau, staInkFloFau, staPriHeaCle ;
		bool staFanFau, staChaFau, staPhaFau;
		bool staHigVolFau ;
		string staSolLevFau, staInkLevFau, staRFID ;
		bool staPrnting, staHigVolSwi, staActProSen, staProSenFas, staAutModFau, staValFau ;
		bool staPrinted, staRemPrinSwi, staBufFul, staBufRea, staEncDir, staLinFas, staPriHeaHot, staPriHeaHotFau, staSetTimeEna ;
		int staPressure, staBumSpe, staHigVol, staEncFre ;
		BYTE staPriHeaTem, staActVis, staTarVis, staInkLev, staSolLev, staPhase ;
		int staInkTem ;
		int staProCou, staPriCou, staInkLifeTime ;
		BYTE staPixDotNee, staAutModVol ;
		bool staFanFauLas, staChaFauLas, staPhaFauLas, staHigVolFauLas ;
		bool staProSenFasLas, staAutModFauLas, staValFauLas, staLinFasLas, staPriHeaHotFauLas ;
		bool staInkTemSenFauLas, staPriHeaTemFauLas, staBumSpeOveFauLas, staPreOveFauLas, staVisAbnFauLas, staVisSenFauLas, staInkFloFauLas ;


			BYTE ctr0X00, ctr0X01, ctr0X02, ctr0X03, ctr0X04 ;
			//'控制0X00
			BYTE ctr0X00bit0 ;//'0关机，1开机
			BYTE ctr0X00bit1   ;//'0正常，1快速
			BYTE ctr0X00bit2   ;//'0泵速模式，1压力模式
			BYTE ctr0X00bit3   ;//'0关泵，1开泵
			BYTE ctr0X00bit5   ;//'清除下位机故障标志位，0平时，1清除下位机故障

			//'控制0X01
			BYTE ctr0X01bit0   ;//'0关喷嘴，1开喷嘴
			BYTE ctr0X01bit1 ; //'0关供墨阀，1开供墨阀
			BYTE ctr0X01bit2  ; //'0关排气阀，1开排气阀
			BYTE ctr0X01bit3   ;//'0关清洗阀，1开清洗阀
			BYTE ctr0X01bit4 ; //'0关溶剂阀，1开溶剂阀
			BYTE ctr0X01bit5  ; //'0关粘度阀，1开粘度阀
			BYTE ctr0X01bit6  ; //'0关冲洗阀，1开冲洗阀

			//'控制0X02
			BYTE ctr0X02bit0 ; //'关回收检测功能，1为关闭检测，0为开启检测
			BYTE ctr0X02bit1 ; //'关墨线功能，1为关闭墨线，0为开启墨线
			BYTE ctr0X02bit2  ; //'添加溶剂，0关，1开
			BYTE ctr0X02bit3  ; //'测试粘度，0关，1开
			BYTE ctr0X02bit4  ; //'冲洗喷嘴，0关，1开
			BYTE ctr0X02bit5  ; //'反吸喷嘴，0关，1开
			BYTE ctr0X02bit6 ; //'墨路校正，0关，1开
			BYTE ctr0X02bit7  ; //'墨路循环，0关，1开

			//'控制0X03
			BYTE ctr0X03bit0  ; //'开打印功能，1开启
			BYTE ctr0X03bit1  ; //'故障重打印（需要重新确认该功能）
			BYTE ctr0X03bit3  ; //'高压开关，1为开启
			BYTE ctr0X03bit6  ; //'分裂模式，0为手动，1为自动 (下位机默认为1)

			//'其它
			BYTE bytModuStep  ; //'固定分裂电压步级
			int	bytModuVol, SolLevSum, InkLevSum, LevCoun ;
};
class ModuleMain//通用算法库
{
public:
	ModuleMain(void);
	~ModuleMain(void);
	LPCWSTR stringToLPCWSTR(std::string orig);
    string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
	string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//查
    //bool writeXml(string xmlFileName,string valueStr,string textStr,string path);//增
	bool changeXml(string xmlFileName,string valueStr,string textStr,string path);//改
	void string2tchar(std::string &src, TCHAR* buf);
	string TCHAR2STRING(TCHAR *STR);
   const char* CString2ConstChar(CString str);
   string CString2string(CString csStrData);
public:
	void InitCommMsg();
};

