#pragma once
#include <string>
#include <vector>
#include<map>
#include <queue> 

using namespace std;
typedef unsigned char BYTE;

#define max 100


#ifdef MESSAGEEDIT_EXPORTS
#define MESSAGEEDIT_API  _declspec(dllexport)
#else
#define MESSAGEEDIT_API  _declspec(dllimport)
#endif

class MESSAGEEDIT_API OBJ_Control
{
public: 
    OBJ_Control(void);
	~OBJ_Control(void);

public://参数
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

	int booETimeOffSet;//字段的时间偏移开关（faulse为关闭，true为开启）
	int intTimeOffSet;//字段的时间偏移值
	int strTimeOffSet;//字段的时间偏移类型

	int intSerialFirstLimit;//字段的FirstLimit属性，即序列号第一象限
	int intSerialSecondLimit;//字段的SecondLimit属性，即序列号第二象限
	int intSerialStartValue;//字段的StartValue属性，即序列号起始值
	int intSerialStep;//字段的StepSize属性，即序列号步长值
	int intSerialRepeat;//字段的RepeatCount属性，即序列号重复值
    BYTE intSerialDigits;//字段的Digital属性，即序列号位数值
	int intSerialCounter;//第几个序列号
	BYTE bytSerialFormat;//字段的SerialFormat属性，即序列号格式
	int intLineSize;//字段的行数
	int intRowSize;//字段的列数
	int intLineStart;//字段的开始行
	int intRowStart;//字段的开始列
  
	string strqrcodeVersion;//二维码的版本类型
	string strqrcodeECCLevel;//二维码的容错率等级
	int intqrcodeQuietZone;//二维码空白框层数

    bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;
	bool booFocus;//焦点是否显示,True:显示蓝框,False:显示红框
public://参数，待定
	string img;//此为logo图片，vb中为Image类型
    //vector<vector<bool>> logobmp;//不明

    //vector<vector<bool>> LogoDotToMes;//改变后的Logo图片点阵用于下发数据用
    //vector<vector<bool>> LogoDot;//logo点阵


	bool boDotBmp[32][255];//加载bmp用
	int xMaxBmp,yMaxBmp;//用来记录本次加载图片的大小


public://方法
	void DrawFrame(CDC* pDC);
    void DrawDot(CDC* pDC);
    void ReadBmp(char* strFileName);
	static std::wstring stringToWstring(const std::string& str);
	static bool readBin(string FontName,int offset,char *arr, int DataLen );
	static string DEC_to_BIN(long long Dec);
	static string to_String(int n);
	static long long BIN_to_DEC(string Bin);
	void DrawLogoQRcodeDM(CDC* pDC);
	void DrawText(CDC* pDC);
	void Draw5x5_7x5Text(CDC* pDC,int nFontRow,int nFontCol,int nBytesOneWord);
	void Draw12x12Text(CDC* pDC);
	void Draw16x12Text(CDC* pDC);
};
 
class MESSAGEEDIT_API ClassMessage
{
	public:
		 ClassMessage(void);
		 ~ClassMessage(void);
	public:
		vector<OBJ_Control*> OBJ_Vec;
		int Matrix;
		string strMatrix;
		int Pixel;
		string Reverse;//是否群体控制
		string Inverse;
		bool boReverse;//翻转，颠倒，由喷印设置中更改
		bool boInverse;
        bool boDotMes[32][255];
		int intRowMax;//intDotMesRow
		int bytRowByteMul;//一列由几个byte表示
		bool boDynamic;//是否动态打印
		bool boPrintNow;//是否即时打印
		//vector<BYTE> bytTempDataVec;

       /////////////////////////////////////////////
        
		bool CounterEditMes[4];
		///xiansiyong
		
		vector<BYTE> intMesDis;
		int bytSerialConCoundis;
		int intDotMesRowdis;
		int matrixMesdis ;
		int pixelMesdis;
		bool boReversedis, boInversedis;
		int intTimeRowSizedis[4], intTimeRowStartdis[4], bintTimelineStartdis[4], intQSerialRowSizedis[4], intQSerialRowStartdis[4];
		
