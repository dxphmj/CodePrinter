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

public://����
	string strDuan;//��Ϣ�εı�ʶλ
	string strType1;//�ֶ�����
	string strType2;	//�ֶ�ʵ������
	int intX;//�ֶ�ԭ��X���꣨Ĭ��Ϊ0��
	int intY;//�ֶ�ԭ��Y���꣨Ĭ��Ϊ0��
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


public://����
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
		string Reverse;//�Ƿ�Ⱥ�����
		string Inverse;
		bool boReverse;//��ת���ߵ�������ӡ�����и���
		bool boInverse;
        bool boDotMes[32][255];
		int intRowMax;//intDotMesRow
		int bytRowByteMul;//һ���ɼ���byte��ʾ
		bool boDynamic;//�Ƿ�̬��ӡ
		bool boPrintNow;//�Ƿ�ʱ��ӡ
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
		///ʱ��
		int bytTimeConCoun ;
		int bytTimeConCoundis;
		string strTimeFormat[1][4] ;
		string strTimeFont[4];
		int strETimeOffSet[4], strTimeOffSetUint[4];
		string strETimetext[4];
		////
		bool SerialCountNew;//�Ƿ�Ϊ�½�
		bool SerialCountSet[3];//�������к�
		int bytSerialConCoun;//���кż���
		int bytQserialCounter[4];//���кż�����
		int intQSerialRepeat[4];//�ظ�ֵ
		int intQSerialFirstLimit[4];//��һ����
		int intQSerialSecondLimit[4];//�ڶ�����
		int intQSerialStartValue[4];//��ʼֵ
		int intQSerialStep[4];//����
		int bytQSerialFormat[4];//��ʽ
		int bytQSerialDigits[4];//λ��
		int CountNum0, CountNum1, CountNum2, CountNum3, CountNumRep0, CountNumRep1, CountNumRep2, CountNumRep3 ;
		string strQSerialFont[4];
		bool boTimeBWDy[4], boTimeBWDx[4], boTimeNEG[4], boQSerialBWDy[4], boQSerialBWDx[4], boQSerialNEG[4] ;
		int bytTimeSS[4], bytTimeSW[4], bytTimeLineSize[4], bytTimeLineStart[4], bytQSerialSS[4], bytQSerialSW[4], bytQSerialLineSize[4], bytQSerialLineStart[4] ;
		int intTimeRowSize[4], intTimeRowStart[4], intTimeOffSetdis[4], intQSerialRowSize[4], intQSerialRowStart[4] ;
		bool boCountEn[4];//�Ƿ����������static���к�

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

		UINT32 *IntMes;//��̬����
		///////////////////////////////////////
		vector<BYTE> bytPrintDataAllOrder;//��������BUF
		vector<BYTE> bytPrintDataAll;//��ʱ�Զ�����BUF
		////////////////////////////////////

 	public:
		 string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//��
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



 
