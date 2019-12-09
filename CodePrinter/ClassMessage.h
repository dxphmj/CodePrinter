#pragma once
#include <string>
#include <vector>
#include<map>
using namespace std;
typedef unsigned char BYTE;
#define max 100
//#include <atlimage.h>
#ifdef MESSAGEEDIT_EXPORTS
#define MESSAGEEDIT_API  _declspec(dllexport)
#else
#define MESSAGEEDIT_API  _declspec(dllimport)
#endif

namespace MyNameSpace
{

    class MESSAGEEDIT_API OBJ_Control
	{
	public://参数
        OBJ_Control(void);
		~OBJ_Control(void);
		string strDuan;//信息段的标识位
		string strType1;//字段类型
		string strType2;	//字段实际类型
		int intX;//字段原点X坐标（默认为0）
		int intY;//字段原点Y坐标（默认为0）
		int intSW;//字段的加粗属性（默认为0）
		int intSS;//字段的字距（默认为0）
		bool booNEG;//字段的反色（faulse为不反，true为反）
		bool booBWDx;//字段沿X轴镜像（faulse为关闭，true为开启）
		bool booBWDy;//字段沿Y轴镜像（faulse为关闭，true为开启）
		string strFont;//字段的字体（有的类型有，有的类型没有）
		string strText;//字段的text属性，即内容
		string strTime;//字段的time属性，即时间格式
		string strETimeOffSet;//字段的时间偏移开关（faulse为关闭，true为开启）
		int intTimeOffSet;//字段的时间偏移值
		string strTimeOffSet;//字段的时间偏移类型
		int intSerialFirstLimit;//字段的FirstLimit属性，即序列号第一象限
		int intSerialSecondLimit;//字段的SecondLimit属性，即序列号第二象限
		int intSerialStartValue;//字段的StartValue属性，即序列号起始值
		int intSerialStep;//字段的StepSize属性，即序列号步长值
		int intSerialRepeat;//字段的RepeatCount属性，即序列号重复值
        BYTE intSerialDigits;//字段的Digital属性，即序列号位数值
		int strSerialCounter;//第几个序列号
		BYTE bytSerialFormat;//字段的SerialFormat属性，即序列号格式
		int intLineSize;//字段的行数
		int intRowSize;//字段的列数
		int intLineStart;//字段的开始行
		int intRowStart;//字段的开始列
      
		string strqrcodeVersion;//二维码的版本类型
		string strqrcodeECCLevel;//二维码的容错率等级
		int intqrcodeQuietZone;//二维码空白框层数
		bool booFocus;//焦点是否显示,True:显示蓝框,False:显示红框
	public://参数，待定
		string img;//此为logo图片，vb中为Image类型
        //vector<vector<bool>> logobmp;//不明

        //vector<vector<bool>> LogoDotToMes;//改变后的Logo图片点阵用于下发数据用
        //vector<vector<bool>> LogoDot;//logo点阵


		bool boDotBmp[32][255];//加载bmp用
		int xMaxBmp,yMaxBmp;//用来记录本次加载图片的大小
	public://方法
		char objbytTex5x5Line[7];
		char objbytTex7x5Line[8];
		char objbytTex12x12Line[25];
		char objbytTex16x12Line[29];
		void DrawFrame(CDC* pDC);
        void DrawDot(CDC* pDC);
        void ReadBmp(char* strFileName);
	private:
		//ClassMessage objClassMessage;
		map<string,int> fntMap;


	};

	class MESSAGEEDIT_API ClassMessage : private OBJ_Control
	{
	public:
		 ClassMessage(void);
		 ~ClassMessage(void);
	public:
		vector<OBJ_Control> OBJ_Vec;
		int Matrix;
		string strMatrix;
		int Pixel;
		string Reverse;//是否群体控制
		string Inverse;
		bool boReverse;//翻转，颠倒，由喷印设置中更改
		bool boInverse;
        bool boDotMes[32][255];
		int bytRowByteMul;//一列由几个byte表示
		//vector<BYTE> bytTempDataVec;
       
	public:
		 BYTE getByteFromDot(bool boDot,int moveNum); 
		 string DEC_to_BIN(long long Dec);
		 string to_String(int n);
		 long long BIN_to_DEC(string Bin);
		 bool readBin(string FontName,int offset,char *arr, int DataLen );//此处先用char来代替BYTE
		 void DrawDot(CDC* pDC);//
		 void getdot(string tempfont, bool tempBWDy, bool tempBWDx , bool tempNEG, string tempsetTEXT , int tempRowSize, int tempLineSize, int tempLineStart , int tempRowStart , int tempSS , int tempSW );
		 vector<BYTE> DotToByte(int tempintDotRowStart, int tempintDotRowEnd);
	public://XML
		void ReadObjectsFromXml(char* strFileName);
		void SaveObjectsToXml(char* strFileName);
		
	};



}

