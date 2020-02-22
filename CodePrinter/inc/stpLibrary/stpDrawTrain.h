/*
*	Copyright 2009,
*	All rights reserved.
*	
*	文件名称：stpUDPSocket.h
*	文件标识: 仿真测试平台函数库中实现画列车的类的头文件
*	摘要：
*		此类的主要功能有:
*		 1.封装了小车在任意角度的线路上运行的功能。
*		 2.通过接口可以改变小车车身长度、车头尖端长度等车辆模型参数的功能
*		 3.可以预置小车将要运行的线路。并且每一段线段的长度可以与屏幕比例没有关系。
*	当前版本：1.0
*	作 者：王伟
*	完成日期：2009-6-20
*
*	取代版本：
*	作 者：
*	完成日期：
*///////////////////////////////////////////////////////////////////////

#ifndef _FILE_STP_DRAW_TRAIN_H__
#define _FILE_STP_DRAW_TRAIN_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//----------------------包含头文件-----------------------------------------
#include "stpDefine.h"

//----------------------宏定义-----------------------------------------
//错误码定义
#define STP_DRAW_TRAIN_ERR_SUCCESS						0				//成功
#define STP_DRAW_TRAIN_ERR_UNKNOWN							0xffff0200		//未知错误
#define STP_DRAW_TRAIN_ERR_INLEGAL_SEGMENT_SET				0xffff0201		//线段集非法，即不能保证线段集中线段的首尾相接
#define STP_DRAW_TRAIN_ERR_INLEGAL_DISTANCE					0xffff0202		//距离非法
#define STP_DRAW_TRAIN_ERR_INLEGAL_DC						0xffff0203		//DC非法

//关键参数定义
#define STP_DARW_TRAIN_MAX_POINTS_COUNT					50				//画车类中描述一辆车最多需要点的数量						
#define STP_DARW_TRAIN_MAX_SEGMENTS_COUNT				200				//画车类中描述一辆车最多同时加载的线段数量						

//----------------------结构体定义-----------------------------------------
//线段模型Segment，一段线路。物理上是比Link（DSU当中描述）更小的一段线路。一段Link可以是多段（或者一段）
//Segment，但是一段Segment可以是一条Link也可以是Link当中的一部分。Link的端点可以是道岔点、计轴点、线路终端，
//Segment的端点除了Link的所有端点外还可以是为了画图好看（保证斜线段的角度）而把一条Link分成折线段而引入的拐点
typedef struct DRAW_TRAIN_SEGMENT_STRUCT 
{
	POINT ptStart;//起点
	POINT ptEnd;//终点
	DWORD dwStartPosition;//起点公里标，单位是cm。预留用
	DWORD dwEndPosition;//终点公里标，单位是cm。预留用
	DWORD dwDistance;//线段的物理长度（区段始终端间的距离），单位是cm
	int nSegmentIndex;//当前Segment在Segment集合中的编号
} DrawTrainSegment, *pDrawTrainSegment;

//线段集合，用于描述一整条线段
typedef struct DRAW_TRAIN_SEGMENT_SET_STRUCT
{
	int nTotalSegments;//线段个数
	DrawTrainSegment stSegmentInfo[STP_DARW_TRAIN_MAX_SEGMENTS_COUNT];//线段信息描述，在此数组里必须要求
																	  //上一条线路的终点必须是本条线路的起点
} DrawTrainSegmentSet, *pDrawTrainSegmentSet;

//列车模型参数
typedef struct DRAW_TRAIN_MODEL_STRUCT
{
	DWORD dwTotalLength;//车辆总长度。物理长度，不考虑像素显示，单位是cm
	int nSemiWidth;//车半宽，像素显示的宽度，与物理长度无关
	BOOL boHeadDirection;//车头有方向，用于控制车头在显示时是尖头显示还是平头显示
	BOOL boTailDirection;//车尾有方向，用于控制车尾在显示时是尖头显示还是平头显示
	int nHeadOrTailLength;//车头或者车尾的长度，物理长度，不考虑像素显示，单位是cm
} DrawTrainModel, *pDrawTrainModel;

//画车时用到的中转类型
typedef struct DRAW_TRAIN_TEMP_STRUCT
{
	//需要描述四个点    每个点以所在线段编号 + 距离该线段起点偏移量即可描述

	//车尾          尖端
	int nTailSegmentIndex;//车尾尖端的所在的线段的编号 
	double dfTailOffset;//车尾尖端距离该线段起点的偏移量，最大为100%，最小为0%

	//BodyTail      这个点当存在尖端时属于车身  不存在时属于车尾
	int nBodyTailSegmentIndex;
	double dfBodyTailOffset;//最大为100%，最小为0%
	//BodyHead		这个点当存在尖端时属于车身  不存在时属于车头
	int nBodyHeadSegmentIndex;
	double dfBodyHeadOffset;//最大为100%，最小为0%

	//车头          尖端
	int nHeadSegmentIndex;//车头尖端的所在的线段的编号 
	double dfHeadOffset;//车头尖端距离该线段起点的偏移量，最大为100%，最小为0%

} DrawTrainTempInfo, *pDrawTrainTempInfo;//绘制小车时用到的临时结构体

