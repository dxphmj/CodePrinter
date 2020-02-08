#include "StdAfx.h"
#include "ModuleMain.h"
#include "CodePrinter.h"
#include<cmath>
#include<algorithm>
#include <fstream>
#include<cstdio> 
#include <math.h>
#include <sstream>//使用该库函数的ostringstream，将int变成string
 
void StatusClass::byStatusFromSlaveState()
{
	theApp.bytSlaveStatusLock.Lock();
	for (int i=0;i<16;i++)
	{
		theApp.bytStatus[i]=theApp.bytSlaveStatus[i];
	}

	if (LevCoun==10)
	{
		theApp.bytStatus[16]=SolLevSum/10;     //墨水液位取平均
		theApp.bytStatus[17]=InkLevSum/10;     //溶剂液位取平均
		SolLevSum = 0;
		InkLevSum = 0;
		LevCoun = 1;
		SolLevSum = SolLevSum + theApp.bytSlaveStatus[16];
		InkLevSum = InkLevSum + theApp.bytSlaveStatus[17];
	} 
	else
	{
		LevCoun = LevCoun + 1;
		SolLevSum = SolLevSum + theApp.bytSlaveStatus[16];
		InkLevSum = InkLevSum + theApp.bytSlaveStatus[17];
	}


	for (int i=18;i<37;i++)
	{
		theApp.bytStatus[i]=theApp.bytSlaveStatus[i];
	}
	theApp.bytSlaveStatusLock.Unlock();
}

