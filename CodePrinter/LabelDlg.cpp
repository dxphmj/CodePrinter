// LabelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "LabelDlg.h"
#include "InputDlg.h"
#include <sstream>
#include <map>
#include "..\KEYBOARD\KEYBOARD\MainDlg.h"


LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}


std::string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP)
{
	std::string str;
	int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
	char	*m_char = new char[len + 1];
	WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	str = m_char;
	delete m_char;
	return str;
}

IMPLEMENT_DYNAMIC(CLabelDlg, CDialog)

CLabelDlg::CLabelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelDlg::IDD, pParent)
{

}

CLabelDlg::~CLabelDlg()
{
}

void CLabelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MATRIX, ComboMatrix);
	DDX_Control(pDX, IDC_COMBO2, pixelComboBox);
	DDX_Control(pDX, IDC_STATIC_DESIGN_AREA, m_designArea);
}


BEGIN_MESSAGE_MAP(CLabelDlg, CDialog)
	ON_BN_CLICKED(IDC_INPUT_BUTTON, &CLabelDlg::OnBnClickedInputButton)

	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO_MATRIX, &CLabelDlg::OnCbnSelchangeComboMatrix)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CLabelDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_USHIFT_BUTTON, &CLabelDlg::OnBnClickedUshiftButton)
	ON_BN_CLICKED(IDC_LSELECT_BUTTON, &CLabelDlg::OnBnClickedLselectButton)
	ON_BN_CLICKED(IDC_RSELECT_BUTTON, &CLabelDlg::OnBnClickedRselectButton)
	ON_BN_CLICKED(IDC_DSHIFT_BUTTON, &CLabelDlg::OnBnClickedDshiftButton)
	ON_BN_CLICKED(IDC_LSHIFT_BUTTON, &CLabelDlg::OnBnClickedLshiftButton)
	ON_BN_CLICKED(IDC_RSHIFT_BUTTON, &CLabelDlg::OnBnClickedRshiftButton)
	ON_BN_CLICKED(IDC_LQSHIFT_BUTTON, &CLabelDlg::OnBnClickedLqshiftButton)
	ON_BN_CLICKED(IDC_RQSHIFT_BUTTON, &CLabelDlg::OnBnClickedRqshiftButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CLabelDlg::OnBnClickedSaveButton)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CLabelDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_REPEAT_BUTTON, &CLabelDlg::OnBnClickedRepeatButton)
END_MESSAGE_MAP()


// CLabelDlg 消息处理程序

BOOL CLabelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    isFrame=false;
	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	//为矩阵组合框添加元素
	//combo_matrix.SetDroppedWidth(10);  //改变下拉列表下的宽度 
	ComboMatrix.AddString(_T("1L5M"));
	ComboMatrix.AddString(_T("1L7M"));
	ComboMatrix.AddString(_T("1L9M"));
	ComboMatrix.AddString(_T("1L12M"));
	ComboMatrix.AddString(_T("1L19M"));
	ComboMatrix.AddString(_T("1L25M"));
	ComboMatrix.AddString(_T("2L7M"));
	ComboMatrix.SetCurSel(-1);

    m_designArea.SetWindowPos(NULL,-1,-1,781,161, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);//781, 161


	//test

	OBJ_Control myOBJ_Control;
	myOBJ_Control.intLineSize=7;
	myOBJ_Control.intRowSize=18;
	myOBJ_Control.strFont="7x5";
	myOBJ_Control.strText="ABf";
	myOBJ_Control.booFocus=false;
	myclassMessage.OBJ_Vec.push_back(myOBJ_Control);
	OBJ_Control myNewOBJ;
	myNewOBJ.intLineStart=0;
	myNewOBJ.intRowStart=18;
	myNewOBJ.intLineSize=7;
	myNewOBJ.intRowSize=18;
	myNewOBJ.strFont="7x5";
	myNewOBJ.strText="987";
	myclassMessage.OBJ_Vec.push_back(myNewOBJ);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CLabelDlg::OnBnClickedInputButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CInputDlg Input;
	Input.DoModal();
}



void CLabelDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	CDC* pDC = m_designArea.GetDC();
	//先清除打印预览内容
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	CRect rect;
	m_designArea.GetClientRect(&rect);
	cbrush.CreateSolidBrush(RGB(255,255,255)); 
	pBrush=pDC->SelectObject(&cbrush); //载入笔刷
	pDC->Rectangle(&rect); //绘制矩形		
	pDC->SelectObject(pBrush); //恢复笔刷
	cbrush.DeleteObject();
	pBrush->DeleteObject();
	if(isFrame)
	{//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = pDC->SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=rect.Width();)//竖
		{
			pDC->MoveTo(i,rect.Height()-5*pixel-1);
			pDC->LineTo(i,rect.Height());
            i+=5;
		}
        for (int j=rect.Height()-5*pixel-1;j<=rect.Height();)
        {
			pDC->MoveTo(0,j);
			pDC->LineTo(rect.Width(),j);
			j+=5;
        }
		pDC->SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();
		//isFrame=false;
	}


	if(m_bDesign)
	{
		//绘制设计结果
		//m_PrintObjectsDeal.DrawObjects(pDC,m_nStepPixels);
	}
	else
	{		 
		//CPen cPen; 
		//cPen.CreatePen(PS_SOLID,1,RGB(252,157,154)); 
		//CPen* pOldPen; 
		//pOldPen = pDC->SelectObject(&cPen); //载入笔刷

		//for(int i = 0; i < m_nRowSum; i++)
		//{
		//	pDC->MoveTo(0,i*m_nStepPixels);
		//	pDC->LineTo(m_nStepPixels*m_nColSum,i*m_nStepPixels);
		//}
		//for(int i = 0; i < m_nColSum; i++)
		//{
		//	pDC->MoveTo(i*m_nStepPixels,0);
		//	pDC->LineTo(i*m_nStepPixels,m_nStepPixels*m_nRowSum);
		//}
		//pDC->SelectObject(pOldPen);
		//cPen.DeleteObject();
		//pOldPen->DeleteObject();

		//CBrush cbrush;
		//CBrush* pBrush; //旧笔刷	
		//cbrush.CreateSolidBrush(RGB(0,0,0)); 
		//pBrush = pDC->SelectObject(&cbrush); //载入笔刷

		//for(int i = 0; i < m_nRowSum; i++)
		//	for(int j = 0; j < m_nColSum; j++)
		//		DrawOnePoint(pDC,i,j);

		//pDC->SelectObject(pBrush); //恢复笔刷
		//cbrush.DeleteObject();
		//pBrush->DeleteObject();
	}

	myclassMessage.DrowDot(pDC);

	//myOBJ_Control.DrowDot(pDC);
	//myOBJ_Control.DrawFrame(pDC);
	ReleaseDC(pDC); 


}

