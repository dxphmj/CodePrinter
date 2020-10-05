#include "StdAfx.h"
#include "ModuleMain.h"
#include "CodePrinter.h"
#include<cmath>
#include<algorithm>
#include <fstream>
#include<cstdio> 
#include <math.h>
#include <sstream>//ʹ�øÿ⺯����ostringstream����int���string

#include "qrcode\zint.h"
 
void StatusClass::byStatusFromSlaveState()
{
	theApp.bytSlaveStatusLock.Lock();
	for (int i=0;i<16;i++)
	{
		theApp.bytStatus[i]=theApp.bytSlaveStatus[i];
	}

	if (LevCoun==10)
	{
		theApp.bytStatus[16]=SolLevSum/10;     //īˮҺλȡƽ��
		theApp.bytStatus[17]=InkLevSum/10;     //�ܼ�Һλȡƽ��
		SolLevSum = 0;
		InkLevSum = 0;
		LevCoun = 1;
		SolLevSum = SolLevSum + theApp.bytSlaveStatus[16];
		InkLevSum = InkLevSum + theApp.bytSlaveStatus[17];
	} 
	else
	{
		LevCoun = LevCoun + 1;
		SolLevSum = SolLevSum + theApp.bytSlaveStatus[16];
		InkLevSum = InkLevSum + theApp.bytSlaveStatus[17];
	}


	for (int i=18;i<37;i++)
	{
		theApp.bytStatus[i]=theApp.bytSlaveStatus[i];
	}
	theApp.bytSlaveStatusLock.Unlock();
}