		int CountNumForPre[4];
		///时间
		int bytTimeConCoun ;
		int bytTimeConCoundis;
		string strTimeFormat[1][4] ;
		string strTimeFont[4];
		int strETimeOffSet[4], strTimeOffSetUint[4];
		string strETimetext[4];
		////
		bool SerialCountNew;//是否为新建
		bool SerialCountSet[3];//重置序列号
		int bytSerialConCoun;//序列号计数
		int bytQserialCounter[4];//序列号计数器
		int intQSerialRepeat[4];//重复值
		int intQSerialFirstLimit[4];//第一象限
		int intQSerialSecondLimit[4];//第二象限
		int intQSerialStartValue[4];//开始值
		int intQSerialStep[4];//步长
		int bytQSerialFormat[4];//格式
		int bytQSerialDigits[4];//位数
		int CountNum0, CountNum1, CountNum2, CountNum3, CountNumRep0, CountNumRep1, CountNumRep2, CountNumRep3 ;
		string strQSerialFont[4];
		bool boTimeBWDy[4], boTimeBWDx[4], boTimeNEG[4], boQSerialBWDy[4], boQSerialBWDx[4], boQSerialNEG[4] ;
		int bytTimeSS[4], bytTimeSW[4], bytTimeLineSize[4], bytTimeLineStart[4], bytQSerialSS[4], bytQSerialSW[4], bytQSerialLineSize[4], bytQSerialLineStart[4] ;
		int intTimeRowSize[4], intTimeRowStart[4], intTimeOffSetdis[4], intQSerialRowSize[4], intQSerialRowStart[4] ;
		bool boCountEn[4];//是否更新主界面static序列号

		void getdigitaldot();
		UINT32* searchworddata(bool tempBWDy, bool tempBWDx , bool tempNEG , string tempsetTEXT , int tempRowSize ,
			int tempLineSize , int tempLineStart , int tempRowStart, int tempSS, int tempSW, int line , map<string,vector<BYTE>> bytdigitalfont,
			int tempNEGinteger, int tempBWDxinteger);
		UINT32* searchworddata12(bool tempBWDy, bool tempBWDx , bool tempNEG , string tempsetTEXT , int tempRowSize ,
			int tempLineSize , int tempLineStart , int tempRowStart, int tempSS, int tempSW, int line , map<string,vector<BYTE>> bytdigitalfont,
			int tempNEGinteger, int byte1int , int byte2int);

		BYTE byteUPsidedown(BYTE a,BYTE bBit);
		UINT32 int32shift(UINT32 a, BYTE y,UINT32 b, BYTE h);
		vector<BYTE> DotToByte1(int tempintDotRowStart, int tempintDotRowEnd, vector<BYTE> bytTempData,string tempfont, bool tempBWDy, bool tempBWDx ,bool tempNEG , 
			string tempsetTEXT, int tempRowSize, int tempLineSize , int tempLineStart , int tempRowStart , int tempSS , int tempSW);
		map<string,vector<BYTE>> bytdigital5x5LineMap;
		map<string,vector<BYTE>> bytdigital7x5LineMap;
		map<string,vector<BYTE>> bytdigital12x12LineMap;
		map<string,vector<BYTE>> bytdigital16x12LineMap;

		UINT32 *IntMes;//动态数组
		///////////////////////////////////////
		vector<BYTE> bytPrintDataAllOrder;//主动发送BUF
		vector<BYTE> bytPrintDataAll;//空时自动发送BUF
		////////////////////////////////////

 	public:
		 string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//查
		 BYTE getByteFromDot(bool boDot,int moveNum); 
		 void DrawDot(CDC* pDC);//
		 void getdot(string tempfont, bool tempBWDy, bool tempBWDx , bool tempNEG, string tempsetTEXT , int tempRowSize, int tempLineSize, int tempLineStart , int tempRowStart , int tempSS , int tempSW );
		 vector<BYTE> DotToByte(int tempintDotRowStart, int tempintDotRowEnd);

	public://XML
		void ReadObjectsFromXml(char* strFileName);
		void SaveObjectsToXml(char* strFileName);
		string labPath;
		string labName;
		void createLABXML();
		void getLabFromXml();
};



 
