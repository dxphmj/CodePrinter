#include "StdAfx.h"
#include "ModuleMain.h"
#include "CodePrinter.h"
#include<cmath>
#include<algorithm>
#include <fstream>
#include<cstdio>
//#include <iostream>
#include <math.h>
#include <sstream>//使用该库函数的ostringstream，将int变成string
ModuleMain::ModuleMain(void)
{
}

ModuleMain::~ModuleMain(void)
{
}

//字符转数字
int ModuleMain::charToDigit(char c)
{
	if(c=='A'||c=='a')
		return 10;
	else if(c=='B'||c=='b')
		return 11;
	else if(c=='C'||c=='c')
		return 12;
	else if(c=='D'||c=='d')
		return 13;
	else if(c=='E'||c=='e')
		return 14;
	else if(c=='F'||c=='f')
		return 15;
	else
		return c-'0';
}

int ModuleMain::jinzhi16to10(string pre)
{
	int length=pre.size();
	int result=0;
	for(int i=0; i<length; i++)
	{
		result+=((charToDigit(pre[i]))*pow(16.0,length-1-i));
	}
	return result;
}

int ModuleMain::jinzhi8to10(string pre) {
	int length=pre.size();
	int result=0;
	for(int i=0; i<length; i++)
	{
		result+=((charToDigit(pre[i]))*pow(8.0,length-1-i));
	}
	return result;
}

int ModuleMain::jinzhi2to10(string pre)
{
	// 在此处可以添加验证是否为二进制数字的逻辑
	int length=pre.size();
	int result=0;
	for(int i=0; i<length; i++)
	{
		result+=((charToDigit(pre[i]))*pow(2.0,length-1-i));
	}
	return result;
}

string ModuleMain::jinzhi10to2(int pre) {
	ostringstream oss;
	while(pre!=0){
		oss<<pre%2;
		pre/=2;
	}
	string res=oss.str();
	oss.str("");//清空原数据流
	for(int i=0;i<res.length();i++){
		oss<<res[res.length()-i-1];
	}
	return oss.str();
}
string ModuleMain::jinzhi10to8(int pre) {
	ostringstream oss;
	while(pre!=0){
		oss<<pre%8;
		pre/=8;
	}
	string res=oss.str();
	oss.str("");//清空原数据流
	for(int i=0;i<res.length();i++){
		oss<<res[res.length()-i-1];
	}
	return oss.str();
}
string ModuleMain::jinzhi10to16(int pre) {
	//ostringstream oss;
	//while(pre!=0){
	//	oss<<pre%16;
	//	pre/=16;
	//}
	//string res=oss.str();
	//oss.str("");//清空原数据流
	//for(int i=0;i<res.length();i++){
	//	oss<<res[res.length()-i-1];
	//}
	//return oss.str();
	string str;
	long long Temp = pre / 16;
	int left = pre % 16;
	if (Temp > 0)
		str += jinzhi10to16(Temp);
	if (left < 10)
		str += (left + '0');
	else
		str += ('A' + left - 10);
	return str;
}

LPCWSTR ModuleMain::stringToLPCWSTR(string orig)
{
	//size_t origsize = orig.length() + 1;
	//const size_t newsize = 100;
	//size_t convertedChars = 0;
	//wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	//mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	//return wcstring;
	return string2CString(orig);

	/*
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
  
    USES_CONVERSION;  
	return A2W(orig.c_str());
  */
}

string ModuleMain::WcharToChar(const wchar_t* wp, size_t m_encode)
{
	std::string str;
	int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
	char	*m_char = new char[len + 1];
	WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	str = m_char;
	delete m_char;
	return str;
}

string ModuleMain::ReadXml(string xmlFileName,string nameStr,string faultText,string path)
{
	path=path+"\\"+xmlFileName;
	TiXmlDocument mydoc(path.c_str());//xml文档对象
	bool loadOk=mydoc.LoadFile();//加载文档
	if(!loadOk)
	{
		return faultText;
	}

	TiXmlElement *RootElement=mydoc.RootElement();	//根元素
	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
	{
		string strValue = StuElement->Value();
		if (strValue==nameStr)
		{
			return StuElement->GetText();
		}

		//子元素
		TiXmlElement *childElm=StuElement->FirstChildElement();
		while (childElm != NULL)
		{
			string strChiValue = childElm->Value();
			if (strChiValue==nameStr)
			{
				return childElm->GetText();
			}
			childElm = childElm->NextSiblingElement();
		}
	}
    return faultText;
}

