
#include "stdafx.h"
 
//---------------------------------------------------------
//  视频(摄象头)采集程序
 
//CCameraDS  camera;

CvCapture* m_Video;                         //  视频指针
IplImage*  m_Frame;                         //  OpenCV 位图指针
IplImage** m_List;                          //  位图指针表

int	       cap_shift=2;      //  取平均右移位数                 1-2-3 
int        cap_num  =4;      //  采样缓冲区数目(与上面数值相关) 2-4-8
int        frame_time;

int        frameSetW=640;                   //  采集分辨率设置值
int        frameSetH=480;

int        frameW;
int        frameH;
int        cap_time;                        //  冻结标志

//int  StartCapture(void)                     //  启动视频
//{
//	int cam_count,i;
//
//	//仅仅获取摄像头数目
//	cam_count = CCameraDS::CameraCount();
//	printf("There are %d cameras.\n", cam_count);
//
//
//	//获取所有摄像头的名称
//	for(i=0; i < cam_count; i++)
//	{
//		char camera_name[1024];  
//		int retval = CCameraDS::CameraName(i, camera_name, sizeof(camera_name) );
//
//		if(retval >0)
//			printf("Camera #%d's Name is '%s'.\n", i, camera_name);
//		else
//			printf("Can not get Camera #%d's name.\n", i);
//	}
//
//
//	if(cam_count==0)
//		return(false);
//
//	//打开第一个摄像头
//	//if(! camera.OpenCamera(0, true)) //弹出属性选择窗口
//	if(! camera.OpenCamera(0, false, frameSetW,frameSetH)) //不弹出属性选择窗口，用代码制定图像宽和高
//	{
//		fprintf(stderr, "Can not open camera.\n");
//		camera.CloseCamera();
//		return(-1);
//	}
//
//	frameW=frameSetW;    frameH=frameSetH;  //  取设置分辨率
//	cap_time=0;                             //  冻结标志初始化
// 
//	//-------------------------------------------
//	cap_num=(1<<cap_shift);                 //  确定缓冲区位图数
//
//	m_List=(IplImage**) malloc(cap_num*sizeof(IplImage*));
//	for (i=0;i<cap_num;i++) {
//		m_List[i]=cvCreateImage(cvSize(frameW,frameH), IPL_DEPTH_8U, 3);
//		                                    //  建立位图缓冲区
//	}
//	frame_time=0;
//	return(true);
//}

//BOOL OpenAviFile(CString strFileName)       //  打开视频文件
//{
//	m_Video = cvCreateFileCapture(strFileName);
//	if (!m_Video) return(false);
//
// 	m_Frame=cvQueryFrame(m_Video);
//	frameW =(int) cvGetCaptureProperty(m_Video,CV_CAP_PROP_FRAME_WIDTH);
//	frameH =(int) cvGetCaptureProperty(m_Video,CV_CAP_PROP_FRAME_HEIGHT);
// 
// 	cap_time=0;                             //  标志初始化
//
//	//-------------------------------------------
//	m_List=(IplImage**) malloc(cap_num*sizeof(IplImage*));
//	for (int i=0;i<cap_num;i++) {
//		m_List[i]=cvCreateImage(cvSize(frameW,frameH), IPL_DEPTH_8U, 3);
//	}
//	frame_time=0;
//	return(true);
//}

void StartAverage(void)
{
	frame_time=cap_num;
}

//int  LoadImageFrame(IplImage* pImg,int f)   //  读出视频图像
//{
//	int  bl;
//
//	if (m_Video) {
// 		m_Frame=cvQueryFrame(m_Video);      //  取出位图
//	}
//	else {
//		m_Frame=camera.QueryFrame();
//	}
//	if (m_Frame) {
//		if (frame_time==0) bl=1;
//		else {                              //  多图像平均采样
//			frame_time--;
//			memcpy(m_List[frame_time]->imageData,m_Frame->imageData,
//					m_Frame->imageSize);    //  保存位图
//			if (frame_time==0) bl=2;
//			else bl=1;
//		}
//	}
//	else bl=0;
//
//	if ((bl==1)&&(f==1)) {
//		memcpy(pImg->imageData,m_Frame->imageData,
//				m_Frame->imageSize);        //  传出位图
// 		cap_time++;                         //  修改标志
//	}
//	return(bl);
//}

