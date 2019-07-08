#include "stdafx.h"
#include "CVMFCDoc.h"
#include "CVMFCView.h"
#include "Processing.h"
#include "GamaDLG.h"
#include "DLGImgMatch.h"
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;

#endif
double gama;
 CString srcfilePath;
 CString dstfilePath;

IMPLEMENT_DYNCREATE(CCVMFCView, CScrollView)

BEGIN_MESSAGE_MAP(CCVMFCView, CScrollView)
	//{{AFX_MSG_MAP(CCVMFCView)
 	ON_UPDATE_COMMAND_UI(ID_REFRESH, OnUpdateRefresh)
	ON_UPDATE_COMMAND_UI(ID_COLOR_IMAGE_REFRESH, OnUpdateColorImageRefresh)
	
 	
 	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_CLOSE, OnUpdateFileClose) 	
	
	
  	ON_COMMAND(ID_REFRESH, OnRefresh)
	ON_COMMAND(ID_COLOR_IMAGE_REFRESH, OnColorImageRefresh)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
 //	ON_COMMAND(ID_START_CAPTURE, OnStartCapture)
	//ON_COMMAND(ID_CAPTURE_IMAGE, OnCaptureImage)
 //	ON_COMMAND(ID_CAP_ABORT, OnCapAbort)
	//ON_COMMAND(ID_OPEN_AVI_FILE, OnOpenAviFile)
	ON_COMMAND(ID_VIEW_CONTINUE, OnViewContinue)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_GAUSS_SMOOTH, OnUpdateGaussSmooth)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_SHRINK, OnUpdateImageShrink)
	ON_UPDATE_COMMAND_UI(ID_CANNY_BORDDETEC, OnUpdateCannyBorddetec)
	ON_COMMAND(ID_GAUSS_SMOOTH, OnGaussSmooth)
	ON_COMMAND(ID_IMAGE_SHRINK, OnImageShrink)
	ON_COMMAND(ID_CANNY_BORDDETEC, OnCannyBorddetec)
	ON_UPDATE_COMMAND_UI(ID_COLOR_TO_GRAY, OnUpdateColorToGray)
	ON_UPDATE_COMMAND_UI(ID_FLIP_V, OnUpdateFlipV)
	ON_UPDATE_COMMAND_UI(ID_FLIP_H, OnUpdateFlipH)
	ON_COMMAND(ID_COLOR_TO_GRAY, OnColorToGray)
	ON_COMMAND(ID_FLIP_V, OnFlipV)
	ON_COMMAND(ID_FLIP_H, OnFlipH)
	ON_UPDATE_COMMAND_UI(ID_FLIP, OnUpdateFlip)
	ON_COMMAND(ID_FLIP, OnFlip)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_INVERT, OnUpdateImageInvert)
	
	ON_UPDATE_COMMAND_UI(ID_SOBEL, OnUpdateSobel)
	ON_UPDATE_COMMAND_UI(ID_LAPLACE, OnUpdateLaplace)
	//ON_COMMAND(ID_SOBEL, OnSobel)
	//ON_COMMAND(ID_LAPLACE, OnLaplace)
	ON_UPDATE_COMMAND_UI(ID_CONSERVATION_IMAGE, OnUpdateConservationImage)
	ON_COMMAND(ID_CONSERVATION_IMAGE, OnConservationImage)
	
	//ON_COMMAND(ID_SET_PARAMETER, OnSetParameter)
	ON_UPDATE_COMMAND_UI(ID_RADIAL_GRADS, OnUpdateRadialGrads)
	
	ON_UPDATE_COMMAND_UI(ID_EROSION, OnUpdateErosion)
	ON_UPDATE_COMMAND_UI(ID_DILATION, OnUpdateDilation)
	ON_UPDATE_COMMAND_UI(ID_OPENNING, OnUpdateOpenning)
	ON_UPDATE_COMMAND_UI(ID_CLOSING, OnUpdateClosing)
	ON_UPDATE_COMMAND_UI(ID_GRADS, OnUpdateGrads)
	ON_UPDATE_COMMAND_UI(ID_GRAY_TOPHAT, OnUpdateGrayTophat)
	ON_UPDATE_COMMAND_UI(ID_GRAY_BLACKHAT, OnUpdateGrayBlackhat)
	ON_COMMAND(ID_EROSION, OnErosion)
	ON_COMMAND(ID_DILATION, OnDilation)
	
	
	
	
	
	ON_UPDATE_COMMAND_UI(ID_ADAPTIVE_THRESHOLD, OnUpdateAdaptiveThreshold)
	
	ON_UPDATE_COMMAND_UI(ID_BASIC_GLOBAL_THRESHOLD, OnUpdateBasicGlobalThreshold)
	
	ON_UPDATE_COMMAND_UI(ID_CONTOUR_TRACK, OnUpdateContourTrack)
	ON_COMMAND(ID_CONTOUR_TRACK, OnContourTrack)
	ON_UPDATE_COMMAND_UI(ID_DISTANCE, OnUpdateDistance)
	//ON_COMMAND(ID_DISTANCE, OnDistance)
	
	ON_COMMAND(ID_AVERAGE_IMAGE, OnAverageImage)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_HISTOGRAM, OnUpdateImageHistogram)
	ON_COMMAND(ID_IMAGE_HISTOGRAM, OnImageHistogram)
	ON_UPDATE_COMMAND_UI(ID_ROTATION_30, OnUpdateRotation30)
	ON_COMMAND(ID_ROTATION_30, OnRotation90)
	ON_UPDATE_COMMAND_UI(ID_BLUR_SMOOTH, OnUpdateBlurSmooth)
	ON_UPDATE_COMMAND_UI(ID_MEDIAN_SMOOTH, OnUpdateMedianSmooth)
	ON_COMMAND(ID_BLUR_SMOOTH, OnBlurSmooth)
	ON_COMMAND(ID_MEDIAN_SMOOTH, OnMedianSmooth)
	ON_UPDATE_COMMAND_UI(ID_SNAKE, OnUpdateSnake)
	
	ON_UPDATE_COMMAND_UI(ID_CONVEX_HULL, OnUpdateConvexHull)
	
	ON_UPDATE_COMMAND_UI(ID_FIT_ELLIPSE, OnUpdateFitEllipse)
	
	ON_UPDATE_COMMAND_UI(ID_IMAGE_ADJUST, OnUpdateImageAdjust)
	ON_UPDATE_COMMAND_UI(ID_HIST_EQUALIZE, OnUpdateHistEqualize)
	ON_COMMAND(ID_HIST_EQUALIZE, OnHistEqualize)
	ON_UPDATE_COMMAND_UI(ID_AREA_CONVEX_HULL, OnUpdateAreaConvexHull)
	ON_UPDATE_COMMAND_UI(ID_MIN_AREA_RECT, OnUpdateMinAreaRect)
	
	ON_UPDATE_COMMAND_UI(ID_AREA_RECT, OnUpdateAreaRect)
	
	ON_UPDATE_COMMAND_UI(ID_APPROX_POLY, OnUpdateApproxPoly)
	
	ON_WM_SIZE()
	ON_UPDATE_COMMAND_UI(ID_CONVEXITY_DEFECTS, OnUpdateConvexityDefects)
	
	ON_UPDATE_COMMAND_UI(ID_WATERSHED, OnUpdateWatershed)
	
	ON_UPDATE_COMMAND_UI(ID_FLOOD_FILL, OnUpdateFloodFill)
	ON_UPDATE_COMMAND_UI(ID_PYR_SEGMENTATION, OnUpdatePyrSegmentation)
	

	ON_UPDATE_COMMAND_UI(ID_THRESHOLDING_1, OnUpdateThresholding1)
	ON_COMMAND(ID_THRESHOLDING_1, OnThresholding1)
	ON_UPDATE_COMMAND_UI(ID_THRESHOLDING_2, OnUpdateThresholding2)
	ON_COMMAND(ID_THRESHOLDING_2, OnThresholding2)
	ON_UPDATE_COMMAND_UI(ID_CORNERS_TEST, OnUpdateCornersTest)
	
	ON_UPDATE_COMMAND_UI(ID_DYNAMIC_BORDER_TEST, OnUpdateDynamicBorderTest)
	//ON_COMMAND(ID_DYNAMIC_BORDER_TEST, OnDynamicBorderTest)
	ON_UPDATE_COMMAND_UI(ID_OPTICAL_FLOW_TRACK, OnUpdateOpticalFlowTrack)
	ON_COMMAND(ID_OPTICAL_FLOW_TRACK, OnOpticalFlowTrack)
	ON_UPDATE_COMMAND_UI(ID_CONVEX_HULL_2, OnUpdateConvexHull2)
	
	ON_UPDATE_COMMAND_UI(ID_MOTION_DETECT, OnUpdateMotionDetect)
	//ON_COMMAND(ID_MOTION_DETECT, OnMotionDetect)
	ON_UPDATE_COMMAND_UI(ID_MIN_AREA_RECT_2, OnUpdateMinAreaRect2)
	
	ON_UPDATE_COMMAND_UI(ID_CAM_SHIFT_DEMO, OnUpdateCamShiftDemo)
	ON_COMMAND(ID_CAM_SHIFT_DEMO, OnCamShiftDemo)
	ON_UPDATE_COMMAND_UI(ID_CLUSTERS, OnUpdateClusters)
	
	ON_UPDATE_COMMAND_UI(ID_HOUGH_LINES, OnUpdateHoughLines)
	
	ON_UPDATE_COMMAND_UI(ID_SQUARES_TEST, OnUpdateSquaresTest)
	
	ON_UPDATE_COMMAND_UI(ID_ROTATION_TRACK, OnUpdateRotationTrack)

	ON_UPDATE_COMMAND_UI(ID_FACE_DETECT, OnUpdateFaceDetect)
	
	ON_UPDATE_COMMAND_UI(IF_FOREGROUND_DETECT, OnUpdateForegroundDetect)
	//ON_COMMAND(IF_FOREGROUND_DETECT, OnForegroundDetect)
	ON_UPDATE_COMMAND_UI(ID_FACE_DETECT_2, OnUpdateFaceDetect2)
	





	ON_UPDATE_COMMAND_UI(ID_HOUGH_CIRCLE, OnUpdateHoughCircle)
	
	ON_UPDATE_COMMAND_UI(ID_BLUR_SMOOTH_C, OnUpdateBlurSmoothC)
	ON_UPDATE_COMMAND_UI(ID_GAUSS_SMOOTH_C, OnUpdateGaussSmoothC)
	ON_UPDATE_COMMAND_UI(ID_MEDIAN_SMOOTH_C, OnUpdateMedianSmoothC)
	ON_UPDATE_COMMAND_UI(ID_SOBEL_C, OnUpdateSobelC)
	ON_UPDATE_COMMAND_UI(ID_LAPLACE_C, OnUpdateLaplaceC)
	ON_COMMAND(ID_BLUR_SMOOTH_C, OnBlurSmoothC)
	ON_COMMAND(ID_GAUSS_SMOOTH_C, OnGaussSmoothC)
	ON_COMMAND(ID_MEDIAN_SMOOTH_C, OnMedianSmoothC)
	ON_COMMAND(ID_SOBEL_C, OnSobelC)
	ON_COMMAND(ID_LAPLACE_C, OnLaplaceC)
	

	ON_UPDATE_COMMAND_UI(ID_IMAGE_RGB, OnUpdateImageRgb)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_HSV, OnUpdateImageHsv)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_LAB, OnUpdateImageLab)
	//ON_COMMAND(ID_IMAGE_RGB, OnImageRgb)
	//ON_COMMAND(ID_IMAGE_HSV, OnImageHsv)
	//ON_COMMAND(ID_IMAGE_LAB, OnImageLab)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_XYZ, OnUpdateImageXyz)
	ON_UPDATE_COMMAND_UI(ID_IMAGE_YCRCB, OnUpdateImageYcrcb)
	
	
	ON_UPDATE_COMMAND_UI(ID_IMAGE_LUV, OnUpdateImageLuv)
	
	ON_UPDATE_COMMAND_UI(ID_IMAGE_RGB_C, OnUpdateImageRgbC)
	//ON_COMMAND(ID_IMAGE_RGB_C, OnImageRgbC)
	ON_UPDATE_COMMAND_UI(ID_2D_HISTOGRAM, OnUpdate2dHistogram)
	//ON_COMMAND(ID_2D_HISTOGRAM, On2dHistogram)
	ON_UPDATE_COMMAND_UI(ID_SEQ_PARTITION, OnUpdateSeqPartition)

	ON_UPDATE_COMMAND_UI(ID_WARP_AFFINE, OnUpdateWarpAffine)
	
	ON_UPDATE_COMMAND_UI(ID_WARP_PERSPECT, OnUpdateWarpPerspect)
	ON_UPDATE_COMMAND_UI(ID_FILE_OPEN, OnUpdateFileOpen)
	ON_UPDATE_COMMAND_UI(ID_APP_EXIT, OnUpdateAppExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
		ON_COMMAND(ID_Img2BIG, &CCVMFCView::OnImg2big)
		ON_COMMAND(ID_GAOSILVBO, &CCVMFCView::OnGaosilvbo)
		ON_COMMAND(ID_JUNZHILVBO, &CCVMFCView::OnJunzhilvbo)
		ON_COMMAND(ID_ZHONGZHILVBO, &CCVMFCView::OnZhongzhilvbo)
		ON_COMMAND(ID_SHAUNGBIANLVBO, &CCVMFCView::OnShaungbianlvbo)
		ON_COMMAND(ID_FANGKUANGLVBO, &CCVMFCView::OnFangkuanglvbo)
		ON_COMMAND(ID_LightChange, &CCVMFCView::OnLightchange)
		ON_COMMAND(ID_DISTANCE, &CCVMFCView::OnDistance)
		ON_COMMAND(ID_MYSOBEL, &CCVMFCView::OnMysobel)
		ON_COMMAND(ID_Laplacian, &CCVMFCView::OnLaplacian)
		ON_COMMAND(ID_ADDMASAIKE, &CCVMFCView::OnAddmasaike)
		ON_COMMAND(ID_LunKuoJiuZhen, &CCVMFCView::OnLunkuojiuzhen)
		ON_COMMAND(ID_TextJIAOZHENG, &CCVMFCView::OnTextjiaozheng)
		ON_COMMAND(ID_ImageMatch, &CCVMFCView::OnImagematch)
		END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView construction/destruction

CFile fCapture;
CFileException eCapture;
char pbuf[20];
int  captSetFlag=0;
 int i,n;
CCVMFCView::CCVMFCView()
{
	// TODO: add construction code here
	saveImg    = NULL;
	workImg    = NULL;
  
	m_lpBmi    = 0;

	m_CaptFlag = 0;
	m_dibFlag  = 0;
 	m_ImageType= 0;
  
	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);

	
}

