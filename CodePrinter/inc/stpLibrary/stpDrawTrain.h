/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpUDPSocket.h
*	�ļ���ʶ: �������ƽ̨��������ʵ�ֻ��г������ͷ�ļ�
*	ժҪ��
*		�������Ҫ������:
*		 1.��װ��С��������Ƕȵ���·�����еĹ��ܡ�
*		 2.ͨ���ӿڿ��Ըı�С�������ȡ���ͷ��˳��ȵȳ���ģ�Ͳ����Ĺ���
*		 3.����Ԥ��С����Ҫ���е���·������ÿһ���߶εĳ��ȿ�������Ļ����û�й�ϵ��
*	��ǰ�汾��1.0
*	�� �ߣ���ΰ
*	������ڣ�2009-6-20
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*///////////////////////////////////////////////////////////////////////

#ifndef _FILE_STP_DRAW_TRAIN_H__
#define _FILE_STP_DRAW_TRAIN_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//----------------------����ͷ�ļ�-----------------------------------------
#include "stpDefine.h"

//----------------------�궨��-----------------------------------------
//�����붨��
#define STP_DRAW_TRAIN_ERR_SUCCESS						0				//�ɹ�
#define STP_DRAW_TRAIN_ERR_UNKNOWN							0xffff0200		//δ֪����
#define STP_DRAW_TRAIN_ERR_INLEGAL_SEGMENT_SET				0xffff0201		//�߶μ��Ƿ��������ܱ�֤�߶μ����߶ε���β���
#define STP_DRAW_TRAIN_ERR_INLEGAL_DISTANCE					0xffff0202		//����Ƿ�
#define STP_DRAW_TRAIN_ERR_INLEGAL_DC						0xffff0203		//DC�Ƿ�

//�ؼ���������
#define STP_DARW_TRAIN_MAX_POINTS_COUNT					50				//������������һ���������Ҫ�������						
#define STP_DARW_TRAIN_MAX_SEGMENTS_COUNT				200				//������������һ�������ͬʱ���ص��߶�����						

//----------------------�ṹ�嶨��-----------------------------------------
//�߶�ģ��Segment��һ����·���������Ǳ�Link��DSU������������С��һ����·��һ��Link�����Ƕ�Σ�����һ�Σ�
//Segment������һ��Segment������һ��LinkҲ������Link���е�һ���֡�Link�Ķ˵�����ǵ���㡢����㡢��·�նˣ�
//Segment�Ķ˵����Link�����ж˵��⻹������Ϊ�˻�ͼ�ÿ�����֤б�߶εĽǶȣ�����һ��Link�ֳ����߶ζ�����Ĺյ�
typedef struct DRAW_TRAIN_SEGMENT_STRUCT 
{
	POINT ptStart;//���
	POINT ptEnd;//�յ�
	DWORD dwStartPosition;//��㹫��꣬��λ��cm��Ԥ����
	DWORD dwEndPosition;//�յ㹫��꣬��λ��cm��Ԥ����
	DWORD dwDistance;//�߶ε������ȣ�����ʼ�ն˼�ľ��룩����λ��cm
	int nSegmentIndex;//��ǰSegment��Segment�����еı��
} DrawTrainSegment, *pDrawTrainSegment;

//�߶μ��ϣ���������һ�����߶�
typedef struct DRAW_TRAIN_SEGMENT_SET_STRUCT
{
	int nTotalSegments;//�߶θ���
	DrawTrainSegment stSegmentInfo[STP_DARW_TRAIN_MAX_SEGMENTS_COUNT];//�߶���Ϣ�������ڴ����������Ҫ��
																	  //��һ����·���յ�����Ǳ�����·�����
} DrawTrainSegmentSet, *pDrawTrainSegmentSet;

