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
	bool booResetCount;//计数器
	bool booResetSerial;//序列号

//墨水五个没权限只可看，不可按
	bool booInkUsual;//普通
	bool booInkAdvance;//高级
	bool booInkSetup;//安装
	bool booInkParameter;//参数
	bool booInkPhasing;//相位

	bool booFileManage;//文件管理
	bool booPcfIO;//pcf	第三个按钮（导入）和对号按钮（下发按钮）
	bool booPcfAll;//配置里面的全部权限，没有权限除了返回键可以操作，其他的按键皆不可

	bool booLabelIO;//下发按钮（第一个按钮）和打开按钮（第三个按钮）
	bool booLabelAll;//标签的全部权限

	bool booSysNetComOK;//网络、串口和对号（下发按钮）
	bool booSysEnvCusOK;//环境、自定义和对号

	bool booFaultDelete;//删除故障

	map<string,UserStruct> userMap;
	//map<string,int> userLevelMap;
	UserStruct nowUser;

	bool isChangeUser;
	//string nowUserKey;
};