CCVMFCView::~CCVMFCView()
{
	         //  关闭视频

 	if (saveImg)
		cvReleaseImage(&saveImg);           //  释放位图
 	if (workImg)
		cvReleaseImage(&workImg);
 
	if (m_lpBmi)
		free(m_lpBmi);                      //  释放位图信息

	
}

BOOL CCVMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView drawing
CSize logicSize = 0;
void CCVMFCView::OnDraw(CDC* pDC)
{
	CCVMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	if (pDoc->pImg!=NULL)	{	            //  有磁盘输入图像
		if (pDoc->m_Display==0) {           //  尚未显示
 			imageClone(pDoc->pImg,&saveImg);         //  复制到备份位图
			m_dibFlag=imageClone(saveImg,&workImg);  //  复制到工作位图

			m_ImageType=imageType(workImg);
			m_SaveFlag=m_ImageType;
			pDoc->m_Display=1;
		}
	}
 
	if (m_dibFlag) {                        //  DIB 结构改变
 		if (m_lpBmi)
			free(m_lpBmi);
		m_lpBmi=CtreateMapInfo(workImg,m_dibFlag);
		m_dibFlag=0;

		CSize  sizeTotal;
 		sizeTotal = CSize(workImg->width,workImg->height);
		SetScrollSizes(MM_TEXT,sizeTotal);  //  设置滚动条
	}

	char *pBits;
	 if (workImg)  pBits=workImg->imageData;
	
	if (workImg) {                          //  刷新窗口画面
		logicSize = GetTotalSize();// logical size
		StretchDIBits(pDC->m_hDC,
			0,0, workImg->width,workImg->height,
				0,0,workImg->width,workImg->height,
				pBits,m_lpBmi,DIB_RGB_COLORS,SRCCOPY);
	}
}

