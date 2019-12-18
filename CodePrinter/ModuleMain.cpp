#include "StdAfx.h"
#include "ModuleMain.h"
#include "CodePrinter.h"
#include<cmath>
ModuleMain::ModuleMain(void)
{
}

ModuleMain::~ModuleMain(void)
{
}

LPCWSTR ModuleMain::stringToLPCWSTR(string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
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

bool ModuleMain::writeXml(string xmlFileName,string valueStr,string textStr,string path)
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
			TiXmlText textCs(textStr.c_str());
			StuElement->InsertEndChild(textCs);
			return true;
		}

		//子元素
		TiXmlElement *childElm=StuElement->FirstChildElement();
		while (childElm != NULL)
		{
			string chiValue = childElm->Value();
			if (strValue==valueStr)
			{
				TiXmlText textCs(textStr.c_str());
				childElm->InsertEndChild(textCs);
				return true;
			}
			childElm = childElm->NextSiblingElement();
		}
	}
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

	int iLen = WideCharToMultiByte(CP_ACP, 0,STR, -1, NULL, 0, NULL, NULL);   //首先计算TCHAR 长度。

	char* chRtn =new char[iLen*sizeof(char)];  //定义一个 TCHAR 长度大小的 CHAR 类型。

	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);  //将TCHAR 类型的数据转换为 CHAR 类型。

	std::string str(chRtn); //最后将CHAR 类型数据 转换为 STRING 类型数据。

	return str;

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

string ModuleMain::CString2string(CString csStrData)
{
	string strRet ;

	char ss[2048];
	memset(ss, 0, sizeof(char)*2048);
	sprintf(ss, "%s", csStrData);

	strRet = ss;
	return strRet;
}

