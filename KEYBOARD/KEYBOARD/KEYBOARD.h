// KEYBOARD.h : KEYBOARD DLL 的主头文件
//
//
#pragma once
#include "Resource.h"
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"

// CKEYBOARDApp
// 有关此类实现的信息，请参阅 KEYBOARD.cpp
//



class  CKEYBOARDApp : public CWinApp
{
public:
	CKEYBOARDApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
public:
	//void dlgShow();
};
