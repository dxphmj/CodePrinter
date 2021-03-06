#include "StdAfx.h"
#include "Arabicconjunction.h"
#include "CodePrinterDlg.h"

CArabicconjunction::CArabicconjunction(CWnd* pParent)
{

}

CArabicconjunction::~CArabicconjunction(void)
{
}

CString CArabicconjunction::disposeinputtext(CString inputtext)
{
	CCodePrinterDlg* pCodeDlg;
	pCodeDlg = (CCodePrinterDlg*)(m_pCodePrinterDlg);
	int nIndex = pCodeDlg->m_System->pEvn->m_langeageList.GetCurSel();  //当前语言选中的项
	if ( nIndex != 0 )//非阿拉伯
	{
		return inputtext;
	}
	if ( inputtext.Compare(_T("")) == 0 )
	{
		return inputtext;
	}
	//inputtext = _T("شصض");
	map<int,CString>textbyte;	
	for (int i = inputtext.GetLength();i > 0;i--)
	{
		CString cstr =inputtext.Mid(inputtext.GetLength() - i,1);
		CString tempstr = ConvertWCHARToHex(cstr,1);
		//textbyte[inputtext.GetLength() - i] = tempstr;
		textbyte[i-1] = tempstr;
	}//转为十六进制字符串

	CString outputtext = _T("");
	vector<CString>textarray;
	map<int,CString>textarray2;
	vector<CString>textunicodearray;
	vector<CString>arleft;
	map<int,CString>textstring1;
	//bool textbytearrayBoolean[textbyte.size()+2];
	map<int,bool>textbytearrayBoolean;
	for ( int i =0;i < textbyte.size()+2;i++)
	{
		textbytearrayBoolean[i] = false;
	}


	for ( int j = 0;j < textbyte.size();j++)
	{
		if ( ArabicLan(textbyte[j])=="" )
		{
			textbytearrayBoolean[j + 1] = false;
		} 
		else
		{
			textbytearrayBoolean[j + 1] = true;
		}
		textstring1[j] = ArabicLan(textbyte[j]);
	}

	for ( int n = 0;n < textstring1.size();n++ )
	{
		if ( textstring1[n] == "" )//不在变形列表的文字
		{
			CString valueStr = textbyte[n];
			if ( valueStr.Mid(1, 1) == _T("6") || valueStr.Mid(1, 2) == _T("FE") 
				|| valueStr.Mid(1, 3) == _T("FB"))//不在变形列表的阿拉伯文字
			{
				if ( n + 3 == textbyte.size()+2 )//在最后一列
				{
					arleft.push_back(_T("0x") + textbyte[n]);
					//for ( int f = 0;f < arleft.size();f++)
					//{
					//	textarray.push_back(arleft.at(f));
					//	textarray2[n] = arleft.at(f);
					//}
					//arleft.clear();
				}
				else//不在最后一列
				{
					if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )//空格
					{
						arleft.push_back(_T("0x") + textbyte[n]);
						//for ( int f= 0;f < arleft.size();f++)
						//{
						//	textarray.push_back(arleft.at(f));
						//	textarray2[n] = arleft.at(f);
						//}
						//arleft.clear();
					}
					else
					{
						textarray.push_back(_T("0x") + textbyte[n]);//其他文字
						textarray2[textstring1.size()-1-n] = _T("0x") + textbyte[n];
					}
				}
			}
			else//不在变形列表的其他文字
			{
				if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )//空格
				{
					arleft.push_back(_T("0x") + textbyte[n]);
					//for ( int f= 0;f < arleft.size();f++)
					//{
					//	textarray.push_back(arleft.at(f));
					//	textarray2[n] = arleft.at(f);
					//}
					//arleft.clear();
				} 
				else
				{
					textarray.push_back(_T("0x") + textbyte[n]);//其他文字
					textarray2[textstring1.size()-1-n] = _T("0x") + textbyte[n];
				}
			}
		} 
		else//在变形列表
		{
			textunicodearray = split(textstring1[n]);
			if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )
			{
				arleft.push_back(textunicodearray.at(2));
			} 
			else if( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == false)
			{
				if ( n + 3 == textbyte.size()+2 )
				{
					arleft.push_back(textunicodearray.at(1));
					for ( int f= 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));
						textarray2[textstring1.size()-1-n+f] = arleft.at(f);
					}
					arleft.clear();
				} 
				else
				{
					if ( textbytearrayBoolean[n + 3] == true )
					{
						arleft.push_back(textunicodearray.at(1));
						//for ( int f= 0;f < arleft.size();f++)
						//{
						//	textarray.push_back(arleft.at(f));
						//	textarray2[n] = arleft.at(f);
						//}
						//arleft.clear();
					}
					else
					{
						arleft.push_back(textunicodearray.at(1));
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));
							textarray2[textstring1.size()-1-n+f] = arleft.at(f);
						}
						arleft.clear();
					}
				}
			}
			else if ( textbytearrayBoolean[n] == false && textbytearrayBoolean[n + 2] == true )
			{
				arleft.push_back(textunicodearray.at(0));
			}
			else if ( textbytearrayBoolean[n] == false && textbytearrayBoolean[n + 2] == false )
			{
				textarray.push_back(textunicodearray.at(3));
				textarray2[textstring1.size()-1-n] = textunicodearray.at(3);
			}
		}
	}
	//vector<CString>tempVec;
	//for (int k = textarray.size(); k > 0;k-- )
	//{
	//	tempVec.push_back(textarray.at(k-1));//倒置
	//}
	//for ( int m = 0; m < textarray.size();m++)
	//{
	//	outputtext = outputtext + HexStrToCString(textarray[m]);
	//}
	for ( int m = 0; m < textarray2.size();m++)
	{
		outputtext = outputtext + HexStrToCString(textarray2[m]);
	}
	return outputtext;	
}

