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

//ͨ���㷨��
class MESSAGEEDIT_API ModuleMain//ͨ���㷨��
{
public:
	ModuleMain(void);
	~ModuleMain(void);
	CString string2CString(string str){return Utf8ToUnicode(str).c_str();}
	std::string ASCToUTF8(const std::string& str) ;
	string CString2string(CString cstr){return UnicodeToUtf8_CSTR(cstr);}
	LPCWSTR stringToLPCWSTR(std::string orig);
    string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
	string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//��
    //bool writeXml(string xmlFileName,string valueStr,string textStr,string path);//��
	bool changeXml(string xmlFileName,string valueStr,string textStr,string path);//��
	void string2tchar(std::string &src, TCHAR* buf);
	string TCHAR2STRING(TCHAR *STR);
   const char* CString2ConstChar(CString str);
   void DisableAllBtn(HWND hwnd,bool booOpen);
   void ReportPower();
   //string CString2string(CString csStrData);
   //�ַ�ת����
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

public://�ַ�ת����
	wstring AsciiToUnicode(const string& str);  
	string  UnicodeToAscii(const wstring& wstr);  
	// UTF8��Unicode��ת  
	wstring Utf8ToUnicode(const string& str);  
	string  UnicodeToUtf8(const wstring& wstr);  
	// ASCII��UTF8��ת  
	string  AsciiToUtf8(const string& str);  
	string  Utf8ToAscii(const string& str);  
	//**************CString******************//  
	// ASCII��Unicode��ת  
	CStringW    AsciiToUnicode_CSTR(const CStringA& str);  
	CStringA    UnicodeToAscii_CSTR(const CStringW& wstr);  
	// UTF8��Unicode��ת  
	CStringW    Utf8ToUnicode_CSTR(const CStringA& str);  
	CStringA    UnicodeToUtf8_CSTR(const CStringW& wstr);  
	// ASCII��UTF8��ת  
	CStringA    AsciiToUtf8_CSTR(const CStringA& str);  
	CStringA    Utf8ToAscii_CSTR(const CStringA& str);  
	/************string-int***************/  
	// string ת Int  
	int StringToInt(const string& str);  
	string IntToString(int i);  
	string IntToString(char i);  
	string IntToString(double i);

public:
	 
 };


class MESSAGEEDIT_API OBJ_Control
{
public: 
    OBJ_Control(void);
	OBJ_Control(OBJ_Control* pObj);
	~OBJ_Control(void);

public://����
	string strDuan;//��Ϣ�εı�ʶλ
	string strType1;//�ֶ�����
	string strType2;	//�ֶ�ʵ������
	//int intX;//�ֶ�ԭ��X���꣨Ĭ��Ϊ0��
	//int intY;//�ֶ�ԭ��Y���꣨Ĭ��Ϊ0��
	int intSW;//�ֶεļӴ����ԣ�Ĭ��Ϊ0��
	int intSS;//�ֶε��־ࣨĬ��Ϊ0��
	bool booNEG;//�ֶεķ�ɫ��faulseΪ������trueΪ����
	bool booBWDx;//�ֶ���X�᾵��faulseΪ�رգ�trueΪ������
	bool booBWDy;//�ֶ���Y�᾵��faulseΪ�رգ�trueΪ������
	string strFont;//�ֶε����壨�е������У��е�����û�У�
	string strText;//�ֶε�text���ԣ�������

	string strTime;//�ֶε�time���ԣ���ʱ���ʽ
	int booETimeOffSet;//�ֶε�ʱ��ƫ�ƿ��أ�faulseΪ�رգ�trueΪ������
	int intTimeOffSet;//�ֶε�ʱ��ƫ��ֵ
	int strTimeOffSet;//�ֶε�ʱ��ƫ������

	int intSerialFirstLimit;//�ֶε�FirstLimit���ԣ������кŵ�һ����
	int intSerialSecondLimit;//�ֶε�SecondLimit���ԣ������кŵڶ�����
	int intSerialStartValue;//�ֶε�StartValue���ԣ������к���ʼֵ
	int intSerialStep;//�ֶε�StepSize���ԣ������кŲ���ֵ
	int intSerialRepeat;//�ֶε�RepeatCount���ԣ������к��ظ�ֵ
    BYTE intSerialDigits;//�ֶε�Digital���ԣ������к�λ��ֵ
	int intSerialCounter;//�ڼ������к�
	BYTE bytSerialFormat;//�ֶε�SerialFormat���ԣ������кŸ�ʽ
	int CountNum; //���кŵ�ǰֵ�Ĵ�С
	int CountNumRep; //���кŵ�ǰ�ظ��Ĵ�С

