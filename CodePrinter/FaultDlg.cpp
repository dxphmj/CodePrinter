// FaultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "FaultDlg.h"
#include <fstream>
#include "CodePrinterDlg.h"

// CFaultDlg 对话框

IMPLEMENT_DYNAMIC(CFaultDlg, CDialog)

CFaultDlg::CFaultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFaultDlg::IDD, pParent)
{

}

CFaultDlg::~CFaultDlg()
{
}

void CFaultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_FAULT_LIST,m_faultList);

	DDX_Control(pDX, IDC_FAULT_CLOSE_BTN, m_pReturn);
	DDX_Control(pDX,IDC_L_HISTORY_BTN,m_LHistory);
	DDX_Control(pDX,IDC_R_HISTORY_BTN,m_RHistory);
	DDX_Control(pDX,IDC_REFRESH_BTN,m_refresh);
	DDX_Control(pDX, IDC_DELETE_BTN, m_delete);
	DDX_Control(pDX,IDC_NEXT_BTN,m_next);
	DDX_Control(pDX, IDC_BEFORE_BTN, m_before);
}


BEGIN_MESSAGE_MAP(CFaultDlg, CDialog)
	ON_BN_CLICKED(IDC_FAULT_CLOSE_BTN, &CFaultDlg::OnBnClickedFaultCloseBtn)
	ON_BN_CLICKED(IDC_DELETE_BTN, &CFaultDlg::OnBnClickedDeleteBtn)
	ON_BN_CLICKED(IDC_BEFORE_BTN, &CFaultDlg::OnBnClickedBeforeBtn)
	ON_BN_CLICKED(IDC_NEXT_BTN, &CFaultDlg::OnBnClickedNextBtn)
	ON_BN_CLICKED(IDC_REFRESH_BTN, &CFaultDlg::OnBnClickedRefreshBtn)
	ON_BN_CLICKED(IDC_L_HISTORY_BTN, &CFaultDlg::OnBnClickedLHistoryBtn)
	ON_BN_CLICKED(IDC_R_HISTORY_BTN, &CFaultDlg::OnBnClickedRHistoryBtn)
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CFaultDlg 消息处理程序

