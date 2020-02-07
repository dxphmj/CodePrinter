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


const class MESSAGEEDIT_API nullptr_t
{
public:
	template<class T>
	inline operator T*() const
	{ return 0; }

	template<class C, class T>
	inline operator T C::*() const
	{ return 0; }

private:
	void operator&() const;
} nullptr = {};

//通用算法库
class MESSAGEEDIT_API ModuleMain//通用算法库
{
public:
	ModuleMain(void);
	~ModuleMain(void);
	CString string2CString(string str){return Utf8ToUnicode(str).c_str();
		//int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);  
		//// 给指向缓冲区的指针变量分配内存    
		//wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
		//// 开始向缓冲区转换字节    
		//MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
		//wstring ret_str = pUnicode;  
		//free(pUnicode);  
		//return ret_str; 
	}
	std::string ASCToUTF8(const std::string& str) ;
	string CString2string(CString cstr){
		
		/*string st = W2A(strT.GetBuffer());*/
		return UnicodeToUtf8_CSTR(cstr);
		//int iLen = cstr.GetLength() + 1;
		//char* pSrc = cstr.GetBuffer(iLen * sizeof(char));
		//string strRet = string(pSrc);
		//cstr.ReleaseBuffer(iLen);
		//return strRet;
		//USES_CONVERSION;
		//return W2A(cstr.GetString(),CP_UTF8);

		//string str;
		//str.resize(cstr.GetLength()*2);
		//WideCharToMultiByte(CP_ACP,0,cstr,cstr.GetLength(),&str[0],(int)str.size(),NULL,NULL);
		//return str;
		//CStringW cs = L"中文English";
		//CStringA temp = cstr.GetBuffer(0); //通过转化，temp接受了原来字符串的多字节形式
		//string dst = temp.GetBuffer(0); //现在就可以将值直接赋给string类型了
		//return dst;

		//USES_CONVERSION;
		//std::string str(W2A(cstr));
		//return str;

		//USES_CONVERSION;
		//string city=CT2CA(cstr);
		//return city;
	}
	LPCWSTR stringToLPCWSTR(std::string orig);
    string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
	string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//查
    //bool writeXml(string xmlFileName,string valueStr,string textStr,string path);//增
	bool changeXml(string xmlFileName,string valueStr,string textStr,string path);//改
	void string2tchar(std::string &src, TCHAR* buf);
	string TCHAR2STRING(TCHAR *STR);
   const char* CString2ConstChar(CString str);
   void DisableAllBtn(HWND hwnd,bool booOpen);
   void ReportPower();
   //string CString2string(CString csStrData);
   //字符转数字
   int charToDigit(char c);
   int jinzhi16to10(string pre);
   int jinzhi8to10(string pre) ;
   int jinzhi2to10(string pre);
   string jinzhi10to2(int pre) ;
   string jinzhi10to8(int pre) ;
   string jinzhi10to16(int pre) ;
   bool MesDisIsB(int MesDis,int isNumber);
   string SerialFormatToText(int Value, int Digits, int Format);
   string TimeFormatToText(CString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint);

public://字符转换库
	wstring AsciiToUnicode(const string& str);  
	string  UnicodeToAscii(const wstring& wstr);  
	// UTF8与Unicode互转  
	wstring Utf8ToUnicode(const string& str);  
	string  UnicodeToUtf8(const wstring& wstr);  
	// ASCII与UTF8互转  
	string  AsciiToUtf8(const string& str);  
	string  Utf8ToAscii(const string& str);  
	//**************CString******************//  
	// ASCII与Unicode互转  
	CStringW    AsciiToUnicode_CSTR(const CStringA& str);  
	CStringA    UnicodeToAscii_CSTR(const CStringW& wstr);  
	// UTF8与Unicode互转  
	CStringW    Utf8ToUnicode_CSTR(const CStringA& str);  
	CStringA    UnicodeToUtf8_CSTR(const CStringW& wstr);  
	// ASCII与UTF8互转  
	CStringA    AsciiToUtf8_CSTR(const CStringA& str);  
	CStringA    Utf8ToAscii_CSTR(const CStringA& str);  
	/************string-int***************/  
	// string 转 Int  
	int StringToInt(const string& str);  
	string IntToString(int i);  
	string IntToString(char i);  
	string IntToString(double i);

};


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

	vector<vector<bool>> m_TempboDotMes; //临时用，没有任何意义

public://方法
 
	void DrawFrame(CDC* pDC);
    void DrawDot(CDC* pDC);
    void GetDot(vector<vector<bool>>& boDotMes);
    void ReadBmp(char* strFileName);
	static std::wstring stringToWstring(const std::string& str);
	static bool readBin(string FontName,int offset,char *arr, int DataLen );
	static string DEC_to_BIN(long long Dec);
	static string to_String(int n);
	static long long BIN_to_DEC(string Bin);
	void DrawText(CDC* pDC,vector<vector<bool>>& boDotMes);
	void DrawLogoQRcodeDM(CDC* pDC,vector<vector<bool>>& boDotMes);
	void Draw5x5_7x5Text(CDC* pDC,int nFontRow,int nFontCol,int nBytesOneWord,vector<vector<bool>>& boDotMes);
	void Draw12x12Text(CDC* pDC,vector<vector<bool>>& boDotMes);
	void Draw16x12Text(CDC* pDC,vector<vector<bool>>& boDotMes);

};
 
class MESSAGEEDIT_API ClassMessage
{
	public:
		 ClassMessage(void);
		 ~ClassMessage(void);
	public:
		vector<OBJ_Control*> OBJ_Vec;
		vector<OBJ_Control*> lastObj_Vec;
		int Matrix;
		string strMatrix;
		int Pixel;
		string Reverse;//是否群体控制
		string Inverse;
		bool boReverse;//翻转，颠倒，由喷印设置中更改
		bool boInverse;
		vector<vector<bool>> boDotMes;/////    int N=5, M=6; //vector<vector<int> > obj(N, vector<int>(M)); //定义二维动态数组5行6列 
		int scrMaxRow;//滚动条用
		int intRowMax;//intDotMesRow//用于主界面显示等
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
		void getSerialDotBuf2();
		void GetNextObjPosition(int& xPos, int &yPos);//获得下一个对象绘制的起始位置

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
		 void DrawDot(CDC* pDC);
		 void DrawMainPageDot(CDC* pDC);

		 void getdot();
		 vector<BYTE> DotToByte(int tempintDotRowStart, int tempintDotRowEnd);


	public://XML
		void ReadObjectsFromXml(char* strFileName);
		void SaveObjectsToXml(char* strFileName);
		string labPath;
		string labName;
		void createLABXML();
		void getLabFromXml();
};



 