	int intLineSize;//�ֶε�����
	int intRowSize;//�ֶε�����
	int intLineStart;//�ֶεĿ�ʼ��
	int intRowStart;//�ֶεĿ�ʼ��
  
	string strqrcodeVersion;//��ά��İ汾����
	string strqrcodeECCLevel;//��ά����ݴ��ʵȼ�
	int intqrcodeQuietZone;//��ά��հ׿����

    bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;
	bool booFocus;//�����Ƿ���ʾ,True:��ʾ����,False:��ʾ���
public://����������
	string img;//��ΪlogoͼƬ��vb��ΪImage����
    //vector<vector<bool>> logobmp;//����

    //vector<vector<bool>> LogoDotToMes;//�ı���LogoͼƬ���������·�������
    //vector<vector<bool>> LogoDot;//logo����


	bool boDotBmp[32][255];//����bmp��
	int xMaxBmp,yMaxBmp;//������¼���μ���ͼƬ�Ĵ�С
	 
	vector<vector<bool>> m_TempboDotMes; //��ʱ�ã�û���κ�����

public://����
 
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

	void CreateTimeDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,
									map<string,vector<BYTE>> bytdigital5x5LineMap,map<string,vector<BYTE>> bytdigital7x5LineMap,
									map<string,vector<BYTE>> bytdigital12x12LineMap,map<string,vector<BYTE>> bytdigital16x12LineMap,UINT32 *IntMes);
	void CreateSerialDynamic(vector<BYTE>& bytPrintDataAll);
	void CreateSerialDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,map<string,vector<BYTE>> bytdigital5x5LineMap,map<string,vector<BYTE>> bytdigital7x5LineMap,
									map<string,vector<BYTE>> bytdigital12x12LineMap,map<string,vector<BYTE>> bytdigital16x12LineMap,UINT32 *IntMes);
	vector<BYTE> DotToByte1(int tempintDotRowStart, int tempintDotRowEnd, vector<BYTE>& bytTempData,string tempfont, bool tempBWDy, bool tempBWDx ,bool tempNEG , 
							string tempsetTEXT, int tempRowSize, int tempLineSize , int tempLineStart , int tempRowStart , int tempSS , int tempSW,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,
							map<string,vector<BYTE>> bytdigital5x5LineMap,map<string,vector<BYTE>> bytdigital7x5LineMap,
									map<string,vector<BYTE>> bytdigital12x12LineMap,map<string,vector<BYTE>> bytdigital16x12LineMap,UINT32 *IntMes);
	BYTE byteUPsidedown(BYTE a,BYTE bBit);
	UINT32 int32shift(UINT32 a, BYTE y,UINT32 b, BYTE h);
	void searchworddata(bool tempBWDy, bool tempBWDx , bool tempNEG , string tempsetTEXT , int tempRowSize ,
				int tempLineSize , int tempLineStart , int tempRowStart, int tempSS, int tempSW, int line , map<string,vector<BYTE>> bytdigitalfont,
				int tempNEGinteger, int tempBWDxinteger,UINT32 *IntMes);
	void searchworddata12(bool tempBWDy, bool tempBWDx , bool tempNEG , string tempsetTEXT , int tempRowSize ,
							int tempLineSize , int tempLineStart , int tempRowStart, int tempSS, int tempSW, int line , map<string,vector<BYTE>> bytdigitalfont,
							int tempNEGinteger, int byte1int , int byte2int,UINT32 *IntMes); 
};
 
class MESSAGEEDIT_API ClassMessage
{
	public:
		 ClassMessage(void);
		 ~ClassMessage(void);
	public:
		vector<OBJ_Control*> OBJ_Vec;//�༭��
		vector<OBJ_Control*> lastObj_Vec;//��������ʾ��
		int Matrix;//����
		string strMatrix;//������1L7M
		int Pixel;//ʵ������
		string Reverse;//�Ƿ�Ⱥ�����
		string Inverse;//�Ƿ�Ⱥ�����//����û��
		bool boReverse;//��ת���ߵ�������ӡ�����и���
		bool boInverse;//��ת���ߵ�������ӡ�����и���
		vector<vector<bool>> boDotMes;//����///    int N=5, M=6; //vector<vector<int> > obj(N, vector<int>(M)); //�����ά��̬����5��6�� 
		int scrMaxRow;//��������
		int intRowMax;//intDotMesRow//������������ʾ��
		int bytRowByteMul;//һ���ɼ���byte��ʾ
		bool boDynamic;//�Ƿ�̬��ӡ
		bool boPrintNow;//�Ƿ�ʱ��ӡ
        