//画车时用到的中转类型
typedef struct DRAW_TRAIN_STRUCT{
	POINT ptTrainPoint[STP_DARW_TRAIN_MAX_POINTS_COUNT];//要表示车需要的点数
	DWORD ptTrainPointPosition[STP_DARW_TRAIN_MAX_POINTS_COUNT];//每个点的公里标，单位是cm
	int nValidPointCount;//要表示车用到的有效的点数
} DrawTrainInfo,  *pDrawTrainInfo;//绘制小车时用到的结构体

class AFX_EXT_CLASS CstpDrawTrain  
{
public:
	/*
	函数原型:CstpDrawTrain(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		构造函数，完成必要的变量初始化
	返回值:无
	*/	
	CstpDrawTrain(void);

	/*
	函数原型:virtual ~CstpDrawTrain(void)
	参数说明:
	使用到的全局变量：
	功能描述:
		析构函数，必要的空间资源的释放
	返回值:无
	*/		
	virtual ~CstpDrawTrain(void);

	/*
	函数原型:DWORD InitTrain(DrawTrainSegmentSet IN *pstSegmentSet, DrawTrainModel IN *pstTrainModel)
	参数说明:
		DrawTrainSegmentSet IN *pstSegmentSet			列车即将运行的线段集合
		DrawTrainModel IN *pstTrainModel				列车的模型参数
	使用到的全局变量：
	功能描述:
		初始化线路模型和列车模型，便于将来绘制列车
	返回值:
		成功返回0，失败返回错误码。
	*/	
	DWORD InitTrain(DrawTrainSegmentSet IN *pstSegmentSet, DrawTrainModel IN *pstTrainModel);

	/*
	函数原型:DWORD DrawTrain(CDC IN *pDC, DWORD IN dwCurRunDistance)
	参数说明:
		CDC IN *pDC										将要绘制图形使用的CDC类
		DWORD IN dwCurRunDistance						车尾当前位置距离线路模型集合中第一条线段起点的物理距离，单位为cm
	使用到的全局变量：
	功能描述:
		使用指定DC在指定位置绘制列车
	返回值:
		成功返回0，失败返回错误码。
	*/	
	DWORD DrawTrain(CDC IN *pDC, DWORD IN dwCurRunDistance);

	/*
	函数原型:BOOL PtInTrain(POINT IN pt)
	参数说明:
		POINT IN pt			某个点的坐标
	使用到的全局变量：
	功能描述:
		判断某个点是否在列车范围内
	返回值:
		成功返回0，失败返回错误码。
	*/	
	BOOL PtInTrain(POINT IN pt);

	/*
	函数原型:BOOL PtInTrain(POINT IN pt)
	参数说明:
		int IN nX			点的横坐标
		int IN nY			点的纵坐标
	使用到的全局变量：
	功能描述:
		判断某个点是否在列车范围内
	返回值:
		成功返回0，失败返回错误码。
	*/	
	BOOL PtInTrain(int IN nX, int IN nY);


	DWORD dwSumRunDistance;//累计运行距离，就是车走过的距离，以线段集合中最后一条的终端为零点。当此值为0时，车尾位于
						   //第一条线段的起点。	
private:

	//私有成员函数
	
	/*
	函数原型:DWORD GetLengthOfTwoPts(POINT IN *pPtA,POINT IN *pPtB)
	参数说明:
		POINT IN *pPtA									A点位置指针
		POINT IN *pPtB									B点位置指针
	使用到的全局变量：
	功能描述:
		获取A点和B点之间的长度，屏幕上的距离
	返回值:
		屏幕上A点和B点之间的距离
	*/	
	DWORD GetLengthOfTwoPts(POINT IN *pPtA,POINT IN *pPtB);

	/*
	函数原型:void GetSegmentIndexAndOffset(DWORD IN dwDistance, int OUT *pnSegmentIndex, double OUT *pdfOffset)
	参数说明:
		DWORD IN dwDistance								当前质点距离线路集起点的总距离。
		int OUT *pnSegmentIndex							当前质点所在的线段编号
		double OUT *pdfOffset							当前质点距离所在线段起点的偏移量，最大为100%，最小为0%
	使用到的全局变量：
	功能描述:
		通过输入当前质点距离线路集起点的总距离获取当前质点所在的线段编号和偏移量
	返回值:
		无
	*/	
	void GetSegmentIndexAndOffset(DWORD IN dwDistance, int OUT *pnSegmentIndex, double OUT *pdfOffset);

