#pragma once
#include <vector>;
#include <map>;
#include <string>
using namespace std;
struct UserStruct
{
	string userName;
	string userKey;
	string fatherName;
	int userLevel;
};
class UserPower
{
private:
	string rootPassKey;
public:
	UserPower(void);
	~UserPower(void);
	string GetRootPass();
	vector<string> split(const string& str, const string& delim);
	void SaveUser();
	vector<string> GetPower(string filePathName);
	void SavePower(string filePathName,vector<string> tempVec);
	void changeUserPower();
	//void ChangeBottonEnable(HWND hwnd);
	void initUser();
public:
	bool booResetCount;//������
	bool booResetSerial;//���к�

//īˮ���ûȨ��ֻ�ɿ������ɰ�
	bool booInkUsual;//��ͨ
	bool booInkAdvance;//�߼�
	bool booInkSetup;//��װ
	bool booInkParameter;//����
	bool booInkPhasing;//��λ

	bool booFileManage;//�ļ�����
	bool booPcfIO;//pcf	��������ť�����룩�ͶԺŰ�ť���·���ť��
	bool booPcfAll;//���������ȫ��Ȩ�ޣ�û��Ȩ�޳��˷��ؼ����Բ����������İ����Բ���

	bool booLabelIO;//�·���ť����һ����ť���ʹ򿪰�ť����������ť��
	bool booLabelAll;//��ǩ��ȫ��Ȩ��

	bool booSysNetComOK;//���硢���ںͶԺţ��·���ť��
	bool booSysEnvCusOK;//�������Զ���ͶԺ�

	bool booFaultDelete;//ɾ������

	map<string,UserStruct> userMap;
	//map<string,int> userLevelMap;
	UserStruct nowUser;

	bool isChangeUser;
	//string nowUserKey;
};
