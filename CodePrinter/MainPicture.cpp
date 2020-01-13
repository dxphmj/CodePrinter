// MainPicture.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "MainPicture.h"


// MainPicture

IMPLEMENT_DYNAMIC(MainPicture, CStatic)

MainPicture::MainPicture()
{

}

MainPicture::~MainPicture()
{
}


BEGIN_MESSAGE_MAP(MainPicture, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// MainPicture 消息处理程序



void MainPicture::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	CWnd::Default();   // 让控件画它自己的东西
	CClientDC  dc(this);
	//////////////////////////////////////////////////////////////////////////
	int pixSize=4;

	////
	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//获取窗口信息
	bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	dcMem.SelectObject(&bitmapTemp);
	//填充颜色
	GetClientRect(&rectClient);
	CRect drawRect=rectClient;
	drawRect.top=rectClient.top+(32-theApp.mainPicPixel)*pixSize;
	CRect bkRect=rectClient;
	bkRect.bottom=(32-theApp.mainPicPixel)*pixSize;
	dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	dcMem.FillSolidRect(drawRect,RGB(255,255,255));   //填充颜色

	CBrush cbrush;
	CBrush cwrush;
	CBrush *pBrush; //旧笔刷
	cbrush.CreateSolidBrush(RGB(0,0,0)); 
	cwrush.CreateSolidBrush(RGB(255,255,255));
	//int pixel = theApp.myclassMessage.Pixel+1;
	if(1)
	{
		//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=rectClient.Width();)//竖
		{
			dcMem.MoveTo(i,rectClient.Height()-pixSize*theApp.mainPicPixel-1);
			dcMem.LineTo(i,rectClient.Height());
			i+=pixSize;
		}
		for (int j=rectClient.Height()-pixSize*theApp.mainPicPixel-1;j<=rectClient.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(rectClient.Width(),j);
			j+=pixSize;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();
		//isFrame=false;
	}
	///theApp.myclassMessage.DrawDot(&dcMem);

	//int recSize=4;
	for (int ni=0;ni<theApp.myclassMessage.OBJ_Vec.size();ni++)
	{
		if (theApp.myclassMessage.OBJ_Vec[ni].strType2!="serial"&&theApp.myclassMessage.OBJ_Vec[ni].strType2!="time")
		{
			for (int i=theApp.myclassMessage.OBJ_Vec[ni].intLineStart;i<(theApp.myclassMessage.OBJ_Vec[ni].intLineSize+theApp.myclassMessage.OBJ_Vec[ni].intLineStart);i++)
			{
				for (int j=theApp.myclassMessage.OBJ_Vec[ni].intRowStart;j<(theApp.myclassMessage.OBJ_Vec[ni].intRowSize+theApp.myclassMessage.OBJ_Vec[ni].intRowStart);j++)
				{
					if (theApp.myclassMessage.boDotMes[i][j])
					{
						int tx=j*pixSize+1;
						int ty=129-(i+1)*pixSize;
						int bx=(j+1)*pixSize;
						int by=129-i*pixSize-1;
						pBrush=dcMem.SelectObject(&cbrush);
						dcMem.Rectangle(tx,ty,bx,by);
					}
				}
			}
		}
	}
	//if (!theApp.myclassMessage.boDynamic)
	//{
	//	//for (int i=0;i<(theApp.myclassMessage.Pixel+1);i++)
	//	for (int i=0;i<theApp.mainPicPixel;i++)
	//	{
	//		for (int j=0;j<theApp.myclassMessage.intRowMax;j++)
	//		{
	//			if (theApp.myclassMessage.boDotMes[i][j])
	//			{
	//				int tx=j*pixSize+1;
	//				int ty=129-(i+1)*pixSize;
	//				int bx=(j+1)*pixSize;
	//				int by=129-i*pixSize-1;
	//				pBrush=dcMem.SelectObject(&cbrush);
	//				dcMem.Rectangle(tx,ty,bx,by);
	//			}
	//		}
	//	}
	//}

	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, 0, 0, SRCCOPY);//绘制图片到主dc
	//dcMem.SelectObject(pOldBitmap);//清理
	dcMem.DeleteDC();      // 删除内存DC
	bitmapTemp.DeleteObject();      // 删除内存位图
	//theApp.myclassMessage.DrawDot(pDC);

	ReleaseDC(pDC); 
}