BOOL CFaultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_FAULT_CLOSE_BTN)->SetWindowPos(NULL,10,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BEFORE_BTN)->SetWindowPos(NULL,710,80,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_NEXT_BTN)->SetWindowPos(NULL,710,160,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DELETE_BTN)->SetWindowPos(NULL,700,320,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_REFRESH_BTN)->SetWindowPos(NULL,700,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_R_HISTORY_BTN)->SetWindowPos(NULL,580,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_L_HISTORY_BTN)->SetWindowPos(NULL,460,420,80,55,SWP_SHOWWINDOW);

	GetDlgItem(IDC_FAULT_LIST)->SetWindowPos(NULL,21,65,670,330,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DATE_STATIC)->SetWindowPos(NULL,21, 42,200, 20,SWP_SHOWWINDOW);
	GetDlgItem(IDC_TIME_STATIC)->SetWindowPos(NULL,124, 42,200, 20,SWP_SHOWWINDOW);
	GetDlgItem(IDC_TYPE_STATIC)->SetWindowPos(NULL,229, 42,200, 20,SWP_SHOWWINDOW);
	GetDlgItem(IDC_MESSAGE_STATIC)->SetWindowPos(NULL,321, 42,200, 20,SWP_SHOWWINDOW);

	m_pReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_pReturn.SizeToContent(); 
	m_LHistory.LoadBitmaps(IDB_L_HISTORY1_BITMAP,IDB_L_HISTORY2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_LHistory.SizeToContent(); 
	m_RHistory.LoadBitmaps(IDB_R_HISTORY1_BITMAP,IDB_R_HISTORY1_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_RHistory.SizeToContent(); 
	m_refresh.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_refresh.SizeToContent(); 
	m_delete.LoadBitmaps(IDB_DELETE1_BITMAP,IDB_DELETE2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_delete.SizeToContent(); 
	m_next.LoadBitmaps(IDB_NEXT1_BITMAP,IDB_NEXT2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_next.SizeToContent(); 
	m_before.LoadBitmaps(IDB_BEFORE1_BITMAP,IDB_BEFORE2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_before.SizeToContent(); 

	getAllErrorFile();
	get_error_name();
	CTime localT=CTime::GetCurrentTime(); //时间类，以后日期用这个！！
	string timeErr="Storage Card\\System\\Error\\";
	Errorlog_name=theApp.myclassMessage.to_String(localT.GetYear())+theApp.myclassMessage.to_String(localT.GetMonth())+theApp.myclassMessage.to_String(localT.GetDay());
	timeErr=timeErr+Errorlog_name+".txt";
	ofstream timeErrout(timeErr.c_str(), ios::app);
	timeErrout.close();
	ofstream out99("Storage Card\\System\\Error\\99999999.TXT", ios::app);
	out99.close();
	nowErrDay=0;

 
	//openfailurefile("Storage Card\\System\\Error\\99999999.TXT");
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CFaultDlg::OnBnClickedFaultCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(m_strPreOperation); 
}
bool comp(const WIN32_FIND_DATA &a, const WIN32_FIND_DATA &b){return a.cFileName<b.cFileName;}
void CFaultDlg::getAllErrorFile()
{
	vector<WIN32_FIND_DATA> allErrVec;
	vector<WIN32_FIND_DATA> detErrVec;
	CString szCurDir=_T("Storage Card\\System\\Error\\");
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA wfd;
	BOOL bRet;
	TCHAR szPath[MAX_PATH];

	lstrcpy(szPath, szCurDir);
	if(szPath[lstrlen(szCurDir)-1] != _T('\\'))
		lstrcat(szPath, _T("\\"));
	lstrcat(szPath, _T("*.*"));

	hFind = FindFirstFile(szPath, &wfd);
	bRet = ((hFind == INVALID_HANDLE_VALUE) ? FALSE : TRUE);
	while(bRet)
	{
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				//FindClose(hFind);
				lstrcpy(szPath, szCurDir);
				lstrcat(szPath,wfd.cFileName);
				RemoveDirectory(szPath);
			}
		}
		else //if(wfd.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				//FindClose(hFind);
				lstrcpy(szPath, szCurDir);
				lstrcat(szPath,wfd.cFileName);
				ifstream fin(szPath);/////应该删除空文件
				if(!fin)
				{
					continue;;
				}
				string c;
				fin >> c;
				if(c.empty())
				{
					fin.close();
					detErrVec.push_back(wfd);
					bRet = FindNextFile(hFind, &wfd);
					continue;
				}
				fin.close();
				allErrVec.push_back(wfd);
			}
		}
		bRet = FindNextFile(hFind, &wfd);
	}
	FindClose(hFind);

	sort(allErrVec.begin(),allErrVec.end(),comp);
	for (int i=0;i<detErrVec.size();i++)
	{
		WIN32_FIND_DATA tempDet=detErrVec.at(i);
		lstrcpy(szPath, szCurDir);
		lstrcat(szPath,tempDet.cFileName);
		int tsttt=DeleteFile(szPath);
		tsttt=GetLastError();
	}
	if (allErrVec.size()>32)
	{
		for (vector<WIN32_FIND_DATA>::iterator iterTemp=allErrVec.begin()+31;iterTemp!=allErrVec.end();iterTemp++)
		{
			lstrcpy(szPath, szCurDir);
			lstrcat(szPath,iterTemp->cFileName);
			int tsttt=DeleteFile(szPath);
			tsttt=GetLastError();
		}
	}
}
//获取所有名字
void CFaultDlg::get_error_name()
{
	vector<WIN32_FIND_DATA> allErrVec;
	CString szCurDir=_T("Storage Card\\System\\Error\\");
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA wfd;
	BOOL bRet;
	TCHAR szPath[MAX_PATH];

	lstrcpy(szPath, szCurDir);
	if(szPath[lstrlen(szCurDir)-1] != _T('\\'))
		lstrcat(szPath, _T("\\"));
	lstrcat(szPath, _T("*.*"));

	hFind = FindFirstFile(szPath, &wfd);
	bRet = ((hFind == INVALID_HANDLE_VALUE) ? FALSE : TRUE);
	while(bRet)
	{
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				//FindClose(hFind);
				lstrcpy(szPath, szCurDir);
				lstrcat(szPath,wfd.cFileName);
				RemoveDirectory(szPath);
			}
		}
		else //if(wfd.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				//FindClose(hFind);
				lstrcpy(szPath, szCurDir);
				lstrcat(szPath,wfd.cFileName);
				allErrVec.push_back(wfd);
			}
		}
		bRet = FindNextFile(hFind, &wfd);
	}
	FindClose(hFind);

	sort(allErrVec.begin(),allErrVec.end(),comp);
	
	for (int i=0;i<allErrVec.size();i++)
	{
		WIN32_FIND_DATA tempErr=allErrVec.at(i);
		string tempErrName=theApp.myModuleMain.CString2string(tempErr.cFileName);
		string errName=tempErrName.substr(0,tempErrName.length()-4);
		strErrorFileNameArr.push_back(errName);
	}

	intErrorFileNameArr=strErrorFileNameArr.size();
}
//存
void CFaultDlg::get_save_error()
{
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	if (m_errBox->GetCount()>0)
	{
		string timeErr="Storage Card\\System\\Error\\";
		timeErr=timeErr+Errorlog_name+".txt";
		ofstream outErr99("Storage Card\\System\\Error\\99999999.TXT", ios::trunc);
		ofstream outErrNow(timeErr.c_str(), ios::trunc);
		for (int i=0;i<m_errBox->GetCount();i++)
		{
			CString s;
			m_errBox->GetText(i,s);
			string sss= CT2A(s.GetString());
			outErr99<<sss<<endl;
			outErrNow<<sss<<endl;
		}
		outErr99.close();
		outErrNow.close();
		m_errBox->ResetContent();
	}

}
//打开
void CFaultDlg::openfailurefile(string filePathName)
{
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	//m_errBox->ResetContent();
	ifstream fin;
	fin.open(theApp.myModuleMain.stringToLPCWSTR(filePathName));
	string str;
	while (getline(fin, str))
	{
		//getline(fin, str);
		m_errBox->AddString(theApp.myModuleMain.stringToLPCWSTR(str));
	}
	fin.close();
}
//删除
void CFaultDlg::OnBnClickedDeleteBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	if (m_errBox->GetCount()==0)
	{
		return;
	}
	if (m_errBox->GetCurSel()<0||m_errBox->GetCurSel()>=m_errBox->GetCount())
	{
		return;
	}
	//m_errBox->DeleteString(m_errBox->GetCurSel());
	if (m_errBox->GetCurSel()==(m_errBox->GetCount()-1))
	{
		m_errBox->DeleteString(m_errBox->GetCurSel());
		m_errBox->SetCurSel(m_errBox->GetCount()-1);
	} 
	else
	{
		int nowCur=m_errBox->GetCurSel();
		m_errBox->DeleteString(nowCur);
		m_errBox->SetCurSel(nowCur+1);
	}
	string timeErr="Storage Card\\System\\Error\\";
	timeErr=timeErr+Errorlog_name+".txt";
	ofstream outErrNow(timeErr.c_str(), ios::trunc);
	for (int i=0;i<m_errBox->GetCount();i++)
	{
		CString s;
		m_errBox->GetText(i,s);
		string sss= CT2A(s.GetString());
		outErrNow<<sss<<endl;
	}
	outErrNow.close();
}

