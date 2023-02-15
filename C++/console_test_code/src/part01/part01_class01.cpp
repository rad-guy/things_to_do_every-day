#include "part01/part01_class01.h"

#define min(a,b)            (((a) < (b)) ? (a) : (b))

ImgInfo CPart01Class01::copyBitmap(ImgInfo src, ImgInfo dest, int x,int y,int cx,int cy,int destX,int destY)
{
	ImgInfo img;
	img.bf = src.bf;
	img.bi = src.bi;
	long long sizeSrc = src.bi.biWidth * src.bi.biHeight;
	long long sizeDest = dest.bi.biWidth * dest.bi.biHeight;

	long long cx1 = min(src.bi.biWidth - x, cx);
	long long cy1 = min(src.bi.biHeight - y, cy);

	long long destPoint = destX * destY;
	long long destArea = cx1 * cy1;

	for (long long i = x * y, j = destPoint; i < src.imgData.size(), j < destArea; i++, j++)
	{
		if (j == destArea + 1)
			cout << "dada" << endl;

		src.imgData[i] = dest.imgData[j];
		printf("%d %d\n", src.imgData[i][0], dest.imgData[j][0]);
	};
	return src;
}

//根据图片路径读取Bmp图像，生成ImgInfo对象
ImgInfo CPart01Class01::readBitmap(string imgPath)
{
	ImgInfo imgInfo;
	char* buf;                                              //定义文件读取缓冲区
	char* p;

	FILE* fp;
	fopen_s(&fp, imgPath.c_str(), "rb");
	if (fp == NULL) {
		cout << "打开文件失败!" << endl;
		exit(0);
	}

	fread(&imgInfo.bf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&imgInfo.bi, sizeof(BITMAPINFOHEADER), 1, fp);

	if (imgInfo.bi.biBitCount != 24) {
		cout << "不支持该格式的BMP位图！" << endl;
		exit(0);
	}

	fseek(fp, imgInfo.bf.bfOffBits, 0);

	buf = (char*)malloc(imgInfo.bi.biWidth * imgInfo.bi.biHeight * 4);
	fread(buf, 1, imgInfo.bi.biWidth * imgInfo.bi.biHeight * 4, fp);

	p = buf;

	vector<vector<char>> imgData;
	for (int y = 0; y < imgInfo.bi.biHeight; y++) {
		for (int x = 0; x < imgInfo.bi.biWidth; x++) {
			vector<char> vRGB;

			vRGB.push_back(*(p++));     //blue
			vRGB.push_back(*(p++));     //green
			vRGB.push_back(*(p++));     //red

			if (x == imgInfo.bi.biWidth - 1)
			{
				for (int k = 0; k < imgInfo.bi.biWidth % 4; k++) p++;
			}
			imgData.push_back(vRGB);
		}
	}
	fclose(fp);
	imgInfo.imgData = imgData;
	return imgInfo;
}

void drawColorOnPoint(void* buffer, int x, int y, DWORD color)
{

	DWORD* bitWord = (DWORD*)buffer;
	int addr = x + y;
	bitWord[addr] = color;
}
void drawColorOnRow(void* buffer, int row, DWORD color)
{

	DWORD* bitWord = (DWORD*)buffer;
	int addr = row;
	bitWord[addr] = color;
}
void drawColor(void* buffer, int w, int h, DWORD color)
{
	DWORD* bitWord = (DWORD*)buffer;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) {
			//if (i > 100 && i < 200)
			//	drawColorOnRow(buffer,i*w + j, 0xffffff00);
			//else if (i >= 0 && i <= 50)
			//	drawColorOnRow(buffer, i * w + j, 0xffffffff);
			//else
			//{
				int addr = i * w + j;
				bitWord[addr] = color;
			//}

			//if (i == h / 2 && j == w / 2)
			//	drawColorOnPoint(buffer, i*w, j, 0xff000000);

		}
	}
}
static int g_color_tab = 0;

void drawBitMapColor(char* buffer, int w, int h, DWORD color)
{
	//if (g_color_tab / 10 % 3 == 0)
	//{
	//	color = 0xffff0000;
	//}
	//else if (g_color_tab / 10 % 3 == 1) {
	//	color = 0xff00ff00;
	//}
	//else {
	//	color = 0xff0000ff;
	//}
	//绘制标准红色 add by ljm 2022-3-24
	drawColor((LPVOID*)buffer, w, h, color);
	//g_color_tab++;
}


