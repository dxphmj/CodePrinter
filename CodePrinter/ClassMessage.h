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
	public://����
        OBJ_Control(void);
		~OBJ_Control(void);
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
		string strETimeOffSet;//�ֶε�ʱ��ƫ�ƿ��أ�faulseΪ�رգ�trueΪ������
		int intTimeOffSet;//�ֶε�ʱ��ƫ��ֵ
		string strTimeOffSet;//�ֶε�ʱ��ƫ������
		int intSerialFirstLimit;//�ֶε�FirstLimit���ԣ������кŵ�һ����
		int intSerialSecondLimit;//�ֶε�SecondLimit���ԣ������кŵڶ�����
		int intSerialStartValue;//�ֶε�StartValue���ԣ������к���ʼֵ
		int intSerialStep;//�ֶε�StepSize���ԣ������кŲ���ֵ
		int intSerialRepeat;//�ֶε�RepeatCount���ԣ������к��ظ�ֵ
        BYTE intSerialDigits;//�ֶε�Digital���ԣ������к�λ��ֵ
		int strSerialCounter;//�ڼ������к�
		BYTE bytSerialFormat;//�ֶε�SerialFormat���ԣ������кŸ�ʽ
		int intLineSize;//�ֶε�����
		int intRowSize;//�ֶε�����
		int intLineStart;//�ֶεĿ�ʼ��
		int intRowStart;//�ֶεĿ�ʼ��
      
		string strqrcodeVersion;//��ά��İ汾����
		string strqrcodeECCLevel;//��ά����ݴ��ʵȼ�
		int intqrcodeQuietZone;//��ά��հ׿����
		bool booFocus;//�����Ƿ���ʾ,True:��ʾ����,False:��ʾ���
	public://����������
		string img;//��ΪlogoͼƬ��vb��ΪImage����
        //vector<vector<bool>> logobmp;//����

        //vector<vector<bool>> LogoDotToMes;//�ı���LogoͼƬ���������·�������
        //vector<vector<bool>> LogoDot;//logo����


		bool boDotBmp[32][255];//����bmp��
		int xMaxBmp,yMaxBmp;//������¼���μ���ͼƬ�Ĵ�С
	public://����
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
		string Reverse;//�Ƿ�Ⱥ�����
		string Inverse;
		bool boReverse;//��ת���ߵ�������ӡ�����и���
		bool boInverse;
        bool boDotMes[32][255];
		int bytRowByteMul;//һ���ɼ���byte��ʾ
		//vector<BYTE> bytTempDataVec;
       
	public:
		 BYTE getByteFromDot(bool boDot,int moveNum); 
		 string DEC_to_BIN(long long Dec);
		 string to_String(int n);
		 long long BIN_to_DEC(string Bin);
		 bool readBin(string FontName,int offset,char *arr, int DataLen );//�˴�����char������BYTE
		 void DrawDot(CDC* pDC);//
		 void getdot(string tempfont, bool tempBWDy, bool tempBWDx , bool tempNEG, string tempsetTEXT , int tempRowSize, int tempLineSize, int tempLineStart , int tempRowStart , int tempSS , int tempSW );
		 vector<BYTE> DotToByte(int tempintDotRowStart, int tempintDotRowEnd);
	public://XML
		void ReadObjectsFromXml(char* strFileName);
		void SaveObjectsToXml(char* strFileName);
		
	};



}