CString CArabicconjunction::ArabicLan(CString inputstring)
{
	CString outputstring = _T("");
	if (inputstring.Compare(_T("0621")) == 0|| inputstring.Compare(_T("FE80")) == 0 
		||inputstring.Compare(_T("FE80")) == 0 ||inputstring.Compare(_T("FE80")) == 0 ||inputstring.Compare(_T("FE80")) == 0) 
		outputstring = _T("0xFE80, 0xFE80, 0xFE80, 0xFE80");

	else if (inputstring.Compare(_T("0622")) == 0|| inputstring.Compare(_T("FE82")) == 0 
		||inputstring.Compare(_T("FE81")) == 0 ||inputstring.Compare(_T("FE82")) == 0 ||inputstring.Compare(_T("FE81")) == 0)
		outputstring = _T("0xFE82, 0xFE81, 0xFE82, 0xFE81");

	else if (inputstring.Compare(_T("0623")) == 0|| inputstring.Compare(_T("FE84")) == 0 
		||inputstring.Compare(_T("FE83")) == 0 ||inputstring.Compare(_T("FE84")) == 0 ||inputstring.Compare(_T("FE83")) == 0)
		outputstring = _T("0xFE84, 0xFE83, 0xFE84, 0xFE83");


	else if (inputstring.Compare(_T("0624")) == 0|| inputstring.Compare(_T("FE86")) == 0 
		||inputstring.Compare(_T("FE85")) == 0 ||inputstring.Compare(_T("FE86")) == 0 ||inputstring.Compare(_T("FE85")) == 0)
		outputstring = _T("0xFE86, 0xFE85, 0xFE86, 0xFE85");


	else if (inputstring.Compare(_T("0625")) == 0|| inputstring.Compare(_T("FE88")) == 0 
		||inputstring.Compare(_T("FE87")) == 0 ||inputstring.Compare(_T("FE88")) == 0 ||inputstring.Compare(_T("FE87")) == 0)
		outputstring = _T("0xFE88, 0xFE87, 0xFE88, 0xFE87");


	else if (inputstring.Compare(_T("0626")) == 0|| inputstring.Compare(_T("FE8A")) == 0 
		||inputstring.Compare(_T("FE8B")) == 0 ||inputstring.Compare(_T("FE8C")) == 0 ||inputstring.Compare(_T("FE89")) == 0)
		outputstring = _T("0xFE8A, 0xFE8B, 0xFE8C, 0xFE89");


	else if (inputstring.Compare(_T("0627")) == 0|| inputstring.Compare(_T("FE8E")) == 0 
		||inputstring.Compare(_T("FE8D")) == 0 ||inputstring.Compare(_T("FE8E")) == 0 ||inputstring.Compare(_T("FE8D")) == 0)
		outputstring = _T("0xFE8E, 0xFE8D, 0xFE8E, 0xFE8D");


	else if (inputstring.Compare(_T("0628")) == 0|| inputstring.Compare(_T("FE90")) == 0 
		||inputstring.Compare(_T("FE91")) == 0 ||inputstring.Compare(_T("FE92")) == 0 ||inputstring.Compare(_T("FE8F")) == 0)
		outputstring = _T("0xFE90, 0xFE91, 0xFE92, 0xFE8F");


	else if (inputstring.Compare(_T("0629")) == 0|| inputstring.Compare(_T("FE94")) == 0 
		||inputstring.Compare(_T("FE93")) == 0 ||inputstring.Compare(_T("FE94")) == 0 ||inputstring.Compare(_T("FE93")) == 0)
		outputstring = _T("0xFE94, 0xFE93, 0xFE94, 0xFE93");


	else if (inputstring.Compare(_T("062A")) == 0|| inputstring.Compare(_T("FE96")) == 0 
		||inputstring.Compare(_T("FE97")) == 0 ||inputstring.Compare(_T("FE98")) == 0 ||inputstring.Compare(_T("FE95")) == 0)
		outputstring = _T("0xFE96, 0xFE97, 0xFE98, 0xFE95");

	else if (inputstring.Compare(_T("062B")) == 0|| inputstring.Compare(_T("FE9A")) == 0 
		||inputstring.Compare(_T("FE9B")) == 0 ||inputstring.Compare(_T("FE9C")) == 0 ||inputstring.Compare(_T("FE99")) == 0)
		outputstring = _T("0xFE9A, 0xFE9B, 0xFE9C, 0xFE99");


	else if (inputstring.Compare(_T("062C")) == 0|| inputstring.Compare(_T("FE9E")) == 0 
		||inputstring.Compare(_T("FE9F")) == 0 ||inputstring.Compare(_T("FEA0")) == 0 ||inputstring.Compare(_T("FE9D")) == 0)
		outputstring = _T("0xFE9E, 0xFE9F, 0xFEA0, 0xFE9D");


	else if (inputstring.Compare(_T("062D")) == 0|| inputstring.Compare(_T("FEA2")) == 0 
		||inputstring.Compare(_T("FEA3")) == 0 ||inputstring.Compare(_T("FEA4")) == 0 ||inputstring.Compare(_T("FEA1")) == 0)
		outputstring = _T("0xFEA2, 0xFEA3, 0xFEA4, 0xFEA1");


	else if (inputstring.Compare(_T("062E")) == 0|| inputstring.Compare(_T("FEA6")) == 0 
		||inputstring.Compare(_T("FEA7")) == 0 ||inputstring.Compare(_T("FEA8")) == 0 ||inputstring.Compare(_T("FEA5")) == 0)
		outputstring = _T("0xFEA6, 0xFEA7, 0xFEA8, 0xFEA5");


	else if (inputstring.Compare(_T("062F")) == 0|| inputstring.Compare(_T("FEAA")) == 0 
		||inputstring.Compare(_T("FEA9")) == 0 ||inputstring.Compare(_T("FEAA")) == 0 ||inputstring.Compare(_T("FEA9")) == 0)
		outputstring = _T("0xFEAA, 0xFEA9, 0xFEAA, 0xFEA9");


	else if (inputstring.Compare(_T("0630")) == 0|| inputstring.Compare(_T("FEAC")) == 0 
		||inputstring.Compare(_T("FEAB")) == 0 ||inputstring.Compare(_T("FEAC")) == 0 ||inputstring.Compare(_T("FEAB")) == 0)
		outputstring = _T("0xFEAC, 0xFEAB, 0xFEAC, 0xFEAB");


	else if (inputstring.Compare(_T("0631")) == 0|| inputstring.Compare(_T("FEAE")) == 0 
		||inputstring.Compare(_T("FEAD")) == 0 ||inputstring.Compare(_T("FEAE")) == 0 ||inputstring.Compare(_T("FEAD")) == 0)
		outputstring = _T("0xFEAE, 0xFEAD, 0xFEAE, 0xFEAD");


	else if (inputstring.Compare(_T("0632")) == 0|| inputstring.Compare(_T("FEB0")) == 0 
		||inputstring.Compare(_T("FEAF")) == 0 ||inputstring.Compare(_T("FEB0")) == 0 ||inputstring.Compare(_T("FEAF")) == 0)
		outputstring = _T("0xFEB0, 0xFEAF, 0xFEB0, 0xFEAF");


	else if (inputstring.Compare(_T("0633")) == 0|| inputstring.Compare(_T("FEB2")) == 0 
		||inputstring.Compare(_T("FEB3")) == 0 ||inputstring.Compare(_T("FEB4")) == 0 ||inputstring.Compare(_T("FEB1")) == 0 )
		outputstring = _T("0xFEB2, 0xFEB3, 0xFEB4, 0xFEB1");


	else if (inputstring.Compare(_T("0634")) == 0|| inputstring.Compare(_T("FEB6")) == 0 
		||inputstring.Compare(_T("FEB7")) == 0 ||inputstring.Compare(_T("FEB8")) == 0 ||inputstring.Compare(_T("FEB5")) == 0 )
		outputstring = _T("0xFEB6, 0xFEB7, 0xFEB8, 0xFEB5");


	else if (inputstring.Compare(_T("0635")) == 0|| inputstring.Compare(_T("FEBA")) == 0 
		||inputstring.Compare(_T("FEBB")) == 0 ||inputstring.Compare(_T("FEBC")) == 0 ||inputstring.Compare(_T("FEB9")) == 0)
		outputstring = _T("0xFEBA, 0xFEBB, 0xFEBC, 0xFEB9");


	else if (inputstring.Compare(_T("0636")) == 0|| inputstring.Compare(_T("FEBE")) == 0 
		||inputstring.Compare(_T("FEBF")) == 0 ||inputstring.Compare(_T("FEC0")) == 0 ||inputstring.Compare(_T("FEBD")) == 0)
		outputstring = _T("0xFEBE, 0xFEBF, 0xFEC0, 0xFEBD");


	else if (inputstring.Compare(_T("0637")) == 0|| inputstring.Compare(_T("FEC2")) == 0 
		||inputstring.Compare(_T("FEC3")) == 0 ||inputstring.Compare(_T("FEC4")) == 0 ||inputstring.Compare(_T("FEC1")) == 0)
		outputstring = _T("0xFEC2, 0xFEC3, 0xFEC4, 0xFEC1");


	else if (inputstring.Compare(_T("0638")) == 0|| inputstring.Compare(_T("FEC6")) == 0 
		||inputstring.Compare(_T("FEC7")) == 0 ||inputstring.Compare(_T("FEC8")) == 0 ||inputstring.Compare(_T("FEC5")) == 0)
		outputstring = _T("0xFEC6, 0xFEC7, 0xFEC8, 0xFEC5");


	else if (inputstring.Compare(_T("0639")) == 0|| inputstring.Compare(_T("FECA")) == 0 
		||inputstring.Compare(_T("FECB")) == 0 ||inputstring.Compare(_T("FECC")) == 0 ||inputstring.Compare(_T("FEC9")) == 0)
		outputstring = _T("0xFECA, 0xFECB, 0xFECC, 0xFEC9");


	else if (inputstring.Compare(_T("063A")) == 0|| inputstring.Compare(_T("FECE")) == 0 
		||inputstring.Compare(_T("FECF")) == 0 ||inputstring.Compare(_T("FED0")) == 0 ||inputstring.Compare(_T("FECD")) == 0)
		outputstring = _T("0xFECE, 0xFECF, 0xFED0, 0xFECD");


	else if (inputstring.Compare(_T("063B")) == 0|| inputstring.Compare(_T("63B")) == 0 
		||inputstring.Compare(_T("63B")) == 0 ||inputstring.Compare(_T("63B")) == 0 ||inputstring.Compare(_T("63B")) == 0)
		outputstring = _T("0x63B, 0x63B, 0x63B, 0x63B");


	else if (inputstring.Compare(_T("063C")) == 0|| inputstring.Compare(_T("63C")) == 0 
		||inputstring.Compare(_T("63C")) == 0 ||inputstring.Compare(_T("63C")) == 0 ||inputstring.Compare(_T("63C")) == 0)
		outputstring = _T("0x63C, 0x63C, 0x63C, 0x63C");


	else if (inputstring.Compare(_T("063D")) == 0|| inputstring.Compare(_T("63D")) == 0 
		||inputstring.Compare(_T("63D")) == 0 ||inputstring.Compare(_T("63D")) == 0 ||inputstring.Compare(_T("63D")) == 0)
		outputstring = _T("0x63D, 0x63D, 0x63D, 0x63D");


	else if (inputstring.Compare(_T("063E")) == 0|| inputstring.Compare(_T("63E")) == 0 
		||inputstring.Compare(_T("63E")) == 0 ||inputstring.Compare(_T("63E")) == 0 ||inputstring.Compare(_T("63E")) == 0)
		outputstring = _T("0x63E, 0x63E, 0x63E, 0x63E");


	else if (inputstring.Compare(_T("063F")) == 0|| inputstring.Compare(_T("63F")) == 0 
		||inputstring.Compare(_T("63F")) == 0 ||inputstring.Compare(_T("63F")) == 0 ||inputstring.Compare(_T("63F")) == 0)
		outputstring = _T("0x63F, 0x63F, 0x63F, 0x63F");


	else if (inputstring.Compare(_T("0640")) == 0|| inputstring.Compare(_T("640")) == 0 
		||inputstring.Compare(_T("640")) == 0 ||inputstring.Compare(_T("640")) == 0 ||inputstring.Compare(_T("640")) == 0)
		outputstring = _T("0x640, 0x640, 0x640, 0x640");


	else if (inputstring.Compare(_T("0641")) == 0|| inputstring.Compare(_T("FED2")) == 0 
		||inputstring.Compare(_T("FED3")) == 0 ||inputstring.Compare(_T("FED4")) == 0 ||inputstring.Compare(_T("FED1")) == 0)
		outputstring = _T("0xFED2, 0xFED3, 0xFED4, 0xFED1");


	else if (inputstring.Compare(_T("0642")) == 0|| inputstring.Compare(_T("FED6")) == 0 
		||inputstring.Compare(_T("FED7")) == 0 ||inputstring.Compare(_T("FED8")) == 0 ||inputstring.Compare(_T("FED5")) == 0)
		outputstring = _T("0xFED6, 0xFED7, 0xFED8, 0xFED5");


	else if (inputstring.Compare(_T("0643")) == 0|| inputstring.Compare(_T("FEDA")) == 0 
		||inputstring.Compare(_T("FEDB")) == 0 ||inputstring.Compare(_T("FEDC")) == 0 ||inputstring.Compare(_T("FED9")) == 0)
		outputstring = _T("0xFEDA, 0xFEDB, 0xFEDC, 0xFED9");


	else if (inputstring.Compare(_T("0644")) == 0|| inputstring.Compare(_T("FEDE")) == 0 
		||inputstring.Compare(_T("FEDF")) == 0 ||inputstring.Compare(_T("FEE0")) == 0 ||inputstring.Compare(_T("FEDD")) == 0)
		outputstring = _T("0xFEDE, 0xFEDF, 0xFEE0, 0xFEDD");


	else if (inputstring.Compare(_T("0645")) == 0|| inputstring.Compare(_T("FEE2")) == 0 
		||inputstring.Compare(_T("FEE3")) == 0 ||inputstring.Compare(_T("FEE4")) == 0 ||inputstring.Compare(_T("FEE1")) == 0)
		outputstring = _T("0xFEE2, 0xFEE3, 0xFEE4, 0xFEE1");


	else if (inputstring.Compare(_T("0646")) == 0|| inputstring.Compare(_T("FEE6")) == 0 
		||inputstring.Compare(_T("FEE7")) == 0 ||inputstring.Compare(_T("FEE8")) == 0 ||inputstring.Compare(_T("FEE5")) == 0)
		outputstring = _T("0xFEE6, 0xFEE7, 0xFEE8, 0xFEE5");


	else if (inputstring.Compare(_T("0647")) == 0|| inputstring.Compare(_T("FEEA")) == 0 
		||inputstring.Compare(_T("FEEB")) == 0 ||inputstring.Compare(_T("FEEC")) == 0 ||inputstring.Compare(_T("FEE9")) == 0)
		outputstring = _T("0xFEEA, 0xFEEB, 0xFEEC, 0xFEE9");


	else if (inputstring.Compare(_T("0648")) == 0|| inputstring.Compare(_T("FEEE")) == 0 
		||inputstring.Compare(_T("FEED")) == 0 ||inputstring.Compare(_T("FEEE")) == 0 ||inputstring.Compare(_T("FEED")) == 0)
		outputstring = _T("0xFEEE, 0xFEED, 0xFEEE, 0xFEED");


	else if (inputstring.Compare(_T("0649")) == 0 ||inputstring.Compare(_T("FEF0")) == 0 ||
		inputstring.Compare(_T("FEF3")) == 0 || inputstring.Compare(_T("FEF4")) == 0 || inputstring.Compare(_T("FEEF")) == 0)
		outputstring = _T("0xFEF0, 0xFEF3, 0xFEF4, 0xFEEF");


	else if (inputstring.Compare(_T("064A")) == 0 || inputstring.Compare(_T("FEF2")) == 0 
		||inputstring.Compare(_T("FEF3")) == 0 ||inputstring.Compare(_T("FEF4")) == 0 ||inputstring.Compare(_T("FEF1")) == 0)
		outputstring = _T("0xFEF2, 0xFEF3, 0xFEF4, 0xFEF1");
	return outputstring;
}

