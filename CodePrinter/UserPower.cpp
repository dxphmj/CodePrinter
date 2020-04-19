#include "StdAfx.h"
#include "UserPower.h"
#include <fstream>
#include "CodePrinter.h"
UserPower::UserPower(void)
{
	rootPassKey="root";

	// booResetCount=false;//������
	// booResetSerial=false;//���к�

	////īˮ���ûȨ��ֻ�ɿ������ɰ�
	// booInkUsual=false;//��ͨ
	// booInkAdvance=false;//�߼�
	// booInkSetup=false;//��װ
	// booInkParameter=false;//����
	// booInkPhasing=false;//��λ

	// booFileManage=false;//�ļ�����
	// booPcfIO=false;//pcf	��������ť�����룩�ͶԺŰ�ť���·���ť��
	// booPcfAll=false;//���������ȫ��Ȩ�ޣ�û��Ȩ�޳��˷��ؼ����Բ����������İ����Բ���

	// booLabelIO=false;//�·���ť����һ����ť���ʹ򿪰�ť����������ť��
	// booLabelAll=false;//��ǩ��ȫ��Ȩ��

	// booSysNetComOK=false;//���硢���ںͶԺţ��·���ť��
	// booSysEnvCusOK=false;//�������Զ���ͶԺ�

	// booFaultDelete=false;//ɾ������
	//CreateDirectory(_T("Storage Card\\System"), NULL);
	//nowUser.userName=theApp.myModuleMain.ReadXml("SoftSystem.xml","User","root","Storage Card\\System");
	//CreateDirectory(_T("Storage Card\\System\\UserPower"), NULL);
	// //userMap.insert(make_pair("root","root"));
	//
	// FILE *testFile;
	// testFile = fopen("Storage Card\\System\\UserPower\\userName.txt", "r");
	// if (testFile)
	// {
	//	 fclose(testFile);
	//	 ifstream fin;
	//	 fin.open(_T("Storage Card\\System\\UserPower\\userName.txt"));
	//	 string str;
	//	 while (getline(fin, str))
	//	 {
	//		 //getline(fin, str);
	//		vector<string> tempUser=split(str,"|");
	//		if (tempUser.size()==2)
	//		{
	//			//
	//			vector<string> tempUserStr=split(tempUser.at(1),",");
	//			UserStruct tempUT;
	//			tempUT.userName=tempUserStr.at(0);
	//			tempUT.userKey=tempUserStr.at(1);
	//			tempUT.fatherName=tempUserStr.at(2);
	//			tempUT.userLevel=atoi(tempUserStr.at(3).c_str());
	//			userMap.insert(make_pair(tempUser.at(0),tempUT));
	//		}
	//	 }
	//	 fin.close();
	// }
	// else
	// {
	//	 ofstream outUser("Storage Card\\System\\UserPower\\userName.txt", ios::out);
	//	 outUser.close();
	// }

	// map<string,UserStruct>::iterator mapIter=userMap.find(nowUser.userName);
	// if (mapIter!=userMap.end())
	// {
	//	 nowUser.userKey=mapIter->second.userKey;
	//	 nowUser.userLevel=mapIter->second.userLevel;
	//	 nowUser.fatherName=mapIter->second.fatherName;
	// } 
	// else///��һ���Ҳ�������Ĭ��root
	// {
	//	nowUser.userName="root";
	//	nowUser.userKey=rootPassKey;
	//	nowUser.userLevel=0;
	//	nowUser.fatherName="";
	// }
	// //FILE *testFile;
	// testFile = fopen("Storage Card\\System\\UserPower\\root.txt", "r");
	// if (testFile)
	// {
	//	 fclose(testFile);
	// }
	// else
	// {
	//	 ofstream outUser("Storage Card\\System\\UserPower\\root.txt", ios::out);
	//	 outUser<<"ResetCount,ResetSerial,InkUsual,InkAdvance,InkSetup,InkParameter,InkPhasing,FileManage,PcfIO,PcfAll,LabelIO,LabelAll,SysNetComOK,SysEnvCusOK,FaultDelete"<<endl;
	//	 outUser.close();
	// }

	// changeUserPower();
	//isChangeUser=true;
}

UserPower::~UserPower(void)
{
}

string UserPower::GetRootPass()
{
	return rootPassKey;
}
vector<string> UserPower::split(const string& str, const string& delim)
{
	 
	vector<string> res;  
	if("" == str) return res;  
	//�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����  
	char * strs = new char[str.length() + 1] ; //��Ҫ����  
	strcpy(strs, str.c_str());   

	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  

	char *p = strtok(strs, d);  
	while(p) {  
		string s = p; //�ָ�õ����ַ���ת��Ϊstring����  
		res.push_back(s); //����������  
		p = strtok(NULL, d);  
	}  

	return res;  

}

void UserPower::SaveUser()
{
	ofstream outUser("Storage Card\\System\\UserPower\\userName.txt", ios::trunc);
	
	for(map<string,UserStruct>::iterator iter=userMap.begin();iter!=userMap.end();iter++ )
	{
		string tempUNK=iter->first+"|"+iter->second.userName+","+iter->second.userKey+","+iter->second.fatherName+","+OBJ_Control::to_String(iter->second.userLevel);
		outUser<<tempUNK<<endl;
	}
	outUser.close();

}

vector<string> UserPower::GetPower(string filePathName)
{
	ifstream fin;
	fin.open(theApp.myModuleMain.stringToLPCWSTR(filePathName));
	string str;
	getline(fin, str);
	vector<string> tempUserPower=split(str,",");
	fin.close();
	return tempUserPower;	
}