void StatusClass::getstatu()
{
	//staSysRea = GETnBIT_from_bytStatus(0, 0, 1)==_T("1")?true:false;  //ϵͳ׼����
	staSysRea = GETnBIT_from_bytStatus(0, 0, 1)==1?true:false;  //ϵͳ׼����
	//staSysRea = (GETnBIT_from_bytStatus(0, 0, 1)==1);  //ϵͳ׼����
	staSysBus = (GETnBIT_from_bytStatus(0, 1, 1)==1?true:false) ;  //ϵͳæ
	staBumMod = (GETnBIT_from_bytStatus(0, 2, 1)==1?true:false)  ; //��ģʽ
	staBum = (GETnBIT_from_bytStatus(0, 3, 1)==1?true:false)   ;   //'�ÿ���
	staHarFin = (GETnBIT_from_bytStatus(0, 4, 1)==1?true:false) ;  //'��λ����λ���
	staCleFauFin = (GETnBIT_from_bytStatus(0, 5, 1)==1?true:false) ;// '����������
	//6����ִ����ɡ�7����ģʽ������
	staComExeFin=(GETnBIT_from_bytStatus(0, 6, 1)==1?true:false) ;//bit6:  0 û��ִ����� 1 ����ִ�����
	staSleMod=(GETnBIT_from_bytStatus(0, 7, 1)==1?true:false) ;//Bit7:  1 ����ģʽ�����У�0 ������


	staNozVal = (GETnBIT_from_bytStatus(1, 0, 1)==1?true:false);   //'���췧
	staFeeVal = (GETnBIT_from_bytStatus(1, 1, 1)==1?true:false) ;  //'��ī��
	staBleVal = (GETnBIT_from_bytStatus(1, 2, 1)==1?true:false) ;  //'������
	staFluVal = (GETnBIT_from_bytStatus(1, 3, 1)==1?true:false) ;  //'��ϴ��
	staSolVal = (GETnBIT_from_bytStatus(1, 4, 1)==1?true:false) ;  //'�ܼ���
	staVisVal = (GETnBIT_from_bytStatus(1, 5, 1)==1?true:false) ;  //'ճ�ȷ�
	staWasVal = (GETnBIT_from_bytStatus(1, 6, 1)==1?true:false) ;  //'��ϴ��
	staValFau = (GETnBIT_from_bytStatus(1, 7, 1)==1?true:false) ;  //������Bit7: ��ŷ�����,0������1����
	
	staInkFloSenOff = (GETnBIT_from_bytStatus(2, 0, 1)==1?true:false) ;  //'�ػ���
	staCloInkLin = (GETnBIT_from_bytStatus(2, 1, 1)==1?true:false) ;  //'��ī��
	staAddSol = (GETnBIT_from_bytStatus(2, 2, 1)==1?true:false)  ; //'����ܼ�
	staDetVis = (GETnBIT_from_bytStatus(2, 3, 1)==1?true:false)  ; //'����ճ��
	staWasNoz = (GETnBIT_from_bytStatus(2, 4, 1)==1?true:false)  ; //'��ϴ��ͷ
	staSucNoz = (GETnBIT_from_bytStatus(2, 5, 1)==1?true:false)   ;//'��������
	staAdjInkLin = (GETnBIT_from_bytStatus(2, 6, 1)==1?true:false) ; // 'ī·У��
	staInkCir = (GETnBIT_from_bytStatus(2, 7, 1)==1?true:false)  ; //'ī·ѭ��
	staInkTemSenFau = (GETnBIT_from_bytStatus(3, 0, 1)==1?true:false)  ; //'īˮ�¶ȴ���������
	staPriHeaTemFau = (GETnBIT_from_bytStatus(3, 1, 1)==1?true:false) ;  //'��ͷ�¶ȴ���������
	staBumSpeOveFau = (GETnBIT_from_bytStatus(3, 2, 1)==1?true:false) ;  //'�ó��ٱ���
	staPreOveFau = (GETnBIT_from_bytStatus(3, 3, 1)==1?true:false)  ; //'��ѹ����
	staVisAbnFau = (GETnBIT_from_bytStatus(3, 4, 1)==1?true:false) ;  //'ճ���쳣
	staVisSenFau = (GETnBIT_from_bytStatus(3, 5, 1)==1?true:false) ; //'ճ�ȼƹ���
	staInkFloFau = (GETnBIT_from_bytStatus(3, 6, 1)==1?true:false)  ; //'���չ���
	staPriHeaCle = (GETnBIT_from_bytStatus(3, 7, 1)==1?true:false) ;  //'���ػ���ϴ//���ڱ�Ϊ��ϴ��ѹ���ϣ�Ӧ����һ����˼
	//bit7: ��ϴ��ѹ���ϣ�0 ������1��ѹ���㣻

	staFanFau = (GETnBIT_from_bytStatus(4, 0, 1)==1?true:false) ; // '���ȹ���
	staChaFau = (GETnBIT_from_bytStatus(4, 1, 1)==1?true:false) ;  //'������
	staPhaFau = (GETnBIT_from_bytStatus(4, 2, 1)==1?true:false) ;  //'��λ����
	staHigVolFau = (GETnBIT_from_bytStatus(4, 3, 1)==1?true:false) ; // '��ѹ����
	staSolLevFau = OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 5, 1)==1?true:false) +OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 4, 1)==1?true:false);  //'�ܼ�Һλ״̬
	staInkLevFau = OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 7, 1)==1?true:false) + OBJ_Control::to_String(GETnBIT_from_bytStatus(4, 6, 1)==1?true:false);  //'īˮҺλ״̬
	
	staPrnting = (GETnBIT_from_bytStatus(5, 0, 1)==1?true:false) ; // '��ӡ��
	staSerNumRes= (GETnBIT_from_bytStatus(5, 1, 1)==1?true:false) ;//Bit1: ���кŸ�λ���أ�0 �����ް��£�1 �������£���ȡ���Զ���0

	//'staBufOveFau = IIf(GETnBIT_from_bytStatus(5, 2, 1)==1);  // '�ı�buf���
	staHigVolSwi = (GETnBIT_from_bytStatus(5, 3, 1)==1?true:false)  ; //'��ѹ����
	staActProSen = (GETnBIT_from_bytStatus(5, 4, 1)==1?true:false)  ; //'���۵�ǰ��ƽ
	staProSenFas = (GETnBIT_from_bytStatus(5, 5, 1)==1?true:false) ;  ////'���۹���
	staAutModFau = (GETnBIT_from_bytStatus(5, 6, 1)==1?true:false) ; // '�Զ�����ʧ��

	//Bit7: īˮ�������� 0 ���������߹��ܣ�1 �������߹��ܣ�ע������λ������������
	staInkSleAll = (GETnBIT_from_bytStatus(5, 7, 1)==1?true:false) ;  //��Ϊīˮ��������������ת��1��
	

	staPrinted = (GETnBIT_from_bytStatus(6, 0, 1)==1?true:false)  ; //'��ӡ���
	staRemPrinSwi = (GETnBIT_from_bytStatus(6, 1, 1)==1?true:false); //  'Զ�̴�ӡ����
	//'staBufFul = (GETnBIT_from_bytStatus(6, 2, 1)==1);   //'�ı�buf��
	staBufRea = (GETnBIT_from_bytStatus(6, 3, 1)==1?true:false) ;  //'��Ϣ׼����
	staEncDir = (GETnBIT_from_bytStatus(6, 4, 1)==1?true:false) ;  //'����������
	staLinFas = (GETnBIT_from_bytStatus(6, 5, 1)==1?true:false) ;  //'����������
	staPriHeaHot = (GETnBIT_from_bytStatus(6, 6, 1)==1?true:false);  // '����״̬
	staPriHeaHotFau = (GETnBIT_from_bytStatus(6, 7, 1)==1?true:false) ; // '���¹���
	if (theApp.bytStatus[8] * 256 +theApp. bytStatus[7] > 5000)  //'ʵʱѹ��
	{
		staPressure=theApp.bytStatus[8] * 256 + theApp.bytStatus[7] - 65536;
	} 
	else
	{
		staPressure=theApp.bytStatus[8] * 256 + theApp.bytStatus[7];
	}
	
	staBumSpe = theApp.bytStatus[10] * 256 + theApp.bytStatus[9];     //'ʵʱ����
	staPriHeaTem = theApp.bytStatus[11] ;                                       //'ʵʱ��ͷ�¶�
	staInkTem = (theApp.bytStatus[13] * 256 + theApp.bytStatus[12]) / 10   ;              //'ʵʱīˮ�¶�
	staActVis = theApp.bytStatus[14] ;                                     //'Ŀǰʵʱճ��
	staTarVis = theApp.bytStatus[15] ;                                         // 'Ŀ��ο�ճ��
	staInkLev = theApp.bytStatus[16] ;                                        // 'ʵʱīˮҺλ
	staSolLev = theApp.bytStatus[17] ;                                          //'ʵʱ�ܼ�Һλ
	staHigVol = theApp.bytStatus[19]* 256 + theApp.bytStatus[18] ;                      // 'ʵʱ��ѹ
	staPhase = theApp.bytStatus[20] ;                                        // 'ʵʱ��λ
	staEncFre = theApp.bytStatus[22] * 256 + theApp.bytStatus[21] ;                       //'ʵʱ������Ƶ��
	staProCou = theApp.bytStatus[26] * pow(256 , 3) + theApp.bytStatus[25] * pow(256 , 2 )+ theApp.bytStatus[24] * 256 + theApp.bytStatus[23];      // '��Ʒ������
	staPriCou = theApp.bytStatus[30] * pow(256 , 3) + theApp.bytStatus[29] * pow(256 , 2 )+ theApp.bytStatus[28] * 256 + theApp.bytStatus[27];      // '��ӡ������
	staPixDotNee = theApp.bytStatus[31];                                  // '�й��ɵ���
	staAutModVol = theApp.bytStatus[32];                                  // '�Զ����ѵ�ѹ
	//33-36 īˮʱ����أ�
	//0x21~0x24: 	��ӡʱ�䣬����0x24(byte3)bit7~6��ʾ��״̬��00 �޿���10 ����Ч��11ˢ���ɹ�,��ȡ��״̬λ���Զ���0��
	//bit5��ʾˢ�����ܣ�0 ��ֹˢ����1 ����ˢ��;
	//������
	//��������
	//	���ڲ����ʣ�2400bps����ʼλ1������8λ��ֹͣλ1����żλû��

	staSetTimeEna = (GETnBIT_from_bytStatus(36, 5, 1)==1?true:false);   //'ά����īˮʱ����Ĺ��ܿ���
	if (!staSetTimeEna)
	{
		staInkLifeTime = (theApp.bytStatus[36] & 31) * pow(256 , 3) + theApp.bytStatus[35] * pow(256 , 2) + theApp.bytStatus[34] * 256 + theApp.bytStatus[33];   // 'īˮʱ��
		staRFID =  OBJ_Control::to_String(GETnBIT_from_bytStatus(36, 7, 1)==1?true:false) + OBJ_Control::to_String(GETnBIT_from_bytStatus(36, 6, 1)==1?true:false); //'RFID״̬
	}
}