//�г�ģ�Ͳ���
typedef struct DRAW_TRAIN_MODEL_STRUCT
{
	DWORD dwTotalLength;//�����ܳ��ȡ������ȣ�������������ʾ����λ��cm
	int nSemiWidth;//�����������ʾ�Ŀ�ȣ����������޹�
	BOOL boHeadDirection;//��ͷ�з������ڿ��Ƴ�ͷ����ʾʱ�Ǽ�ͷ��ʾ����ƽͷ��ʾ
	BOOL boTailDirection;//��β�з������ڿ��Ƴ�β����ʾʱ�Ǽ�ͷ��ʾ����ƽͷ��ʾ
	int nHeadOrTailLength;//��ͷ���߳�β�ĳ��ȣ������ȣ�������������ʾ����λ��cm
} DrawTrainModel, *pDrawTrainModel;

//����ʱ�õ�����ת����
typedef struct DRAW_TRAIN_TEMP_STRUCT
{
	//��Ҫ�����ĸ���    ÿ�����������߶α�� + ������߶����ƫ������������

	//��β          ���
	int nTailSegmentIndex;//��β��˵����ڵ��߶εı�� 
	double dfTailOffset;//��β��˾�����߶�����ƫ���������Ϊ100%����СΪ0%

	//BodyTail      ����㵱���ڼ��ʱ���ڳ���  ������ʱ���ڳ�β
	int nBodyTailSegmentIndex;
	double dfBodyTailOffset;//���Ϊ100%����СΪ0%
	//BodyHead		����㵱���ڼ��ʱ���ڳ���  ������ʱ���ڳ�ͷ
	int nBodyHeadSegmentIndex;
	double dfBodyHeadOffset;//���Ϊ100%����СΪ0%

	//��ͷ          ���
	int nHeadSegmentIndex;//��ͷ��˵����ڵ��߶εı�� 
	double dfHeadOffset;//��ͷ��˾�����߶�����ƫ���������Ϊ100%����СΪ0%

} DrawTrainTempInfo, *pDrawTrainTempInfo;//����С��ʱ�õ�����ʱ�ṹ��

//����ʱ�õ�����ת����
typedef struct DRAW_TRAIN_STRUCT{
	POINT ptTrainPoint[STP_DARW_TRAIN_MAX_POINTS_COUNT];//Ҫ��ʾ����Ҫ�ĵ���
	DWORD ptTrainPointPosition[STP_DARW_TRAIN_MAX_POINTS_COUNT];//ÿ����Ĺ���꣬��λ��cm
	int nValidPointCount;//Ҫ��ʾ���õ�����Ч�ĵ���
} DrawTrainInfo,  *pDrawTrainInfo;//����С��ʱ�õ��Ľṹ��

class AFX_EXT_CLASS CstpDrawTrain  
{
public:
	/*
	����ԭ��:CstpDrawTrain(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		���캯������ɱ�Ҫ�ı�����ʼ��
	����ֵ:��
	*/	
	CstpDrawTrain(void);

	/*
	����ԭ��:virtual ~CstpDrawTrain(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		������������Ҫ�Ŀռ���Դ���ͷ�
	����ֵ:��
	*/		
	virtual ~CstpDrawTrain(void);