//bool ModuleMain::writeXml(string xmlFileName,string valueStr,string textStr,string path)
//{
//	path=path+"\\"+xmlFileName;
//	TiXmlDocument mydoc(path.c_str());//xml文档对象
//	bool loadOk=mydoc.LoadFile();//加载文档
//	if(!loadOk)
//	{
//		return false;
//	}
//
//	TiXmlElement *RootElement=mydoc.RootElement();	//根元素
//	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
//	{
//		string strValue = StuElement->Value();
//		if (strValue==valueStr)
//		{
//			TiXmlText textCs(textStr.c_str());
//			StuElement->InsertEndChild(textCs);
//			mydoc.SaveFile();
//			return true;
//		}
//
//		//子元素
//		TiXmlElement *childElm=StuElement->FirstChildElement();
//		while (childElm != NULL)
//		{
//			string chiValue = childElm->Value();
//			if (strValue==valueStr)
//			{
//				TiXmlText textCs(textStr.c_str());
//				childElm->InsertEndChild(textCs);
//				mydoc.SaveFile();
//				return true;
//			}
//			childElm = childElm->NextSiblingElement();
//		}
//	}
//	return false;
//}

bool ModuleMain::changeXml(string xmlFileName,string valueStr,string textStr,string path)
{
	path=path+"\\"+xmlFileName;
	TiXmlDocument mydoc(path.c_str());//xml文档对象
	bool loadOk=mydoc.LoadFile();//加载文档
	if(!loadOk)
	{
		return false;
	}

	TiXmlElement *RootElement=mydoc.RootElement();	//根元素
	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
	{
		string strValue = StuElement->Value();
		if (strValue==valueStr)
		{
			TiXmlNode *pValue = StuElement->FirstChild();
			if (pValue)
			{
				pValue->SetValue(textStr.c_str());
				mydoc.SaveFile();
				return true;
			}
		}

		//子元素
		TiXmlElement *childElm=StuElement->FirstChildElement();
		while (childElm != NULL)
		{
			string strChiValue = childElm->Value();
			if (strChiValue==valueStr)
			{
				TiXmlNode *pValue = childElm->FirstChild();
				if (pValue)
				{
					pValue->SetValue(textStr.c_str());
					mydoc.SaveFile();
					return true;
				}
			}
			childElm = childElm->NextSiblingElement();
		}
	}
	mydoc.SaveFile();
	return false;
	
}

void ModuleMain::string2tchar(std::string &src, TCHAR* buf)
{
#ifdef UNICODE  
	_stprintf_s(buf, MAX_PATH, _T("%S"), src.c_str());//%S宽字符  
#else  
	_stprintf_s(buf, MAX_PATH, _T("%s"), src.c_str());//%s单字符
#endif
}

string ModuleMain::TCHAR2STRING(TCHAR *STR)

{

	//int iLen = WideCharToMultiByte(CP_ACP, 0,STR, -1, NULL, 0, NULL, NULL);   //首先计算TCHAR 长度。

	//char* chRtn =new char[iLen*sizeof(char)];  //定义一个 TCHAR 长度大小的 CHAR 类型。

	//WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);  //将TCHAR 类型的数据转换为 CHAR 类型。

	//std::string str(chRtn); //最后将CHAR 类型数据 转换为 STRING 类型数据。

	//return str;

	return   UnicodeToUtf8(STR);  


}


const char* ModuleMain::CString2ConstChar(CString str)
{
	//CStringA     stra(str.GetBuffer(0));
	//str.ReleaseBuffer();
	//string          st(stra.GetBuffer(0));
	//const char*  cs = st.c_str();
	char szStr[256] = {};  
	wcstombs(szStr, str, str.GetLength());//将宽字符转换成多字符  
	const char* pBuf = szStr; 
	return pBuf;
}

//string ModuleMain::CString2string(CString csStrData)
//{
//	string strRet ;
//
//	char ss[2048];
//	memset(ss, 0, sizeof(char)*2048);
//	sprintf(ss, "%s", csStrData);
//
//	strRet = ss;
//	return strRet;
//}