void StatusClass::us_button_onoff(HWND hwnd)
{
	CWnd* pWnd = CWnd::FromHandle(hwnd);

	if (!theApp.myStatusClass.staSysBus && theApp.myStatusClass.ctr0X02bit3 == 0 && theApp.myStatusClass.ctr0X02bit4 == 0 &&
		theApp.myStatusClass.ctr0X02bit5 == 0 && theApp.myStatusClass.ctr0X02bit6 == 0 && theApp.myStatusClass.ctr0X02bit7 == 0 )
	{
		pWnd->GetDlgItem(IDC_SPEED_MODE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_PRESSURE_MODE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_BLEED_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_PUMP_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_WASH_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_FEED_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_VISCO_VALVE_BTN)->EnableWindow(true);
		pWnd->GetDlgItem(IDC_FLUSH_VALVE_BTN)->EnableWindow(true);
	} 
	else
	{
		pWnd->GetDlgItem(IDC_SPEED_MODE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_PRESSURE_MODE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_BLEED_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_PUMP_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_WASH_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_FEED_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_VISCO_VALVE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_FLUSH_VALVE_BTN)->EnableWindow(false);
	}
}

void StatusClass::ad_button_onoff(HWND hwnd)
{
	CWnd* pWnd = CWnd::FromHandle(hwnd);
	if (!theApp.myStatusClass.staSysBus)
	{
		if (theApp.myStatusClass.ctr0X02bit3==1)
		{
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		} 
		else if(theApp.myStatusClass.ctr0X02bit4==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit5==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit6==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit7==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X03bit3==1)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
		}
		else if(theApp.myStatusClass.ctr0X02bit3 == 0 && theApp.myStatusClass.ctr0X02bit4 == 0 && theApp.myStatusClass.ctr0X02bit5 == 0 &&
			theApp.myStatusClass.ctr0X02bit6 == 0 && theApp.myStatusClass.ctr0X02bit7 == 0 && theApp.myStatusClass.ctr0X03bit3 == 0)
		{
			pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(true);
			pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(true);
		}
	} 
	else
	{
		pWnd->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(false);
		pWnd->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(false);
	}

}

void StatusClass::download_inksystem_control00()
{
	ctr0X00 = ctr0X00bit5 * 32 + ctr0X00bit3 * 8 + ctr0X00bit2 * 4 + ctr0X00bit1 * 2 + ctr0X00bit0;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x0);
	tempCtrVec.push_back(ctr0X00);
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
		theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}
void StatusClass::download_inksystem_control01()
{
	ctr0X01 = ctr0X01bit6 * 64 + ctr0X01bit5 * 32 + ctr0X01bit4 * 16 + ctr0X01bit3 * 8 + ctr0X01bit2 * 4 + ctr0X01bit1 * 2 + ctr0X01bit0;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(ctr0X01);
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}
void StatusClass::download_inksystem_control02()
{
	ctr0X02 = ctr0X02bit7 * 128 + ctr0X02bit6 * 64 + ctr0X02bit5 * 32 + ctr0X02bit4 * 16 + ctr0X02bit3 * 8 + ctr0X02bit2 * 4 + ctr0X02bit1 * 2 + ctr0X02bit0;
	 vector<BYTE> tempCtrVec;
	 tempCtrVec.push_back(0x1);
	 tempCtrVec.push_back(0x80);
	 tempCtrVec.push_back(0x3);
	 tempCtrVec.push_back(0x3);
	 tempCtrVec.push_back(0x2);
	 tempCtrVec.push_back(ctr0X02);
	 tempCtrVec.push_back(0xff);
	 tempCtrVec.push_back(0xff);

	 theApp.boQueCtrLock.Lock();
	 theApp.queCtr.push(tempCtrVec);
	 theApp.boQueCtrLock.Unlock();
}
void StatusClass::download_inksystem_control03()
{
	//ctr0X03 = ctr0X03bit7 * 128 + ctr0X03bit6 * 64 + ctr0X03bit5 * 32 + ctr0X03bit4 * 16 + ctr0X03bit3 * 8 + ctr0X03bit1 * 2 + ctr0X03bit0
	ctr0X03 = ctr0X03bit6 * 64 + ctr0X03bit3 * 8 + ctr0X03bit1 * 2 + ctr0X03bit0;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(ctr0X03);
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}


void StatusClass::download_inksystem_control05()
{

	//ctr0X05 = ctr0X05bit11*2048+ctr0X05bit10*1024+ctr0X05bit5*32+ctr0X05bit4 * 16 + ctr0X05bit2 * 4 + ctr0X05bit1 * 2 ;
	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x5);
	tempCtrVec.push_back(ctr0X05);//�˴�ֱ���·�ctr0x05
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}
//////////////////////////////////////////////////////////////////////////////
BYTE* VEC2ARRAY(vector<BYTE> tempVec,int n)
{
	//BYTE charary[n];
	BYTE *arr = new BYTE[n];
	memcpy(arr, &tempVec[0], tempVec.size() * sizeof(tempVec[0]));
	return arr;
}

