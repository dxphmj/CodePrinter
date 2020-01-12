// CustomStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "CustomStatic.h"


// CCustomStatic

IMPLEMENT_DYNAMIC(CCustomStatic, CStatic)

CCustomStatic::CCustomStatic()
{

}

CCustomStatic::~CCustomStatic()
{
}


BEGIN_MESSAGE_MAP(CCustomStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CCustomStatic ��Ϣ�������



void CCustomStatic::OnPaint()
{
//	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
  	CWnd::Default();   

	CString str;
	this->GetWindowTextW(str);

    CFont* pof;
	CClientDC  dc(this);
	CRect rect;
	this->GetClientRect(&rect); 

	CDC menbm;
	bool b = menbm.CreateCompatibleDC(&dc);
	pof = menbm.SelectObject(theApp.m_StaticFont);
 
	 
	menbm.FillSolidRect(rect,RGB(255,255,255)); //�����ɫ
		 
	menbm.SetTextColor(RGB(0, 0, 0));
	// ͸��
	menbm.SetBkMode(TRANSPARENT);
	// ������
	rect.left += 5;
	menbm.DrawText(str,&rect,DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	b = dc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&menbm,0,0,SRCCOPY);
	menbm.SelectObject(pof); 
	menbm.DeleteDC();      // ɾ���ڴ�DC
}