void StatusClass::getstatu()
{
	staSysRea = GETnBIT_from_bytStatus(0, 0, 1)==_T("1")?true:false;  //系统准备好
//	staSysRea = (GETnBIT_from_bytStatus(0, 0, 1)==_T("1"));  //系统准备好
	staSysBus = (GETnBIT_from_bytStatus(0, 1, 1)==_T("1")?true:false) ;  //系统忙
	staBumMod = (GETnBIT_from_bytStatus(0, 2, 1)==_T("1")?true:false)  ; //泵模式
	staBum = (GETnBIT_from_bytStatus(0, 3, 1)==_T("1")?true:false)   ;   //'泵开关
	staHarFin = (GETnBIT_from_bytStatus(0, 4, 1)==_T("1")?true:false) ;  //'下位机复位完成
	staCleFauFin = (GETnBIT_from_bytStatus(0, 5, 1)==_T("1")?true:false) ;// '清除故障完成
	staNozVal = (GETnBIT_from_bytStatus(1, 0, 1)==_T("1")?true:false);   //'喷嘴阀
	staFeeVal = (GETnBIT_from_bytStatus(1, 1, 1)==_T("1")?true:false) ;  //'供墨阀
	staBleVal = (GETnBIT_from_bytStatus(1, 2, 1)==_T("1")?true:false) ;  //'排气阀
	staFluVal = (GETnBIT_from_bytStatus(1, 3, 1)==_T("1")?true:false) ;  //'清洗阀
	staSolVal = (GETnBIT_from_bytStatus(1, 4, 1)==_T("1")?true:false) ;  //'溶剂阀
	staVisVal = (GETnBIT_from_bytStatus(1, 5, 1)==_T("1")?true:false) ;  //'粘度阀
	staWasVal = (GETnBIT_from_bytStatus(1, 6, 1)==_T("1")?true:false) ;  //'冲洗阀
	staInkFloSenOff = (GETnBIT_from_bytStatus(2, 0, 1)==_T("1")?true:false) ;  //'关回收
	staCloInkLin = (GETnBIT_from_bytStatus(2, 1, 1)==_T("1")?true:false) ;  //'关墨线
	staAddSol = (GETnBIT_from_bytStatus(2, 2, 1)==_T("1")?true:false)  ; //'添加溶剂
	staDetVis = (GETnBIT_from_bytStatus(2, 3, 1)==_T("1")?true:false)  ; //'测试粘度
	staWasNoz = (GETnBIT_from_bytStatus(2, 4, 1)==_T("1")?true:false)  ; //'冲洗喷头
	staSucNoz = (GETnBIT_from_bytStatus(2, 5, 1)==_T("1")?true:false)   ;//'反吸喷嘴
	staAdjInkLin = (GETnBIT_from_bytStatus(2, 6, 1)==_T("1")?true:false) ; // '墨路校正
	staInkCir = (GETnBIT_from_bytStatus(2, 7, 1)==_T("1")?true:false)  ; //'墨路循环
	staInkTemSenFau = (GETnBIT_from_bytStatus(3, 0, 1)==_T("1")?true:false)  ; //'墨水温度传感器故障
	staPriHeaTemFau = (GETnBIT_from_bytStatus(3, 1, 1)==_T("1")?true:false) ;  //'喷头温度传感器故障
	staBumSpeOveFau = (GETnBIT_from_bytStatus(3, 2, 1)==_T("1")?true:false) ;  //'泵超速保护
	staPreOveFau = (GETnBIT_from_bytStatus(3, 3, 1)==_T("1")?true:false)  ; //'过压保护
	staVisAbnFau = (GETnBIT_from_bytStatus(3, 4, 1)==_T("1")?true:false) ;  //'粘度异常
	staVisSenFau = (GETnBIT_from_bytStatus(3, 5, 1)==_T("1")?true:false) ; //'粘度计故障
	staInkFloFau = (GETnBIT_from_bytStatus(3, 6, 1)==_T("1")?true:false)  ; //'回收故障
	staPriHeaCle = (GETnBIT_from_bytStatus(3, 7, 1)==_T("1")?true:false) ;  //'开关机清洗
	staFanFau = (GETnBIT_from_bytStatus(4, 0, 1)==_T("1")?true:false) ; // '风扇故障
	staChaFau = (GETnBIT_from_bytStatus(4, 1, 1)==_T("1")?true:false) ;  //'充电故障
	staPhaFau = (GETnBIT_from_bytStatus(4, 2, 1)==_T("1")?true:false) ;  //'相位故障
	staHigVolFau = (GETnBIT_from_bytStatus(4, 3, 1)==_T("1")?true:false) ; // '高压故障
	staSolLevFau = OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 5, 1)==_T("1")?true:false) +OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 4, 1)==_T("1")?true:false);  //'溶剂液位状态
	staInkLevFau = OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 7, 1)==_T("1")?true:false) + OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 6, 1)==_T("1")?true:false);  //'墨水液位状态
	staPrnting = (GETnBIT_from_bytStatus(5, 0, 1)==_T("1")?true:false) ; // '打印中
	//'staBufOveFau = IIf(GETnBIT_from_bytStatus(5, 2, 1)==_T("1"));  // '文本buf溢出
	staHigVolSwi = (GETnBIT_from_bytStatus(5, 3, 1)==_T("1")?true:false)  ; //'高压开关
	staActProSen = (GETnBIT_from_bytStatus(5, 4, 1)==_T("1")?true:false)  ; //'电眼当前电平
	staProSenFas = (GETnBIT_from_bytStatus(5, 5, 1)==_T("1")?true:false) ;  ////'电眼过快
	staAutModFau = (GETnBIT_from_bytStatus(5, 6, 1)==_T("1")?true:false) ; // '自动分裂失败
	staValFau = (GETnBIT_from_bytStatus(5, 7, 1)==_T("1")?true:false) ;  //'阀故障
	staPrinted = (GETnBIT_from_bytStatus(6, 0, 1)==_T("1")?true:false)  ; //'打印完成
	staRemPrinSwi = (GETnBIT_from_bytStatus(6, 1, 1)==_T("1")?true:false); //  '远程打印开关
	//'staBufFul = (GETnBIT_from_bytStatus(6, 2, 1)==_T("1"));   //'文本buf满
	staBufRea = (GETnBIT_from_bytStatus(6, 3, 1)==_T("1")?true:false) ;  //'信息准备好
	staEncDir = (GETnBIT_from_bytStatus(6, 4, 1)==_T("1")?true:false) ;  //'编码器方向
	staLinFas = (GETnBIT_from_bytStatus(6, 5, 1)==_T("1")?true:false) ;  //'编码器过快
	staPriHeaHot = (GETnBIT_from_bytStatus(6, 6, 1)==_T("1")?true:false);  // '恒温状态
	staPriHeaHotFau = (GETnBIT_from_bytStatus(6, 7, 1)==_T("1")?true:false) ; // '恒温故障
	if (theApp.bytStatus[8] * 256 +theApp. bytStatus[7] > 5000)  //'实时压力
	{
		staPressure=theApp.bytStatus[8] * 256 + theApp.bytStatus[7] - 65536;
	} 
	else
	{
		staPressure=theApp.bytStatus[8] * 256 + theApp.bytStatus[7];
	}
	
	staBumSpe = theApp.bytStatus[10] * 256 + theApp.bytStatus[9];     //'实时泵速
	staPriHeaTem = theApp.bytStatus[11] ;                                       //'实时喷头温度
	staInkTem = (theApp.bytStatus[13] * 256 + theApp.bytStatus[12]) / 10   ;              //'实时墨水温度
	staActVis = theApp.bytStatus[14] ;                                     //'目前实时粘度
	staTarVis = theApp.bytStatus[15] ;                                         // '目标参考粘度
	staInkLev = theApp.bytStatus[16] ;                                        // '实时墨水液位
	staSolLev = theApp.bytStatus[17] ;                                          //'实时溶剂液位
	staHigVol = theApp.bytStatus[19]* 256 + theApp.bytStatus[18] ;                      // '实时高压
	staPhase = theApp.bytStatus[20] ;                                        // '实时相位
	staEncFre = theApp.bytStatus[22] * 256 + theApp.bytStatus[21] ;                       //'实时编码器频率
	staProCou = theApp.bytStatus[26] * pow(256 , 3) + theApp.bytStatus[25] * pow(256 , 2 )+ theApp.bytStatus[24] * 256 + theApp.bytStatus[23];      // '产品计数器
	staPriCou = theApp.bytStatus[30] * pow(256 , 3) + theApp.bytStatus[29] * pow(256 , 2 )+ theApp.bytStatus[28] * 256 + theApp.bytStatus[27];      // '打印计数器
	staPixDotNee = theApp.bytStatus[31];                                  // '列构成点数
	staAutModVol = theApp.bytStatus[32];                                  // '自动分裂电压

	staSetTimeEna = (GETnBIT_from_bytStatus(36, 5, 1)==_T("1")?true:false);   //'维护、墨水时间更改功能开放
	if (!staSetTimeEna)
	{
		staInkLifeTime = (theApp.bytStatus[36] & 31) * pow(256 , 3) + theApp.bytStatus[35] * pow(256 , 2) + theApp.bytStatus[34] * 256 + theApp.bytStatus[33];   // '墨水时间
		staRFID =  OBJ_Control::to_String(GETnBIT_from_bytStatus(36, 7, 1)==_T("1")?true:false) + OBJ_Control::to_String(GETnBIT_from_bytStatus(36, 6, 1)==_T("1")?true:false); //'RFID状态
	}
}


