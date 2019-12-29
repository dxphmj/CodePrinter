// FaultDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "FaultDlg.h"
#include <fstream>
#include "CodePrinterDlg.h"

// CFaultDlg �Ի���

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
}


BEGIN_MESSAGE_MAP(CFaultDlg, CDialog)
	ON_BN_CLICKED(IDC_FAULT_CLOSE_BTN, &CFaultDlg::OnBnClickedFaultCloseBtn)
	ON_BN_CLICKED(IDC_BUTTON3, &CFaultDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CFaultDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFaultDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CFaultDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CFaultDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CFaultDlg::OnBnClickedButton5)
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CFaultDlg ��Ϣ�������

BOOL CFaultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_FAULT_CLOSE_BTN)->SetWindowPos(NULL,10,420,80,50,SWP_SHOWWINDOW);

	getAllErrorFile();
	get_error_name();
	CTime localT=CTime::GetCurrentTime(); //ʱ���࣬�Ժ��������������
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
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CFaultDlg::OnBnClickedFaultCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
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
				ifstream fin(szPath);/////Ӧ��ɾ�����ļ�
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
//��ȡ��������
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
		string tempErrName=theApp.myModuleMain.WcharToChar(tempErr.cFileName);
		string errName=tempErrName.substr(0,tempErrName.length()-4);
		strErrorFileNameArr.push_back(errName);
	}

	intErrorFileNameArr=strErrorFileNameArr.size();
}
//��
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
//��
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
//ɾ��
void CFaultDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

//��
void CFaultDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	if (m_errBox->GetCurSel()>0)
	{
		m_errBox->SetCurSel(m_errBox->GetCurSel()-1);
	}
}

//��
void CFaultDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_FAULT_LIST);
	if (m_errBox->GetCurSel()<(m_errBox->GetCount()-1))
	{
		m_errBox->SetCurSel(m_errBox->GetCurSel()+1);
	}
}

//����
void CFaultDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


	///////����ͼƬ�Ժ��
	
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
		//'�˳�ҳ��
		//panError.Location = New Point(900, 0)
		//labForName.Text = tempformname
		//labForMName.Text = tempmname

		//If pangro_gui.Location.X.Equals(0) Then
		//picLogo.Location = New Point(0, 0)
		//panForName.Location = New Point(900, 0)
		//End If
		//'��λ����λ�¡�1��
		theApp.myStatusClass.ctr0X00bit5 = 1;
		//'���á�����inksystem_control00�����ָ�
		theApp.myStatusClass.download_inksystem_control00();
}

void CFaultDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CFaultDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}
