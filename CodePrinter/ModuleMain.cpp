#include "StdAfx.h"
#include "ModuleMain.h"

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