CString GETnBIT_from_bytReadData(int I , int m , int n )
{
	string tempCstr="";
	ModuleMain tempstringToLPCWSTR;
	tempCstr="00000000"+OBJ_Control::DEC_to_BIN(theApp.myCIOVsd.m_pRecvBuf[I+4]);

    //tempCstr=tempCstr.Mid(tempCstr.GetLength()-m,n);
	CString cstringStr= tempstringToLPCWSTR.stringToLPCWSTR(tempCstr);
	return cstringStr.Mid(cstringStr.GetLength()-m-1,n);
}

//CString GETnBIT_from_bytStatus(int I , int m , int n )
//{
//	string tempCstr="";
//	ModuleMain tempstringToLPCWSTR;
//	tempCstr="00000000"+OBJ_Control::DEC_to_BIN(theApp.bytStatus[I]);
//
//	//tempCstr=tempCstr.Mid(tempCstr.GetLength()-m,n);
//
//	CString cstringStr= tempstringToLPCWSTR.stringToLPCWSTR(tempCstr);
//	int dd=cstringStr.GetLength();
//	return cstringStr.Mid(cstringStr.GetLength()-m-1,n);
//}
int GETnBIT_from_bytStatus(int I , int m , int n )
{
	return (theApp.bytStatus[I] >> (m-1)) & 0x01;
}

