#ifndef		PROCESSING
#define		PROCESSING

#include "stdafx.h" 

LPBITMAPINFO CtreateMapInfo(IplImage* workImg,int flag);
 
int  imageType(IplImage* p);
int  imageClone(IplImage* pi,IplImage** ppo);  //  复制 IplImage 位图
int  imageReplace(IplImage* pi,IplImage** ppo);  //  位图替换
 
//---------------------------------------------------------
//  常规图像处理

void ImageDwindle(IplImage *pi,IplImage *po,int n,int nCnls);   
int  NextColor(int start,int k,int step);            //  下一彩色号
void Histog(BYTE *buf,int *pg,int Dx,int Dy);
int  BasicGlobalThreshold(int *pg,int start,int end);
void GrayColorTransfor(RGBQUAD *pal); 

extern RGBQUAD VgaDefPal[256];
extern RGBQUAD VgaColorTab[256];

#endif  //PROCESSING