	/*
	����ԭ��:DWORD InitTrain(DrawTrainSegmentSet IN *pstSegmentSet, DrawTrainModel IN *pstTrainModel)
	����˵��:
		DrawTrainSegmentSet IN *pstSegmentSet			�г��������е��߶μ���
		DrawTrainModel IN *pstTrainModel				�г���ģ�Ͳ���
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ʼ����·ģ�ͺ��г�ģ�ͣ����ڽ��������г�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/	
	DWORD InitTrain(DrawTrainSegmentSet IN *pstSegmentSet, DrawTrainModel IN *pstTrainModel);

	/*
	����ԭ��:DWORD DrawTrain(CDC IN *pDC, DWORD IN dwCurRunDistance)
	����˵��:
		CDC IN *pDC										��Ҫ����ͼ��ʹ�õ�CDC��
		DWORD IN dwCurRunDistance						��β��ǰλ�þ�����·ģ�ͼ����е�һ���߶�����������룬��λΪcm
	ʹ�õ���ȫ�ֱ�����
	��������:
		ʹ��ָ��DC��ָ��λ�û����г�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/	
	DWORD DrawTrain(CDC IN *pDC, DWORD IN dwCurRunDistance);

	/*
	����ԭ��:BOOL PtInTrain(POINT IN pt)
	����˵��:
		POINT IN pt			ĳ���������
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ж�ĳ�����Ƿ����г���Χ��
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/	
	BOOL PtInTrain(POINT IN pt);

	/*
	����ԭ��:BOOL PtInTrain(POINT IN pt)
	����˵��:
		int IN nX			��ĺ�����
		int IN nY			���������
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ж�ĳ�����Ƿ����г���Χ��
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/	
	BOOL PtInTrain(int IN nX, int IN nY);


	DWORD dwSumRunDistance;//�ۼ����о��룬���ǳ��߹��ľ��룬���߶μ��������һ�����ն�Ϊ��㡣����ֵΪ0ʱ����βλ��
						   //��һ���߶ε���㡣	
private:

	//˽�г�Ա����
	
	/*
	����ԭ��:DWORD GetLengthOfTwoPts(POINT IN *pPtA,POINT IN *pPtB)
	����˵��:
		POINT IN *pPtA									A��λ��ָ��
		POINT IN *pPtB									B��λ��ָ��
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡA���B��֮��ĳ��ȣ���Ļ�ϵľ���
	����ֵ:
		��Ļ��A���B��֮��ľ���
	*/	
	DWORD GetLengthOfTwoPts(POINT IN *pPtA,POINT IN *pPtB);

	/*
	����ԭ��:void GetSegmentIndexAndOffset(DWORD IN dwDistance, int OUT *pnSegmentIndex, double OUT *pdfOffset)
	����˵��:
		DWORD IN dwDistance								��ǰ�ʵ������·�������ܾ��롣
		int OUT *pnSegmentIndex							��ǰ�ʵ����ڵ��߶α��
		double OUT *pdfOffset							��ǰ�ʵ���������߶�����ƫ���������Ϊ100%����СΪ0%
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ�����뵱ǰ�ʵ������·�������ܾ����ȡ��ǰ�ʵ����ڵ��߶α�ź�ƫ����
	����ֵ:
		��
	*/	
	void GetSegmentIndexAndOffset(DWORD IN dwDistance, int OUT *pnSegmentIndex, double OUT *pdfOffset);

	/*
	����ԭ��:void GetJiaoPingFenXianPoint(DWORD IN dwDistance,
		POINT IN *pPtLine1Start, CPoint IN *pPtCenter, POINT IN *pPtLine2End, 
		POINT OUT *pPtUp, POINT OUT *pPtDown)
	����˵��:
		DWORD IN dwDistance								��ƽ�����Ͼ������ĵ�ľ��룬��Ļ�ϵľ���
		POINT IN *pPtLine1Start							�߶�һ�����
		POINT IN *pPtCenter								�߶�һ���߶ζ��Ľ��㣬�����ĵ�
		POINT IN *pPtLine2End							�߶�һ���յ�
		POINT OUT *pPtUp								ֱ��һ������γɵļнǽ�ƽ������
														�������ĵ㳤��ΪdwDistace�Ĵ��������һ���㣬���з�����
		POINT OUT *pPtDown								ֱ��һ������γɵļнǽ�ƽ������
														�������ĵ㳤��ΪdwDistace�Ĵ��������һ���㣬���з�����
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ�����������㣬��ֱ��һ��һ�㣨������Ϊ��㣩��ֱ�߶���һ�㣨������Ϊ�յ㣩��ֱ��һ����Ľ��㣨������Ϊ���ĵ㣩��
		��ֱ��һ������γɵļнǽ�ƽ�����Ͼ������ĵ㳤��ΪdwDistace�������㣨Up���Down�㣩��
	����ֵ:
		��
	*/	
	void GetJiaoPingFenXianPoint(DWORD IN dwDistance,
		POINT IN *pPtLine1Start, POINT IN *pPtCenter, POINT IN *pPtLine2End, 
		POINT OUT *pPtUp, POINT OUT *pPtDown);

