#ifndef		OPENVCCAP
#define		OPENVCCAP
 
#include <windows.h>
    
//---------------------------------------------------------
//  ��Ƶ(����ͷ)�ɼ�����

extern CvCapture* m_Video;
extern IplImage*  m_Frame;                  //  ���ڴ洢һ֡

extern int        frameSetW;
extern int        frameSetH;

extern int        frameW;
extern int        frameH;
extern int        framepS;
extern int        cap_time;                 //  �������
extern int        frame_time;               //  �����ɼ�֡��
  
int  StartCapture(void);                    //  ������Ƶ
BOOL OpenAviFile(CString strFileName);      //  ����Ƶ�ļ�
void StartAverage(void);                    //  ��ʼƽ��
int  LoadImageFrame(IplImage* pImg,int f);  //  ������Ƶͼ��
void AverageImage(IplImage* pImg);          //  ��ͼ��ƽ��
void AbortCapture(IplImage* pImg);          //  �ر���Ƶ
BOOL SetParameter(void);                    //  ����ѡ��
 
#endif  //OPENVCCAP


