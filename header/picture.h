#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include<stdio.h>  
#include<string>  
#include <algorithm>
//#include<sys/types.h>  
#include <vector>
#include <windows.h>
#include <wingdi.h>
#include <minwindef.h>
#include <io.h>
using namespace std;
 
__declspec(dllexport)struct IMAGEINFO {
	unsigned int width;
	unsigned int height;
	BITMAPINFOHEADER INFOHEADER;
};

__declspec(dllexport)int Getimage(const char * filename, unsigned char* pRimage,int row);

//unsigned char* GetimageG(const char * filename, int row);
//
//unsigned char* GetimageB(const char * filename, int row);

__declspec(dllexport)IMAGEINFO GetWidHei(const char* filename);

__declspec(dllexport)int SaveBmp(PUCHAR data, BITMAPINFOHEADER pBmpInfo, int nImgW, int nImgH, const char* filename);

__declspec(dllexport)struct ImageFile
{
	std::string file_name; /*!< 文件名 */
	int order_number; /*!< 文件序号, 取文件名 */
};

// sort picture retuan array
__declspec(dllexport)bool SortByImageFiles(const ImageFile img1, const ImageFile img2);
__declspec(dllexport)vector<string> split(const string& str, const string& delim);
__declspec(dllexport)void GetImagePaths(std::string folder_path, std::string file_format, std::vector<ImageFile>& file_names);
