#include <stdio.h>
#include <Windows.h>
#include "..\libQR\qrencode.h"

#pragma comment(lib,"..\\Debug\\libQR.lib")

int main()
{
	const char * QRTEXT = "你好";
	QRcode * qrCode;
	int version = 5;//设置版本号，这里设为5，对应尺寸：37 * 37
	QRecLevel level = QR_ECLEVEL_H;//纠错级别
	QRencodeMode hint = QR_MODE_8;//编码模式
	int casesensitive = 1;//是否区分大小写，true/false
	qrCode = QRcode_encodeString(QRTEXT, version, level, hint, casesensitive);
	if (NULL == qrCode)
	{
		printf("QRcode create fail\n");
		return -1;
	}

	//将要生成的二维码保存为BMP真彩色图片文件
	FILE * pf = fopen("qrcode.bmp", "wb");
	if (NULL == pf)
	{
		printf("file open fail.\n");
		fclose(pf);
		return -1;
	}
	int width = qrCode->width;
	int height = qrCode->width;
	int biCount = 24;//真彩色
	int lineByte = (width * biCount / 8 + 3) / 4 * 4; //每line字节数必须为4的倍数
	//位图文件头
	BITMAPFILEHEADER bitMapFileHeader;
	bitMapFileHeader.bfType = 0x4D42;
	bitMapFileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + lineByte * height;
	bitMapFileHeader.bfReserved1 = 0;
	bitMapFileHeader.bfReserved2 = 0;
	bitMapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	//位图信息头
	BITMAPINFOHEADER bitMapInfoHeader;
	bitMapInfoHeader.biBitCount = biCount;
	bitMapInfoHeader.biClrImportant = 0;
	bitMapInfoHeader.biClrUsed = 0;
	bitMapInfoHeader.biCompression = 0;
	bitMapInfoHeader.biHeight = height;
	bitMapInfoHeader.biPlanes = 1;
	bitMapInfoHeader.biSize = 40;
	bitMapInfoHeader.biSizeImage = lineByte * height;
	bitMapInfoHeader.biWidth = width;
	bitMapInfoHeader.biXPelsPerMeter = 0;
	bitMapInfoHeader.biYPelsPerMeter = 0;
	//写文件头进文件
	fwrite(&bitMapFileHeader, sizeof(BITMAPFILEHEADER), 1, pf);
	//写位图信息头进文件
	fwrite(&bitMapInfoHeader, sizeof(BITMAPINFOHEADER), 1, pf);
	unsigned char * pBMPData = new unsigned char[lineByte * height];
	memset(pBMPData, 255, lineByte * height);

	unsigned char * qrData = qrCode->data;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < lineByte/3; j++)
		{
			if (*(qrData) & 1)
			{
				//设置rgb颜色，可自定义设置，这里设为黑色。
				*(pBMPData + lineByte * i + 3 * j) = 0;
				*(pBMPData + lineByte * i + 3 * j + 1) = 0;
				*(pBMPData + lineByte * i + 3 * j + 2) = 0;
			}
			qrData++;
		}
	}

	//写数据进文件
	fwrite(pBMPData, sizeof(unsigned char), lineByte * height, pf);
	fclose(pf);
	delete[] pBMPData;
	pBMPData = NULL;

	QRcode_free(qrCode);
	return 0;
}