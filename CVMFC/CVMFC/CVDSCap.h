#ifndef		OPENVCCAP
#define		OPENVCCAP
 
#include <windows.h>
    
//---------------------------------------------------------
//  视频(摄象头)采集程序

extern CvCapture* m_Video;
extern IplImage*  m_Frame;                  //  用于存储一帧

extern int        frameSetW;
extern int        frameSetH;

extern int        frameW;
extern int        frameH;
extern int        framepS;
extern int        cap_time;                 //  冻结次数
extern int        frame_time;               //  连续采集帧数
  
int  StartCapture(void);                    //  启动视频
BOOL OpenAviFile(CString strFileName);      //  打开视频文件
void StartAverage(void);                    //  开始平均
int  LoadImageFrame(IplImage* pImg,int f);  //  读出视频图像
void AverageImage(IplImage* pImg);          //  多图像平均
void AbortCapture(IplImage* pImg);          //  关闭视频
BOOL SetParameter(void);                    //  属性选择
 
#endif  //OPENVCCAP


