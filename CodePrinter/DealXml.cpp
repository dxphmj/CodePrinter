
#include "stdafx.h"
#include "DealXml.h"
#include <string>

using namespace std;

CDealXml::CDealXml(void)
{
}

CDealXml::~CDealXml(void)
{
}

CString CDealXml::ReadXml(CString FileName,CString Name,CString FaultStr,CString Path)
{
    USES_CONVERSION;  
	FileName = Path+_T("\\")+FileName;
	const char* fileName = W2A(FileName.GetBuffer(0));//CString To ConstChar
	
	TiXmlDocument mydoc(fileName);//xml�ĵ�����
	bool loadOk=mydoc.LoadFile();//�����ĵ�
	if (loadOk)
	{
		TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
		TiXmlElement *pEle=RootElement;
		//�����ý��
		for(TiXmlElement *StuElement = pEle->FirstChildElement();//��һ����Ԫ��
			StuElement != NULL;
			StuElement = StuElement->NextSiblingElement())//��һ���ֵ�Ԫ��
		{

			CString ValueName = NULL;
			CString ValueStr = NULL;

			const char *nodename = StuElement->Value();//�ڵ�����
			const char *nodetext = StuElement->GetText();//�ڵ�ֵ

			CStringA stra1(nodename);
			ValueName =  CString(stra1);//ConstChar To CStirng

			CStringA stra2(nodetext);
			ValueStr =  CString(stra2);//ConstChar To CStirng

			if ( ValueName.CompareNoCase(Name) == 0 )
			{
				return ValueStr;
			}
		}
	}
	
	//MessageBox(L"could not load the file");
	return FaultStr;	
}

bool CDealXml::WriteXml(CString FileName,CString Name,CString Value,CString Path)
{	
	USES_CONVERSION;  
	FileName = Path+_T("\\")+FileName;
	const char* fileName = W2A(FileName.GetBuffer(0));//CString To ConstChar

	const char* NameStr = W2A(Name.GetBuffer(0));//CString To ConstChar
	const char* valueStr = W2A(Value.GetBuffer(0));//CString To ConstChar

	TiXmlDocument mydoc(fileName);//xml�ĵ�����
	bool loadOk=mydoc.LoadFile();//�����ĵ�
	if (loadOk)
	{
		TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
		TiXmlElement *pEle=RootElement;
		//�����ý��
		for(TiXmlElement *StuElement = pEle->FirstChildElement();//��һ����Ԫ��
			StuElement != NULL;
			StuElement = StuElement->NextSiblingElement())//��һ���ֵ�Ԫ��
		{
			CString ValueName = NULL;
			const char *nodename = StuElement->Value();//�ڵ�����
			CStringA stra1(nodename);
			ValueName =  CString(stra1);//ConstChar To CStirng

			if ( ValueName == Name)//�иýڵ㣬���ֵ
			{	
				TiXmlNode *pValue = StuElement->FirstChild();
				if (pValue)
				{
					pValue->SetValue(valueStr);
				}
				
				mydoc.SaveFile("inksystem.xml");
				return true;
			}	
		}
//û���򴴽��ýڵ�	
		TiXmlElement *childElement = new TiXmlElement(NameStr);
		RootElement->LinkEndChild(childElement);

		TiXmlText *Content = new TiXmlText(valueStr);
		childElement->LinkEndChild(Content);

		mydoc.SaveFile("inksystem.xml");
		return true;	
	}
	else
	{	
		//MessageBox(L"could not load the file");
		return false;
	}
}

BYTE CDealXml::HEX_to_DECbyte(CString strHex)
{
	USES_CONVERSION;
	CString strDec;
	const char* chHex = W2A(strHex.GetBuffer(0));//CString To ConstChar
	DWORD dwHex = strtoul(chHex, NULL, 16);
	strDec.Format(_T("%ld"), dwHex);
	BYTE byte = _wtoi(strDec.GetBuffer(0));
	return byte;
}