void ModuleMain::InitCommMsg()
{
	MyDcb tempDcb;
	tempDcb.nComPort=4;
	tempDcb.BaudRate=115200;
	tempDcb.ByteSize=(BYTE)8;
	tempDcb.Parity=(BYTE)0;
	tempDcb.StopBits=(BYTE)0;
	tempDcb.bIsSave=true;
	theApp.myCIOVsd.SetComIndx(tempDcb.nComPort);
	if (!theApp.myCIOVsd.OpenComm(tempDcb))
	{
		CString csMsg ;//= _T("串口4打开失败!");
		csMsg.Format(_T("串口%d打开失败!"),tempDcb.nComPort);
		AfxMessageBox(csMsg);
	}
}


void ModuleMain::DisableAllBtn(HWND hwnd,bool booOpen)
{
	HWND subWnd = ::GetWindow(hwnd,GW_CHILD);
	//HWND subWnd = ::GetWindow(this->GetSafeHwnd(),GW_CHILD);//如果是CFormView
	while(subWnd)   
	{   
		CWnd *subCWnd = CWnd::FromHandle(subWnd);//HWND转Cwnd
		TCHAR ClassName[MAX_PATH];
		GetClassName(subCWnd->GetSafeHwnd(), ClassName, MAX_PATH);
		string strClassName=TCHAR2STRING(ClassName);
		if(strClassName=="Button"||strClassName=="button"){
			subCWnd->EnableWindow(booOpen);
		}
		if(strClassName=="combobox"){
			subCWnd->EnableWindow(booOpen);
		}
		if(strClassName=="Edit"){
			subCWnd->EnableWindow(booOpen);
		}
		if(strClassName=="listbox"){
			subCWnd->EnableWindow(booOpen);
		}
		////类型不知道为什么判断不出来
		//if (subCWnd->IsKindOf(RUNTIME_CLASS(CListBox))) {
		//	subCWnd->EnableWindow(booOpen);
		//}
		//if (subCWnd->IsKindOf(RUNTIME_CLASS(CButton))) {
		//	subCWnd->EnableWindow(booOpen);
		//}
		//if (subCWnd->IsKindOf(RUNTIME_CLASS(CComboBox))) {
		//	subCWnd->EnableWindow(booOpen);
		//}
		//if (subCWnd->IsKindOf(RUNTIME_CLASS(CEdit))) {
		//	subCWnd->EnableWindow(booOpen);
		//}

		subWnd = ::GetWindow(subWnd,GW_HWNDNEXT);
	}
}
void ModuleMain::ReportPower()
{
	CString csMsg=_T("操作失败！\n您无此权限！") ;//= _T("串口4打开失败!");
	//csMsg.Format(_T("串口%d打开失败!"),tempDcb.nComPort);
	AfxMessageBox(csMsg);
}
bool ModuleMain::MesDisIsB(int MesDis,int isNumber)
{
	int tempB=MesDis&(1 << isNumber);
	if (tempB>0)
	{
		return true;
	} 
	else
	{
		return false;
	}
}
////////////////////////////////////////////////
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
	staSolLevFau = theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 5, 1)==_T("1")?true:false) +theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 4, 1)==_T("1")?true:false);  //'溶剂液位状态
	staInkLevFau = theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 7, 1)==_T("1")?true:false) + theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 6, 1)==_T("1")?true:false);  //'墨水液位状态
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
		staRFID =  theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(36, 7, 1)==_T("1")?true:false) + theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(36, 6, 1)==_T("1")?true:false); //'RFID状态
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
	tempCstr="00000000"+theApp.myclassMessage.DEC_to_BIN(theApp.myCIOVsd.m_pRecvBuf[I+4]);

    //tempCstr=tempCstr.Mid(tempCstr.GetLength()-m,n);
	CString cstringStr= tempstringToLPCWSTR.stringToLPCWSTR(tempCstr);
	return cstringStr.Mid(cstringStr.GetLength()-m-1,n);
}

CString GETnBIT_from_bytStatus(int I , int m , int n )
{
	string tempCstr="";
	ModuleMain tempstringToLPCWSTR;
	tempCstr="00000000"+theApp.myclassMessage.DEC_to_BIN(theApp.bytStatus[I]);

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
							theApp.myclassMessage.CountNumRep0=theApp.myclassMessage.CountNumRep0+1;
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
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum0);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum0);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum0);
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
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum1);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum1);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum1);
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
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum2);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum2);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum2);
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
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum3);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum3);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum3);
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