//�����߳�
UINT TTLcomLoop(LPVOID pParam)
{
	theApp.boTTL=true;
	int bytComErr=0;//���ڴ������
	int strTempCmdLen=0;//���ݳ���
	LPTSTR strTempCmd;//��������
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};//��ȡ��Ϣ����
	strTempCmd=(LPTSTR)readArr;
	strTempCmdLen=8;
	while(theApp.boTTL)
	{
		if (theApp.readCount==43)
		{
			theApp.readCount=0;
			if (theApp.myCIOVsd.m_pRecvBuf[0]==0x2&&theApp.myCIOVsd.m_pRecvBuf[1]==0x80&&theApp.myCIOVsd.m_pRecvBuf[2]==0x26)
			{
				bytComErr=0;
				theApp.boQueCtrLock.Lock();
					if (theApp.queCtr.size()>0)//�������
					{
						vector<BYTE> tempQueVec=theApp.queCtr.front();
						theApp.queCtr.pop();
						strTempCmdLen=tempQueVec.size();
						strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
					}
					else if (theApp.m_MessagePrint.boPrintNow)
					{
						theApp.boPrintNowLock.Lock();
						if (theApp.m_MessagePrint.bytPrintDataAllOrder.size()>13)
						{
							strTempCmd=(LPTSTR)VEC2ARRAY(theApp.m_MessagePrint.bytPrintDataAllOrder,theApp.m_MessagePrint.bytPrintDataAllOrder.size());
							strTempCmdLen=theApp.m_MessagePrint.bytPrintDataAllOrder.size();
							theApp.m_MessagePrint.boPrintNow=false;

							if (theApp.m_UserList.GetCount()>0)
							{
								theApp.boSendCodeLock.Lock();
								theApp.sendCodeque=queue<vector<BYTE>>();
								theApp.sendCodeque.push(theApp.m_MessagePrint.bytPrintDataAllOrder);//�����������
								theApp.boSendCodeLock.Unlock();
							}
						} 
						else
						{
							strTempCmd=(LPTSTR)readArr;
							strTempCmdLen=8;
						}
						theApp.boPrintNowLock.Unlock();
					}
					else if (!theApp.m_MessagePrint.boPrintNow)
					{
						if (GETnBIT_from_bytReadData(6,2,1)!=_T("1"))//�ı�buf��
						{
							if (theApp.m_MessagePrint.boDynamic)
							{
								if (theApp.ForPreQue.size()>0)//���кŶ���
								{
									vector<BYTE> tempQueVec=theApp.ForPreQue.front();
									theApp.ForPreQue.pop();
									if (theApp.m_UserList.GetCount()>0)
									{
										if (theApp.sendCodeque.size()<10)
										{
											theApp.boSendCodeLock.Lock();
											theApp.sendCodeque.push(theApp.m_MessagePrint.bytPrintDataAllOrder);//�����������
											theApp.boSendCodeLock.Unlock();
										}		
									}
									strTempCmdLen=tempQueVec.size();
									strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
									if (strTempCmdLen>13)
									{
										//��̬��ʾ���										
										theApp.m_MessagePrint.intMesDis = tempQueVec;										 
									} 
									else
									{
										strTempCmd=(LPTSTR)readArr;
										strTempCmdLen=8;
									}
								} 
								else
								{
									strTempCmd=(LPTSTR)readArr;
									strTempCmdLen=8;
								}
							} 
							else//���Ƕ�̬��ӡ
							{
								if (theApp.m_MessagePrint.bytPrintDataAll.size()>13)
								{
									strTempCmd=(LPTSTR)VEC2ARRAY(theApp.m_MessagePrint.bytPrintDataAll,theApp.m_MessagePrint.bytPrintDataAll.size());
									strTempCmdLen=theApp.m_MessagePrint.bytPrintDataAll.size();
									if (strTempCmdLen<14)
									{
										strTempCmd=(LPTSTR)readArr;
										strTempCmdLen=8;
									}
								}
							}
						} 
						else
						{
							strTempCmd=(LPTSTR)readArr;
							strTempCmdLen=8;
						}
					}
					else
					{
						strTempCmd=(LPTSTR)readArr;
						strTempCmdLen=8;
					}
				theApp.boQueCtrLock.Unlock();

				//ͬ��״̬����
				theApp.bytSlaveStatusLock.Lock();
					for (int i=0;i<37;i++)
					{
						theApp.bytSlaveStatus[i]=theApp.myCIOVsd.m_pRecvBuf[i+4];
					}
				theApp.bytSlaveStatusLock.Unlock();
			} 
		}
		else if (theApp.readCount==6)
		{
			theApp.readCount=0;
			strTempCmdLen=0;
			if (theApp.myCIOVsd.m_pRecvBuf[0]==0x2&&theApp.myCIOVsd.m_pRecvBuf[1]==0x80&&theApp.myCIOVsd.m_pRecvBuf[3]==0x10)
			{
				bytComErr=0;
				theApp.boQueCtrLock.Lock();
				if (theApp.queCtr.size()>0)
				{
					vector<BYTE> tempQueVec=theApp.queCtr.front();
					theApp.queCtr.pop();
					strTempCmdLen=tempQueVec.size();
					strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,strTempCmdLen);
				} 
				else if(theApp.m_MessagePrint.boPrintNow)
				{
					theApp.boPrintNowLock.Lock();
					if (theApp.m_MessagePrint.bytPrintDataAllOrder.size()>13)
					{
						strTempCmd=(LPTSTR)VEC2ARRAY(theApp.m_MessagePrint.bytPrintDataAllOrder,theApp.m_MessagePrint.bytPrintDataAllOrder.size());
						strTempCmdLen=theApp.m_MessagePrint.bytPrintDataAllOrder.size();
						theApp.m_MessagePrint.boPrintNow=false;
						if (theApp.m_UserList.GetCount()>0)
						{
							theApp.boSendCodeLock.Lock();
							theApp.sendCodeque=queue<vector<BYTE>>();
							theApp.sendCodeque.push(theApp.m_MessagePrint.bytPrintDataAllOrder);//�����������
							theApp.boSendCodeLock.Unlock();
						}
					} 
					else
					{
						strTempCmd=(LPTSTR)readArr;
						strTempCmdLen=8;
					}
					theApp.boPrintNowLock.Unlock();
				}
				else if (!theApp.m_MessagePrint.boPrintNow)
				{
					strTempCmd=(LPTSTR)readArr;
					strTempCmdLen=8;
				}
				theApp.boQueCtrLock.Unlock();
			}
			else
			{
				strTempCmd=(LPTSTR)readArr;
				strTempCmdLen=8;
			}
		} 
		else// if (theApp.myCIOVsd.m_pRecvBuf[0]==0x2&&theApp.myCIOVsd.m_pRecvBuf[1]==0x80&&theApp.myCIOVsd.m_pRecvBuf[3]==0x20)
		{
			bytComErr++;
			if (bytComErr>10)
			{/////�����Ի���
				int result =MessageBox( NULL,TEXT("�Ƿ����") , TEXT("ѡ��") ,MB_YESNO);
				switch(result)
				{
				case IDYES:
					bytComErr=0;
					strTempCmd=(LPTSTR)readArr;
					strTempCmdLen=8;
					break;
				case IDNO:
					AfxMessageBox(_T("����ͨѶ���ϣ�\n����ϵ����Ա��"));
					break;
				}
			} 
		}
		//else    ///////////////���ڲ��ԡ��Ժ�ɾ��
		//{
		//	//bytComErr++;
		//	//if (bytComErr>10)
		//	//{/////�����Ի���
		//	//	int result =MessageBox( NULL,TEXT("��Ӧ���Ƿ����") , TEXT("ѡ��") ,MB_YESNO);
		//	//	switch(result)
		//	//	{
		//	//	case IDYES:
		//	//		bytComErr=0;
		//	//		strTempCmd=(LPTSTR)readArr;
		//	//		strTempCmdLen=8;
		//	//		break;
		//	//	case IDNO:
		//	//		AfxMessageBox(_T("������Ӧ��\n����ϵ����Ա��"));
		//	//		break;
		//	//	}
		//	//} 
		//	//strTempCmd=(LPTSTR)readArr;
		//	//strTempCmdLen=8;

		//	/////////���´��������
		//	//theApp.boQueCtrLock.Lock();
		//	//if (theApp.queCtr.size()>0)
		//	//{
		//	//	vector<BYTE> tempQueVec=theApp.queCtr.front();
		//	//	theApp.queCtr.pop();
		//	//	strTempCmdLen=tempQueVec.size();
		//	//	strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		//	//}
		//	//theApp.boQueCtrLock.Unlock();

		//	//if (theApp.m_MessagePrint.boDynamic)
		//	//{
		//	//	if (theApp.ForPreQue.size()>0)
		//	//	{
		//	//		theApp.boPrintNowLock.Lock();
		//	//			vector<BYTE> tempQueVec=theApp.ForPreQue.front();
		//	//			theApp.ForPreQue.pop();
		//	//		
		//	//			strTempCmdLen=tempQueVec.size();
		//	//			strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		//	//			if (strTempCmdLen>13)
		//	//			{////��̬��ʾ���
		//	//				vector<BYTE> intMesDis1;
		//	//				intMesDis1.insert(intMesDis1.end(),tempQueVec.begin(),tempQueVec.end());
		//	//				theApp.boDotForPreQue.push(intMesDis1);
		//	//				theApp.m_MessagePrint.intMesDis=theApp.boDotForPreQue.front();//�����ʵ���Բ�Ҫ
		//	//				theApp.boDotForPreQue.pop();
		//	//				vector<int> tempCountVec;
		//	//				if (theApp.intCounNumForPreQue.size()>0)
		//	//				{
		//	//					tempCountVec = theApp.intCounNumForPreQue.front();

		//	//					theApp.intCounNumForPreQue.pop();

		//	//					for (int num=0;num<tempCountVec.size();num++)
		//	//					{
		//	//						theApp.m_MessagePrint.CountNumForPre[num]=tempCountVec[num];
		//	//					}
		//	//				}
		//	//			} 
		//	//			else
		//	//			{
		//	//				strTempCmd=(LPTSTR)readArr;
		//	//				strTempCmdLen=8;
		//	//			}
		//	//		theApp.boPrintNowLock.Unlock();
		//	//	} 
		//	//	else
		//	//	{
		//	//		strTempCmd=(LPTSTR)readArr;
		//	//		strTempCmdLen=8;
		//	//	}
		//	//}
		//			if (theApp.m_MessagePrint.boPrintNow)
		//			{
		//				theApp.boPrintNowLock.Lock();
		//				if (theApp.m_MessagePrint.bytPrintDataAllOrder.size()>13)
		//				{
		//					strTempCmd=(LPTSTR)VEC2ARRAY(theApp.m_MessagePrint.bytPrintDataAllOrder,theApp.m_MessagePrint.bytPrintDataAllOrder.size());
		//					strTempCmdLen=theApp.m_MessagePrint.bytPrintDataAllOrder.size();
		//					theApp.m_MessagePrint.boPrintNow=false;

		//					if (theApp.m_UserList.GetCount()>0)
		//					{
		//						theApp.boSendCodeLock.Lock();
		//						theApp.sendCodeque=queue<vector<BYTE>>();
		//						theApp.sendCodeque.push(theApp.m_MessagePrint.bytPrintDataAllOrder);//�����������
		//						theApp.boSendCodeLock.Unlock();
		//					}
		//				} 
		//				else
		//				{
		//					strTempCmd=(LPTSTR)readArr;
		//					strTempCmdLen=8;
		//				}
		//				theApp.boPrintNowLock.Unlock();
		//			}
		//}

        theApp.myCIOVsd.Send(strTempCmd,strTempCmdLen);//��һ�ν��ȷ���

		Sleep(10);
		
		theApp.readCount=theApp.myCIOVsd.Read();//������λ����ȡ�ֽ���

	}
	return 0;
}

