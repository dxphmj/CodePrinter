#include "StdAfx.h"
#include "ModuleMain.h"
#include "CodePrinter.h"
#include<cmath>
#include<algorithm>
#include <fstream>
#include<cstdio>
//#include <iostream>
#include <math.h>
#include <sstream>//ʹ�øÿ⺯����ostringstream����int���string
ModuleMain::ModuleMain(void)
{
}

ModuleMain::~ModuleMain(void)
{
}

//�ַ�ת����
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
	// �ڴ˴����������֤�Ƿ�Ϊ���������ֵ��߼�
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
	oss.str("");//���ԭ������
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
	oss.str("");//���ԭ������
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
	//oss.str("");//���ԭ������
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
	TiXmlDocument mydoc(path.c_str());//xml�ĵ�����
	bool loadOk=mydoc.LoadFile();//�����ĵ�
	if(!loadOk)
	{
		return faultText;
	}

	TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
	{
		string strValue = StuElement->Value();
		if (strValue==nameStr)
		{
			return StuElement->GetText();
		}

		//��Ԫ��
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
//	TiXmlDocument mydoc(path.c_str());//xml�ĵ�����
//	bool loadOk=mydoc.LoadFile();//�����ĵ�
//	if(!loadOk)
//	{
//		return false;
//	}
//
//	TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
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
//		//��Ԫ��
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
	TiXmlDocument mydoc(path.c_str());//xml�ĵ�����
	bool loadOk=mydoc.LoadFile();//�����ĵ�
	if(!loadOk)
	{
		return false;
	}

	TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
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

		//��Ԫ��
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
	_stprintf_s(buf, MAX_PATH, _T("%S"), src.c_str());//%S���ַ�  
#else  
	_stprintf_s(buf, MAX_PATH, _T("%s"), src.c_str());//%s���ַ�
#endif
}

string ModuleMain::TCHAR2STRING(TCHAR *STR)

{

	int iLen = WideCharToMultiByte(CP_ACP, 0,STR, -1, NULL, 0, NULL, NULL);   //���ȼ���TCHAR ���ȡ�

	char* chRtn =new char[iLen*sizeof(char)];  //����һ�� TCHAR ���ȴ�С�� CHAR ���͡�

	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);  //��TCHAR ���͵�����ת��Ϊ CHAR ���͡�

	std::string str(chRtn); //���CHAR �������� ת��Ϊ STRING �������ݡ�

	return str;

}


const char* ModuleMain::CString2ConstChar(CString str)
{
	//CStringA     stra(str.GetBuffer(0));
	//str.ReleaseBuffer();
	//string          st(stra.GetBuffer(0));
	//const char*  cs = st.c_str();
	char szStr[256] = {};  
	wcstombs(szStr, str, str.GetLength());//�����ַ�ת���ɶ��ַ�  
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
		CString csMsg ;//= _T("����4��ʧ��!");
		csMsg.Format(_T("����%d��ʧ��!"),tempDcb.nComPort);
		AfxMessageBox(csMsg);
	}
}


