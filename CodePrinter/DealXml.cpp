
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
	
	TiXmlDocument mydoc(fileName);//xml文档对象
	bool loadOk=mydoc.LoadFile();//加载文档
	if (loadOk)
	{
		TiXmlElement *RootElement=mydoc.RootElement();	//根元素
		TiXmlElement *pEle=RootElement;
		//遍历该结点
		for(TiXmlElement *StuElement = pEle->FirstChildElement();//第一个子元素
			StuElement != NULL;
			StuElement = StuElement->NextSiblingElement())//下一个兄弟元素
		{

			CString ValueName = NULL;
			CString ValueStr = NULL;

			const char *nodename = StuElement->Value();//节点名称
			const char *nodetext = StuElement->GetText();//节点值

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

	TiXmlDocument mydoc(fileName);//xml文档对象
	bool loadOk = mydoc.LoadFile();//加载文档
	if (loadOk)
	{
		TiXmlElement *RootElement=mydoc.RootElement();	//根元素
		TiXmlElement *pEle=RootElement;
		//遍历该结点
		for(TiXmlElement *StuElement = pEle->FirstChildElement();//第一个子元素
			StuElement != NULL;
			StuElement = StuElement->NextSiblingElement())//下一个兄弟元素
		{
			CString ValueName = NULL;
			const char *nodename = StuElement->Value();//节点名称
			CStringA stra1(nodename);
			ValueName =  CString(stra1);//ConstChar To CStirng

			if ( ValueName.CompareNoCase(Name) == 0)//有该节点，则改值
			{	
				TiXmlNode *pValue = StuElement->FirstChild();
				if (pValue)
				{
					pValue->SetValue(valueStr);
				}				
				mydoc.SaveFile();
				return true;
			}	
		}
		//没有则创建该节点	
		TiXmlElement *childElement = new TiXmlElement(NameStr);
		RootElement->LinkEndChild(childElement);

		TiXmlText *Content = new TiXmlText(valueStr);
		childElement->LinkEndChild(Content);

		mydoc.SaveFile();
		return true;	
	}
	else
	{	
		return false;
	}
}

CString CDealXml::GetIniXML(CString FullPath,CString RootNode,CString SelChildNode,CString Attribute)
{
	USES_CONVERSION;  
	const char* fullPath = W2A(FullPath.GetBuffer(0));//CString To ConstChar
	const char* rootNode = W2A(RootNode.GetBuffer(0));
	const char* selchildNode = W2A(SelChildNode.GetBuffer(0));

	TiXmlDocument mydoc(fullPath);//xml文档对象
	bool loadOk=mydoc.LoadFile();//加载文档
	if (loadOk)
	{
		TiXmlElement *RootElement=mydoc.RootElement();	//根节点
		TiXmlElement *pEle=RootElement;
		//遍历该结点
		for(TiXmlElement *childnode = pEle->FirstChildElement();//第一个子节点
			childnode != NULL;
			childnode = childnode->NextSiblingElement())//下一个兄弟节点
		{
			
			const char *nodename = childnode->Value();//子节点名称
			if (  *selchildNode == *nodename )
			{
				for(TiXmlElement *Element = childnode->FirstChildElement();//第一个子元素
					Element != NULL;
					Element = Element->NextSiblingElement())//下一个兄弟元素
				{
					CString ValueName = NULL;
					CString ValueStr = NULL;

					const char *nodename = Element->Value();//节点名称
					const char *nodetext = Element->GetText();//节点值

					CStringA stra1(nodename);
					ValueName =  CString(stra1);//ConstChar To CStirng

					CStringA stra2(nodetext);
					ValueStr =  CString(stra2);//ConstChar To CStirng

					if ( ValueName.CompareNoCase(Attribute) == 0 )
					{
						return ValueStr;
					}
				}
			}
		}
	}
	return NULL;
}

bool CDealXml::SetIniXML(CString FullPath,CString RootNode,CString SelChildNode,CString Attribute,CString ValueStr)
{
	USES_CONVERSION;  
	const char* fullPath = W2A(FullPath.GetBuffer(0));//CString To ConstChar
	const char* rootNode = W2A(RootNode.GetBuffer(0));
	const char* selchildNode = W2A(SelChildNode.GetBuffer(0));
	const char* valuestr = W2A(ValueStr.GetBuffer(0));
	TiXmlDocument mydoc(fullPath);//xml文档对象
	bool loadOk=mydoc.LoadFile();//加载文档
	if (loadOk)
	{
		TiXmlElement *RootElement=mydoc.RootElement();	//根节点
		TiXmlElement *pEle=RootElement;
		//遍历该结点
		for(TiXmlElement *childnode = pEle->FirstChildElement();//第一个子节点
			childnode != NULL;
			childnode = childnode->NextSiblingElement())//下一个兄弟节点
		{

			const char *nodename = childnode->Value();//子节点名称
			if (  *selchildNode == *nodename )
			{
				for(TiXmlElement *Element = childnode->FirstChildElement();//第一个子元素
					Element != NULL;
					Element = Element->NextSiblingElement())//下一个兄弟元素
				{
					CString ValueName = NULL;
					CString ValueStr = NULL;

					const char *nodename = Element->Value();//节点名称
					const char *nodetext = Element->GetText();//节点值

					CStringA stra1(nodename);
					ValueName =  CString(stra1);//ConstChar To CStirng

					CStringA stra2(nodetext);
					ValueStr =  CString(stra2);//ConstChar To CStirng

					if ( ValueName.CompareNoCase(Attribute) == 0 )
					{
						TiXmlNode *pValue = Element->FirstChild();
						pValue->SetValue(valuestr);
						mydoc.SaveFile();
						return true;
					}
				}
			}
		}
	}
	else
	{	
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