void StatusClass::us_button_onoff(HWND hwnd)
{
	CWnd* pWnd = CWnd::FromHandle(hwnd);

	if (!theApp.myStatusClass.staSysBus && theApp.myStatusClass.ctr0X02bit3 == 0 && theApp.myStatusClass.ctr0X02bit4 == 0 &&
		theApp.myStatusClass.ctr0X02bit5 == 0 && theApp.myStatusClass.ctr0X02bit6 == 0 && theApp.myStatusClass.ctr0X02bit7 == 0 )
	{
		pWnd->GetDlgItem(IDC_SPEED_MODE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_PRESSURE_MODE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_BLEED_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_PUMP_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_WASH_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_FEED_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_VISCO_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_FLUSH_VALVE_BTN)->EnableWindow(true);
	} 
	else
	{
		pWnd->GetDlgItem(IDC_SPEED_MODE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_PRESSURE_MODE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_BLEED_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_PUMP_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_WASH_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_FEED_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_VISCO_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_FLUSH_VALVE_BTN)->EnableWindow(false);
	}
}

void StatusClass::ad_button_onoff(HWND hwnd)
{
	CWnd* pWnd = CWnd::FromHandle(hwnd);
	if (!theApp.myStatusClass.staSysBus)
	{
		if (theApp.myStatusClass.ctr0X02bit3==1)
		{
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		} 
		else if(theApp.myStatusClass.ctr0X02bit4==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit5==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit6==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit7==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X03bit3==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit3 == 0 && theApp.myStatusClass.ctr0X02bit4 == 0 && theApp.myStatusClass.ctr0X02bit5 == 0 &&
			theApp.myStatusClass.ctr0X02bit6 == 0 && theApp.myStatusClass.ctr0X02bit7 == 0 && theApp.myStatusClass.ctr0X03bit3 == 0)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(true);
		}
	} 
	else
	{
		pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
	}

}

