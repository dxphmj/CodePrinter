#include "StdAfx.h"
#include "Language.h"
#include "xml\tinyxml.h"
#include "CodePrinter.h"
using namespace std;
Language::Language(void)
{
}

Language::~Language(void)
{
}

bool Language::readLanguageXml(string xmlName)
{
	string path="\\Storage Card\\user\\LanguageXml\\";
	path+=xmlName;
	TiXmlDocument *pDocument = new TiXmlDocument(path.c_str());
	if (NULL == pDocument)
	{
		return false;
	}
	pDocument->LoadFile(path.c_str());

	TiXmlElement *pRoot = pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pChildNode = pRoot->FirstChildElement();
	while (pChildNode != NULL)
	{
		string strValue = pChildNode->Value();
		string strText  = pChildNode->GetText();
		theApp.myLanguage.LanguageMap[strValue]=strText;
		pChildNode = pChildNode->NextSiblingElement();
	}


	//TiXmlDocument doc(path.c_str());
	//bool loadOkay = doc.LoadFile();

	////vector<CCharObject> m_arrObjects;
	//TiXmlNode* node = 0;
	//TiXmlElement* todoElement = 0;
	//TiXmlElement* itemElement = 0;
	//node = doc.FirstChild( "MES" );
	//assert( node );
	//todoElement = node->ToElement();
	//assert( todoElement  );

	//node = todoElement->FirstChildElement();	 
	//assert( node );
	//itemElement = node->ToElement();
	//assert( itemElement  );

	//int count = 0;
	////itemElement = itemElement->NextSiblingElement();
	//for( node = todoElement->FirstChildElement();node;node = node->NextSibling() )
	//{
	//	const char* str ;
	//	string ss;
	//	ss.assign(str);
	//	str = node->ValueTStr().c_str();
	//	count++;
	//	if(strcmp(str,"PRO") == 0)
	//	{
	//		//读入信息//判断对不对


	//	}
	//	else if(strcmp(str,"LAN") == 0)//语言
	//	{
	//		//读入属性信息
	//		TiXmlNode* nodeTmp = 0;
	//		for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
	//		{
	//			const char* strItem = nodeTmp->ValueTStr().c_str();
	//			const char* strText; 
	//			TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
	//			strText = nodeText->ValueTStr().c_str();
	//			string lk,lv;
	//			lk.assign(strItem);
	//		    lv.assign(strText);
 //               LanguageMap.insert(make_pair(lk,lv));

	//		}
	//	}
	//}

}