void CCVMFCView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CCVMFCView diagnostics

#ifdef _DEBUG
void CCVMFCView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCVMFCView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCVMFCDoc* CCVMFCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCVMFCDoc)));
	return (CCVMFCDoc*)m_pDocument;
}
#endif //_DEBUG

//  图像恢复与存储

void CCVMFCView::OnUpdateFileOpen(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_ImageType!=-3);
}

void CCVMFCView::OnUpdateRefresh(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateConservationImage(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFileClose(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateColorImageRefresh(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateAppExit(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(m_ImageType!=-3);
}

void CCVMFCView::OnRefresh() 
{
	m_dibFlag=imageClone(saveImg,&workImg);
	m_ImageType=m_SaveFlag;
  	Invalidate();
}

void CCVMFCView::OnConservationImage() 
{
 	imageClone(workImg,&saveImg);
	m_SaveFlag=m_ImageType;
}

void CCVMFCView::OnColorImageRefresh() 
{
	CCVMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_Display=0;
	Invalidate();
}

void CCVMFCView::OnFileSaveAs() 
{
    CString csBMP="BMP Files(*.BMP)|*.BMP|";
	CString csJPG="JPEG Files(*.JPG)|*.JPG|";
	CString csTIF="TIF Files(*.TIF)|*.TIF|";
	CString csPNG="PNG Files(*.PNG)|*.PNG|";
	CString csDIB="DIB Files(*.DIB)|*.DIB|";
	CString csPBM="PBM Files(*.PBM)|*.PBM|";
	CString csPGM="PGM Files(*.PGM)|*.PGM|";
	CString csPPM="PPM Files(*.PPM)|*.PPM|";
	CString csSR ="SR  Files(*.SR) |*.SR|";
	CString csRAS="RAS Files(*.RAS)|*.RAS||";

    CString csFilter=csBMP+csJPG+csTIF+csPNG+csDIB
					 +csPBM+csPGM+csPPM+csSR+csRAS;

	CString name[]={"","bmp","jpg","tif","png","dib",
		               "pbm","pgm","ppm","sr", "ras",""};

	CString strFileName;
	CString strExtension;
 
	CFileDialog FileDlg(false,NULL,NULL,OFN_HIDEREADONLY,csFilter);
	                                        //  文件存盘对话框
	if (FileDlg.DoModal()==IDOK ) {         //  选择了文件名
 		strFileName = FileDlg.m_ofn.lpstrFile;
		if (FileDlg.m_ofn.nFileExtension == 0) {  //  无文件后缀
			strExtension = name[FileDlg.m_ofn.nFilterIndex];
			strFileName = strFileName + '.' + strExtension;
			                                //  加文件后缀
		}

		CCVMFCDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		//Mat g_SrcImage;
		//g_SrcImage = cvarrToMat(workImg);
		//std::string sz2 = CT2A(strFileName.GetBuffer()); //转化为非unicode.
		// cv::imwrite(sz2, g_SrcImage);
		pDoc->Save(strFileName,workImg);   //  当前画面存盘
	}
}

void CCVMFCView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	
	if (workImg) {                          //  刷新窗口画面
 		CSize  sizeTotal;
 		sizeTotal = CSize((workImg->width)/2,(workImg->height)/2);
		SetScrollSizes(MM_TEXT, sizeTotal);   //  设置滚动条
	}
}


void CCVMFCView::OnAverageImage() 
{
	
}

void CCVMFCView::OnViewContinue()           //  视频解冻
{
	SetTimer(ID_TIMER,67,NULL);             //  每秒采样 15 次
	m_CaptFlag=1;                           //  恢复视频状态
}



//  点处理

void CCVMFCView::OnUpdateColorToGray(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType>1));
}

void CCVMFCView::OnUpdateImageInvert(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFlipV(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFlipH(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFlip(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateRotation30(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateWarpAffine(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateWarpPerspect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateImageHistogram(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateImageAdjust(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateHistEqualize(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnColorToGray()            //  图像彩色变灰阶   
{
	IplImage* pImage;

	pImage = workImg;
	Mat g_SrcImage = cvarrToMat(pImage);
	Mat g_DstImage = Mat::zeros(g_SrcImage.size(), g_SrcImage.type());
	if (g_SrcImage.channels()>=3)
	{
		cvtColor(g_SrcImage, g_DstImage, CV_BGR2GRAY);
	}
	IplImage* pBinary = &IplImage(g_DstImage);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	////**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType = 1;
	Invalidate();

}

void CCVMFCView::OnFlipV() 
{
 	cvFlip(workImg);                        //  垂直镜像 cvFlip(in,0,0) 
	Invalidate();
}

void CCVMFCView::OnFlipH() 
{
 	cvFlip(workImg,0,1);                    //  水平镜像
 	Invalidate();
}

void CCVMFCView::OnFlip() 
{
  	cvFlip(workImg,0,-1);                   //  180 度旋转
 	Invalidate();
}

IplImage* rotateImage1(IplImage* img, int degree) {
	Mat srcimg = cvarrToMat(img);
	if (srcimg.channels()>=3)
	{	}
		double angle = degree * CV_PI / 180.; // 弧度    
		double a = sin(angle), b = cos(angle);
		int width = img->width;
		int height = img->height;
		int width_rotate = int(height * fabs(a) + width * fabs(b));
		int height_rotate = int(width * fabs(a) + height * fabs(b));
		float map[6];
		CvMat map_matrix = cvMat(2, 3, CV_32F, map);
		// 旋转中心  
		CvPoint2D32f center = cvPoint2D32f(width / 2, height / 2);
		cv2DRotationMatrix(center, degree, 1.0, &map_matrix);
		map[2] += (width_rotate - width) / 2;
		map[5] += (height_rotate - height) / 2;
		IplImage* img_rotate = cvCreateImage(cvSize(width_rotate, height_rotate), 8, 3);
		cvWarpAffine(img, img_rotate, &map_matrix, CV_INTER_LINEAR | CV_WARP_FILL_OUTLIERS, cvScalarAll(0));
		return img_rotate;

	
}

Mat angleRectify(Mat img, float angle)
{ 

	Mat retMat = Mat::zeros(550, 850, CV_8UC3);
	float anglePI = (float)(angle * CV_PI / 180);
	int xSm, ySm;
	for (int i = 0; i < retMat.rows; i++)
		for (int j = 0; j < retMat.cols; j++)
		{
			xSm = (int)((i - retMat.rows / 2)*cos(anglePI) - (j - retMat.cols / 2)*sin(anglePI) + 0.5);
			ySm = (int)((i - retMat.rows / 2)*sin(anglePI) + (j - retMat.cols / 2)*cos(anglePI) + 0.5);
			xSm += img.rows / 2;
			ySm += img.cols / 2;
			if (xSm >= img.rows || ySm >= img.cols || xSm <= 0 || ySm <= 0) {
				retMat.at<Vec3b>(i, j) = Vec3b(0, 0);
			}
			else {
				retMat.at<Vec3b>(i, j) = img.at<Vec3b>(xSm, ySm);
			}
		}

	return retMat;
}

void CCVMFCView::OnRotation90()             //  90 度旋转
{   
    IplImage *pImage;
	IplImage *inputdst;
	//cvFlip(workImg, 0, -1);
	pImage = workImg;
	Mat srcimg = cvarrToMat(pImage);
	inputdst = rotateImage1(pImage, 90);
	m_dibFlag = imageReplace(inputdst, &workImg);
	Invalidate();
}

int ImageAdjust(IplImage* src, IplImage* dst, 
    	double low, double high,   // X方向：low and high are the intensities of src
    	double bottom, double top, // Y方向：mapped to bottom and top of dst
    	double gamma )
{
	if( 	low<0 && low>1 && high <0 && high>1&&
		bottom<0 && bottom>1 && top<0 && top>1 && low>high)
        return -1;
    double low2 = low*255;
    double high2 = high*255;
    double bottom2 = bottom*255;
    double top2 = top*255;
    double err_in = high2 - low2;
    double err_out = top2 - bottom2;

    int x,y;
    double val;

    // intensity transform
    for( y = 0; y < src->height; y++)
    {
        for (x = 0; x < src->width; x++)
        {
            val = ((uchar*)(src->imageData + src->widthStep*y))[x]; 
            val = pow((val - low2)/err_in, gamma) * err_out + bottom2;
            if(val>255) val=255; if(val<0) val=0; // Make sure src is in the range [low,high]
            ((uchar*)(dst->imageData + dst->widthStep*y))[x] = (uchar) val;
        }
    }
    return 0;
}


void CCVMFCView::OnImageHistogram()         //  灰阶图像直方图
{                
    IplImage *src;
    IplImage *histimg = 0;
    CvHistogram *hist = 0;
    
    int hdims = 256;     // 划分HIST的个数，越高越精确
    float hranges_arr[] = {0,255};
    float* hranges = hranges_arr;
    int bin_w;  
    float max_val;
    int i;
    
	src = workImg;
    
    cvNamedWindow( "Histogram", 0 );
     
    hist = cvCreateHist( 1, &hdims, CV_HIST_ARRAY, &hranges, 1 );  // 计算直方图
    histimg = cvCreateImage( cvSize(320,200), 8, 3 );
    cvZero( histimg );
    cvCalcHist( &src, hist, 0, 0 ); // 计算直方图
    cvGetMinMaxHistValue( hist, 0, &max_val, 0, 0 );  // 只找最大值
	cvConvertScale( hist->bins, hist->bins, 
		max_val ? 255. / max_val : 0., 0 ); // 缩放 bin 到区间 [0,255] 
    cvZero( histimg );
    bin_w = histimg->width / hdims;  // hdims: 条的个数，则 bin_w 为条的宽度
    
    // 画直方图
    for( i = 0; i < hdims; i++ )
    {
        double val = ( cvGetReal1D(hist->bins,i)*histimg->height/255 );
        CvScalar color = CV_RGB(255,255,0); //(hsv2rgb(i*180.f/hdims);
        cvRectangle( histimg, cvPoint(i*bin_w,histimg->height),
            cvPoint((i+1)*bin_w,(int)(histimg->height - val)),
            color, 1, 8, 0 );
    }
    
    cvShowImage( "Histogram", histimg );

    cvReleaseImage( &histimg );
    cvReleaseHist ( &hist );
    cvWaitKey(0);

    cvDestroyWindow("Histogram");
}


//  直方图均衡化
#define HDIM    256    // bin of HIST, default = 256

void CCVMFCView::OnHistEqualize()           //  直方图均衡化
{

    IplImage *src = 0, *dst = 0;
    CvHistogram *hist = 0;
    
    int n = HDIM;     
    double nn[HDIM];
    uchar T[HDIM];
    CvMat *T_mat;
    
    int x;
    int sum = 0; // sum of pixels of the source image 图像中象素点的总和
    double val = 0;
    
//    if( argc != 2 || (src=cvLoadImage(argv[1], 0)) == NULL)  // force to gray image
//        return -1;

	src = workImg;
    
//    cvNamedWindow( "source", 1 );
    cvNamedWindow( "result", 1 );
    
    // 计算直方图
    hist = cvCreateHist( 1, &n, CV_HIST_ARRAY, 0, 1 );  
    cvCalcHist( &src, hist, 0, 0 ); 
    
    // Create Accumulative Distribute Function of histgram
    val = 0;
    for ( x = 0; x < n; x++)
    {
        val = val + cvGetReal1D (hist->bins, x);
        nn[x] = val;
    }

    // 归一化直方图
    sum = src->height * src->width;
    for( x = 0; x < n; x++ )
    {
        T[x] = (uchar) (255 * nn[x] / sum); // range is [0,255]
    }

    // Using look-up table to perform intensity transform for source image 
    dst = cvCloneImage( src );
    T_mat = cvCreateMatHeader( 1, 256, CV_8UC1 );
    cvSetData( T_mat, T, 0 );    
    // 直接调用内部函数完成 look-up-table 的过程
    cvLUT( src, dst, T_mat ); 

//    cvShowImage( "source", src );
	cvFlip(dst);
    cvShowImage( "result", dst );

    cvReleaseHist ( &hist );
    cvWaitKey(0);


    cvDestroyWindow("result");


	cvFlip(dst);
	m_dibFlag=imageReplace(dst,&workImg);
  	
	Invalidate();
}


//  邻域处理

void CCVMFCView::OnUpdateBlurSmooth(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateGaussSmooth(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateMedianSmooth(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateSobel(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateLaplace(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnBlurSmooth()             //  邻域平均
{
	IplImage* in;
 
	in = workImg;
 
	IplImage* out = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels); 

	cvSmooth(in,out,CV_BLUR,3,workImg->nChannels);  //  简单平均

	m_dibFlag=imageReplace(out,&workImg); 

	Invalidate();
}

void CCVMFCView::OnGaussSmooth()            //  Gauss 滤波
{                     
	IplImage* in;
 
	in = workImg;
 
	IplImage* out = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels);   //  建立辅助位图

	cvSmooth(in,out,CV_GAUSSIAN,3,workImg->nChannels);  //  Gauss 平滑

	m_dibFlag=imageReplace(out,&workImg);   //  输出处理结果

	Invalidate();
}

void CCVMFCView::OnMedianSmooth()           //  中值滤波
{
	IplImage* in;
 
	in = workImg;
 
	IplImage* out = cvCreateImage(cvGetSize(in),
		IPL_DEPTH_8U,workImg->nChannels); 

	cvSmooth(in,out,CV_MEDIAN,3,workImg->nChannels);  //  中值滤波

	m_dibFlag=imageReplace(out,&workImg);

	Invalidate();
}

//  二值图像处理

void CCVMFCView::OnUpdateThresholding1(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateThresholding2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateBasicGlobalThreshold(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateAdaptiveThreshold(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateContourTrack(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}


void CCVMFCView::OnUpdateDistance(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateConvexHull(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateConvexHull2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateAreaConvexHull(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateConvexityDefects(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateMinAreaRect2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateAreaRect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateMinAreaRect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}

void CCVMFCView::OnUpdateApproxPoly(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==-1));
}
 
char *threWin="Threshold Window";
IplImage *threImage0 = 0;
IplImage *threImage  = 0;
int  Threshold       = 128;

void onThreChange(int pos)
{
	cvThreshold(threImage,threImage0,Threshold,
				255,CV_THRESH_BINARY);
	cvShowImage( threWin, threImage0 );
}

void CCVMFCView::OnThresholding1() 
{
  	threImage  = cvCloneImage(workImg);
	cvFlip(threImage);
   	threImage0 = cvCloneImage(threImage);
  
    cvNamedWindow(threWin, 0);
	cvResizeWindow(threWin, 300, 320);

    cvCreateTrackbar( "Thresh", threWin, &Threshold, 255, onThreChange );
	onThreChange(0);
 	
	cvWaitKey(0);

	cvReleaseImage(&threImage);
    cvDestroyWindow(threWin);

	cvFlip(threImage0);
	m_dibFlag=imageReplace(threImage0,&workImg);
  	
	m_ImageType=-1;
	Invalidate();
}
 
void onThreChange2(int pos)
{
	/*cvThreshold(threImage,threImage0,Threshold,
				255,CV_THRESH_BINARY);*/
}

void CCVMFCView::OnThresholding2() 
{
	//int   flag=0,thre=0;

 // 	threImage  = cvCloneImage(workImg);
	//cvFlip(threImage);
 //  	threImage0 = cvCloneImage(threImage);
 // 
 //   cvNamedWindow(threWin, 0);
	//cvResizeWindow(threWin, 300, 320);

 //   cvCreateTrackbar( "Thresh", threWin, &Threshold, 255, onThreChange2 );
	//cvShowImage( threWin, threImage );
	//onThreChange2(0);
 //	
	//m_ImageType=-3;
	//for (;;) {
	//	if (cvWaitKey(40)==27) break;

 //		if (flag==0) {
	//		free(m_lpBmi);
	//		m_lpBmi=CtreateMapInfo(workImg,1);
	//		flag=1;
	//	}
	//	if (Threshold != thre) {
	//		cvCopy(threImage0,workImg);
 //			cvFlip(workImg);

	//		CClientDC dc(this);
	//		StretchDIBits(dc.m_hDC,         //  刷新视图窗口
	//			0,0,workImg->width,workImg->height,  
	//			0,0,workImg->width,workImg->height,
	//			workImg->imageData,m_lpBmi,DIB_RGB_COLORS,SRCCOPY);
	//		thre = Threshold;
	//	}
	//}

	//cvReleaseImage(&threImage);
	//cvReleaseImage(&threImage0);
 //   cvDestroyWindow(threWin);
 //  	
	//m_ImageType=-1;
	//Invalidate();
}
void CCVMFCView::OnContourTrack()           //  轮廓跟踪
{   

 	int  mode = CV_RETR_CCOMP;
	int  contours_num = 0,color;
	CvScalar external_color;
	CvScalar hole_color;
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contour = 0;
	IplImage* pImg;
	IplImage* pContourImg = NULL;
	CvFont  font;
	char  ch[20];

 	cvFlip(workImg);
 	pImg = workImg;
	pContourImg = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,3);
	cvZero(pContourImg);

	mode = CV_RETR_LIST;
//---------------------------------------------------------
	contours_num=cvFindContours(pImg,storage,&contour,  //  轮廓跟踪
		sizeof(CvContour),mode,CV_CHAIN_APPROX_NONE);
//---------------------------------------------------------

	color=2;
	for (int n=0; contour != 0; contour = contour->h_next,n++) {
//		external_color = CV_RGB(rand()&255,rand()&255,rand()&255);
//		hole_color = CV_RGB(rand()&255,rand()&255,rand()&255);
		external_color = CV_RGB(VgaDefPal[color].rgbRed,
			VgaDefPal[color].rgbGreen,VgaDefPal[color].rgbBlue);
		color=NextColor(2,color,4);         //  1 or 4
		hole_color = CV_RGB(192,192,192);
		cvDrawContours(pContourImg,contour,
				external_color,hole_color,1,1,8);
	}

	cvReleaseMemStorage(&storage);

	m_dibFlag=imageReplace(pContourImg,&workImg);  //  输出处理结果

	if ((n>2)&&(workImg->width>200)&&(workImg->height>150)) {
		cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX,0.4,0.4,0,1,CV_AA);
		sprintf(ch,"%d",contours_num);
		cvPutText(workImg,"contours_num",cvPoint(30,40),&font,CV_RGB(255,255,255));
		cvPutText(workImg,ch,cvPoint(30,60),&font,CV_RGB(255,255,255));
	}

 	cvFlip(workImg);
 
	m_ImageType=-2;
 	Invalidate();
}

//  形态学处理

void CCVMFCView::OnUpdateErosion(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateDilation(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateOpenning(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateClosing(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateGrads(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(abs(m_ImageType)==1));
}

void CCVMFCView::OnUpdateGrayTophat(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateGrayBlackhat(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

//  二值与灰值形态学处理
void CCVMFCView::OnErosion()                //  腐蚀
{
  	cvErode(workImg,workImg,0,1);
 	Invalidate();
}

void CCVMFCView::OnDilation()               //  膨胀
{
  	cvDilate(workImg,workImg,0,1);
 	Invalidate();
}
 
//  综合处理

void CCVMFCView::OnUpdateImageShrink(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateRadialGrads(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>2));
}

void CCVMFCView::OnUpdateCannyBorddetec(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}
 
void CCVMFCView::OnUpdateHoughLines(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateHoughCircle(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateSquaresTest(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&
		(m_ImageType)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateFloodFill(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdatePyrSegmentation(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateFitEllipse(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateSnake(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==1));
}

void CCVMFCView::OnUpdateWatershed(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateCornersTest(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType>0));
}

void CCVMFCView::OnUpdateClusters(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateSeqPartition(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateRotationTrack(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==0));
}

void CCVMFCView::OnUpdateFaceDetect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

//-------------------------------------
//  图像缩半


IplImage* doPyrDown(IplImage* in, int filter= CV_GAUSSIAN_5x5)
{                                           //  位图缩小一倍
	if (in->width%2) in->width++;
	IplImage* out = cvCreateImage(cvSize(in->width/2,
			in->height/2),in->depth,in->nChannels);
	cvPyrDown(in,out);                      //  位图缩小
	return(out);
}



void CCVMFCView::OnImageShrink()            //  图像缩半
{
	IplImage* in;
	IplImage* out = 0;
 
	in = workImg;
	if ((in->nChannels==3)&&                //  长或宽非偶数的真彩色图像
			((in->width%2)||(in->height%2))) {
		out = cvCreateImage(cvSize((in->width+1)/2,
			(in->height+1)/2),in->depth,in->nChannels);
		ImageDwindle(in,out,2,in->nChannels);
	}
	else 
 		out = doPyrDown(in);                //  图像缩小

	if (out)
		m_dibFlag=imageReplace(out,&workImg);   //  输出处理结果
	Invalidate();
}

void CCVMFCView::OnCannyBorddetec()         //  Canny 边缘检测
{     
	IplImage* in;
	IplImage* out = 0;

	in = workImg;
	Mat DstPic, edge, grayImage;
	Mat im ;
	Mat  matimg = cvarrToMat(in);
	//cv::Mat img(workImg, 0);  // 0是不複製影像，也就是pImg與img的data共用同個記憶體位置，header各自有

	//
	//创建与src同类型和同大小的矩阵
	DstPic.create(matimg.size(), matimg.type());

	//将原始图转化为灰度图
	if (matimg.channels()>=3)
	{
		cvtColor(matimg, grayImage, COLOR_BGR2GRAY);
	}
	else
	{
		grayImage = matimg.clone();
	}
	//先使用3*3内核来降噪
	blur(grayImage, edge, Size(3, 3));
	//运行canny算子
	Canny(edge, edge, 3, 9, 3);
	IplImage* pBinary = &IplImage(edge);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	m_ImageType=1;
	Invalidate();

}



//---------------------------------------------------------
//  视频处理

void CCVMFCView::OnUpdateDynamicBorderTest(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}
 
void CCVMFCView::OnUpdateOpticalFlowTrack(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateMotionDetect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateCamShiftDemo(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateForegroundDetect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

void CCVMFCView::OnUpdateFaceDetect2(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag==0)&&(m_ImageType!=-3));
}

//-------------------------------------
//  动态边缘检测


//-------------------------------------
//  L_K 算法光流跟踪

//IplImage *image = 0, *grey = 0, *prev_grey = 0, *pyramid = 0, *prev_pyramid = 0, *swap_temp;
IplImage *grey = 0, *prev_grey = 0, *pyramid = 0, *prev_pyramid = 0, *swap_temp;

int win_size = 10;
const int MAX_COUNT = 500;
CvPoint2D32f* points[2] = {0,0}, *swap_points;
char* status = 0;
int count = 0;
int need_to_init = 0;
int night_mode = 0;
int flags = 0;
int add_remove_pt = 0;
CvPoint pt;


void CCVMFCView::OnOpticalFlowTrack()       //  L_K 算法光流跟踪
{
    CvCapture* capture = 0;
    
    capture = cvCaptureFromCAM(0);
 
    if( !capture )
    {
 		AfxMessageBox("本机没有安装摄像头！");
        return;
    }

	m_CaptFlag=3;                           //  设置视频状态标志

    cvNamedWindow( "LkDemo", 0 );  

	m_ImageType=-3;
    for(;;)
    {
        IplImage* frame = 0;
        int i, k, c;

        frame = cvQueryFrame( capture );
        if( !frame )
            break;

 
   

 
        
        if( need_to_init )
        {
            /* automatic initialization */
            IplImage* eig = cvCreateImage( cvGetSize(grey), 32, 1 );
            IplImage* temp = cvCreateImage( cvGetSize(grey), 32, 1 );
            double quality = 0.01;
            double min_distance = 10;

            count = MAX_COUNT;
            cvGoodFeaturesToTrack( grey, eig, temp, points[1], &count,
                                   quality, min_distance, 0, 3, 0, 0.04 );
            cvFindCornerSubPix( grey, points[1], count,
                cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
            cvReleaseImage( &eig );
            cvReleaseImage( &temp );

            add_remove_pt = 0;
        }
        else if( count > 0 )
        {
            cvCalcOpticalFlowPyrLK( prev_grey, grey, prev_pyramid, pyramid,
                points[0], points[1], count, cvSize(win_size,win_size), 3, status, 0,
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03), flags );
            flags |= CV_LKFLOW_PYR_A_READY;
            for( i = k = 0; i < count; i++ )
            {
                if( add_remove_pt )
                {
                    double dx = pt.x - points[1][i].x;
                    double dy = pt.y - points[1][i].y;

                    if( dx*dx + dy*dy <= 25 )
                    {
                        add_remove_pt = 0;
                        continue;
                    }
                }
                
                if( !status[i] )
                    continue;
                
                points[1][k++] = points[1][i];
   
            }
            count = k;
        }

        if( add_remove_pt && count < MAX_COUNT )
        {
            points[1][count++] = cvPointTo32f(pt);
            cvFindCornerSubPix( grey, points[1] + count - 1, 1,
                cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
            add_remove_pt = 0;
        }

        CV_SWAP( prev_grey, grey, swap_temp );
        CV_SWAP( prev_pyramid, pyramid, swap_temp );
        CV_SWAP( points[0], points[1], swap_points );
        need_to_init = 0;
    
        c = cvWaitKey(10);
        if( (char)c == 27 )
            break;
        switch( (char) c )
        {
        case 'r':
            need_to_init = 1;
            break;
        case 'c':
            count = 0;
            break;
        case 'n':
            night_mode ^= 1;
            break;
        default:
            ;
        }
    }

    cvReleaseCapture( &capture );
    cvDestroyWindow("LkDemo");

	m_CaptFlag=0;
	m_ImageType=0;
}

//-------------------------------------
//  背景建模检测运动物体





//  运动目标跟踪

// various tracking parameters (in seconds)
const double MHI_DURATION = 1;
const double MAX_TIME_DELTA = 0.5;
const double MIN_TIME_DELTA = 0.05;
// number of cyclic frame buffer used for motion detection
// (should, probably, depend on FPS)
const int N = 4;

// ring image buffer
IplImage **buf = 0;
int last = 0;

// temporary images
IplImage *mhi = 0; // MHI
IplImage *orient = 0; // orientation
//IplImage *mask = 0; // valid orientation mask
IplImage *segmask = 0; // motion segmentation map
//CvMemStorage* storage = 0; // temporary storage


//  彩色目标跟踪

//IplImage *image = 0, *hsv = 0, *hue = 0, *mask = 0, *backproject = 0, *histimg = 0;
IplImage *hsv = 0, *hue = 0, *backproject = 0, *histimg = 0;
CvHistogram *hist = 0;

int backproject_mode = 0;
int select_object = 0;
int track_object = 0;
int show_hist = 1;
CvRect selection;
CvRect track_window;
CvBox2D track_box;
CvConnectedComp track_comp;
int hdims = 16;
float hranges_arr[] = {0,180};
float* hranges = hranges_arr;
int vmin = 10, vmax = 256, smin = 30;


CvScalar hsv2rgb( float hue )
{
    int rgb[3], p, sector;
    static const int sector_data[][3]=
        {{0,2,1}, {1,2,0}, {1,0,2}, {2,0,1}, {2,1,0}, {0,1,2}};
    hue *= 0.033333333333333333333333333333333f;
    sector = cvFloor(hue);
    p = cvRound(255*(hue - sector));
    p ^= sector & 1 ? 255 : 0;

    rgb[sector_data[sector][0]] = 255;
    rgb[sector_data[sector][1]] = 0;
    rgb[sector_data[sector][2]] = p;

    return cvScalar(rgb[2], rgb[1], rgb[0],0);
}

void CCVMFCView::OnCamShiftDemo() 
{
}
//  彩色图像处理

void CCVMFCView::OnUpdateImageRgb(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageRgbC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageHsv(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageLab(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageXyz(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageYcrcb(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateImageLuv(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdate2dHistogram(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateBlurSmoothC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateGaussSmoothC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateMedianSmoothC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateSobelC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}

void CCVMFCView::OnUpdateLaplaceC(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((m_CaptFlag!=1)&&(m_ImageType==3));
}


void CCVMFCView::OnBlurSmoothC() 
{
	OnBlurSmooth();
}

void CCVMFCView::OnGaussSmoothC() 
{
	OnGaussSmooth();
}

void CCVMFCView::OnMedianSmoothC() 
{
	OnMedianSmooth();
}

void CCVMFCView::OnSobelC() 
{
	/*OnSobel();*/
}

void CCVMFCView::OnLaplaceC() 
{
	/*OnLaplace();*/
}


void pyramid_up(cv::Mat &image, std::vector<Mat> &pyramid_images, int level) {
	Mat temp = image.clone();
	Mat dst;
	for (int i = 0; i < level; i++) {
		pyrDown(temp, dst);
		//imshow(format("pyramid_up_%d", i), dst);
		temp = dst.clone();
		pyramid_images.push_back(temp);
	}
}

void laplaian_demo(std::vector<Mat> &pyramid_images, Mat &image) {
	for (int t = pyramid_images.size() - 1; t > -1; t--) {
		Mat dst;
		if (t - 1 < 0) {
			pyrUp(pyramid_images[t], dst, image.size());
			subtract(image, dst, dst);
			dst = dst + Scalar(127, 127, 127);
			//imshow(format("laplaian_layer_%d", t), dst);
		}
		else {
			pyrUp(pyramid_images[t], dst, pyramid_images[t - 1].size());
			subtract(pyramid_images[t - 1], dst, dst);
			dst = dst + Scalar(127, 127, 127);
			//imshow(format("laplaian_layer_%d", t), dst);
		}
	}
}
	


void CCVMFCView::OnImg2big()
{
	IplImage* in;
	IplImage* out = 0;
	in = workImg;
	CvSize size;
	double scale = 1.5;
	size.width = in->width*scale;
	size.height = in->height*scale;
	out = cvCreateImage(size, in->depth, in->nChannels);
	// ·CV_INTER_NN - 最近-邻居插补
	// ·CV_INTER_LINEAR - 双线性插值（默认方法）
	// ·CV_INTER_AREA - 像素面积相关重采样。当缩小图像时，该方法可以避免波纹的出现。当放大图像时，类似于方法CV_INTER_NN。
	// ·CV_INTER_CUBIC - 双三次插值。)
	cvResize(in, out, CV_INTER_AREA);
	m_dibFlag = imageReplace(out, &workImg);
	Invalidate();
}
//Mat src = cvarrToMat(in);
//std::vector<Mat> p_images;
//pyramid_up(src, p_images, 2);
//laplaian_demo(p_images, src);
//
//IplImage* pBinary = &IplImage(src);
////深拷贝只要再加一次复制数据：  
//IplImage *input = cvCloneImage(pBinary);
//m_dibFlag = imageReplace(input, &workImg);
//
void CCVMFCView::OnGaosilvbo()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* in;

	in = workImg;
	Mat src = cvarrToMat(in);
	Mat out;
	GaussianBlur(src, out, Size(3, 3), 0, 0);


	IplImage* pBinary = &IplImage(out);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	////**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType = 1;
	Invalidate();

}


void CCVMFCView::OnJunzhilvbo()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* in;
	in = workImg;
	Mat src = cvarrToMat(in);
	Mat out;
	blur(src, out, Size(3, 3));//-1指原图深度
	IplImage* pBinary = &IplImage(out);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	////**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType = 1;
	Invalidate();

}


void CCVMFCView::OnZhongzhilvbo()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* in;
	in = workImg;
	Mat src = cvarrToMat(in);
	Mat out;
	medianBlur(src, out, 5);//第三个参数表示孔径的线性尺寸，它的值必须是大于1的奇数
	IplImage* pBinary = &IplImage(out);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	////**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType = 1;
	Invalidate();
}


void CCVMFCView::OnShaungbianlvbo()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* in;
	in = workImg;
	Mat src = cvarrToMat(in);
	Mat out;
	bilateralFilter(src, out, 25, 25 * 2, 25 / 2);
	IplImage* pBinary = &IplImage(out);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	////**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType = 1;
	Invalidate();
}


void CCVMFCView::OnFangkuanglvbo()
{
	IplImage* in;
	in = workImg;
	Mat src = cvarrToMat(in);
	Mat out;
	boxFilter(src, out, -1, Size(3, 3));//-1指原图深度
	IplImage* pBinary = &IplImage(out);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	////**  设置标志及刷新窗口  **            //  修改部分 3
	m_ImageType = 1;
	Invalidate();
}
void gammaProcessImage(Mat& oriMat, double gamma, Mat outputMat) {

	//伽马方法也是按照一个公式修改了每个像素值，我们可以通过LUT函数进行编写，它的公式是：
	//O=(I/255)的γ次方×255
	//代码如下
	Mat lookupTable(1, 256, CV_8U);
	uchar* p = lookupTable.ptr();
	for (int i = 0; i < 256; i++) {
		p[i] = saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
	}
	LUT(oriMat, lookupTable, outputMat);
}


void CCVMFCView::OnLightchange()
{

	GamaDLG dlg;
	dlg.DoModal();
	double a;
	a = gama;
	IplImage* src;
	src = workImg;

	Mat srcimg = cvarrToMat(src);
	Mat dstimg;


	Mat lookupTable(1, 256, CV_8U);
	uchar* p = lookupTable.ptr();
	for (int i = 0; i < 256; i++) {
		p[i] = saturate_cast<uchar>(pow(i / 255.0, a) * 255.0);
	}
	LUT(srcimg, lookupTable, dstimg);

	IplImage* pBinary = &IplImage(dstimg);
	Mat smallimg = cvarrToMat(pBinary);
	Mat Bigdst;
	resize(smallimg, Bigdst, Size(), 1.5, 1.5);//我长宽都变为原来的0.5倍
	IplImage* pBinary1 = &IplImage(Bigdst);

	cvFlip(pBinary1);
	IplImage *input1 = cvCloneImage(pBinary1);
	cvFlip(input1);

	m_dibFlag = imageReplace(input1, &workImg);
	m_ImageType = 1;
	Invalidate();
}


void CCVMFCView::OnDistance()
{
	
}



void CCVMFCView::OnMysobel()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
	IplImage* src;
	src = workImg;
	Mat srcimg = cvarrToMat(src);
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	//求x方向梯度
	Sobel(srcimg, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	//求y方向梯度
	Sobel(srcimg, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	//合并梯度
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	IplImage* pBinary = &IplImage(dst);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	Invalidate();

}


void CCVMFCView::OnLaplacian()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* src;
	src = workImg;
	Mat img = cvarrToMat(src);
	Mat gray, dst, abs_dst;
	//高斯滤波消除噪声
	GaussianBlur(img, img, Size(3, 3), 0, 0, BORDER_DEFAULT);
	if (img.channels()>=3)
	{
		//转换为灰度图
		cvtColor(img, gray, COLOR_RGB2GRAY);
	}
	else
	{
		gray = img.clone();
	}
	//第三个参数：目标图像深度；第四个参数：滤波器孔径尺寸；第五个参数：比例因子；第六个参数：表示结果存入目标图
	Laplacian(gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	//计算绝对值，并将结果转为8位
	convertScaleAbs(dst, abs_dst);
	IplImage* pBinary = &IplImage(abs_dst);
	//深拷贝只要再加一次复制数据：  
	IplImage *input = cvCloneImage(pBinary);
	m_dibFlag = imageReplace(input, &workImg);
	Invalidate();

}

Mat inputImage;
Mat inputImage_mosaic;
Mat inputImage_clone;
//马赛克的大小 
int neightbourhood = 50;
//记录鼠标的状态，0为鼠标左键未按下或弹起，1为鼠标左键按下 
int mouseStatus = 0;
void createMosaicImage(Mat inputMat, Mat& outputMat, int size) {
	RNG rng;
	int height = inputMat.rows;
	int width = inputMat.cols;
	Mat padding;
	Mat tempMat;

	//为了方便后面的计算，将输入的图像大小扩充到宽高都是size的倍数 
	copyMakeBorder(inputMat, padding, 0, size - inputMat.rows % size, 0, size - inputMat.cols % size, BORDER_REPLICATE);
	tempMat = padding.clone();

	for (int row = 0; row < padding.rows; row += size) {
		for (int col = 0; col < padding.cols; col += size) {
			int rand_x = rng.uniform(0, size);
			int rand_y = rng.uniform(0, size);
			Rect rect = Rect(col, row, size, size);
			Mat roi = tempMat(rect);
			Scalar color = Scalar(padding.at<Vec3b>(row + rand_y, col + rand_x)[0], \
				padding.at<Vec3b>(row + rand_y, col + rand_x)[1], \
				padding.at<Vec3b>(row + rand_y, col + rand_x)[2]);
			roi.setTo(color);
		}
	}
	outputMat = tempMat(Rect(0, 0, width, height)).clone();
}

void setMosaic(Mat& inputMat, Rect rect) {
	Mat roi = inputMat(rect);
	Mat tempRoi = inputImage_mosaic(rect);
	tempRoi.copyTo(roi);
}

void onMouse(int events, int x, int y, int flag, void* ustg) {

	//当鼠标移除图片区域的时候，不做操作 
	if (x < 0 || x > inputImage.cols || y < 0 || y > inputImage.rows) {
		return;
	}

	//马赛克块的位置信息 
	int x_left, x_right, y_top, y_bottom;
	x - neightbourhood <= 0 ? x_left = 0 : x_left = x - neightbourhood;
	x + neightbourhood > inputImage.cols ? x_right = inputImage.cols : x_right = x + neightbourhood;
	y - neightbourhood <= 0 ? y_top = 0 : y_top = y - neightbourhood;
	y + neightbourhood > inputImage.rows ? y_bottom = inputImage.rows : y_bottom = y + neightbourhood;

	if (events == CV_EVENT_LBUTTONDOWN) {
		mouseStatus = 1;
		setMosaic(inputImage_clone, Rect(x_left, y_top, x_right - x_left, y_bottom - y_top));
	}
	else if (events == CV_EVENT_MOUSEMOVE) {
		if (mouseStatus == 1) {
			setMosaic(inputImage_clone, Rect(x_left, y_top, x_right - x_left, y_bottom - y_top));
		}
		else {
			//nothing 
		}
	}
	else if (events == CV_EVENT_LBUTTONUP) {
		mouseStatus = 0;
	}
	else {
		//cout << "nothing" << endl; 
	}
	imshow("showImage", inputImage_clone);
}
void CCVMFCView::OnAddmasaike()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* src;
	src = workImg;
	cvFlip(src);
	inputImage = cvarrToMat(src);
	inputImage_clone = inputImage.clone();
	createMosaicImage(inputImage, inputImage_mosaic, neightbourhood);
	namedWindow("showImage", 0);
	setMouseCallback("showImage", onMouse);
	waitKey();

}
Mat GetContoursPic(Mat srcImg)
{
	
	Mat gray, binImg;
	if (srcImg.channels()>=3)
	{
		//灰度化
		cvtColor(srcImg, gray, COLOR_RGB2GRAY);
	}
	else
	{
		gray = srcImg.clone();
	}
	//二值化
	threshold(gray, binImg, 100, 200, CV_THRESH_BINARY);
	std::vector<std::vector<Point> > contours;
	std::vector<Rect> boundRect(contours.size());
	//注意第5个参数为CV_RETR_EXTERNAL，只检索外框  
	findContours(binImg, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); //找轮廓
	for (int i = 0; i < contours.size(); i++)
	{
		//需要获取的坐标  
		CvPoint2D32f rectpoint[4];
		CvBox2D rect = minAreaRect(Mat(contours[i]));
		cvBoxPoints(rect, rectpoint); //获取4个顶点坐标  
		//与水平线的角度  
		float angle = rect.angle;
		int line1 = sqrt((rectpoint[1].y - rectpoint[0].y)*(rectpoint[1].y - rectpoint[0].y) + (rectpoint[1].x - rectpoint[0].x)*(rectpoint[1].x - rectpoint[0].x));
		int line2 = sqrt((rectpoint[3].y - rectpoint[0].y)*(rectpoint[3].y - rectpoint[0].y) + (rectpoint[3].x - rectpoint[0].x)*(rectpoint[3].x - rectpoint[0].x));
		if (line1 * line2 < 600)
		{
			continue;
		}
		//为了让正方形横着放，所以旋转角度是不一样的。竖放的，给他加90度，翻过来  
		if (line1 > line2)
		{
			angle = 90 + angle;
		}
		//新建一个感兴趣的区域图，大小跟原图一样大  
		Mat RoiSrcImg(srcImg.rows, srcImg.cols, CV_8UC3); //注意这里必须选CV_8UC3
		RoiSrcImg.setTo(0); //颜色都设置为黑色  
		//imshow("新建的ROI", RoiSrcImg);
		//对得到的轮廓填充一下  
		drawContours(binImg, contours, -1, Scalar(255), CV_FILLED);
		//抠图到RoiSrcImg
		srcImg.copyTo(RoiSrcImg, binImg);
		//创建一个旋转后的图像  
		Mat RatationedImg(RoiSrcImg.rows, RoiSrcImg.cols, CV_8UC1);
		RatationedImg.setTo(0);
		//对RoiSrcImg进行旋转  
		Point2f center = rect.center;  //中心点  
		Mat M2 = getRotationMatrix2D(center, angle, 1);//计算旋转加缩放的变换矩阵 
		warpAffine(RoiSrcImg, RatationedImg, M2, RoiSrcImg.size(), 1, 0, Scalar(0));//仿射变换 
		return RatationedImg;
		
	}
}


//基于轮廓纠正
void CCVMFCView::OnLunkuojiuzhen()
{
	// TODO: 在此添加命令处理程序代码
	IplImage* src;
	src = workImg;
	
	Mat srcimg = cvarrToMat(src);

	Mat dst = GetContoursPic(srcimg);

	IplImage* pBinary = &IplImage(dst);
	IplImage *input = cvCloneImage(pBinary);

	m_dibFlag = imageReplace(input, &workImg);
		m_ImageType = 1;

	Invalidate();
}
//度数转换
double DegreeTrans(double theta)
{
	double res = theta / CV_PI * 180;
	return res;
}
void rotateImage(Mat src, Mat& img_rotate, double degree)
{
	//旋转中心为图像中心    
	Point2f center;
	center.x = float(src.cols / 2.0);
	center.y = float(src.rows / 2.0);
	int length = 0;
	length = sqrt(src.cols*src.cols + src.rows*src.rows);
	//计算二维旋转的仿射变换矩阵  
	Mat M = getRotationMatrix2D(center, degree, 1);
	warpAffine(src, img_rotate, M, Size(length, length), 1, 0, Scalar(255, 255, 255));//仿射变换，背景色填充为白色  
}
//通过霍夫变换计算角度
double CalcDegree(const Mat &srcImage, Mat &dst)
{
	Mat midImage, dstImage;

	Canny(srcImage, midImage, 50, 200, 3);
	cvtColor(midImage, dstImage, CV_GRAY2BGR);

	//通过霍夫变换检测直线
	std::vector<Vec2f> lines;
	HoughLines(midImage, lines, 1, CV_PI / 180, 300, 0, 0);//第5个参数就是阈值，阈值越大，检测精度越高
	if (!lines.size())
	{
		HoughLines(midImage, lines, 1, CV_PI / 180, 200, 0, 0);
	}
	//cout << lines.size() << endl;

	if (!lines.size())
	{
		HoughLines(midImage, lines, 1, CV_PI / 180, 150, 0, 0);
	}
	//cout << lines.size() << endl;
	if (!lines.size())
	{
		return ERROR;
	}
	float sum = 0;
	//依次画出每条线段
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		Point pt1, pt2;
		//cout << theta << endl;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		//只选角度最小的作为旋转角度
		sum += theta;
		line(dstImage, pt1, pt2, Scalar(55, 100, 195), 1, LINE_AA); //Scalar函数用于调节线段颜色
	}
	float average = sum / lines.size(); //对所有角度求平均，这样做旋转效果会更好
	double angle = DegreeTrans(average) - 90;

	rotateImage(dstImage, dst, angle);
	//imshow("直线探测效果图2", dstImage);
	return angle;
}
Mat ImageRecify(Mat src)
{
	double degree;
	Mat dst;
	//倾斜角度矫正
	degree = CalcDegree(src, dst);
	
	rotateImage(src, dst, degree);
	Mat resulyImage = dst(Rect(0, 0, dst.cols, 500)); //根据先验知识，估计好文本的长宽，再裁剪下来
	return resulyImage;
}

void CCVMFCView::OnTextjiaozheng()
{
	IplImage* src;
	src = workImg;
	Mat srcimg = cvarrToMat(src);
	flip(srcimg, srcimg, 0);
	Mat dst;
	dst= ImageRecify(srcimg);
	//flip(dst, dst, 0);
	cvNamedWindow("图像校正", 1);
	cv::imshow("图像校正",dst);
	cvWaitKey(0);
	cvDestroyWindow("result");
	IplImage* pBinary = &IplImage(dst);
	cvFlip(pBinary);
	IplImage *input1 = cvCloneImage(pBinary);
	//cvFlip(pBinary);
	m_dibFlag = imageReplace(input1, &workImg);

	Invalidate();
}


void CCVMFCView::OnImagematch()
{
	// TODO: 在此添加命令处理程序代码
	DLGImgMatch dlg;
	dlg.DoModal();
	CString srcPath = srcfilePath;
	CString dstPath = dstfilePath;

	Mat srcimg, dstimg;
	std::string spath = CT2A(srcPath.GetBuffer()); //转化为非unicode.
	srcimg = imread(spath);
	std::string dpath = CT2A(dstPath.GetBuffer()); //转化为非unicode.
	dstimg = imread(dpath);

	Ptr<cv::xfeatures2d::SURF> surf;      //创建方式和2中的不一样
	surf = SURF::create(700);

	BFMatcher matcher;
	Mat c, d;
	std::vector<KeyPoint>key1, key2;
	std::vector<DMatch> matches;

	surf->detectAndCompute(srcimg, Mat(), key1, c);
	surf->detectAndCompute(dstimg, Mat(), key2, d);

	matcher.match(c, d, matches);       //匹配

	//sort(matches.begin(), matches.end());  //筛选匹配点
	std::vector< DMatch > good_matches;
	double max_dist = 0;
	double min_dist = 100;
	for (int k = 0; k < matches.size(); k++)
	{
		double dist = matches[k].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}
	//筛选出较好的匹配点  
	std::vector<DMatch> goodMatches;
	for (int j = 0; j < matches.size(); j++)
	{
		if (matches[j].distance < 0.2*(max_dist + min_dist))
		{
			goodMatches.push_back(matches[j]);
		}
	}
	Mat outimg;
	drawMatches(srcimg, key1, dstimg, key2, goodMatches, outimg, Scalar::all(-1), Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);  //绘制匹配点
	cv::imshow("结果", outimg);
}