void CPart01Class01::showBitmap(ImgInfo imgInfo)
{
	HWND hWindow;                                                //窗口句柄
	HDC hDc;                                                     //绘图设备环境句柄
	int yOffset = 150;
	hWindow = GetForegroundWindow();
	hDc = GetDC(hWindow);

	int posX, posY;
	for (int i = 0; i < imgInfo.imgData.size(); i++) {
		char blue = imgInfo.imgData.at(i).at(0);
		char green = imgInfo.imgData.at(i).at(1);
		char red = imgInfo.imgData.at(i).at(2);

		posX = i % imgInfo.bi.biWidth;
		posY = imgInfo.bi.biHeight - i / imgInfo.bi.biWidth + yOffset;
		SetPixel(hDc, posX, posY, RGB(red, green, blue));
	}
}

void CPart01Class01::saveBitmap(ImgInfo imgInfo)
{
	FILE* fpw;
	fopen_s(&fpw, saveImgPath.c_str(), "wb");
	fwrite(&imgInfo.bf, sizeof(BITMAPFILEHEADER), 1, fpw);  //写入文件头
	fwrite(&imgInfo.bi, sizeof(BITMAPINFOHEADER), 1, fpw);  //写入文件头信息

	int size = imgInfo.bi.biWidth * imgInfo.bi.biHeight;
	for (int i = 0; i < size; i++) {
		fwrite(&imgInfo.imgData.at(i).at(0), 1, 1, fpw);
		fwrite(&imgInfo.imgData.at(i).at(1), 1, 1, fpw);
		fwrite(&imgInfo.imgData.at(i).at(2), 1, 1, fpw);

		if (i % imgInfo.bi.biWidth == imgInfo.bi.biWidth - 1) {
			char ch = '0';
			for (int j = 0; j < imgInfo.bi.biWidth % 4; j++) {
				fwrite(&ch, 1, 1, fpw);
			}
		}
	}
	fclose(fpw);
	cout << "已保存图像至: " + saveImgPath << endl;
}


void CPart01Class01::createBitmap(const char* path,int width,int height, DWORD color)
{	
	HWND hWindow;
	HDC hDc;
	HDC hMemDC;
	char* buffer;
	hWindow = GetForegroundWindow();
	hDc = ::GetDC(hWindow);
	hMemDC = ::CreateCompatibleDC(hDc);
	SetStretchBltMode(hMemDC, HALFTONE);
	HBITMAP bitmapMem;

	int size = width * height * 4;
	BITMAPINFO bi;
	ZeroMemory(&bi, sizeof(BITMAPINFO));
	// Part.1 Create Bitmap File Header  
	BITMAPFILEHEADER fileHeader;

	fileHeader.bfType = 0x4D42;
	fileHeader.bfReserved1 = 0;
	fileHeader.bfReserved2 = 0;
	fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// Part.2 Create Bitmap Info Header  
	BITMAPINFOHEADER bitmapHeader = { 0 };

	bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapHeader.biHeight = height;


	bitmapHeader.biWidth = width;
	bitmapHeader.biPlanes = 1;
	bitmapHeader.biBitCount = 32;
	bitmapHeader.biSizeImage = size;
	bitmapHeader.biCompression = BI_RGB; //BI_RGB  

	bi.bmiHeader = bitmapHeader;

	bitmapMem = ::CreateDIBSection(hMemDC, &bi, DIB_RGB_COLORS, (LPVOID*)&buffer, NULL, 0);

	//为了直接测试编解码器，绘制指定颜色
	drawBitMapColor(buffer,width,height,color);

	FILE* output;
	fopen_s(&output,path, "wb");

	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
	fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
	fwrite(buffer, size, 1, output);
	fclose(output);

	DeleteDC(hMemDC);
	ReleaseDC(NULL, hDc);
	DeleteObject(bitmapMem);
}