	/*
	函数原型:void GetJiaoPingFenXianPoint(DWORD IN dwDistance,
		POINT IN *pPtLine1Start, CPoint IN *pPtCenter, POINT IN *pPtLine2End, 
		POINT OUT *pPtUp, POINT OUT *pPtDown)
	参数说明:
		DWORD IN dwDistance								角平分线上距离中心点的距离，屏幕上的距离
		POINT IN *pPtLine1Start							线段一的起点
		POINT IN *pPtCenter								线段一与线段二的交点，即中心点
		POINT IN *pPtLine2End							线段一的终点
		POINT OUT *pPtUp								直线一与二所形成的夹角角平分线上
														距离中心点长度为dwDistace的处于上面的一个点，具有方向性
		POINT OUT *pPtDown								直线一与二所形成的夹角角平分线上
														距离中心点长度为dwDistace的处于下面的一个点，具有方向性
	使用到的全局变量：
	功能描述:
		通过输入三个点，即直线一的一点（不妨称为起点）、直线二的一点（不妨称为终点）和直线一与二的交点（不妨称为中心点），
		求直线一与二所形成的夹角角平分线上距离中心点长度为dwDistace的两个点（Up点和Down点）。
	返回值:
		无
	*/	
	void GetJiaoPingFenXianPoint(DWORD IN dwDistance,
		POINT IN *pPtLine1Start, POINT IN *pPtCenter, POINT IN *pPtLine2End, 
		POINT OUT *pPtUp, POINT OUT *pPtDown);

	/*
	函数原型:void GetCertainPoint(double IN dfOffset, POINT IN *pPtStart, POINT IN *pPtEnd,
		POINT OUT *pPtCertain)
	参数说明:
		double IN dfOffset								线段上距离起点的偏移量，最大为100%，最小为0%
		POINT IN *pPtStart								线段的起点
		POINT IN *pPtEnd								线段的终点
		POINT OUT *pPtCertain							线段上距离起点长度为dwDistance的点
	使用到的全局变量：
	功能描述:
		通过输入线段的起点终点，线段上距离起点长度为dwDistance的点的描述。
	返回值:
		无
	*/	
	void GetCertainPoint(double IN dfOffset, POINT IN *pPtStart, POINT IN *pPtEnd,
		POINT OUT *pPtCertain);

	/*
	函数原型:void GetJiaoPingFenXianPoint(DWORD IN dwDistance,
		POINT IN *pPtLine1Start, CPoint IN *pPtCenter, POINT IN *pPtLine2End, 
		POINT OUT *pPtUp, POINT OUT *pPtDown)
	参数说明:
		DWORD IN dwDistance								线段垂线上距离中心点的距离
		POINT IN *pPtStart								线段的起点
		POINT IN *pPtEnd								线段的终点
		POINT IN *pPtCenter								线段上的特定点
		POINT OUT *pPtUp								线段的垂线上距离线段上特定点长度为dwDistace处于
														上面的一个点，具有方向性
		POINT OUT *pPtDown								线段的垂线上距离线段上特定点长度为dwDistace处于
														下面的一个点，具有方向性
	使用到的全局变量：
	功能描述:
		通过输入两个点描述一条线段，求线段的垂线上距离线段上特定点长度为dwDistace的两个点（Up点和Down点）。
	返回值:
		无
	*/	
	void GetUpDownPoint_of_Line(DWORD IN dwDistance, POINT IN *pPtStart, POINT IN *pPtEnd,
		POINT IN *pPtCertain, POINT OUT *pPtUp, POINT OUT *pPtDown);

	/*
	函数原型:void GetTrainSegmentIndex(DWORD IN dwCurDistance)
	参数说明:
		DWORD IN dwCurDistance									当前车尾距离线路集起点的总距离。单位是cm，物理长度，与像素无关
	使用到的全局变量：
	功能描述:
		通过输入当前车尾距离线路集起点的总距离计算当前描述列车时Head、Tail、BodyHead、BodyTail所在的线段编号和偏移量
	返回值:
		无
	*/	
	void GetTrainSegmentIndex(DWORD IN dwCurDistance);

	//成员变量
	DrawTrainSegmentSet m_stSegmentSet;//线段集合，存储列车将要用到的线段集
	DrawTrainModel m_stTrainModel;//列车模型
	DrawTrainTempInfo m_stDrawTrainTempInfo;//绘制列车时用到的信息
	DrawTrainInfo m_stDrawTrainInfo;//绘制列车时用到的最终信息
	DWORD m_pdwSegmentTotalLength[STP_DARW_TRAIN_MAX_SEGMENTS_COUNT];//末端线段距离线段集起点的总长度
};


#endif // !defined(AFX_STPDRAWLIBRARY_H__7A134B45_0496_4E29_A27A_5AC24D19DB33__INCLUDED_)
