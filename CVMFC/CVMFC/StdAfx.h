#ifndef POINTER_64  
  
#if !defined(_MAC) && (defined(_M_MRX000) || defined(_M_AMD64) || defined(_M_IA64)) && (_MSC_VER >= 1100) && !(defined(MIDL_PASS) || defined(RC_INVOKED))  
#define POINTER_64 __ptr64  
typedef unsigned __int64 POINTER_64_INT;  
#if defined(_WIN64)  
#define POINTER_32 __ptr32  
#else  
#define POINTER_32  
#endif  
#else  
#if defined(_MAC) && defined(_MAC_INT_64)  
#define POINTER_64 __ptr64  
typedef unsigned __int64 POINTER_64_INT;  
#else  
#if (_MSC_VER >= 1300) && !(defined(MIDL_PASS) || defined(RC_INVOKED))  
#define POINTER_64 __ptr64  
#else  
#define POINTER_64  
#endif  
typedef unsigned long POINTER_64_INT;  
#endif  
#define POINTER_32  
#endif  
#endif  
//

#if !defined(AFX_STDAFX_H__1836CF0C_3704_4215_8745_F068486288D6__INCLUDED_)
#define AFX_STDAFX_H__1836CF0C_3704_4215_8745_F068486288D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
  
#include "CVMFC.h"                          //  窗口管理

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/opencv.hpp"
#include"opencv2/xfeatures2d.hpp"
#include<opencv2/core.hpp>
#include<vector>
using namespace cv::xfeatures2d;


 
                      //  视频采集接口

#include "Processing.h"                     //  附加辅助函数

#endif // !defined(AFX_STDAFX_H__1836CF0C_3704_4215_8745_F068486288D6__INCLUDED_)
#include <afxwin.h>
#include <afxwin.h>