void CLabelDlg::OnCbnSelchangeComboMatrix()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  strText;
	int nIndex = ComboMatrix.GetCurSel();  //当前选中的项
	ComboMatrix.GetLBText(nIndex,strText);
	switch(nIndex)
	{
	case 0:
		matrix = 9;
        pixelComboBox.ResetContent();
		for (int i=1;i<=5;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(4);
        break;

	case 1:
		matrix = 9;
		pixelComboBox.ResetContent();
		for (int i=1;i<=7;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(6);
        break;
	case 2:
		matrix = 9;
		pixelComboBox.ResetContent();
		for (int i=1;i<=9;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(8);
		break;
	case 3:
		matrix = 12;
		pixelComboBox.ResetContent();
		for (int i=1;i<=12;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(11);
		break;
	case 4:
		matrix = 19;
		pixelComboBox.ResetContent();
		for (int i=1;i<=19;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(18);
        break;
	case 5:
		matrix = 25;
		pixelComboBox.ResetContent();
		for (int i=1;i<=25;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(24);
		break;
	case 6:
		matrix = 14;
		pixelComboBox.ResetContent();
		pixelComboBox.AddString(stringToLPCWSTR(myclassMessage.to_String(14)));
        pixelComboBox.SetCurSel(13);

	}
    isFrame=true;
	this->OnCbnSelchangeCombo2();
}

void CLabelDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
    std::stringstream ss;
	CString  strText;
	int nIndex = pixelComboBox.GetCurSel();  //当前选中的项
	pixel=nIndex+1;
	//pixelComboBox.GetLBText(nIndex,strText);
	//ss<<strText;
	//ss>>pixel;
	isFrame=true;
}

void CLabelDlg::OnBnClickedUshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码

	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((myclassMessage.OBJ_Vec[i].intLineStart+myclassMessage.OBJ_Vec[i].intLineSize)>=pixel)
			{
				break;
			}
			myclassMessage.OBJ_Vec[i].intLineStart++;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLselectButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			if (i>0)
			{
				myclassMessage.OBJ_Vec[i].booFocus=false;
				myclassMessage.OBJ_Vec[i-1].booFocus=true;
			}
			else
			{
				break;
			}
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRselectButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			if (i<myclassMessage.OBJ_Vec.size()-1)
			{
				myclassMessage.OBJ_Vec[i].booFocus=false;
				myclassMessage.OBJ_Vec[i+1].booFocus=true;
			}
			else
			{
				break;
			}
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedDshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((myclassMessage.OBJ_Vec[i].intLineStart)<=0)
			{
				break;
			}
			myclassMessage.OBJ_Vec[i].intLineStart--;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((myclassMessage.OBJ_Vec[i].intRowStart)<=0)
			{
				break;
			}
			myclassMessage.OBJ_Vec[i].intRowStart--;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			myclassMessage.OBJ_Vec[i].intRowStart++;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLqshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((myclassMessage.OBJ_Vec[i].intRowStart)<=0)
			{
				break;
			}
			if ((myclassMessage.OBJ_Vec[i].intRowStart)<=1)
			{
				myclassMessage.OBJ_Vec[i].intRowStart--;
				OnPaint();
				break;
			}
			if ((myclassMessage.OBJ_Vec[i].intRowStart)<=2)
			{
				myclassMessage.OBJ_Vec[i].intRowStart=myclassMessage.OBJ_Vec[i].intRowStart-2;
				OnPaint();
				break;
			}
			myclassMessage.OBJ_Vec[i].intRowStart=myclassMessage.OBJ_Vec[i].intRowStart-3;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRqshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<myclassMessage.OBJ_Vec.size();i++)
	{
		if (myclassMessage.OBJ_Vec[i].booFocus)
		{
			myclassMessage.OBJ_Vec[i].intRowStart=myclassMessage.OBJ_Vec[i].intRowStart+3;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedSaveButton()
{
	// TODO: 在此添加控件通知处理程序代码
        
		myclassMessage.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
	
}

void CLabelDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	myclassMessage.ReadObjectsFromXml("\\Storage Card\\user\\Label\\sss.xml");
}

void CLabelDlg::OnBnClickedRepeatButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CMainDlg myCMainDlg;
	myCMainDlg.DoModal();



}