void SaveAsBitmapFile(const char* path, LPVOID pData, int w, int h)
{
	const char* pixelPtr = static_cast<const char*>(pData);
	// Define BMP Size  
	const int height = h;
	const int width = w;
	const int size = w * h * 4;
	double x, y;
	int index;

	// Part.1 Create Bitmap File Header  
	BITMAPFILEHEADER fileHeader;

	fileHeader.bfType = 0x4D42;
	fileHeader.bfReserved1 = 0;
	fileHeader.bfReserved2 = 0;
	fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// Part.2 Create Bitmap Info Header  
	BITMAPINFOHEADER bitmapHeader = { 0 };

	bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapHeader.biHeight = height;//填入负数则颠倒
	//bitmapHeader.biHeight = height;

	bitmapHeader.biWidth = width;
	bitmapHeader.biPlanes = 1;
	bitmapHeader.biBitCount = 32;
	bitmapHeader.biSizeImage = size;
	bitmapHeader.biCompression = BI_RGB; //BI_RGB  


										 // Write to file  
	FILE* output;
	fopen_s(&output,path, "wb");

	if (output == NULL)
	{

	}
	else
	{
		fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
		fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
		fwrite(pixelPtr, size, 1, output);
		fclose(output);
	}
}

void CPart01Class01::drawColorToBitmap(const string& path, const string& destPath)
{
	DWORD* buf;
	FILE* fp;
	fopen_s(&fp, path.data(), "r+b");
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, fp);
	fseek(fp, bf.bfOffBits, 0);
	buf = (DWORD*)malloc(bi.biWidth * bi.biHeight * 4);
	fread(buf, 1, bi.biWidth * bi.biHeight * 4, fp);
	fclose(fp);


	DWORD* bufDest;
	FILE* fpDest;
	fopen_s(&fpDest, destPath.data(), "r+b");
	BITMAPFILEHEADER bfDest;
	BITMAPINFOHEADER biDest;
	fread(&bfDest, sizeof(BITMAPFILEHEADER), 1, fpDest);
	fread(&biDest, sizeof(BITMAPINFOHEADER), 1, fpDest);
	fseek(fpDest, bfDest.bfOffBits, 0);
	bufDest = (DWORD*)malloc(biDest.biWidth * biDest.biHeight * 4);
	fread(bufDest, 1, biDest.biWidth * biDest.biHeight * 4, fpDest);
	//DWORD* buff;
	//buff = (DWORD*)malloc(biDest.biWidth * biDest.biHeight * 4);
	//for (int i = 0; i < biDest.biHeight, i < bi.biHeight; i++)
	//{
	//	for (int j = 0; j < biDest.biWidth, j < bi.biWidth; j++)
	//	{
	//		int addr = i * bi.biWidth + j;
	//		int addr2 = i * biDest.biWidth + j;
	//		bufDest[addr2] = buf[addr];
	//	}
	//}

	int arr = bi.biHeight;
	DWORD* buf_dest = bufDest;
	while (arr-- > 0)
	{
		memcpy(buf_dest, buf,bi.biWidth*4);
		buf_dest += biDest.biWidth ;
		buf += bi.biWidth;
	}

	SaveAsBitmapFile("D:\\res\\112093.bmp", bufDest, biDest.biWidth, biDest.biHeight);
	fclose(fp);
	fclose(fpDest);
}

void CPart01Class01::drawColorToBitmap(const string& path, const string& destPath, int x, int y, int cx, int cy, int destX, int destY)
{
	DWORD* buf;
	FILE* fp;
	fopen_s(&fp, path.data(), "r+b");
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, fp);
	fseek(fp, bf.bfOffBits, 0);
	buf = (DWORD*)malloc(bi.biWidth * bi.biHeight * 4);
	fread(buf, 1, bi.biWidth * bi.biHeight * 4, fp);
	fclose(fp);


	DWORD* bufDest;
	FILE* fpDest;
	fopen_s(&fpDest, destPath.data(), "r+b");
	BITMAPFILEHEADER bfDest;
	BITMAPINFOHEADER biDest;
	fread(&bfDest, sizeof(BITMAPFILEHEADER), 1, fpDest);
	fread(&biDest, sizeof(BITMAPINFOHEADER), 1, fpDest);
	fseek(fpDest, bfDest.bfOffBits, 0);
	bufDest = (DWORD*)malloc(biDest.biWidth * biDest.biHeight * 4);
	fread(bufDest, 1, biDest.biWidth * biDest.biHeight * 4, fpDest);

	DWORD* buf_dest = bufDest + (biDest.biHeight - y -cy) * biDest.biWidth + x;
	buf = buf + (bi.biHeight - destY - cy) * bi.biWidth + destX;
	while (cy-- > 0)
	{
  		memcpy(buf_dest, buf, cx * 4);
		buf_dest += biDest.biWidth;
		buf += bi.biWidth;
	}

	SaveAsBitmapFile("D:\\res\\zhongjie.bmp", bufDest, biDest.biWidth, biDest.biHeight);
	fclose(fp);
	fclose(fpDest);
}

