#include "StdAfx.h"
#include "BMPShow.h"


IMPLEMENT_DYNAMIC(CDesignStatic, CStatic)

CDesignStatic::CDesignStatic()
{

}

CDesignStatic::~CDesignStatic()
{
}

BEGIN_MESSAGE_MAP(CDesignStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CDesignStatic ��Ϣ�������
void CDesignStatic::OnPaint()
{
	CWnd::Default();   // �ÿؼ������Լ��Ķ���
	CClientDC  dc(this);

	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//��ȡ������Ϣ
	bitmapTemp.CreateCompatibleBitmap(pDC, 255, 32);//�����ڴ�λͼ
	dcMem.CreateCompatibleDC(pDC); //��������DC�������ݵ�DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//���ڴ�λͼѡ���ڴ�dc
	dcMem.SelectObject(&bitmapTemp);
	
	//�����ɫ
	GetClientRect(&rectClient);
	CRect bitRect=rectClient;
	//bitRect.right=255;
	//bitRect.top=32;
	dcMem.FillSolidRect(bitRect,RGB(210, 231, 251));   //�����ɫ
	CBrush cbrush;
	CBrush* pBrush; //�ɱ�ˢ
	//����
	//CPen cBPen; 
	//cBPen.CreatePen(PS_SOLID,1,RGB(0,0,0)); 
	//CPen cWPen; 
	//cWPen.CreatePen(PS_SOLID,1,RGB(255,255,255)); 
	//CPen* pOldPen; 
	for (int i=0;i<bmpvec.size();i++)
	{
		for(int j=0;j<bmpvec[i].size();j++)
		{
			if (bmpvec[i][j])
			{
				//pOldPen = dcMem.SelectObject(&cBPen); //�����ˢ
				dcMem.SetPixel(bitRect.left+i,bitRect.top+j,RGB(0,0,0));
			} 
			else
			{
				dcMem.SetPixel(bitRect.left+i,bitRect.top+j,RGB(255,255,255));
			}
		}
	}

	//pDC->BitBlt(0,0,255,32,&dcMem,0,0,SRCCOPY);//����ͼƬ����dc
	pDC->StretchBlt(0,0,510,64,&dcMem,0,0,255,32,SRCCOPY);
	dcMem.DeleteDC();      // ɾ���ڴ�DC
	bitmapTemp.DeleteObject();      // ɾ���ڴ�λͼ
	ReleaseDC(pDC); 




}