		bool CounterEditMes[4];
		UINT32 *IntMes;//��̬����
		vector<BYTE> intMesDis;//��̬��ʾ��
		//int bytSerialConCoundis;//��̬��ʾ�ã����к���
		int intDotMesRowdis;//��̬��ʾ�ã�����
		int matrixMesdis ;//��̬��ʾ�ã���������������������
		int pixelMesdis;//��̬��ʾ�ã���ӡʱʵ��ռ�õ�����
		bool boReversedis, boInversedis;//��̬��ʾ�ã���ת�ߵ�
		//int intTimeRowSizedis[4], intTimeRowStartdis[4], bintTimelineStartdis[4];//��̬��ʾ��
		//int intQSerialRowSizedis[4], intQSerialRowStartdis[4];//��̬��ʾ��
		void getSerialDotBuf2();//���ɶ�Ӧ��ʽ���к�
		void GetNextObjPosition(int& xPos, int &yPos);//�����һ��������Ƶ���ʼλ��

		//int CountNumForPre[4];//���кż�������
		///ʱ��
		//int bytTimeConCoun ;//ʱ������
		//int bytTimeConCoundis;//��̬��ʾ�ã�ʱ������
		//string strTimeFormat[1][4] ;//ʱ���ʽ
		//string strTimeFont[4];//ʱ������
		//int strETimeOffSet[4], strTimeOffSetUint[4];//ʱ��ƫ����
		//string strETimetext[4];//ʱ���ı�
		////
		bool SerialCountNew;//�Ƿ�Ϊ�½�
		bool SerialCountSet[3];//�������к�
		//int bytSerialConCoun;//���кż���
		//int bytQserialCounter[4];//���кż�����
		//int intQSerialRepeat[4];//�ظ�ֵ
		//int intQSerialFirstLimit[4];//��һ����
		//int intQSerialSecondLimit[4];//�ڶ�����
		//int intQSerialStartValue[4];//��ʼֵ
		//int intQSerialStep[4];//����
		//int bytQSerialFormat[4];//��ʽ
		//int bytQSerialDigits[4];//λ��
		//int CountNum[4], CountNumRep[4];//���к�ֵ���ظ�����
		//string strQSerialFont[4];//���к�����
		//bool boTimeBWDy[4], boTimeBWDx[4], boTimeNEG[4], boQSerialBWDy[4], boQSerialBWDx[4], boQSerialNEG[4] ;//���к�������ԣ���dis��β������ʾ��
		//int bytTimeSS[4], bytTimeSW[4], bytTimeLineSize[4], bytTimeLineStart[4], bytQSerialSS[4], bytQSerialSW[4], bytQSerialLineSize[4], bytQSerialLineStart[4] ;
		//int intTimeRowSize[4], intTimeRowStart[4], intTimeOffSetdis[4], intQSerialRowSize[4], intQSerialRowStart[4] ;
		//bool boCountEn[4];//�Ƿ����������static���к�

		void getdigitaldot();//��û����ֿ�
		
		vector<BYTE> DotToByte1(int tempintDotRowStart, int tempintDotRowEnd, vector<BYTE> bytTempData,string tempfont, bool tempBWDy, bool tempBWDx ,bool tempNEG , 
			string tempsetTEXT, int tempRowSize, int tempLineSize , int tempLineStart , int tempRowStart , int tempSS , int tempSW);//��̬��ӡ���ݻ�ȡ����
		map<string,vector<BYTE>> bytdigital5x5LineMap;//�����ֿ�0-9a-zA-Z
		map<string,vector<BYTE>> bytdigital7x5LineMap;
		map<string,vector<BYTE>> bytdigital12x12LineMap;
		map<string,vector<BYTE>> bytdigital16x12LineMap;

		///////////////////////////////////////
		vector<BYTE> bytPrintDataAllOrder;//��������BUF
		vector<BYTE> bytPrintDataAll;//��ʱ�Զ�����BUF
		////////////////////////////////////

 	public:

		string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//��
		BYTE getByteFromDot(bool boDot,int moveNum); 
		void DrawDot(CDC* pDC);
		void DrawMainPageDot(CDC* pDC);
		void DrawSerialTimeDynamic(int nRowStartdis,int intDynamicRowEnd,int nStartValue,CDC* pDC);
 		void DrawSerialTimeDynamic(int nRowStartdis,int intDynamicRowEnd,int intDynamicLineStart,int intDynamicLineEnd,CDC* pDC);
		void CreateSerialTimeDynamic();
		void getdot();
		vector<BYTE> DotToByte(int tempintDotRowStart, int tempintDotRowEnd);
		void OBJ_VecCopy2lastObj_Vec();
		void ClearlastObj_Vec();

	public://XML
		void ReadObjectsFromXml(char* strFileName);
		void SaveObjectsToXml(char* strFileName);
		string labPath;
		string labName;
		void createLABXML();
		void getLabFromXml();

};



 
