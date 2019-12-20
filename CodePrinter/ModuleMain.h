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

//控制变量类
class PcfClass//控制
{
public:
	PcfClass()
	{		
		 pcf0X00bit1_bit0  = 2; 
		 pcf0X00bit2 = 0 ;
		 pcf0X00bit4  = 0 ;
		 pcf0X00bit5  = 0 ;
		 pcf0X00bit6  = 0; 

		
		 pcf0X01bit0  = 1; 
		 pcf0X01bit2  = 0; 
		 pcf0X01bit3  = 0 ;
		  openselectfilename = "";
		  labForMName_temp  = "";

		  pcf_printmode_temp = "";

		  pcf_external_forwarddire_temp= "";
		  pcf_external_signal_temp  = "";
		  pcf_external_cirum_temp  = "";
		  pcf_external_ir_temp  = "";
		  pcf_external_fremul_temp  = "";
		  pcf_external_sensor_temp  = "";
		  pcf_external_active_temp  = "";
		  pcf_external_trilength_temp  = "";
	}
	~PcfClass(){}
	string pcf_currentname ;
	string pcf_currentpath ;


	string lab_currentname ;
	string lab_currentpath ;

	string strPCFlabForMName ;

	string strLABlabForMName ;

	string openselectfilename ;
	string labForMName_temp ;

	string pcf_printmode_temp ;

	string pcf_external_forwarddire_temp ;
	string pcf_external_signal_temp ;
	string pcf_external_cirum_temp ;
	string pcf_external_ir_temp ;
	string pcf_external_fremul_temp ;
	string pcf_external_sensor_temp ;
	string pcf_external_active_temp ;
	string pcf_external_trilength_temp ;
	string pcf0X02_05, pcf0X06_09, pcf0X13_16, pcf0X19_1C ;

	BYTE pcf0X00, pcf0X01, pcf0X02, pcf0X03, pcf0X04, pcf0X05, pcf0X06, pcf0X07, pcf0X08, pcf0X09, pcf0X0A, pcf0X13, pcf0X14, pcf0X15, pcf0X16, pcf0X18, pcf0X19, pcf0X1A, pcf0X1B, pcf0X1C ;
	//'pcf控制0X00
	BYTE pcf0X00bit1_bit0 ;// '列触发方式：0为编码器1相，1为编码器2相，2为内部一列点数（即等于64K/划速率）
	BYTE pcf0X00bit2 ; //'同步器反相，0：A->B，1:B->A
	BYTE pcf0X00bit4 ; //'故障运行，正在打印遇到故障时的处理，0打印停止，1 打印继续，但墨点没有喷出来
	BYTE pcf0X00bit5; //'产品计数器重置，0 不重置，1 重置到设定值
	BYTE pcf0X00bit6 ; //'打印计数器重置，0 不重置，1 重置到设定值

	//'pcf控制0X01
	BYTE pcf0X01bit0 ; //'是否启用电眼，0为关闭，1为启用
	BYTE pcf0X01bit2 ; //'电眼有效电平，0为低电平，1为高电平
	BYTE pcf0X01bit3 ; //'喷印模式为单次还是连续，0为单次，1为连续
};
//状态变量类
class StatusClass//状态
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
//通用算法库
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

