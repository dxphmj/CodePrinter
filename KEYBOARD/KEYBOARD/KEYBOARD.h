// KEYBOARD.h : KEYBOARD DLL ����ͷ�ļ�
//
//
#pragma once
#include "Resource.h"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"

// CKEYBOARDApp
// �йش���ʵ�ֵ���Ϣ������� KEYBOARD.cpp
//



class  CKEYBOARDApp : public CWinApp
{
public:
	CKEYBOARDApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
public:
	//void dlgShow();
};