void ModuleMain::InitCommMsg()
{
	MyDcb tempDcb;
	tempDcb.nComPort=4;
	tempDcb.BaudRate=115200;
	tempDcb.ByteSize=(BYTE)8;
	tempDcb.Parity=(BYTE)0;
	tempDcb.StopBits=(BYTE)1;
	tempDcb.bIsSave=false;
	theApp.myCIOVsd.SetComIndx(tempDcb.nComPort);
	if (!theApp.myCIOVsd.OpenComm(tempDcb))
	{
		CString csMsg = _T("串口4打开失败!");
		//csMsg.Format("串口%d打开失败!",tempDcb.nComPort);
		AfxMessageBox(csMsg);
	}
}

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
	staSysRea = (GETnBIT_from_bytStatus(0, 0, 1)==_T("1"));  //系统准备好
	staSysBus = (GETnBIT_from_bytStatus(0, 1, 1)==_T("1")) ;  //系统忙
	staBumMod = (GETnBIT_from_bytStatus(0, 2, 1)==_T("1"))  ; //泵模式
	staBum = (GETnBIT_from_bytStatus(0, 3, 1)==_T("1"))   ;   //'泵开关
	staHarFin = (GETnBIT_from_bytStatus(0, 4, 1)==_T("1")) ;  //'下位机复位完成
	staCleFauFin = (GETnBIT_from_bytStatus(0, 5, 1)==_T("1")) ;// '清除故障完成
	staNozVal = (GETnBIT_from_bytStatus(1, 0, 1)==_T("1"));   //'喷嘴阀
	staFeeVal = (GETnBIT_from_bytStatus(1, 1, 1)==_T("1")) ;  //'供墨阀
	staBleVal = (GETnBIT_from_bytStatus(1, 2, 1)==_T("1")) ;  //'排气阀
	staFluVal = (GETnBIT_from_bytStatus(1, 3, 1)==_T("1")) ;  //'清洗阀
	staSolVal = (GETnBIT_from_bytStatus(1, 4, 1)==_T("1")) ;  //'溶剂阀
	staVisVal = (GETnBIT_from_bytStatus(1, 5, 1)==_T("1")) ;  //'粘度阀
	staWasVal = (GETnBIT_from_bytStatus(1, 6, 1)==_T("1")) ;  //'冲洗阀
	staInkFloSenOff = (GETnBIT_from_bytStatus(2, 0, 1)==_T("1")) ;  //'关回收
	staCloInkLin = (GETnBIT_from_bytStatus(2, 1, 1)==_T("1")) ;  //'关墨线
	staAddSol = (GETnBIT_from_bytStatus(2, 2, 1)==_T("1"))  ; //'添加溶剂
	staDetVis = (GETnBIT_from_bytStatus(2, 3, 1)==_T("1"))  ; //'测试粘度
	staWasNoz = (GETnBIT_from_bytStatus(2, 4, 1)==_T("1"))  ; //'冲洗喷头
	staSucNoz = (GETnBIT_from_bytStatus(2, 5, 1)==_T("1"))   ;//'反吸喷嘴
	staAdjInkLin = (GETnBIT_from_bytStatus(2, 6, 1)==_T("1")) ; // '墨路校正
	staInkCir = (GETnBIT_from_bytStatus(2, 7, 1)==_T("1"))  ; //'墨路循环
	staInkTemSenFau = (GETnBIT_from_bytStatus(3, 0, 1)==_T("1"))  ; //'墨水温度传感器故障
	staPriHeaTemFau = (GETnBIT_from_bytStatus(3, 1, 1)==_T("1")) ;  //'喷头温度传感器故障
	staBumSpeOveFau = (GETnBIT_from_bytStatus(3, 2, 1)==_T("1")) ;  //'泵超速保护
	staPreOveFau = (GETnBIT_from_bytStatus(3, 3, 1)==_T("1"))  ; //'过压保护
	staVisAbnFau = (GETnBIT_from_bytStatus(3, 4, 1)==_T("1")) ;  //'粘度异常
	staVisSenFau = (GETnBIT_from_bytStatus(3, 5, 1)==_T("1")) ; //'粘度计故障
	staInkFloFau = (GETnBIT_from_bytStatus(3, 6, 1)==_T("1"))  ; //'回收故障
	staPriHeaCle = (GETnBIT_from_bytStatus(3, 7, 1)==_T("1")) ;  //'开关机清洗
	staFanFau = (GETnBIT_from_bytStatus(4, 0, 1)==_T("1")) ; // '风扇故障
	staChaFau = (GETnBIT_from_bytStatus(4, 1, 1)==_T("1")) ;  //'充电故障
	staPhaFau = (GETnBIT_from_bytStatus(4, 2, 1)==_T("1")) ;  //'相位故障
	staHigVolFau = (GETnBIT_from_bytStatus(4, 3, 1)==_T("1")) ; // '高压故障
	staSolLevFau = theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 5, 1)==_T("1")) +theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 4, 1)==_T("1"));  //'溶剂液位状态
	staInkLevFau = theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 7, 1)==_T("1")) + theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 6, 1)==_T("1"));  //'墨水液位状态
	staPrnting = (GETnBIT_from_bytStatus(5, 0, 1)==_T("1")) ; // '打印中
	//'staBufOveFau = IIf(GETnBIT_from_bytStatus(5, 2, 1)==_T("1"));  // '文本buf溢出
	staHigVolSwi = (GETnBIT_from_bytStatus(5, 3, 1)==_T("1"))  ; //'高压开关
	staActProSen = (GETnBIT_from_bytStatus(5, 4, 1)==_T("1"))  ; //'电眼当前电平
	staProSenFas = (GETnBIT_from_bytStatus(5, 5, 1)==_T("1")) ;  ////'电眼过快
	staAutModFau = (GETnBIT_from_bytStatus(5, 6, 1)==_T("1")) ; // '自动分裂失败
	staValFau = (GETnBIT_from_bytStatus(5, 7, 1)==_T("1")) ;  //'阀故障
	staPrinted = (GETnBIT_from_bytStatus(6, 0, 1)==_T("1"))  ; //'打印完成
	staRemPrinSwi = (GETnBIT_from_bytStatus(6, 1, 1)==_T("1")); //  '远程打印开关
	//'staBufFul = (GETnBIT_from_bytStatus(6, 2, 1)==_T("1"));   //'文本buf满
	staBufRea = (GETnBIT_from_bytStatus(6, 3, 1)==_T("1")) ;  //'信息准备好
	staEncDir = (GETnBIT_from_bytStatus(6, 4, 1)==_T("1")) ;  //'编码器方向
	staLinFas = (GETnBIT_from_bytStatus(6, 5, 1)==_T("1")) ;  //'编码器过快
	staPriHeaHot = (GETnBIT_from_bytStatus(6, 6, 1)==_T("1"));  // '恒温状态
	staPriHeaHotFau = (GETnBIT_from_bytStatus(6, 7, 1)==_T("1")) ; // '恒温故障
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
	staActVis = theApp.bytStatus[14]     ;                                     //'目前实时粘度
	staTarVis = theApp.bytStatus[15] ;                                         // '目标参考粘度
	staInkLev = theApp.bytStatus[16]  ;                                        // '实时墨水液位
	staSolLev = theApp.bytStatus[17] ;                                          //'实时溶剂液位
	staHigVol = theApp.bytStatus[19]* 256 + theApp.bytStatus[18] ;                      // '实时高压
	staPhase = theApp.bytStatus[20]   ;                                        // '实时相位
	staEncFre = theApp.bytStatus[22] * 256 + theApp.bytStatus[21] ;                       //'实时编码器频率
	staProCou = theApp.bytStatus[26] * pow(256 , 3) + theApp.bytStatus[25] * pow(256 , 2 )+ theApp.bytStatus[24] * 256 + theApp.bytStatus[23];      // '产品计数器
	staPriCou = theApp.bytStatus[30] * pow(256 , 3) + theApp.bytStatus[29] * pow(256 , 2 )+ theApp.bytStatus[28] * 256 + theApp.bytStatus[27];      // '打印计数器
	staPixDotNee = theApp.bytStatus[31];                                  // '列构成点数
	staAutModVol = theApp.bytStatus[32];                                  // '自动分裂电压

	staSetTimeEna = (GETnBIT_from_bytStatus(36, 5, 1)==_T("1"));   //'维护、墨水时间更改功能开放
	if (!staSetTimeEna)
	{
		staInkLifeTime = (theApp.bytStatus[36] & 31) * pow(256 , 3) + theApp.bytStatus[35] * pow(256 , 2) + theApp.bytStatus[34] * 256 + theApp.bytStatus[33];   // '墨水时间
		staRFID =  theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(36, 7, 1)==_T("1")) + theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(36, 6, 1)==_T("1")); //'RFID状态
	}
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
	return cstringStr.Mid(cstringStr.GetLength()-m,n);
}