void CArabicconjunction::W2C(wchar_t w_cn , char c_cn[])
{
	c_cn[0] = w_cn >> 8 ;
	c_cn[1] = (char)w_cn ;
}

CString CArabicconjunction::ConvertWCHARToHex(CString Data, long nDataLength)
{
	CString sResult("");
	for (long nLoop=0; nLoop<nDataLength; nLoop++)
	{
		wchar_t ch= Data.GetAt(nLoop);//将wchar_t转换为char[2]
		char c_cn[2]={'0'};
		W2C(ch,c_cn);
		static const char *hex = "0123456789ABCDEF";
		for(int i=0;i<2;i++)
		{
			unsigned char chHexA = hex[((unsigned char)(c_cn[i]) >> 4) & 0x0f];
			unsigned char chHexB = hex[(unsigned char)(c_cn[i]) & 0x0f];
			sResult += (char)chHexA;
			sResult += (char)chHexB;
		}
	}
	return sResult;
}

CString CArabicconjunction::HexStrToCString(CString HexStr)
{
	HexStr = _T(" ")+HexStr;
	wchar_t* buf = new wchar_t[2];
	memset(buf, 0, sizeof(wchar_t)*(2));

	TCHAR seps[] = _T(" ");
	TCHAR* token = _tcstok(HexStr.GetBuffer(HexStr.GetLength()), seps);
	while(NULL != token)
	{
		buf[0] = _tcstoul(token, NULL, 16);
		token = _tcstok(NULL, seps);
	}
	HexStr.ReleaseBuffer();
	CString outstr(buf);
	delete[] buf;
	buf = NULL;
	return outstr;
}

std::vector<CString> CArabicconjunction::split(CString str)
{
	int length = str.GetLength();
	vector< CString >SplitOut;
	//////
	int i = 0;
	CString strGet;
	while (AfxExtractSubString(strGet, str, i++, _T(',')))
	{
		SplitOut.push_back(strGet);
	}
	return SplitOut;
}