	/*
	����ԭ��:void GetCertainPoint(double IN dfOffset, POINT IN *pPtStart, POINT IN *pPtEnd,
		POINT OUT *pPtCertain)
	����˵��:
		double IN dfOffset								�߶��Ͼ�������ƫ���������Ϊ100%����СΪ0%
		POINT IN *pPtStart								�߶ε����
		POINT IN *pPtEnd								�߶ε��յ�
		POINT OUT *pPtCertain							�߶��Ͼ�����㳤��ΪdwDistance�ĵ�
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ�������߶ε�����յ㣬�߶��Ͼ�����㳤��ΪdwDistance�ĵ��������
	����ֵ:
		��
	*/	
	void GetCertainPoint(double IN dfOffset, POINT IN *pPtStart, POINT IN *pPtEnd,
		POINT OUT *pPtCertain);

	/*
	����ԭ��:void GetJiaoPingFenXianPoint(DWORD IN dwDistance,
		POINT IN *pPtLine1Start, CPoint IN *pPtCenter, POINT IN *pPtLine2End, 
		POINT OUT *pPtUp, POINT OUT *pPtDown)
	����˵��:
		DWORD IN dwDistance								�߶δ����Ͼ������ĵ�ľ���
		POINT IN *pPtStart								�߶ε����
		POINT IN *pPtEnd								�߶ε��յ�
		POINT IN *pPtCenter								�߶��ϵ��ض���
		POINT OUT *pPtUp								�߶εĴ����Ͼ����߶����ض��㳤��ΪdwDistace����
														�����һ���㣬���з�����
		POINT OUT *pPtDown								�߶εĴ����Ͼ����߶����ض��㳤��ΪdwDistace����
														�����һ���㣬���з�����
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ����������������һ���߶Σ����߶εĴ����Ͼ����߶����ض��㳤��ΪdwDistace�������㣨Up���Down�㣩��
	����ֵ:
		��
	*/	
	void GetUpDownPoint_of_Line(DWORD IN dwDistance, POINT IN *pPtStart, POINT IN *pPtEnd,
		POINT IN *pPtCertain, POINT OUT *pPtUp, POINT OUT *pPtDown);

	/*
	����ԭ��:void GetTrainSegmentIndex(DWORD IN dwCurDistance)
	����˵��:
		DWORD IN dwCurDistance									��ǰ��β������·�������ܾ��롣��λ��cm�������ȣ��������޹�
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ�����뵱ǰ��β������·�������ܾ�����㵱ǰ�����г�ʱHead��Tail��BodyHead��BodyTail���ڵ��߶α�ź�ƫ����
	����ֵ:
		��
	*/	
	void GetTrainSegmentIndex(DWORD IN dwCurDistance);

	//��Ա����
	DrawTrainSegmentSet m_stSegmentSet;//�߶μ��ϣ��洢�г���Ҫ�õ����߶μ�
	DrawTrainModel m_stTrainModel;//�г�ģ��
	DrawTrainTempInfo m_stDrawTrainTempInfo;//�����г�ʱ�õ�����Ϣ
	DrawTrainInfo m_stDrawTrainInfo;//�����г�ʱ�õ���������Ϣ
	DWORD m_pdwSegmentTotalLength[STP_DARW_TRAIN_MAX_SEGMENTS_COUNT];//ĩ���߶ξ����߶μ������ܳ���
};


#endif // !defined(AFX_STPDRAWLIBRARY_H__7A134B45_0496_4E29_A27A_5AC24D19DB33__INCLUDED_)