CString GETnBIT_from_bytStatus(int I , int m , int n )
{
	string tempCstr="";
	ModuleMain tempstringToLPCWSTR;
	tempCstr="00000000"+theApp.myclassMessage.DEC_to_BIN(theApp.myCIOVsd.m_pRecvBuf[I]);

	//tempCstr=tempCstr.Mid(tempCstr.GetLength()-m,n);
	CString cstringStr= tempstringToLPCWSTR.stringToLPCWSTR(tempCstr);
	return cstringStr.Mid(cstringStr.GetLength()-m,n);
}

UINT TTLcomLoop(LPVOID pParam)
{
	theApp.boTTL=true;
	int bytComErr=0;
	int strTempCmdLen=0;
	LPTSTR strTempCmd;
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};
	while(theApp.boTTL)
	{
		if (theApp.readCount==43)
		{
			theApp.readCount=0;
			strTempCmdLen=0;
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
						if (GETnBIT_from_bytReadData(6,2,1)==_T("1"))
						{
							if (theApp.myclassMessage.boDynamic)
							{
								if (theApp.myclassMessage.forPreQue.size()>0)
								{
									vector<BYTE> tempQueVec=theApp.myclassMessage.forPreQue.front();
									theApp.myclassMessage.forPreQue.pop();
									strTempCmdLen=tempQueVec.size();
									strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
									if (strTempCmdLen>11)
									{////动态显示相关
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
								strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
								strTempCmdLen=theApp.myclassMessage.bytPrintDataAllOrder.size();
								if (strTempCmdLen<12)
								{
									strTempCmd=(LPTSTR)readArr;
									strTempCmdLen=8;
								}
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

		if (theApp.readCount==6)
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
		else    ///////////////认为应该增加无应答情况
		{
			bytComErr++;
			if (bytComErr>10)
			{/////弹出对话框
				int result =MessageBox( NULL,TEXT("无应答，是否继续") , TEXT("选择") ,MB_YESNO);
				switch(result)
				{
				case IDYES:
					bytComErr=0;
					strTempCmd=(LPTSTR)readArr;
					strTempCmdLen=8;
					break;
				case IDNO:
					AfxMessageBox(_T("串口无应答！\n请联系管理员！"));
					break;
				}
			} 
			strTempCmd=(LPTSTR)readArr;
			strTempCmdLen=8;
		}
		//theApp.myCIOVsd.ClearInOutBuf();
        theApp.myCIOVsd.Send(strTempCmd,strTempCmdLen);

		Sleep(10);
		
		theApp.readCount=theApp.myCIOVsd.Read();
	}


	return 0;
}