//根据序列号格式生成喷印文本
string ModuleMain::SerialFormatToText(int Value, int Digits, int Format)
{
	string OutPutSerialText="";
	string strTemp="";
	switch(Format)
	{
	case 0:
		for (int a=0;a<Digits;a++)
		{
			strTemp=strTemp+"0";
		}
		strTemp=strTemp+theApp.myclassMessage.to_String(Value);
		OutPutSerialText=strTemp.substr(strTemp.length()-Digits,Digits);
		break;
	case 1:
		for (int a=0;a<Digits;a++)
		{
			strTemp=strTemp+" ";
		}
		strTemp=strTemp+theApp.myclassMessage.to_String(Value);
		OutPutSerialText=strTemp.substr(strTemp.length()-Digits,Digits);
		break;
	case 2:
		strTemp=theApp.myclassMessage.to_String(Value);
		int n=Digits-strTemp.length();
		for(int a=0;a<n;a++)
		{
			strTemp=strTemp+" ";
		}
		OutPutSerialText=strTemp;
		break;
	}
	return OutPutSerialText;
}

//主动下发打印数据后如有序列号要提前生成BUF2里面的内容
void ModuleMain::getSerialDotBuf2()
{
	string tempText="";
	for (int i=0;i<theApp.myclassMessage.bytSerialConCoun;i++)
	{
		switch(theApp.myclassMessage.bytQserialCounter[i])
		{
		case 0:
			if (theApp.myclassMessage.CountNumRep0<theApp.myclassMessage.intQSerialRepeat[i])
			{
				theApp.myclassMessage.CountNumRep0=theApp.myclassMessage.CountNumRep0+1;
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
			tempText = SerialFormatToText(theApp.myclassMessage.CountNum0,theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialFormat[i]);
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

			tempText = SerialFormatToText(theApp.myclassMessage.CountNum1,theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialFormat[i]);
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
			tempText = SerialFormatToText(theApp.myclassMessage.CountNum2,theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialFormat[i]);
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
			tempText = SerialFormatToText(theApp.myclassMessage.CountNum0,theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialFormat[i]);
			break;
		}
            theApp.myclassMessage.getdot(theApp.myclassMessage.strQSerialFont[i], theApp.myclassMessage.boQSerialBWDy[i], theApp.myclassMessage.boQSerialBWDx[i], 
				theApp.myclassMessage.boQSerialNEG[i], tempText, theApp.myclassMessage.intQSerialRowSize[i], theApp.myclassMessage.bytQSerialLineSize[i], 
				theApp.myclassMessage.bytQSerialLineStart[i], theApp.myclassMessage.intQSerialRowStart[i], theApp.myclassMessage.bytQSerialSS[i],theApp.myclassMessage. bytQSerialSW[i]);
	}
	//vector<BYTE> bytPrintDataAll1=theApp.myclassMessage.bytPrintDataAll;
	//theApp.myclassMessage.ForPreQue.push(bytPrintDataAll1);
	vector<int> tempCounNum;
	tempCounNum.push_back(theApp.myclassMessage.CountNum0);
	tempCounNum.push_back(theApp.myclassMessage.CountNum1);
	tempCounNum.push_back(theApp.myclassMessage.CountNum2);
	tempCounNum.push_back(theApp.myclassMessage.CountNum3);
	theApp.intCounNumForPreQue.push(tempCounNum);

	for (int j=0;j<theApp.myclassMessage.bytSerialConCoun;j++)
	{
		int intRowEnd = theApp.myclassMessage.intQSerialRowStart[j] + theApp.myclassMessage.intQSerialRowSize[j];
		vector<BYTE> bytDynamicData= theApp.myclassMessage.DotToByte(theApp.myclassMessage.intQSerialRowStart[j], intRowEnd);
		
		if (theApp.myclassMessage.boReverse)
		{
			copy(bytDynamicData.begin(),bytDynamicData.end(),theApp.myclassMessage.bytPrintDataAll.begin()+(theApp.myclassMessage.intRowMax - intRowEnd) * theApp.myclassMessage.bytRowByteMul + 11);
		} 
		else
		{
			copy(bytDynamicData.begin(),bytDynamicData.end(),theApp.myclassMessage.bytPrintDataAll.begin()+theApp.myclassMessage.intQSerialRowStart[j] * theApp.myclassMessage.bytRowByteMul + 11);
		}
	}
	vector<BYTE> bytPrintDataAll1;
	bytPrintDataAll1.assign(theApp.myclassMessage.bytPrintDataAll.begin(),theApp.myclassMessage.bytPrintDataAll.end());
	theApp.ForPreQue.push(bytPrintDataAll1);
}

//时间文本生成
string ModuleMain::TimeFormatToText(CString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint)
{
	CString outCStr;
	if (tempstrETimeOffSet==0)
	{
		CTime NowTime=CTime::GetCurrentTime();
		outCStr=NowTime.Format(InPutTimeFormat);
	} 
	else
	{
		CTime tempTime=CTime::GetCurrentTime();
		//outCStr=NowTime.Format(InPutTimeFormat);
		CTime NowTime;

		int addYear=0,addMonth=0,addDay=0,addHour=0,addMinute=0;
		switch(tempstrTimeOffSetUint)
		{
		case 0:
			if (tempTime.GetYear()+tempintTimeOffSet<3000)
			{
				addYear=tempintTimeOffSet;
				NowTime=CTime(tempTime.GetYear()+addYear,tempTime.GetMonth()+addMonth,tempTime.GetDay()+addDay,tempTime.GetHour()+addHour,tempTime.GetMinute()+addMinute,tempTime.GetSecond());
			}
			break;
		case 1:
			while(tempTime.GetMonth()+tempintTimeOffSet>12)
			{
				addYear++;
				tempintTimeOffSet-=12;
			}
			addMonth=tempintTimeOffSet;
			NowTime=CTime(tempTime.GetYear()+addYear,tempTime.GetMonth()+addMonth,tempTime.GetDay()+addDay,tempTime.GetHour()+addHour,tempTime.GetMinute()+addMinute,tempTime.GetSecond());

			break;
		case 2:
			while (tempTime.GetDay()+tempintTimeOffSet>31)
			{
				addMonth++;
				tempintTimeOffSet-=31;
			}
			addDay=tempintTimeOffSet;
			while(tempTime.GetMonth()+addMonth>12)
			{
				addYear++;
				addMonth-=12;
			}
			NowTime=CTime(tempTime.GetYear()+addYear,tempTime.GetMonth()+addMonth,tempTime.GetDay()+addDay,tempTime.GetHour()+addHour,tempTime.GetMinute()+addMinute,tempTime.GetSecond());
			break;
		case 3:
			while(tempTime.GetHour()+tempintTimeOffSet>23)
			{
				addDay++;
				tempintTimeOffSet-=24;
			}
			addHour=tempintTimeOffSet;
			while(tempTime.GetDay()+addDay>31)
			{
				addMonth++;
				addDay-=31;
			}
			while(tempTime.GetMonth()+addMonth>12)
			{
				addYear++;
				addMonth-=12;
			}
			NowTime=CTime(tempTime.GetYear()+addYear,tempTime.GetMonth()+addMonth,tempTime.GetDay()+addDay,tempTime.GetHour()+addHour,tempTime.GetMinute()+addMinute,tempTime.GetSecond());
			break;
		case 4:
			while(tempTime.GetMinute()+tempintTimeOffSet>59)
			{
				addHour++;
				tempintTimeOffSet-=60;
			}
			addMinute=tempintTimeOffSet;
			while(tempTime.GetHour()+addHour>23)
			{
				addDay++;
				addHour-=24;
			}
			while(tempTime.GetDay()+addDay>31)
			{
				addMonth++;
				addDay-=31;
			}
			while(tempTime.GetMonth()+addMonth>12)
			{
				addYear++;
				addMonth-=12;
			}
			NowTime=CTime(tempTime.GetYear()+addYear,tempTime.GetMonth()+addMonth,tempTime.GetDay()+addDay,tempTime.GetHour()+addHour,tempTime.GetMinute()+addMinute,tempTime.GetSecond());
			break;
		}
		outCStr=NowTime.Format(InPutTimeFormat);
	}
	return CString2string(outCStr);
}
//时间序列号刷新时间
void ModuleMain::refalsetimedata()
{
	if (theApp.myclassMessage.bytTimeConCoun>0)
	{
		theApp.boETimetextLock.Lock();
		for (int j=0;j<theApp.myclassMessage.bytTimeConCoun;j++)
		{
			theApp.myclassMessage.strETimetext[j]=TimeFormatToText(string2CString(theApp.myclassMessage.strTimeFormat[0][j]),theApp.myclassMessage.strETimeOffSet[j],theApp.myclassMessage.intTimeOffSetdis[j],theApp.myclassMessage.strTimeOffSetUint[j]);
		}
		theApp.boETimetextLock.Unlock();
	}
}
std::string ModuleMain::ASCToUTF8(const std::string& str) 
{
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);   
	wchar_t *pUnicode = new  wchar_t[unicodeLen + 1];   
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));  
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);  
	std::wstring wrt = (wchar_t*)pUnicode;    delete  pUnicode;   
	int iTextLen = WideCharToMultiByte(CP_UTF8, 0, wrt.c_str(), -1, NULL, 0, NULL, NULL);  
	char *pElementText = new char[iTextLen + 1];   
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1)); 
	::WideCharToMultiByte(CP_UTF8, 0, wrt.c_str(), -1, pElementText, iTextLen, NULL, NULL);   
	std::string strText = pElementText;    delete pElementText;    
	return strText;
}


