#include <stdio.h>
#include <Windows.h>
#include "..\libQR\qrencode.h"

#pragma comment(lib,"..\\Debug\\libQR.lib")

int main()
{
	const char * QRTEXT = "���";
	QRcode * qrCode;
	int version = 5;//���ð汾�ţ�������Ϊ5����Ӧ�ߴ磺37 * 37
	QRecLevel level = QR_ECLEVEL_H;//������
	QRencodeMode hint = QR_MODE_8;//����ģʽ
	int casesensitive = 1;//�Ƿ����ִ�Сд��true/false
	qrCode = QRcode_encodeString(QRTEXT, version, level, hint, casesensitive);
	if (NULL == qrCode)
	{
		printf("QRcode create fail\n");
		return -1;
	}

	//��Ҫ���ɵĶ�ά�뱣��ΪBMP���ɫͼƬ�ļ�
	FILE * pf = fopen("qrcode.bmp", "wb");
	if (NULL == pf)
	{
		printf("file open fail.\n");
		fclose(pf);
		return -1;
	}
	int width = qrCode->width;
	int height = qrCode->width;
	int biCount = 24;//���ɫ
	int lineByte = (width * biCount / 8 + 3) / 4 * 4; //ÿline�ֽ�������Ϊ4�ı���
	//λͼ�ļ�ͷ
	BITMAPFILEHEADER bitMapFileHeader;
	bitMapFileHeader.bfType = 0x4D42;
	bitMapFileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + lineByte * height;
	bitMapFileHeader.bfReserved1 = 0;
	bitMapFileHeader.bfReserved2 = 0;
	bitMapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	//λͼ��Ϣͷ
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
	//д�ļ�ͷ���ļ�
	fwrite(&bitMapFileHeader, sizeof(BITMAPFILEHEADER), 1, pf);
	//дλͼ��Ϣͷ���ļ�
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
				//����rgb��ɫ�����Զ������ã�������Ϊ��ɫ��
				*(pBMPData + lineByte * i + 3 * j) = 0;
				*(pBMPData + lineByte * i + 3 * j + 1) = 0;
				*(pBMPData + lineByte * i + 3 * j + 2) = 0;
			}
			qrData++;
		}
	}

	//д���ݽ��ļ�
	fwrite(pBMPData, sizeof(unsigned char), lineByte * height, pf);
	fclose(pf);
	delete[] pBMPData;
	pBMPData = NULL;

	QRcode_free(qrCode);
	return 0;
}