void ModuleMain::DisableAllBtn(HWND hwnd,bool booOpen)
{
	HWND subWnd = ::GetWindow(hwnd,GW_CHILD);
	//HWND subWnd = ::GetWindow(this->GetSafeHwnd(),GW_CHILD);//�����CFormView
	while(subWnd)   
	{   
		CWnd *subCWnd = CWnd::FromHandle(subWnd);//HWNDתCwnd
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
		////���Ͳ�֪��Ϊʲô�жϲ�����
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
	CString csMsg=_T("����ʧ�ܣ�\n���޴�Ȩ�ޣ�") ;//= _T("����4��ʧ��!");
	//csMsg.Format(_T("����%d��ʧ��!"),tempDcb.nComPort);
	AfxMessageBox(csMsg);
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
		theApp.bytStatus[16]=SolLevSum/10;     //īˮҺλȡƽ��
		theApp.bytStatus[17]=InkLevSum/10;     //�ܼ�Һλȡƽ��
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
	staSysRea = GETnBIT_from_bytStatus(0, 0, 1)==_T("1")?true:false;  //ϵͳ׼����
//	staSysRea = (GETnBIT_from_bytStatus(0, 0, 1)==_T("1"));  //ϵͳ׼����
	staSysBus = (GETnBIT_from_bytStatus(0, 1, 1)==_T("1")?true:false) ;  //ϵͳæ
	staBumMod = (GETnBIT_from_bytStatus(0, 2, 1)==_T("1")?true:false)  ; //��ģʽ
	staBum = (GETnBIT_from_bytStatus(0, 3, 1)==_T("1")?true:false)   ;   //'�ÿ���
	staHarFin = (GETnBIT_from_bytStatus(0, 4, 1)==_T("1")?true:false) ;  //'��λ����λ���
	staCleFauFin = (GETnBIT_from_bytStatus(0, 5, 1)==_T("1")?true:false) ;// '����������
	staNozVal = (GETnBIT_from_bytStatus(1, 0, 1)==_T("1")?true:false);   //'���췧
	staFeeVal = (GETnBIT_from_bytStatus(1, 1, 1)==_T("1")?true:false) ;  //'��ī��
	staBleVal = (GETnBIT_from_bytStatus(1, 2, 1)==_T("1")?true:false) ;  //'������
	staFluVal = (GETnBIT_from_bytStatus(1, 3, 1)==_T("1")?true:false) ;  //'��ϴ��
	staSolVal = (GETnBIT_from_bytStatus(1, 4, 1)==_T("1")?true:false) ;  //'�ܼ���
	staVisVal = (GETnBIT_from_bytStatus(1, 5, 1)==_T("1")?true:false) ;  //'ճ�ȷ�
	staWasVal = (GETnBIT_from_bytStatus(1, 6, 1)==_T("1")?true:false) ;  //'��ϴ��
	staInkFloSenOff = (GETnBIT_from_bytStatus(2, 0, 1)==_T("1")?true:false) ;  //'�ػ���
	staCloInkLin = (GETnBIT_from_bytStatus(2, 1, 1)==_T("1")?true:false) ;  //'��ī��
	staAddSol = (GETnBIT_from_bytStatus(2, 2, 1)==_T("1")?true:false)  ; //'����ܼ�
	staDetVis = (GETnBIT_from_bytStatus(2, 3, 1)==_T("1")?true:false)  ; //'����ճ��
	staWasNoz = (GETnBIT_from_bytStatus(2, 4, 1)==_T("1")?true:false)  ; //'��ϴ��ͷ
	staSucNoz = (GETnBIT_from_bytStatus(2, 5, 1)==_T("1")?true:false)   ;//'��������
	staAdjInkLin = (GETnBIT_from_bytStatus(2, 6, 1)==_T("1")?true:false) ; // 'ī·У��
	staInkCir = (GETnBIT_from_bytStatus(2, 7, 1)==_T("1")?true:false)  ; //'ī·ѭ��
	staInkTemSenFau = (GETnBIT_from_bytStatus(3, 0, 1)==_T("1")?true:false)  ; //'īˮ�¶ȴ���������
	staPriHeaTemFau = (GETnBIT_from_bytStatus(3, 1, 1)==_T("1")?true:false) ;  //'��ͷ�¶ȴ���������
	staBumSpeOveFau = (GETnBIT_from_bytStatus(3, 2, 1)==_T("1")?true:false) ;  //'�ó��ٱ���
	staPreOveFau = (GETnBIT_from_bytStatus(3, 3, 1)==_T("1")?true:false)  ; //'��ѹ����
	staVisAbnFau = (GETnBIT_from_bytStatus(3, 4, 1)==_T("1")?true:false) ;  //'ճ���쳣
	staVisSenFau = (GETnBIT_from_bytStatus(3, 5, 1)==_T("1")?true:false) ; //'ճ�ȼƹ���
	staInkFloFau = (GETnBIT_from_bytStatus(3, 6, 1)==_T("1")?true:false)  ; //'���չ���
	staPriHeaCle = (GETnBIT_from_bytStatus(3, 7, 1)==_T("1")?true:false) ;  //'���ػ���ϴ
	staFanFau = (GETnBIT_from_bytStatus(4, 0, 1)==_T("1")?true:false) ; // '���ȹ���
	staChaFau = (GETnBIT_from_bytStatus(4, 1, 1)==_T("1")?true:false) ;  //'������
	staPhaFau = (GETnBIT_from_bytStatus(4, 2, 1)==_T("1")?true:false) ;  //'��λ����
	staHigVolFau = (GETnBIT_from_bytStatus(4, 3, 1)==_T("1")?true:false) ; // '��ѹ����
	staSolLevFau = theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 5, 1)==_T("1")?true:false) +theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 4, 1)==_T("1")?true:false);  //'�ܼ�Һλ״̬
	staInkLevFau = theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 7, 1)==_T("1")?true:false) + theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(4, 6, 1)==_T("1")?true:false);  //'īˮҺλ״̬
	staPrnting = (GETnBIT_from_bytStatus(5, 0, 1)==_T("1")?true:false) ; // '��ӡ��
	//'staBufOveFau = IIf(GETnBIT_from_bytStatus(5, 2, 1)==_T("1"));  // '�ı�buf���
	staHigVolSwi = (GETnBIT_from_bytStatus(5, 3, 1)==_T("1")?true:false)  ; //'��ѹ����
	staActProSen = (GETnBIT_from_bytStatus(5, 4, 1)==_T("1")?true:false)  ; //'���۵�ǰ��ƽ
	staProSenFas = (GETnBIT_from_bytStatus(5, 5, 1)==_T("1")?true:false) ;  ////'���۹���
	staAutModFau = (GETnBIT_from_bytStatus(5, 6, 1)==_T("1")?true:false) ; // '�Զ�����ʧ��
	staValFau = (GETnBIT_from_bytStatus(5, 7, 1)==_T("1")?true:false) ;  //'������
	staPrinted = (GETnBIT_from_bytStatus(6, 0, 1)==_T("1")?true:false)  ; //'��ӡ���
	staRemPrinSwi = (GETnBIT_from_bytStatus(6, 1, 1)==_T("1")?true:false); //  'Զ�̴�ӡ����
	//'staBufFul = (GETnBIT_from_bytStatus(6, 2, 1)==_T("1"));   //'�ı�buf��
	staBufRea = (GETnBIT_from_bytStatus(6, 3, 1)==_T("1")?true:false) ;  //'��Ϣ׼����
	staEncDir = (GETnBIT_from_bytStatus(6, 4, 1)==_T("1")?true:false) ;  //'����������
	staLinFas = (GETnBIT_from_bytStatus(6, 5, 1)==_T("1")?true:false) ;  //'����������
	staPriHeaHot = (GETnBIT_from_bytStatus(6, 6, 1)==_T("1")?true:false);  // '����״̬
	staPriHeaHotFau = (GETnBIT_from_bytStatus(6, 7, 1)==_T("1")?true:false) ; // '���¹���
	if (theApp.bytStatus[8] * 256 +theApp. bytStatus[7] > 5000)  //'ʵʱѹ��
	{
		staPressure=theApp.bytStatus[8] * 256 + theApp.bytStatus[7] - 65536;
	} 
	else
	{
		staPressure=theApp.bytStatus[8] * 256 + theApp.bytStatus[7];
	}
	
	staBumSpe = theApp.bytStatus[10] * 256 + theApp.bytStatus[9];     //'ʵʱ����
	staPriHeaTem = theApp.bytStatus[11] ;                                       //'ʵʱ��ͷ�¶�
	staInkTem = (theApp.bytStatus[13] * 256 + theApp.bytStatus[12]) / 10   ;              //'ʵʱīˮ�¶�
	staActVis = theApp.bytStatus[14] ;                                     //'Ŀǰʵʱճ��
	staTarVis = theApp.bytStatus[15] ;                                         // 'Ŀ��ο�ճ��
	staInkLev = theApp.bytStatus[16] ;                                        // 'ʵʱīˮҺλ
	staSolLev = theApp.bytStatus[17] ;                                          //'ʵʱ�ܼ�Һλ
	staHigVol = theApp.bytStatus[19]* 256 + theApp.bytStatus[18] ;                      // 'ʵʱ��ѹ
	staPhase = theApp.bytStatus[20] ;                                        // 'ʵʱ��λ
	staEncFre = theApp.bytStatus[22] * 256 + theApp.bytStatus[21] ;                       //'ʵʱ������Ƶ��
	staProCou = theApp.bytStatus[26] * pow(256 , 3) + theApp.bytStatus[25] * pow(256 , 2 )+ theApp.bytStatus[24] * 256 + theApp.bytStatus[23];      // '��Ʒ������
	staPriCou = theApp.bytStatus[30] * pow(256 , 3) + theApp.bytStatus[29] * pow(256 , 2 )+ theApp.bytStatus[28] * 256 + theApp.bytStatus[27];      // '��ӡ������
	staPixDotNee = theApp.bytStatus[31];                                  // '�й��ɵ���
	staAutModVol = theApp.bytStatus[32];                                  // '�Զ����ѵ�ѹ

	staSetTimeEna = (GETnBIT_from_bytStatus(36, 5, 1)==_T("1")?true:false);   //'ά����īˮʱ����Ĺ��ܿ���
	if (!staSetTimeEna)
	{
		staInkLifeTime = (theApp.bytStatus[36] & 31) * pow(256 , 3) + theApp.bytStatus[35] * pow(256 , 2) + theApp.bytStatus[34] * 256 + theApp.bytStatus[33];   // 'īˮʱ��
		staRFID =  theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(36, 7, 1)==_T("1")?true:false) + theApp.myclassMessage.to_String(GETnBIT_from_bytStatus(36, 6, 1)==_T("1")?true:false); //'RFID״̬
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
									{////��̬��ʾ���
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

				//ͬ��״̬����
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
			{/////�����Ի���
				int result =MessageBox( NULL,TEXT("�Ƿ����") , TEXT("ѡ��") ,MB_YESNO);
				switch(result)
				{
				case IDYES:
					bytComErr=0;
					strTempCmd=(LPTSTR)readArr;
					strTempCmdLen=8;
					break;
				case IDNO:
					AfxMessageBox(_T("����ͨѶ���ϣ�\n����ϵ����Ա��"));
					break;
				}
			} 
		}
		else    ///////////////���ڲ��ԡ��Ժ�ɾ��
		{
			//bytComErr++;
			//if (bytComErr>10)
			//{/////�����Ի���
			//	int result =MessageBox( NULL,TEXT("��Ӧ���Ƿ����") , TEXT("ѡ��") ,MB_YESNO);
			//	switch(result)
			//	{
			//	case IDYES:
			//		bytComErr=0;
			//		strTempCmd=(LPTSTR)readArr;
			//		strTempCmdLen=8;
			//		break;
			//	case IDNO:
			//		AfxMessageBox(_T("������Ӧ��\n����ϵ����Ա��"));
			//		break;
			//	}
			//} 
			//strTempCmd=(LPTSTR)readArr;
			//strTempCmdLen=8;

			/////////���´��������
			//theApp.boQueCtrLock.Lock();
			//if (theApp.queCtr.size()>0)
			//{
			//	vector<BYTE> tempQueVec=theApp.queCtr.front();
			//	theApp.queCtr.pop();
			//	strTempCmdLen=tempQueVec.size();
			//	strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
			//}
			//theApp.boQueCtrLock.Unlock();
		}

		//theApp.myCIOVsd.ClearInOutBuf();
        theApp.myCIOVsd.Send(strTempCmd,strTempCmdLen);
		//strTempCmdLen=0;   ////////������ʧ�ܣ����·���
		//strTempCmd=(LPTSTR)"";
		Sleep(10);
		
		theApp.readCount=theApp.myCIOVsd.Read();


		////////������
		//theApp.readCount=43;
		//theApp.myCIOVsd.m_pRecvBuf[0]=0x2;
		//theApp.myCIOVsd.m_pRecvBuf[1]=0x80;
		//theApp.myCIOVsd.m_pRecvBuf[2]=0x26;
		//theApp.myCIOVsd.m_pRecvBuf[10]=0xff;
	}


	return 0;
}