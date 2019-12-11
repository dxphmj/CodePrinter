// EditTextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditTextDlg.h"
#include "..\KEYBOARD\KEYBOARD\ExportDlg.h"
#include "ModuleMain.h"
// CEditTextDlg 对话框

IMPLEMENT_DYNAMIC(CEditTextDlg, CDialog)

CEditTextDlg::CEditTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditTextDlg::IDD, pParent)
{

}

CEditTextDlg::~CEditTextDlg()
{
}

void CEditTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, Combo_Font, fontComboBox);
}


BEGIN_MESSAGE_MAP(CEditTextDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITTEXT_CLOSE_BTN, &CEditTextDlg::OnBnClickedEdittextCloseBtn)
	ON_EN_CHANGE(IDC_EDIT1, &CEditTextDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(Combo_Font, &CEditTextDlg::OnCbnSelchangeFont)
	ON_BN_CLICKED(IDC_BUTTON_EDITOK, &CEditTextDlg::OnBnClickedButtonEditok)
END_MESSAGE_MAP()


// CEditTextDlg 消息处理程序

BOOL CEditTextDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	fontComboBox.AddString(_T("5x5"));
	fontComboBox.AddString(_T("7x5"));
	fontComboBox.AddString(_T("12x12"));
	fontComboBox.AddString(_T("16x12"));

	fontComboBox.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEditTextDlg::OnBnClickedEdittextCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

void CEditTextDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	//CEdit* pBoxOne;
	//pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT1);
	//CString str;
	//pBoxOne-> GetWindowText(str);

	//CExportDlg myCExportDlg;
	////CString ts;
	////ts.Format(L"%s",_T("sdfsa"));
	//str=myCExportDlg.GetInputText(str);
 //   pBoxOne-> SetWindowText(str);

}

BOOL CEditTextDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	ASSERT(pEdit && pEdit->GetSafeHwnd());
	if(WM_LBUTTONDOWN == pMsg->message && pEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		//pEdit->SetFocus();
		//pEdit->SetSel(-1);
		CString str;
		pEdit-> GetWindowText(str);

		CExportDlg myCExportDlg;
		//CString ts;
		//ts.Format(L"%s",_T("sdfsa"));
		str=myCExportDlg.GetInputText(str);
		pEdit-> SetWindowText(str);
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CEditTextDlg::OnCbnSelchangeFont()
{
	// TODO: 在此添加控件通知处理程序代码

}

void CEditTextDlg::OnBnClickedButtonEditok()
{
	// TODO: 在此添加控件通知处理程序代码
	ModuleMain fontModule;

	int xPos=0;
	int yPos=0;
	for(int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec.at(i).booFocus)
		{
			theApp.myclassMessage.OBJ_Vec.at(i).booFocus=false;
			yPos=theApp.myclassMessage.OBJ_Vec.at(i).intLineStart;
			xPos=theApp.myclassMessage.OBJ_Vec.at(i).intRowSize+theApp.myclassMessage.OBJ_Vec.at(i).intRowStart;
		}
	}
	OBJ_Control tempObj;
	tempObj.intLineStart=yPos;
	tempObj.intRowStart=xPos;
	tempObj.strType1="text";
	tempObj.strType2="text";
	//以下先写死
	tempObj.intSW=1;
	tempObj.intSS=0;
	tempObj.booNEG=false;
	tempObj.booBWDx=false;
	tempObj.booBWDy=false;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString strText;
	pEdit-> GetWindowText(strText);
	tempObj.strText=fontModule.WcharToChar(strText);
	CString  fontText;
	int nIndex = fontComboBox.GetCurSel();  //当前选中的项
	switch(nIndex)
	{
	case 0:
		tempObj.intLineSize=5;
		tempObj.intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 1:
		tempObj.intLineSize=7;
		tempObj.intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 2:
		tempObj.intLineSize=12;
		tempObj.intRowSize=strText.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 3:
		tempObj.intLineSize=16;
		tempObj.intRowSize=strText.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	}
	fontComboBox.GetLBText(nIndex,fontText);
	tempObj.strFont=fontModule.WcharToChar(fontText);



	tempObj.booFocus=true;
	theApp.myclassMessage.OBJ_Vec.push_back(tempObj);
}