void StatusClass::download_inksystem_control00()
{
	ctr0X00 = ctr0X00bit5 * 32 + ctr0X00bit3 * 8 + ctr0X00bit2 * 4 + ctr0X00bit1 * 2 + ctr0X00bit0;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x0);
	tempCtrVec.push_back(ctr0X00);
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
		theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}
void StatusClass::download_inksystem_control01()
{
	ctr0X01 = ctr0X01bit6 * 64 + ctr0X01bit5 * 32 + ctr0X01bit4 * 16 + ctr0X01bit3 * 8 + ctr0X01bit2 * 4 + ctr0X01bit1 * 2 + ctr0X01bit0;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(ctr0X01);
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}
void StatusClass::download_inksystem_control02()
{
	ctr0X02 = ctr0X02bit7 * 128 + ctr0X02bit6 * 64 + ctr0X02bit5 * 32 + ctr0X02bit4 * 16 + ctr0X02bit3 * 8 + ctr0X02bit2 * 4 + ctr0X02bit1 * 2 + ctr0X02bit0;
	 vector<BYTE> tempCtrVec;
	 tempCtrVec.push_back(0x1);
	 tempCtrVec.push_back(0x80);
	 tempCtrVec.push_back(0x3);
	 tempCtrVec.push_back(0x3);
	 tempCtrVec.push_back(0x2);
	 tempCtrVec.push_back(ctr0X02);
	 tempCtrVec.push_back(0xff);
	 tempCtrVec.push_back(0xff);

	 theApp.boQueCtrLock.Lock();
	 theApp.queCtr.push(tempCtrVec);
	 theApp.boQueCtrLock.Unlock();
}
void StatusClass::download_inksystem_control03()
{
	ctr0X03 = ctr0X03bit6 * 64 + ctr0X03bit3 * 8 + ctr0X03bit1 * 2 + ctr0X03bit0;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(ctr0X03);
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}
//////////////////////////////////////////////////////////////////////////////
BYTE* VEC2ARRAY(vector<BYTE> tempVec,int n)
{
	//BYTE charary[n];
	BYTE *arr = new BYTE[n];
	memcpy(arr, &tempVec[0], tempVec.size() * sizeof(tempVec[0]));
	return arr;
}

CString GETnBIT_from_bytReadData(int I , int m , int n )
{
	string tempCstr="";
	ModuleMain tempstringToLPCWSTR;
	tempCstr="00000000"+OBJ_Control::DEC_to_BIN(theApp.myCIOVsd.m_pRecvBuf[I+4]);

    //tempCstr=tempCstr.Mid(tempCstr.GetLength()-m,n);
	CString cstringStr= tempstringToLPCWSTR.stringToLPCWSTR(tempCstr);
	return cstringStr.Mid(cstringStr.GetLength()-m-1,n);
}