//上
void CFaultDlg::OnBnClickedBeforeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	if (m_errBox->GetCurSel()>0)
	{
		m_errBox->SetCurSel(m_errBox->GetCurSel()-1);
	}
}

//下
void CFaultDlg::OnBnClickedNextBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	if (m_errBox->GetCurSel()<(m_errBox->GetCount()-1))
	{
		m_errBox->SetCurSel(m_errBox->GetCurSel()+1);
	}
}

//重置
void CFaultDlg::OnBnClickedRefreshBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	m_errBox->ResetContent();
	//get_save_error();
	ofstream outErr99("Storage Card\\System\\Error\\99999999.TXT", ios::trunc);
	outErr99.close();

		//picAlarmBlue.Tag = "im004"
		//picAlarmBlue.Image = My.Resources.ResourceBng.im004
		//picAlarmYellow.Tag = "im006"
		//picAlarmYellow.Image = My.Resources.ResourceBng.im006
		//picAlarmRed.Tag = "im008"
		//picAlarmRed.Image = My.Resources.ResourceBng.im008
		//btnError.Tag = "im015"
		//btnError.Image = My.Resources.ResourceBng.im015
     
	((CCodePrinterDlg*)GetParent())->m_PicHead.ResetAlarm(); 


	///////以上图片以后加
	
		theApp.myTimClass.staComFau = false;
		theApp.myTimClass.staSolLevFauLas = "00";
		theApp.myTimClass.staInkLevFauLas = "00";
		theApp.myStatusClass.staInkTemSenFauLas = false;
		theApp.myStatusClass.staPriHeaTemFauLas = false;
		theApp.myStatusClass.staBumSpeOveFauLas = false;
		theApp.myStatusClass.staPreOveFauLas = false;
		theApp.myStatusClass.staVisAbnFauLas = false;
		theApp.myStatusClass.staVisSenFauLas = false;
		theApp.myStatusClass.staInkFloFauLas = false;
		theApp.myStatusClass.staFanFauLas = false;
		theApp.myStatusClass.staChaFauLas = false;
		theApp.myStatusClass.staPhaFauLas = false;
		theApp.myStatusClass.staHigVolFauLas = false;
		//' staBufOveFauLas = False
		theApp.myStatusClass.staProSenFasLas = false;
		theApp.myStatusClass.staAutModFauLas = false;
		theApp.myStatusClass.staValFauLas = false;
		theApp.myStatusClass.staLinFasLas = false;
		theApp.myStatusClass.staPriHeaHotFauLas = false;
		//'  staBufOveFauLas = False
		//'退出页面
		//panError.Location = New Point(900, 0)
		//labForName.Text = tempformname
		//labForMName.Text = tempmname

		//If pangro_gui.Location.X.Equals(0) Then
		//picLogo.Location = New Point(0, 0)
		//panForName.Location = New Point(900, 0)
		//End If
		//'下位机复位致“1”
		theApp.myStatusClass.ctr0X00bit5 = 1;
		//'调用“计算inksystem_control00并添加指令”
		theApp.myStatusClass.download_inksystem_control00();
}

void CFaultDlg::OnBnClickedLHistoryBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	if (nowErrDay<(strErrorFileNameArr.size()-1))
	{
		//CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
		//m_errBox->ResetContent();
		nowErrDay++;
		string timeErr="Storage Card\\System\\Error\\";
		timeErr=timeErr+strErrorFileNameArr.at(nowErrDay)+".txt";
		openfailurefile(timeErr);
	}
}

void CFaultDlg::OnBnClickedRHistoryBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	if (nowErrDay>0)
	{
		//CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
		//m_errBox->ResetContent();
		nowErrDay--;
		string timeErr="Storage Card\\System\\Error\\";
		timeErr=timeErr+strErrorFileNameArr.at(nowErrDay)+".txt";
		openfailurefile(timeErr);
	}
}


HBRUSH CFaultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