//字符转换库
wstring ModuleMain::AsciiToUnicode(const string& str) {  
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);  
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str;  
}  
string ModuleMain::UnicodeToAscii(const wstring& wstr) {  
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);  
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);  
	string ret_str = pAssii;  
	free(pAssii);  
	return ret_str;  
}  
wstring ModuleMain::Utf8ToUnicode(const string& str) {  
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);  
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str;  
}  
string ModuleMain::UnicodeToUtf8(const wstring& wstr) {  
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);  
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);  
	string ret_str = pAssii;  
	free(pAssii);  
	return ret_str;  
}  
string ModuleMain::AsciiToUtf8(const string& str) {  
	return UnicodeToUtf8(AsciiToUnicode(str));  
}  
string ModuleMain::Utf8ToAscii(const string& str) {  
	return UnicodeToAscii(Utf8ToUnicode(str));  
}  
// ASCII与Unicode互转  
CStringW    ModuleMain::AsciiToUnicode_CSTR(const CStringA& str) {  
	return AsciiToUnicode(LPCSTR(str)).c_str();  
}  
CStringA    ModuleMain::UnicodeToAscii_CSTR(const CStringW& wstr) {  
	return UnicodeToAscii(LPCWSTR(wstr)).c_str();  
}  
// UTF8与Unicode互转  
CStringW    ModuleMain::Utf8ToUnicode_CSTR(const CStringA& str) {  
	return Utf8ToUnicode(LPCSTR(str)).c_str();  
}  
CStringA    ModuleMain::UnicodeToUtf8_CSTR(const CStringW& wstr) {  
	return UnicodeToUtf8(LPCWSTR(wstr)).c_str();  
}  
// ASCII与UTF8互转  
CStringA    ModuleMain::AsciiToUtf8_CSTR(const CStringA& str) {  
	return UnicodeToUtf8_CSTR(AsciiToUnicode_CSTR(str));  
}  
CStringA    ModuleMain::Utf8ToAscii_CSTR(const CStringA& str) {  
	return UnicodeToAscii_CSTR(Utf8ToUnicode_CSTR(str));  
}  
// string 与 Int 互转  
int ModuleMain::StringToInt(const string& str) {  
	return atoi(str.c_str());  
}  
string ModuleMain::IntToString(int i) {  
	char ch[1024];  
	memset(ch, 0, 1024);  
	sprintf_s(ch, sizeof(ch), "%d", i);  
	return ch;  
}  
string ModuleMain::IntToString(char i) {  
	char ch[1024];  
	memset(ch, 0, 1024);  
	sprintf_s(ch, sizeof(ch), "%c", i);  
	return ch;  
}  
string ModuleMain::IntToString(double i) {  
	char ch[1024];  
	memset(ch, 0, 1024);  
	sprintf_s(ch, sizeof(ch), "%f", i);  
	return ch;  
}  