//���ɶ�̬�仯�Ĵ�ӡ���ݵ�m_MessagePrint.bytPrintDataAll
void getSerialTimeDotBuf()
{
	theApp.boPrintNowLock.Lock();
 		for(int i = 0; i < theApp.m_MessagePrint.OBJ_Vec.size(); i++)
		{
			 
			if (theApp.m_MessagePrint.OBJ_Vec[i]->strType2 == "serial")
			{					 
				
				 theApp.m_MessagePrint.OBJ_Vec[i]->CreateSerialDynamic(theApp.m_MessagePrint.bytPrintDataAll,theApp.m_MessagePrint.boReverse, theApp.m_MessagePrint.boInverse,
					 theApp.m_MessagePrint.Matrix,theApp.m_MessagePrint.Pixel,theApp.m_MessagePrint.bytdigital5x5LineMap,
					 theApp.m_MessagePrint.bytdigital7x5LineMap,theApp.m_MessagePrint.bytdigital12x12LineMap,
					 theApp.m_MessagePrint.bytdigital16x12LineMap,theApp.m_MessagePrint.IntMes,theApp.m_MessagePrint.intRowMax);
			}
			else if (theApp.m_MessagePrint.OBJ_Vec[i]->strType2 == "time")
			{					 
				
				 theApp.m_MessagePrint.OBJ_Vec[i]->CreateTimeDynamic(theApp.m_MessagePrint.bytPrintDataAll,theApp.m_MessagePrint.boReverse, theApp.m_MessagePrint.boInverse,
					 theApp.m_MessagePrint.Matrix,theApp.m_MessagePrint.Pixel,theApp.m_MessagePrint.bytdigital5x5LineMap,
					 theApp.m_MessagePrint.bytdigital7x5LineMap,theApp.m_MessagePrint.bytdigital12x12LineMap,
					 theApp.m_MessagePrint.bytdigital16x12LineMap,theApp.m_MessagePrint.IntMes,theApp.m_MessagePrint.intRowMax);
			}
		}	 
	theApp.boPrintNowLock.Unlock();
	return;	 	
}

//���кż�ʱ�������߳�
UINT CreateMessageThread(LPVOID pParam)
{

	while(theApp.mythreadDynamicBoo)
	{
		if(theApp.ForPreQue.size() >= 2)
		{
			Sleep(100);
			continue;
		}
		getSerialTimeDotBuf();//�޸�bytPrintDataAll����Ӧ���ֽ�����
		
		getBarcodeDotBuf();
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//vector<BYTE> bytPrintDataAll1 = theApp.m_MessagePrint.bytPrintDataAll;

		theApp.boPrintNowLock.Lock();
			theApp.ForPreQue.push(theApp.m_MessagePrint.bytPrintDataAll);				
		theApp.boPrintNowLock.Unlock();
	}
	
	return 0;
}