UINT methoddis(LPVOID pParam)
{
	structMP *pstructMP=(structMP *)pParam;
	CClientDC  dc(pstructMP->myMainPicture);
	//////////////////////////////////////////////////////////////////////////
	int pixSize=4;

	////
	CDC* pDC = &dc;
	////目前不用双重缓存
	//CRect rectClient;
	//CDC dcMem,dcBkgnd;
	//CBitmap bitmapTemp;//, *pOldBitmap;
	////GetClientRect(&rectClient);//获取窗口信息
	//bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//创建内存位图
	//dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	////pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	//dcMem.SelectObject(&bitmapTemp);

	CBrush cbrushB;//黑笔
	CBrush cbrushW;//白笔
	CBrush* pBrush; //旧笔刷					
	cbrushB.CreateSolidBrush(RGB(0,0,0)); 
	cbrushW.CreateSolidBrush(RGB(255,255,255));
	pDC->SelectStockObject(NULL_PEN);
	//绘制
	//pBrush=pDC->SelectObject(&cbrushB);
	//for(int sw=0;sw<intSW;sw++)
	//{
	//	CRect rect((intRowStart+bmpWidth-i-1)*5+1,161-(intLineStart+bmpHeight-j)*5-1+1,(intRowStart+bmpWidth-i)*5,161-(intLineStart+bmpHeight-j-1)*5-1);
	//	pDC->Ellipse(&rect);
	//}




	while(theApp.mythreadDynamicBoo)
	{
		while(theApp.boDrawMainPic)
		{
			vector<BYTE> intMesDis1=theApp.myclassMessage.intMesDis;
			for (int j=0;j<theApp.myclassMessage.bytSerialConCoundis;j++)
			{
				int intDynamicRowEnd = theApp.myclassMessage.intQSerialRowStartdis[j] + theApp.myclassMessage.intQSerialRowSizedis[j] - 1;
				if (theApp.myclassMessage.matrixMesdis!=14)
				{
					if (theApp.myclassMessage.pixelMesdis<8)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + theApp.myclassMessage.intDotMesRowdis - tmptInt],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + theApp.myclassMessage.intDotMesRowdis - tmptInt],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11+k],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11+k],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					} 
					else if (theApp.myclassMessage.pixelMesdis>7&&theApp.myclassMessage.pixelMesdis<16)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * k] + (intMesDis1[11 + 2 * k + 1] * pow(2 , 8)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * k] + (intMesDis1[11 + 2 * k + 1] * pow(2 , 8)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					}
					else if (theApp.myclassMessage.pixelMesdis>15&&theApp.myclassMessage.pixelMesdis<24)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 3 * k] + (intMesDis1[11 + 3 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 3 * k + 2] * pow(2 , 16)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 3 * k] + (intMesDis1[11 + 3 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 3 * k + 2] * pow(2 , 16)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					}
					else if (theApp.myclassMessage.pixelMesdis>23)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 3] *pow (2 , 24))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 3] *pow (2 , 24))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 4 * k] + (intMesDis1[11 + 4 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 4 * k + 2] * pow(2 , 16))+ (intMesDis1[11 + 4 * k + 3] * pow(2 , 24)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 4 * k] + (intMesDis1[11 + 4 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 4 * k + 2] * pow(2 , 16))+ (intMesDis1[11 + 4 * k + 3] * pow(2 , 24)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										////AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					}

				} 
				else
				{
					int tmptInt=intDynamicRowEnd;
					for (int k=theApp.myclassMessage.intQSerialStartValue[j];k<=intDynamicRowEnd;k++)
					{
						BYTE tempByte1= intMesDis1[k * 2 + 11];
						BYTE tempByte2 = intMesDis1[k * 2 + 11 + 1];

						if (theApp.myModuleMain.MesDisIsB(tempByte1,0))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,31*pixSize+1,(k+1)*pixSize,(32)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,1))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-8)*pixSize+1,(k+1)*pixSize,(32-8)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,2))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-1)*pixSize+1,(k+1)*pixSize,(32-1)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,3))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-9)*pixSize+1,(k+1)*pixSize,(32-9)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,4))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-2)*pixSize+1,(k+1)*pixSize,(32-2)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,5))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-10)*pixSize+1,(k+1)*pixSize,(32-11)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,6))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-3)*pixSize+1,(k+1)*pixSize,(32-3)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,7))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-11)*pixSize+1,(k+1)*pixSize,(32-11)*pixSize);
						Sleep(1);


						if (theApp.myModuleMain.MesDisIsB(tempByte2,0))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-4)*pixSize+1,(k+1)*pixSize,(32-4)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,1))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-12)*pixSize+1,(k+1)*pixSize,(32-12)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,2))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-5)*pixSize+1,(k+1)*pixSize,(32-5)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,3))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-13)*pixSize+1,(k+1)*pixSize,(32-13)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,4))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-6)*pixSize+1,(k+1)*pixSize,(32-6)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,5))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-14)*pixSize+1,(k+1)*pixSize,(32-14)*pixSize);
						Sleep(1);

					}

				}
			}
		}
	}

	//删除
	pBrush = pDC->SelectObject(&cbrushB); //载入笔刷
	pDC->SelectObject(pBrush); //恢复笔刷
	cbrushB.DeleteObject();
	cbrushW.DeleteObject();
	pBrush->DeleteObject();
	return 0;
}