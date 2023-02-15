#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	vector<vector<char>> imgData;
}ImgInfo;

class CPart01Class01
{
public:
	CPart01Class01() {};
	~CPart01Class01() {};

	ImgInfo copyBitmap(ImgInfo src, ImgInfo dest, int x, int y, int cx, int cy, int destX, int destY);
	ImgInfo readBitmap(string imgPath);
	void showBitmap(ImgInfo imgInfo);
	void saveBitmap(ImgInfo imgInfo);

	void createBitmap(const char* path, int width, int height,DWORD color);
	void drawColorToBitmap(const string& path, const string& destPath);
	void drawColorToBitmap(const string& path, const string& destPath, int x, int y, int cx, int cy, int destX, int destY);
	string saveImgPath;
};