//���ɶ�̬�仯�Ĵ�ӡ���ݵ�m_MessagePrint.bytPrintDataAll
void getBarcodeDotBuf()
{
	for(int i = 0; i < theApp.m_MessagePrint.OBJ_Vec.size(); i++)
	{

		if (theApp.m_MessagePrint.OBJ_Vec[i]->strType2 == "qrcode")
		{
			//***************************���кż�ʱ��仯**********************************//
			//for(int i = 0; i < theApp.m_MessagePrint.DynOBJ_Vec.size(); i++)
			//{
			//	if (theApp.m_MessagePrint.DynOBJ_Vec[i]->strType2 == "serial")
			//	{		
			//		int &CountNumRep = theApp.m_MessagePrint.DynOBJ_Vec[i]->CountNumRep;
			//		int &CountNum = theApp.m_MessagePrint.DynOBJ_Vec[i]->CountNum;
			//		int &intSerialStep = theApp.m_MessagePrint.DynOBJ_Vec[i]->intSerialStep;
			//		int &intSerialRepeat = theApp.m_MessagePrint.DynOBJ_Vec[i]->intSerialRepeat;
			//		int &intSerialFirstLimit = theApp.m_MessagePrint.DynOBJ_Vec[i]->intSerialFirstLimit;
			//		int &intSerialSecondLimit = theApp.m_MessagePrint.DynOBJ_Vec[i]->intSerialSecondLimit;
			//		BYTE &bytSerialFormat = theApp.m_MessagePrint.DynOBJ_Vec[i]->bytSerialFormat;
			//		BYTE &intSerialDigits = theApp.m_MessagePrint.DynOBJ_Vec[i]->intSerialDigits;
			//		if (CountNumRep < intSerialRepeat)
			//			CountNumRep++; 
			//		else
			//		{
			//			CountNumRep = 1;
			//			if (intSerialFirstLimit < intSerialSecondLimit)
			//			{
			//				int tempValue = CountNum+intSerialStep;
			//				if (tempValue > intSerialSecondLimit)
			//				{
			//					CountNum = tempValue - intSerialSecondLimit + intSerialFirstLimit - 1; //'���ڶ����޵ļ��㹫ʽ
			//				} 
			//				else
			//				{
			//					CountNum = tempValue;
			//				}
			//			}
			//			else if (intSerialFirstLimit > intSerialSecondLimit)
			//			{
			//				int tempValue = CountNum-intSerialStep;
			//				if (tempValue < intSerialSecondLimit)
			//				{
			//					CountNum = tempValue - intSerialSecondLimit + intSerialFirstLimit + 1; //'���ڶ����޵ļ��㹫ʽ
			//				} 
			//				else
			//				{
			//					CountNum = tempValue;
			//				}
			//			}
			//		}	

			//		string StrSerialText = "";
			//		string strTemp = "";
			//		switch(bytSerialFormat)
			//		{
			//		case 0:
			//			for (int a = 0; a < intSerialDigits; a++)
			//			{
			//				strTemp = strTemp+"0";//123456789
			//			}
			//			strTemp = strTemp+OBJ_Control::to_String(CountNum);
			//			StrSerialText = strTemp.substr(strTemp.length()-intSerialDigits,intSerialDigits);
			//			break;
			//		case 1:
			//			for (int a = 0; a < intSerialDigits; a++)
			//			{
			//				strTemp = strTemp+" ";//123456789
			//			}
			//			strTemp = strTemp +OBJ_Control::to_String(CountNum);
			//			StrSerialText = strTemp.substr(strTemp.length()-intSerialDigits,intSerialDigits);
			//			break;
			//		case 2:
			//			strTemp = OBJ_Control::to_String(CountNum);
			//			int n = intSerialDigits-strTemp.length();
			//			for (int a = 0; a < n; a++)
			//			{
			//				strTemp = strTemp+" ";
			//			}
			//			StrSerialText = strTemp;
			//			break;
			//		}
			//		theApp.m_MessagePrint.DynOBJ_Vec[i]->strText = StrSerialText;
			//	}
			//	else if (theApp.m_MessagePrint.DynOBJ_Vec[i]->strType2 == "time")
			//	{
			//		string strTime = theApp.m_MessagePrint.DynOBJ_Vec[i]->strTime;
			//		int booETimeOffSet = theApp.m_MessagePrint.DynOBJ_Vec[i]->booETimeOffSet;
			//		int intTimeOffSet = theApp.m_MessagePrint.DynOBJ_Vec[i]->intTimeOffSet;
			//		int strTimeOffSet = theApp.m_MessagePrint.DynOBJ_Vec[i]->strTimeOffSet;
			//		ModuleMain myModuleMain;
			//		string strText = myModuleMain.TimeFormatToText(myModuleMain.string2CString(strTime),booETimeOffSet,intTimeOffSet,strTimeOffSet);
			//		theApp.m_MessagePrint.DynOBJ_Vec[i]->strText = strText;
			//	}
			//}	
			//***************************���ɴ�ӡ����**********************************//
			for(int j = 0; j < theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec.size(); j++)
			{

				if (theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strType2 == "serial")
				{					 
					int &CountNumRep = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->CountNumRep;
					int &CountNum = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->CountNum;
					int &intSerialStep = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->intSerialStep;
					int &intSerialRepeat = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->intSerialRepeat;
					int &intSerialFirstLimit = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->intSerialFirstLimit;
					int &intSerialSecondLimit = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->intSerialSecondLimit;
					BYTE &bytSerialFormat = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->bytSerialFormat;
					BYTE &intSerialDigits = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->intSerialDigits;
					if (CountNumRep < intSerialRepeat)
						CountNumRep++; 
					else
					{
						CountNumRep = 1;
						if (intSerialFirstLimit < intSerialSecondLimit)
						{
							int tempValue = CountNum+intSerialStep;
							if (tempValue > intSerialSecondLimit)
							{
								CountNum = tempValue - intSerialSecondLimit + intSerialFirstLimit - 1; //'���ڶ����޵ļ��㹫ʽ
							} 
							else
							{
								CountNum = tempValue;
							}
						}
						else if (intSerialFirstLimit > intSerialSecondLimit)
						{
							int tempValue = CountNum-intSerialStep;
							if (tempValue < intSerialSecondLimit)
							{
								CountNum = tempValue - intSerialSecondLimit + intSerialFirstLimit + 1; //'���ڶ����޵ļ��㹫ʽ
							} 
							else
							{
								CountNum = tempValue;
							}
						}
					}	

					string StrSerialText = "";
					string strTemp = "";
					switch(bytSerialFormat)
					{
					case 0:
						for (int a = 0; a < intSerialDigits; a++)
						{
							strTemp = strTemp+"0";//123456789
						}
						strTemp = strTemp+OBJ_Control::to_String(CountNum);
						StrSerialText = strTemp.substr(strTemp.length()-intSerialDigits,intSerialDigits);
						break;
					case 1:
						for (int a = 0; a < intSerialDigits; a++)
						{
							strTemp = strTemp+" ";//123456789
						}
						strTemp = strTemp +OBJ_Control::to_String(CountNum);
						StrSerialText = strTemp.substr(strTemp.length()-intSerialDigits,intSerialDigits);
						break;
					case 2:
						strTemp = OBJ_Control::to_String(CountNum);
						int n = intSerialDigits-strTemp.length();
						for (int a = 0; a < n; a++)
						{
							strTemp = strTemp+" ";
						}
						StrSerialText = strTemp;
						break;
					}
					theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strText = StrSerialText;
				}
				else if (theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strType2 == "time")
				{					 

					string strTime = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strTime;
					int booETimeOffSet = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->booETimeOffSet;
					int intTimeOffSet = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->intTimeOffSet;
					int strTimeOffSet = theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strTimeOffSet;
					ModuleMain myModuleMain;
					string strText = myModuleMain.TimeFormatToText(myModuleMain.string2CString(strTime),booETimeOffSet,intTimeOffSet,strTimeOffSet);
					theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strText = strText;
				}
			}	
			struct zint_symbol *my_symbol;
			int error_number;
			int rotate_angle;
			int generated;
			int batch_mode;
			int mirror_mode;
			char filetype[4];
			int a;

			error_number = 0;
			rotate_angle = 0;
			generated = 0;
			my_symbol = ZBarcode_Create();
			my_symbol->input_mode = UNICODE_MODE;
			int nType;
			//nType = 58;
			nType = theApp.m_MessagePrint.OBJ_Vec[i]->nBarcodeType;
			my_symbol->symbology = nType;
			if(nType == 20 || nType == 8)
				my_symbol->height = 12;	 
			
			int hhh = my_symbol->height;
			my_symbol->scale = 0.5;
			batch_mode = 0;
			mirror_mode = 0;

			std::string strTmp = "";
			//for(int i = 0; i < theApp.m_MessageEdit.DynOBJ_Vec.size(); i++)
			for(int m = 0; m < theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec.size(); m++)
			{
				strTmp += theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[m]->strText;
			}
			theApp.m_MessagePrint.OBJ_Vec[i]->strText = strTmp;
			error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strTmp.c_str(),strTmp.length(),rotate_angle);
			generated = 1;
			//////////////////////////////////////////////////////////////////////////
			memset(theApp.m_MessagePrint.OBJ_Vec[i]->boDotBmp,false,32*255*sizeof(bool));
			a = 0;
			int r, g, b;
			for (int row = 0; row < my_symbol->bitmap_height; row++)
			{
				for (int col = 0;col < my_symbol->bitmap_width; col++)
				{
					r = my_symbol->bitmap[a];
					g = my_symbol->bitmap[a + 1];
					b = my_symbol->bitmap[a + 2];
					a += 3;
					if (r == 0 && g == 0 && b == 0)
					{
						theApp.m_MessagePrint.OBJ_Vec[i]->boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
					}
					else
					{
						theApp.m_MessagePrint.OBJ_Vec[i]->boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
					}
				}
			}
			ZBarcode_Delete(my_symbol);
			theApp.m_MessagePrint.getdot();
			//******************************************************************************//
			int pixel = theApp.m_MessageEdit.Pixel;
			BYTE dotDataLen_l,dotDataLen_h,matrix_name,pixelMes,pixelAll;

			//theApp.ForPreQue = queue<vector<BYTE>>();

			if(theApp.m_MessagePrint.IntMes)
				delete []theApp.m_MessagePrint.IntMes;
			theApp.m_MessagePrint.IntMes = new UINT32[theApp.m_MessagePrint.intRowMax];
			memset(theApp.m_MessagePrint.IntMes,0,sizeof(UINT32)*theApp.m_MessagePrint.intRowMax);

			for (int j = 0; j < 32; j++)
				for (int i = 0; i < theApp.m_MessagePrint.intRowMax; i++)
					theApp.m_MessagePrint.IntMes[i] += ((theApp.m_MessagePrint.boDotMes[j][i])?1:0)*pow(2,j);

			vector<BYTE> bytPrintData = theApp.m_MessagePrint.DotToByte(0,theApp.m_MessagePrint.intRowMax);
			dotDataLen_l = bytPrintData.size()%256; //dotDataLen_l��dotDataLen_h��ͬ����˴�ӡ���ݵĴ�СdotDataLen_h*256+dotDataLen_l
			dotDataLen_h = bytPrintData.size()/256;
			pixelMes = (BYTE)(pixel+1);
			matrix_name = pixelMes<<2;//�Ͷ�λΪģʽ 
			pixelAll = pixelMes|0x80; //��ʾ�����ݼ�ʱ��Ч����ʼ��ӡ����ǰ����������

			theApp.boPrintNowLock.Lock();
			vector<BYTE>().swap(theApp.m_MessagePrint.bytPrintDataAll);//��clear()�ã��ܹ��ͷ��ڴ�  
			vector<BYTE>().swap(theApp.m_MessagePrint.bytPrintDataAllOrder);  

			//Ԥ�ȸ�vector<BYTE>�����С��Ȼ����ʹ�ã�Ч��Ҳ��ߵ㣬�������
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0x1);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0x80);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0x6);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0x1);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0x11);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(matrix_name);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(pixelMes);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(dotDataLen_l);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(dotDataLen_h);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0xff);
			theApp.m_MessagePrint.bytPrintDataAll.push_back(0xff);

			//���²μ�ͨ�Ÿ�ʽ˵��
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x1);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x80);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x6);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x1);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x11);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(matrix_name);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(pixelAll);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(dotDataLen_l);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(dotDataLen_h);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0xff);
			theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0xff);

			bytPrintData.push_back(0xff);
			bytPrintData.push_back(0xff);

			theApp.m_MessagePrint.bytPrintDataAll.insert(theApp.m_MessagePrint.bytPrintDataAll.end(),bytPrintData.begin(),bytPrintData.end());
			theApp.m_MessagePrint.bytPrintDataAllOrder.insert(theApp.m_MessagePrint.bytPrintDataAllOrder.end(),bytPrintData.begin(),bytPrintData.end());
			theApp.m_MessageEdit.bytPrintDataAllOrder.clear();
			theApp.m_MessageEdit.bytPrintDataAllOrder = theApp.m_MessagePrint.bytPrintDataAllOrder;
			theApp.m_MessagePrint.intMesDis = theApp.m_MessagePrint.bytPrintDataAll;
			theApp.m_MessagePrint.boPrintNow = true;		
			theApp.boPrintNowLock.Unlock();
		}
	}	
}