void UserPower::SavePower(string filePathName,vector<string> tempVec)
{
	ofstream outUser(filePathName.c_str(), ios::trunc);
	string outStr="";
	for (int i=0;i<tempVec.size();i++)
	{
		outStr=outStr+tempVec.at(i);
		if (i<tempVec.size()-1)
		{
			outStr=outStr+",";
		}
	}
	outUser<<outStr<<endl;
	outUser.close();
}
void UserPower::changeUserPower()
{
	booResetCount=false;//������
	booResetSerial=false;//���к�
	//īˮ���ûȨ��ֻ�ɿ������ɰ�
	booInkUsual=false;//��ͨ
	booInkAdvance=false;//�߼�
	booInkSetup=false;//��װ
	booInkParameter=false;//����
	booInkPhasing=false;//��λ
	booFileManage=false;//�ļ�����
	booPcfIO=false;//pcf	��������ť�����룩�ͶԺŰ�ť���·���ť��
	booPcfAll=false;//���������ȫ��Ȩ�ޣ�û��Ȩ�޳��˷��ؼ����Բ����������İ����Բ���
	booLabelIO=false;//�·���ť����һ����ť���ʹ򿪰�ť����������ť��
	booLabelAll=false;//��ǩ��ȫ��Ȩ��
	booSysNetComOK=false;//���硢���ںͶԺţ��·���ť��
	booSysEnvCusOK=false;//�������Զ���ͶԺ�
	booFaultDelete=false;//ɾ������
	string filePathName="Storage Card\\System\\UserPower\\"+nowUser.userName+".txt";
	vector<string> tempVec=GetPower(filePathName);
	for (int i=0;i<tempVec.size();i++)
	{
		string powerName=tempVec.at(i);

		if (powerName=="ResetCount")
		{
			booResetCount=true;
		}
		else if (powerName=="ResetSerial")
		{
			booResetSerial=true;
		}
		else if (powerName=="InkUsual")
		{
			booInkUsual=true;
		}
		else if (powerName=="InkAdvance")
		{
			booInkAdvance=true;
		}
		else if (powerName=="InkSetup")
		{
			booInkSetup=true;
		}
		else if (powerName=="InkParameter")
		{
			booInkParameter=true;
		}
		else if (powerName=="InkPhasing")
		{
			booInkPhasing=true;
		}
		else if (powerName=="FileManage")
		{
			booFileManage=true;
		}
		else if (powerName=="PcfIO")
		{
			booPcfIO=true;
		}
		else if (powerName=="PcfAll")
		{
			booPcfAll=true;
		}
		else if (powerName=="LabelIO")
		{
			booLabelIO=true;
		}
		else if (powerName=="LabelAll")
		{
			booLabelAll=true;
		}
		else if (powerName=="SysNetComOK")
		{
			booSysNetComOK=true;
		}
		else if (powerName=="SysEnvCusOK")
		{
			booSysEnvCusOK=true;
		}
		else if (powerName=="FaultDelete")
		{
			booFaultDelete=true;
		}
	}
	isChangeUser=true;
}

void UserPower::initUser()
{
	CreateDirectory(_T("Storage Card\\System"), NULL);
	nowUser.userName=theApp.myModuleMain.ReadXml("SoftSystem.xml","User","root","Storage Card\\System");
	CreateDirectory(_T("Storage Card\\System\\UserPower"), NULL);
	//userMap.insert(make_pair("root","root"));

	FILE *testFile;
	testFile = fopen("Storage Card\\System\\UserPower\\userName.txt", "r");
	if (testFile)
	{
		fclose(testFile);
		ifstream fin;
		fin.open(_T("Storage Card\\System\\UserPower\\userName.txt"));
		string str;
		while (getline(fin, str))
		{
			//getline(fin, str);
			vector<string> tempUser=split(str,"|");
			if (tempUser.size()==2)
			{
				//
				vector<string> tempUserStr=split(tempUser.at(1),",");
				UserStruct tempUT;
				tempUT.userName=tempUserStr.at(0);
				tempUT.userKey=tempUserStr.at(1);
				tempUT.fatherName=tempUserStr.at(2);
				tempUT.userLevel=atoi(tempUserStr.at(3).c_str());
				userMap.insert(make_pair(tempUser.at(0),tempUT));
			}
		}
		fin.close();
	}
	else
	{
		ofstream outUser("Storage Card\\System\\UserPower\\userName.txt", ios::out);
		outUser.close();
	}

	map<string,UserStruct>::iterator mapIter=userMap.find(nowUser.userName);
	if (mapIter!=userMap.end())
	{
		nowUser.userKey=mapIter->second.userKey;
		nowUser.userLevel=mapIter->second.userLevel;
		nowUser.fatherName=mapIter->second.fatherName;
	} 
	else///��һ���Ҳ�������Ĭ��root
	{
		nowUser.userName="root";
		nowUser.userKey=rootPassKey;
		nowUser.userLevel=0;
		nowUser.fatherName="";
	}
	//FILE *testFile;
	testFile = fopen("Storage Card\\System\\UserPower\\root.txt", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		ofstream outUser("Storage Card\\System\\UserPower\\root.txt", ios::out);
		outUser<<"ResetCount,ResetSerial,InkUsual,InkAdvance,InkSetup,InkParameter,InkPhasing,FileManage,PcfIO,PcfAll,LabelIO,LabelAll,SysNetComOK,SysEnvCusOK,FaultDelete"<<endl;
		outUser.close();
	}

	changeUserPower();
}