CString GETnBIT_from_bytStatus(int I , int m , int n )
{
	string tempCstr="";
	ModuleMain tempstringToLPCWSTR;
	tempCstr="00000000"+OBJ_Control::DEC_to_BIN(theApp.bytStatus[I]);

	//tempCstr=tempCstr.Mid(tempCstr.GetLength()-m,n);

	CString cstringStr= tempstringToLPCWSTR.stringToLPCWSTR(tempCstr);
	int dd=cstringStr.GetLength();
	return cstringStr.Mid(cstringStr.GetLength()-m-1,n);
}

//串口线程
UINT TTLcomLoop(LPVOID pParam)
{
	theApp.boTTL=true;
	int bytComErr=0;
	int strTempCmdLen=0;
	LPTSTR strTempCmd;
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};
	strTempCmd=(LPTSTR)readArr;
	strTempCmdLen=8;
	while(theApp.boTTL)
	{
		if (theApp.readCount==43)
		{
			theApp.readCount=0;
			//strTempCmdLen=0;
			//BYTE bytReadData[43];
			//theApp.myCIOVsd.Read()
			if (theApp.myCIOVsd.m_pRecvBuf[0]==0x2&&theApp.myCIOVsd.m_pRecvBuf[1]==0x80&&theApp.myCIOVsd.m_pRecvBuf[2]==0x26)
			{
				bytComErr=0;
				theApp.boQueCtrLock.Lock();
					if (theApp.queCtr.size()>0)
					{
						vector<BYTE> tempQueVec=theApp.queCtr.front();
						theApp.queCtr.pop();
						strTempCmdLen=tempQueVec.size();
						strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
					}
					else if (theApp.myclassMessage.boPrintNow)
					{
						theApp.boPrintNowLock.Lock();
						if (theApp.myclassMessage.bytPrintDataAllOrder.size()>11)
						{
							strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
							strTempCmdLen=theApp.myclassMessage.bytPrintDataAllOrder.size();
							theApp.myclassMessage.boPrintNow=false;
						} 
						else
						{
							strTempCmd=(LPTSTR)readArr;
							strTempCmdLen=8;
						}
						theApp.boPrintNowLock.Unlock();
					}
					else if (!theApp.myclassMessage.boPrintNow)
					{
						if (GETnBIT_from_bytReadData(6,2,1)!=_T("1"))
						{
							if (theApp.myclassMessage.boDynamic)
							{
								if (theApp.ForPreQue.size()>0)
								{
									vector<BYTE> tempQueVec=theApp.ForPreQue.front();
									theApp.ForPreQue.pop();
									strTempCmdLen=tempQueVec.size();
									strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
									if (strTempCmdLen>11)
									{////动态显示相关
										vector<BYTE> intMesDis1;
										intMesDis1.insert(intMesDis1.end(),tempQueVec.begin(),tempQueVec.end());
										theApp.boDotForPreQue.push(intMesDis1);
										theApp.myclassMessage.intMesDis=theApp.boDotForPreQue.front();
										theApp.boDotForPreQue.pop();
										vector<int> tempCountVec;
										tempCountVec = theApp.intCounNumForPreQue.front();

										theApp.intCounNumForPreQue.pop();

										for (int num=0;num<tempCountVec.size();num++)
										{
											theApp.myclassMessage.CountNumForPre[num]=tempCountVec[num];
										}
									} 
									else
									{
										strTempCmd=(LPTSTR)readArr;
										strTempCmdLen=8;
									}
								} 
								else
								{
									strTempCmd=(LPTSTR)readArr;
									strTempCmdLen=8;
								}
							} 
							else
							{
								if (theApp.myclassMessage.bytPrintDataAll.size()>11)
								{
									strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAll,theApp.myclassMessage.bytPrintDataAll.size());
									strTempCmdLen=theApp.myclassMessage.bytPrintDataAll.size();
									if (strTempCmdLen<12)
									{
										strTempCmd=(LPTSTR)readArr;
										strTempCmdLen=8;
									}
								}
								//strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
								//strTempCmdLen=theApp.myclassMessage.bytPrintDataAllOrder.size();
								//if (strTempCmdLen<12)
								//{
								//	strTempCmd=(LPTSTR)readArr;
								//	strTempCmdLen=8;
								//}
							}
						} 
						else
						{
							strTempCmd=(LPTSTR)readArr;
							strTempCmdLen=8;
						}
					}
					else
					{
						strTempCmd=(LPTSTR)readArr;
						strTempCmdLen=8;
					}
				theApp.boQueCtrLock.Unlock();

				//同步状态数据
				theApp.bytSlaveStatusLock.Lock();
					for (int i=0;i<37;i++)
					{
						theApp.bytSlaveStatus[i]=theApp.myCIOVsd.m_pRecvBuf[i+4];
					}
				theApp.bytSlaveStatusLock.Unlock();
			} 
		}
		else if (theApp.readCount==6)
		{
			theApp.readCount=0;
			strTempCmdLen=0;
			if (theApp.myCIOVsd.m_pRecvBuf[0]==0x2&&theApp.myCIOVsd.m_pRecvBuf[1]==0x80&&theApp.myCIOVsd.m_pRecvBuf[3]==0x10)
			{
				bytComErr=0;
				theApp.boQueCtrLock.Lock();
				if (theApp.queCtr.size()>0)
				{
					vector<BYTE> tempQueVec=theApp.queCtr.front();
					theApp.queCtr.pop();
					strTempCmdLen=tempQueVec.size();
					strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,strTempCmdLen);
				} 
				else if(theApp.myclassMessage.boPrintNow)
				{
					theApp.boPrintNowLock.Lock();
					if (theApp.myclassMessage.bytPrintDataAllOrder.size()>11)
					{
						strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
						strTempCmdLen=theApp.myclassMessage.bytPrintDataAllOrder.size();
						theApp.myclassMessage.boPrintNow=false;
					} 
					else
					{
						strTempCmd=(LPTSTR)readArr;
						strTempCmdLen=8;
					}
					theApp.boPrintNowLock.Unlock();
				}
				else if (!theApp.myclassMessage.boPrintNow)
				{
					strTempCmd=(LPTSTR)readArr;
					strTempCmdLen=8;
				}
				theApp.boQueCtrLock.Unlock();
			}
		} 
		else if (theApp.myCIOVsd.m_pRecvBuf[0]==0x2&&theApp.myCIOVsd.m_pRecvBuf[1]==0x80&&theApp.myCIOVsd.m_pRecvBuf[3]==0x20)
		{
			bytComErr++;
			if (bytComErr>10)
			{/////弹出对话框
				int result =MessageBox( NULL,TEXT("是否继续") , TEXT("选择") ,MB_YESNO);
				switch(result)
				{
				case IDYES:
					bytComErr=0;
					strTempCmd=(LPTSTR)readArr;
					strTempCmdLen=8;
					break;
				case IDNO:
					AfxMessageBox(_T("串口通讯故障！\n请联系管理员！"));
					break;
				}
			} 
		}
		else    ///////////////用于测试。以后删掉
		{
			//bytComErr++;
			//if (bytComErr>10)
			//{/////弹出对话框
			//	int result =MessageBox( NULL,TEXT("无应答，是否继续") , TEXT("选择") ,MB_YESNO);
			//	switch(result)
			//	{
			//	case IDYES:
			//		bytComErr=0;
			//		strTempCmd=(LPTSTR)readArr;
			//		strTempCmdLen=8;
			//		break;
			//	case IDNO:
			//		AfxMessageBox(_T("串口无应答！\n请联系管理员！"));
			//		break;
			//	}
			//} 
			//strTempCmd=(LPTSTR)readArr;
			//strTempCmdLen=8;

			/////////以下代码测试用
			//theApp.boQueCtrLock.Lock();
			//if (theApp.queCtr.size()>0)
			//{
			//	vector<BYTE> tempQueVec=theApp.queCtr.front();
			//	theApp.queCtr.pop();
			//	strTempCmdLen=tempQueVec.size();
			//	strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
			//}
			//theApp.boQueCtrLock.Unlock();

			//if (theApp.myclassMessage.boDynamic)
			//{
			//	if (theApp.ForPreQue.size()>0)
			//	{
			//		theApp.boPrintNowLock.Lock();
			//			vector<BYTE> tempQueVec=theApp.ForPreQue.front();
			//			theApp.ForPreQue.pop();
			//		
			//			strTempCmdLen=tempQueVec.size();
			//			strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
			//			if (strTempCmdLen>11)
			//			{////动态显示相关
			//				vector<BYTE> intMesDis1;
			//				intMesDis1.insert(intMesDis1.end(),tempQueVec.begin(),tempQueVec.end());
			//				theApp.boDotForPreQue.push(intMesDis1);
			//				theApp.myclassMessage.intMesDis=theApp.boDotForPreQue.front();//这个其实可以不要
			//				theApp.boDotForPreQue.pop();
			//				vector<int> tempCountVec;
			//				if (theApp.intCounNumForPreQue.size()>0)
			//				{
			//					tempCountVec = theApp.intCounNumForPreQue.front();

			//					theApp.intCounNumForPreQue.pop();

			//					for (int num=0;num<tempCountVec.size();num++)
			//					{
			//						theApp.myclassMessage.CountNumForPre[num]=tempCountVec[num];
			//					}
			//				}
			//			} 
			//			else
			//			{
			//				strTempCmd=(LPTSTR)readArr;
			//				strTempCmdLen=8;
			//			}
			//		theApp.boPrintNowLock.Unlock();
			//	} 
			//	else
			//	{
			//		strTempCmd=(LPTSTR)readArr;
			//		strTempCmdLen=8;
			//	}
			//}
		}

		//theApp.myCIOVsd.ClearInOutBuf();
        theApp.myCIOVsd.Send(strTempCmd,strTempCmdLen);
		//strTempCmdLen=0;   ////////若发送失败，重新发送
		//strTempCmd=(LPTSTR)"";
		Sleep(10);
		
		theApp.readCount=theApp.myCIOVsd.Read();


		////////测试用
		//theApp.readCount=43;
		//theApp.myCIOVsd.m_pRecvBuf[0]=0x2;
		//theApp.myCIOVsd.m_pRecvBuf[1]=0x80;
		//theApp.myCIOVsd.m_pRecvBuf[2]=0x26;
		//theApp.myCIOVsd.m_pRecvBuf[10]=0xff;
	}


	return 0;
}
//序列号生成线程
UINT method1(LPVOID pParam)
{
	while(theApp.mythreadDynamicBoo)
	{
		if (theApp.ForPreQue.size()<2)
		{
			if (theApp.myclassMessage.bytSerialConCoun>0)
			{
				string StrSerialText="";
				string strTemp="";
				for (int i=0;i<theApp.myclassMessage.bytSerialConCoun;i++)
				{
					switch(theApp.myclassMessage.bytQserialCounter[i])
					{
					case 0:
						if (theApp.myclassMessage.CountNumRep0<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep0++;//=theApp.myclassMessage.CountNumRep0+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep0=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum0+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum0 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum0 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum0-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum0 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum0 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum0);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum0);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = OBJ_Control::to_String(theApp.myclassMessage.CountNum0);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					case 1:
						if (theApp.myclassMessage.CountNumRep1<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep1=theApp.myclassMessage.CountNumRep1+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep1=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum1+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum1 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum1 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum1-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum1 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum1 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum1);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum1);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = OBJ_Control::to_String(theApp.myclassMessage.CountNum1);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					case 2:
						if (theApp.myclassMessage.CountNumRep2<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep2=theApp.myclassMessage.CountNumRep2+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep2=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum2+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum2 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum2 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum2-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum2 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum2 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum2);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum2);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = OBJ_Control::to_String(theApp.myclassMessage.CountNum2);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					case 3:
						if (theApp.myclassMessage.CountNumRep3<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep3=theApp.myclassMessage.CountNumRep3+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep3=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum3+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum3 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum3 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum3-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum3 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum3 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum3);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +OBJ_Control::to_String(theApp.myclassMessage.CountNum3);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = OBJ_Control::to_String(theApp.myclassMessage.CountNum3);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					}
					int intRowEnd=theApp.myclassMessage.intQSerialRowStart[i] + theApp.myclassMessage.intQSerialRowSize[i];
					vector<BYTE> ttVec;
					ttVec=theApp.myclassMessage.DotToByte1(theApp.myclassMessage.intQSerialRowStart[i], intRowEnd, theApp.myclassMessage.bytPrintDataAll, theApp.myclassMessage.strQSerialFont[i], 
						theApp.myclassMessage.boQSerialBWDy[i], theApp.myclassMessage.boQSerialBWDx[i], theApp.myclassMessage.boQSerialNEG[i], StrSerialText, theApp.myclassMessage.intQSerialRowSize[i], 
						theApp.myclassMessage.bytQSerialLineSize[i],theApp.myclassMessage.bytQSerialLineStart[i], theApp.myclassMessage.intQSerialRowStart[i], theApp.myclassMessage.bytQSerialSS[i], theApp.myclassMessage.bytQSerialSW[i]);
					theApp.myclassMessage.bytPrintDataAll.clear();
					theApp.myclassMessage.bytPrintDataAll=ttVec;
				}
			}

			if (theApp.myclassMessage.bytTimeConCoun>0)
			{
				string *strETimetext1=new string[theApp.myclassMessage.bytTimeConCoun];
				theApp.boETimetextLock.Lock();
					//copy(begin(theApp.myclassMessage.strETimetext),end(theApp.myclassMessage.strETimetext),begin(strETimetext1));
					for(int strI=0;strI<theApp.myclassMessage.bytTimeConCoun;strI++)
					{
						strETimetext1[strI]=theApp.myclassMessage.strETimetext[strI];
					}
				theApp.boETimetextLock.Unlock();
				for (int j=0;j<theApp.myclassMessage.bytTimeConCoun;j++)
				{
					int intRowEnd=theApp.myclassMessage.intTimeRowStart[j] + theApp.myclassMessage.intTimeRowSize[j];
					vector<BYTE> ttVec;
					if (strETimetext1[j].length()!=0)
					{
						ttVec = theApp.myclassMessage.DotToByte1(theApp.myclassMessage.intTimeRowStart[j], intRowEnd, theApp.myclassMessage.bytPrintDataAll, 
							theApp.myclassMessage.strTimeFont[j], theApp.myclassMessage.boTimeBWDy[j], theApp.myclassMessage.boTimeBWDx[j], theApp.myclassMessage.boTimeNEG[j], 
							strETimetext1[j], theApp.myclassMessage.intTimeRowSize[j], theApp.myclassMessage.bytTimeLineSize[j], theApp.myclassMessage.bytTimeLineStart[j], 
							theApp.myclassMessage.intTimeRowStart[j], theApp.myclassMessage.bytTimeSS[j], theApp.myclassMessage.bytTimeSW[j]);
						theApp.myclassMessage.bytPrintDataAll.clear();
						theApp.myclassMessage.bytPrintDataAll=ttVec;
					}
				}
				delete []strETimetext1;
			}
			vector<BYTE> bytPrintDataAll1=theApp.myclassMessage.bytPrintDataAll;
			theApp.boPrintNowLock.Lock();
			theApp.ForPreQue.push(bytPrintDataAll1);
			
			vector<int> tempCounNum;
			tempCounNum.push_back(theApp.myclassMessage.CountNum0);
			tempCounNum.push_back(theApp.myclassMessage.CountNum1);
			tempCounNum.push_back(theApp.myclassMessage.CountNum2);
			tempCounNum.push_back(theApp.myclassMessage.CountNum3);
			theApp.intCounNumForPreQue.push(tempCounNum);
			theApp.boPrintNowLock.Unlock();

		}
		else 
		{
			Sleep(10);
		}
	}
	return 0;
}

 