//void AverageImage(IplImage* pImg)           //  多图像平均
//{                                           //  OpenCV语句实现
//	IplImage* pImg32f = NULL;
//	IplImage* pImg32s = NULL;
//	int   i,j,k,*pi;
//	BYTE  *pb;
//
// 	pImg32f = cvCreateImage(cvGetSize(pImg),
//				IPL_DEPTH_32F,pImg->nChannels);
// 	pImg32s = cvCreateImage(cvGetSize(pImg),
//				IPL_DEPTH_32S,pImg->nChannels);
//
//	cvZero(pImg32f);
//	for (i=0;i<cap_num;i++) {
//		cvAcc(m_List[i],pImg32f,NULL);      //  像素数据叠加
//	}
//	cvConvertScale(pImg32f,pImg32s,1.0,0);  //  转变为整数
//
//	k=min(pImg->width,pImg32s->width);
//	for (i=0;i<pImg->height;i++) {
//		pb=(BYTE*) (pImg->imageData+i*pImg->widthStep);
//		pi=(int*)  (pImg32s->imageData+i*pImg32s->widthStep);
//		for (j=0;j<k*pImg->nChannels;j++) 
//			pb[j]=(BYTE) (pi[j]>>cap_shift);  //  pi[j]/cap_num
//	}
//
//	cvReleaseImage(&pImg32f);
//	cvReleaseImage(&pImg32s);
//}

/*
void AverageImage(IplImage* pImg)           //  多(四)图像平均
{                                           //  C 语句实现
	WORD *buffer,*bufferp;
	BYTE *bufp;
	int  i,k,bpl,size;
  
	bpl=(pImg->width*pImg->depth*pImg->nChannels+31)/32*4;
  	size=bpl*pImg->height;

	buffer=(WORD*) malloc(size*sizeof(WORD));
	memset(buffer,0,size*sizeof(WORD));     //  部分和清零

	for (k=0;k<cap_num;k++) {
		bufp=(BYTE*)m_List[k]->imageData;
 		bufferp=buffer;     
		for (i=0;i<size;i++) {
			(*bufferp)+=(WORD)(*bufp++);    //  像素值叠加
			bufferp++;
		}
	}
 
	bufp=(BYTE*)pImg->imageData;     
	bufferp=buffer;
	for (i=0;i<size;i++) {
		(*bufp++)=(BYTE) ((*bufferp++)>>cap_shift);  //  像素值取平均
	}

 	free(buffer);
}
*/

//void AbortCapture(IplImage* pImg)           //  关闭视频
//{
//	if (cap_time==0) {                      //  画面尚未冻结
//		LoadImageFrame(pImg,1);             //  读出视频图像
//	}
//	if (m_Video) {
// 		cvReleaseCapture(&m_Video);         //  释放视频
//	}
//	else {
//		camera.CloseCamera();               //  关闭摄像头
//	}
//
//	//-------------------------------------------
//	for (int i=0;i<cap_num;i++) {
// 		cvReleaseImage(&m_List[i]);         //  释放位图缓冲区
//	}
//	free(m_List);
//	frame_time=0;
//}

//BOOL SetParameter(void)                     //  属性选择
//{
//	int cam_count;
//
//	//仅仅获取摄像头数目
//	cam_count = CCameraDS::CameraCount();
//	printf("There are %d cameras.\n", cam_count);
//
//
//	//获取所有摄像头的名称
//	for(int i=0; i < cam_count; i++)
//	{
//		char camera_name[1024];  
//		int retval = CCameraDS::CameraName(i, camera_name, sizeof(camera_name) );
//
//		if(retval >0)
//			printf("Camera #%d's Name is '%s'.\n", i, camera_name);
//		else
//			printf("Can not get Camera #%d's name.\n", i);
//	}
//
//
//	if(cam_count==0) 
//	{
//		fprintf(stderr, "Can not open camera.\n");
// 		return(false);
//	}
//
//	if( camera.OpenCamera(0, true))         //  弹出属性选择窗口
//	{
//		frameSetW=camera.GetWidth();        //  获取设置分辨率
//		frameSetH=camera.GetHeight();
//		camera.CloseCamera();               //  关闭摄像头
//		return(true);
//	}
//	else
//	{
//		fprintf(stderr, "Can not open camera.\n");
// 		return(false);
//	}
//}

